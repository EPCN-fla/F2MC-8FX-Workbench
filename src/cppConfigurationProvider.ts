import * as childProcess from 'node:child_process';
import * as path from 'node:path';

import * as vscode from 'vscode';

import { resolveCompilerIncludeDirectory } from './toolchain';
import { HELPER_DIR_NAME, LEGACY_HELPER_DIR_NAME } from './constants';
import type { F2mcProjectConfig, F2mcProjectInfo } from './types';

const BUILTIN_DEFINES: string[] = [
	// Neutralize SOFTUNE-only type qualifiers so cpptools can parse I/O register headers
	'__io=',
	'__interrupt=',
	'__near=',
	'__far=',
	'__direct=',
	'__segment=',
	'__at(x)=',
	'__asm(x)='
];

const CPP_FILE_EXTENSIONS = new Set(['.c', '.h', '.cc', '.cpp', '.cxx', '.hpp', '.hxx']);
const FAMILY_HEADER_PATTERN = /^_f2mc.*\.h$/i;
const CHIP_HEADER_PATTERN = /^mb\d+.*\.h$/i;
const MCU_HEADER_NAME = 'mcu.h';
const IO_CHAIN_HEADER_PATTERN = /^(_f2mc.*|mb\d+.*|mcu)\.h$/i;

interface CppToolsApi {
	getCustomConfigurationProvider(): void;
	registerCustomConfigurationProvider(provider: CustomConfigurationProvider): void;
}

interface SourceFileConfiguration {
	includePath: string[];
	defines: string[];
	forcedInclude?: string[];
	intelliSenseMode?: string;
	standard?: string;
	compilerPath?: string;
}

interface SourceFileConfigurationItem {
	uri: vscode.Uri;
	configuration: SourceFileConfiguration;
}

interface WorkspaceBrowseConfiguration {
	browsePath: string[];
	compilerPath?: string;
	standard?: string;
}

interface CustomConfigurationProvider {
	name: string;
	canProvideConfiguration(uri: vscode.Uri, token?: vscode.CancellationToken): Thenable<boolean>;
	provideConfigurations(uris: vscode.Uri[], token?: vscode.CancellationToken): Thenable<SourceFileConfigurationItem[]>;
	canProvideBrowseConfiguration?(token?: vscode.CancellationToken): Thenable<boolean>;
	provideBrowseConfiguration?(token?: vscode.CancellationToken): Thenable<WorkspaceBrowseConfiguration>;
	canProvideBrowseConfigurationsPerFolder?(token?: vscode.CancellationToken): Thenable<boolean>;
	provideFolderBrowseConfiguration?(uri: vscode.Uri, token?: vscode.CancellationToken): Thenable<WorkspaceBrowseConfiguration>;
}

export async function registerCppConfigurationProvider(context: vscode.ExtensionContext, getConfig: () => F2mcProjectConfig | undefined): Promise<void> {
	const cpptools = vscode.extensions.getExtension<CppToolsApi>('ms-vscode.cpptools');
	if (!cpptools) {
		return;
	}

	const api = await cpptools.activate();
	if (!api || typeof api.registerCustomConfigurationProvider !== 'function') {
		return;
	}

	const provider = new F2mcCppConfigurationProvider(context, getConfig);
	context.subscriptions.push(provider);
	api.registerCustomConfigurationProvider(provider);
	
	context.subscriptions.push(
		vscode.window.onDidEndTerminalShellExecution(async e => {
			const text = e.execution.commandLine.value;
			if (text.includes('fcc896s') || text.includes('fasm896s') || text.includes('flnk896s')) {
				provider.clearCaches();
				await rescanCppIntelliSense();
			}
		})
	);
}

class F2mcCppConfigurationProvider implements CustomConfigurationProvider {
	public readonly name = 'F2MC-8FX Workbench';
	private readonly disposable: vscode.Disposable;
	private ioHeaderCache?: { project: F2mcProjectInfo; result: { directories: string[]; familyHeader?: string } };
	private tpiCache?: { project: F2mcProjectInfo; result: string[] };

	constructor(
		private readonly context: vscode.ExtensionContext,
		private readonly getConfig: () => F2mcProjectConfig | undefined
	) {
		this.disposable = vscode.workspace.onDidChangeConfiguration(e => {
			if (e.affectsConfiguration('C_Cpp.default')) {
				this.refresh();
			}
			if (e.affectsConfiguration('f2mc-8fx-workbench.compilerPath')) {
				void rescanCppIntelliSense();
			}
		});
	}

	public dispose(): void {
		this.disposable.dispose();
	}

	public clearCaches(): void {
		this.ioHeaderCache = undefined;
		this.tpiCache = undefined;
	}

	public async canProvideConfiguration(uri: vscode.Uri): Promise<boolean> {
		const config = this.getConfig();
		if (!config) {
			return false;
		}

		if (!CPP_FILE_EXTENSIONS.has(path.extname(uri.fsPath).toLowerCase())) {
			return false;
		}

		const filePath = path.normalize(uri.fsPath).toLowerCase();
		const project = this.getActiveProject(config);
		if (project) {
			const projectFiles = new Set([...project.sourceFiles, ...project.assemblerFiles, ...project.files].map(f => path.normalize(f).toLowerCase()));
			if (projectFiles.has(filePath)) {
				return true;
			}
		}

		const rootPath = path.normalize(config.rootPath).toLowerCase();
		return filePath.startsWith(rootPath + path.sep) && !this.isHelperPath(rootPath, filePath);
	}

	private isHelperPath(rootPathLower: string, filePathLower: string): boolean {
		const helperDirs = [HELPER_DIR_NAME, LEGACY_HELPER_DIR_NAME];
		return helperDirs.some(dir => filePathLower.includes(`${path.sep}${dir.toLowerCase()}${path.sep}`));
	}

	public async provideConfigurations(uris: vscode.Uri[]): Promise<SourceFileConfigurationItem[]> {
		const result: SourceFileConfigurationItem[] = [];
		const config = this.getConfig();
		if (!config) {
			return result;
		}

		const project = this.getActiveProject(config);
		if (!project) {
			return result;
		}

		const tpiPaths = await this.readTpiIncludePaths(project);
		const standardLibPaths = this.getStandardLibPaths();
		const projectIncludePaths = this.getProjectIncludeDirectories(project);
		const ioRegisterHeaders = await this.findIoRegisterHeaders(project);
		const cpuDefine = this.getCpuDefine(project);
		const parentByDep = this.buildParentByDepMap(project);

		const baseConfiguration: SourceFileConfiguration = {
			includePath: [...projectIncludePaths, ...ioRegisterHeaders.directories, ...tpiPaths, ...standardLibPaths],
			defines: [...(cpuDefine ? [cpuDefine] : []), ...BUILTIN_DEFINES],
			standard: 'c99',
			intelliSenseMode: 'gcc-x86',
			compilerPath: ''
		};

		for (const uri of uris) {
			const configuration: SourceFileConfiguration = { ...baseConfiguration };
			// The vendor I/O headers have no include guards, so force-include a guarded
			// shim instead of the headers directly. Files that are textually included by
			// another source file (e.g. main.c includes RF.c) additionally need the
			// including file's include context. cpptools may re-query URIs cached from
			// earlier sessions without calling canProvideConfiguration first, so the
			// helper-dir exclusion must be enforced here as well to avoid shimming our
			// own generated headers recursively.
			const filePathLower = path.normalize(uri.fsPath).toLowerCase();
			if (this.isHelperPath(path.normalize(config.rootPath).toLowerCase(), filePathLower)) {
				result.push({ uri, configuration });
				continue;
			}
			const shimLines = this.buildShimIncludeLines(project, uri.fsPath, ioRegisterHeaders.familyHeader, parentByDep);
			if (shimLines) {
				const shimHeader = await this.ensureShimHeader(config.rootPath, uri.fsPath, shimLines);
				if (shimHeader) {
					configuration.forcedInclude = [shimHeader];
				}
			}
			result.push({ uri, configuration });
		}

		return result;
	}

	public async canProvideBrowseConfiguration(): Promise<boolean> {
		const config = this.getConfig();
		return !!config;
	}

	public async provideBrowseConfiguration(): Promise<WorkspaceBrowseConfiguration> {
		const config = this.getConfig();
		const project = config ? this.getActiveProject(config) : undefined;
		const includePaths: string[] = [];
		const standardLibPaths = this.getStandardLibPaths();

		if (project) {
			includePaths.push(...(await this.readTpiIncludePaths(project)));
			includePaths.push(...this.getProjectIncludeDirectories(project));
			const ioRegisterHeaders = await this.findIoRegisterHeaders(project);
			includePaths.push(...ioRegisterHeaders.directories);
		}

		return {
			browsePath: [...includePaths, ...standardLibPaths],
			standard: 'c99',
			compilerPath: ''
		};
	}

	public async canProvideBrowseConfigurationsPerFolder(): Promise<boolean> {
		return true;
	}

	public async provideFolderBrowseConfiguration(uri: vscode.Uri): Promise<WorkspaceBrowseConfiguration> {
		return this.provideBrowseConfiguration();
	}

	private getActiveProject(config: F2mcProjectConfig): F2mcProjectInfo | undefined {
		return config.projects.find(project => project.isActive) ?? config.projects[0];
	}

	private getStandardLibPaths(): string[] {
		const includeDirectory = resolveCompilerIncludeDirectory(this.context.extensionPath);
		return includeDirectory ? [includeDirectory] : [];
	}

	private getCpuDefine(project: F2mcProjectInfo): string | undefined {
		if (!project.cpuName) {
			return undefined;
		}
		return `__CPU_${project.cpuName}__`;
	}

	private getProjectIncludeDirectories(project: F2mcProjectInfo): string[] {
		const dirSet = new Set<string>();
		for (const file of [...project.files, ...project.sourceFiles, ...project.assemblerFiles]) {
			dirSet.add(path.dirname(file));
		}
		if (project.memberDependencies) {
			for (const dependencies of Object.values(project.memberDependencies)) {
				for (const dep of dependencies) {
					dirSet.add(path.dirname(dep));
				}
			}
		}
		return [...dirSet];
	}

	private async findIoRegisterHeaders(project: F2mcProjectInfo): Promise<{ directories: string[]; familyHeader?: string }> {
		if (this.ioHeaderCache?.project === project) {
			return this.ioHeaderCache.result;
		}

		const projectRoot = project.path ? path.dirname(project.path) : undefined;
		if (!projectRoot) {
			return { directories: [] };
		}

		const familyHeaders: string[] = [];
		const chipHeaders: string[] = [];
		await this.collectIoHeaders(projectRoot, familyHeaders, chipHeaders, 0);

		const dirSet = new Set<string>();
		for (const header of [...familyHeaders, ...chipHeaders]) {
			dirSet.add(path.dirname(header));
		}

		const result = {
			directories: [...dirSet],
			familyHeader: familyHeaders[0]
		};
		this.ioHeaderCache = { project, result };
		return result;
	}

	private buildParentByDepMap(project: F2mcProjectInfo): Map<string, string[]> {
		const map = new Map<string, string[]>();
		if (project.memberDependencies) {
			for (const dependencies of Object.values(project.memberDependencies)) {
				for (const dep of dependencies) {
					map.set(path.normalize(dep).toLowerCase(), dependencies);
				}
			}
		}
		return map;
	}

	private buildShimIncludeLines(project: F2mcProjectInfo, filePath: string, familyHeader: string | undefined, parentByDep: Map<string, string[]>): string[] | undefined {
		const key = path.normalize(filePath).toLowerCase();

		// Vendor I/O headers are self-contained (given the CPU define) and have no
		// include guard; force-including anything into them would double-parse their typedefs.
		if (IO_CHAIN_HEADER_PATTERN.test(path.basename(filePath))) {
			return undefined;
		}

		const dependencies = project.memberDependencies;
		const ownDeps = dependencies?.[key];
		if (ownDeps) {
			if (ownDeps.some(dep => IO_CHAIN_HEADER_PATTERN.test(path.basename(dep)))) {
				return undefined;
			}
			return this.familyHeaderFallback(familyHeader, key);
		}

		const parentDeps = parentByDep.get(key);
		if (!parentDeps) {
			return this.familyHeaderFallback(familyHeader, key);
		}

		const prefix: string[] = [];
		for (const dep of parentDeps) {
			if (path.normalize(dep).toLowerCase() === key) {
				break;
			}
			prefix.push(dep);
		}

		const hasMcuHeader = prefix.some(dep => path.basename(dep).toLowerCase() === MCU_HEADER_NAME);
		let familyKept = false;
		const lines: string[] = [];
		for (const dep of prefix) {
			const base = path.basename(dep);
			if (CHIP_HEADER_PATTERN.test(base)) {
				continue;
			}
			if (FAMILY_HEADER_PATTERN.test(base)) {
				if (hasMcuHeader || familyKept) {
					continue;
				}
				familyKept = true;
			}
			lines.push(base);
		}
		if (lines.length === 0) {
			return this.familyHeaderFallback(familyHeader, key);
		}
		return lines;
	}

	private familyHeaderFallback(familyHeader: string | undefined, selfKey: string): string[] | undefined {
		if (!familyHeader || path.normalize(familyHeader).toLowerCase() === selfKey) {
			return undefined;
		}
		return [path.basename(familyHeader)];
	}

	private async ensureShimHeader(rootPath: string, filePath: string, includeLines: string[]): Promise<string | undefined> {
		const normalized = path.normalize(filePath).toLowerCase();
		let hash = 0;
		for (let i = 0; i < normalized.length; i++) {
			hash = (hash * 31 + normalized.charCodeAt(i)) | 0;
		}
		const baseName = path.basename(filePath).replace(/[^A-Za-z0-9_.]/g, '_');
		const shimName = `shim_${baseName}_${(hash >>> 0).toString(36)}.h`;
		const shimPath = path.join(rootPath, HELPER_DIR_NAME, 'intellisense', shimName);
		const guard = `F2MC_WB_${shimName.replace(/[^A-Za-z0-9]/g, '_').toUpperCase()}`;
		const content = [
			'/* Auto-generated by F2MC-8FX Workbench for cpptools IntelliSense. */',
			`#ifndef ${guard}`,
			`#define ${guard}`,
			...includeLines.map(line => `#include "${line}"`),
			'#endif',
			''
		].join('\r\n');

		try {
			let existing: string | undefined;
			try {
				const bytes = await vscode.workspace.fs.readFile(vscode.Uri.file(shimPath));
				existing = Buffer.from(bytes).toString('utf8');
			} catch {
				existing = undefined;
			}
			if (existing === content) {
				return shimPath;
			}
			await vscode.workspace.fs.createDirectory(vscode.Uri.file(path.dirname(shimPath)));
			await vscode.workspace.fs.writeFile(vscode.Uri.file(shimPath), Buffer.from(content, 'utf8'));
			return shimPath;
		} catch {
			return undefined;
		}
	}

	private async collectIoHeaders(directory: string, familyHeaders: string[], chipHeaders: string[], depth: number): Promise<void> {
		if (depth > 6) {
			return;
		}

		let entries: [string, vscode.FileType][];
		try {
			entries = await vscode.workspace.fs.readDirectory(vscode.Uri.file(directory));
		} catch {
			return;
		}

		for (const [name, type] of entries) {
			const fullPath = path.join(directory, name);
			if (type === vscode.FileType.Directory) {
				if (name === '.git' || name.startsWith('.')) {
					continue;
				}
				await this.collectIoHeaders(fullPath, familyHeaders, chipHeaders, depth + 1);
			} else if (type === vscode.FileType.File) {
				if (FAMILY_HEADER_PATTERN.test(name)) {
					familyHeaders.push(fullPath);
				} else if (CHIP_HEADER_PATTERN.test(name)) {
					chipHeaders.push(fullPath);
				}
			}
		}
	}

	private async readTpiIncludePaths(project: F2mcProjectInfo): Promise<string[]> {
		if (this.tpiCache?.project === project) {
			return this.tpiCache.result;
		}

		let result: string[] = [];
		if (project.directories?.obj) {
			const objDir = project.directories.obj;
			const sourceBases = [...project.sourceFiles, ...project.assemblerFiles].map(f => path.basename(f, path.extname(f)));
			const dirSet = new Set<string>();
			for (let i = 0; i < Math.min(sourceBases.length, 3); i++) {
				const tpiPath = path.join(objDir, `${sourceBases[i]}.tpi`);
				try {
					const stat = await vscode.workspace.fs.stat(vscode.Uri.file(tpiPath));
					if (!stat) continue;
					const content = await this.readTextFile(tpiPath);
					const lines = content.split(/\r?\n/).map(line => line.trim()).filter(Boolean);
					for (const line of lines) {
						dirSet.add(path.dirname(line));
					}
					if (dirSet.size > 0) break;
				} catch {
					// TPI file may not exist — skip
				}
			}
			result = [...dirSet];
		}

		this.tpiCache = { project, result };
		return result;
	}

	private async readTextFile(filePath: string): Promise<string> {
		const bytes = await vscode.workspace.fs.readFile(vscode.Uri.file(filePath));
		return Buffer.from(bytes).toString('utf8');
	}

	private async readAnsiTextFile(filePath: string): Promise<string> {
		const bytes = await vscode.workspace.fs.readFile(vscode.Uri.file(filePath));
		const buffer = Buffer.from(bytes);
		if (buffer.length >= 3 && buffer[0] === 0xEF && buffer[1] === 0xBB && buffer[2] === 0xBF) {
			return buffer.toString('utf8', 3);
		}
		const utf8Result = buffer.toString('utf8');
		if (!utf8Result.includes('\ufffd')) {
			return utf8Result;
		}
		const psPath = filePath.replace(/'/g, "''");
		const cmd = `powershell -NoProfile -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; $bytes = [System.IO.File]::ReadAllBytes('${psPath}'); $enc = [System.Text.Encoding]::Default; [Console]::Write($enc.GetString($bytes))"`;
		return new Promise<string>((resolve, reject) => {
			childProcess.exec(cmd, { encoding: 'utf8', maxBuffer: 1024 * 1024 }, (error, stdout) => {
				if (error) {
					reject(error);
				} else {
					resolve(stdout);
				}
			});
		});
	}

	private refresh(): void {
		// Notify cpptools to re-query configurations
	}
}

export async function rescanCppIntelliSense(): Promise<void> {
	try {
		await vscode.commands.executeCommand('C_Cpp.RescanWorkspace');
	} catch {
		// cpptools may not be installed
	}
}
