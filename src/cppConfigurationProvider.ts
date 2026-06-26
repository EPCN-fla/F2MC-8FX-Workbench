import * as childProcess from 'node:child_process';
import * as path from 'node:path';

import * as vscode from 'vscode';

import type { F2mcProjectConfig, F2mcProjectInfo } from './types';

const BUILTIN_DEFINES: string[] = [
];

interface CppToolsApi {
	getCustomConfigurationProvider(): void;
	registerCustomConfigurationProvider(provider: CustomConfigurationProvider): void;
}

interface SourceFileConfiguration {
	includePath: string[];
	defines: string[];
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
				await rescanCppIntelliSense();
			}
		})
	);
}

class F2mcCppConfigurationProvider implements CustomConfigurationProvider {
	public readonly name = 'F2MC-8FX Workbench';
	private readonly disposable: vscode.Disposable;

	constructor(
		private readonly context: vscode.ExtensionContext,
		private readonly getConfig: () => F2mcProjectConfig | undefined
	) {
		this.disposable = vscode.workspace.onDidChangeConfiguration(e => {
			if (e.affectsConfiguration('C_Cpp.default')) {
				this.refresh();
			}
		});
	}

	public dispose(): void {
		this.disposable.dispose();
	}

	public async canProvideConfiguration(uri: vscode.Uri): Promise<boolean> {
		const config = this.getConfig();
		if (!config) {
			return false;
		}

		const project = this.getActiveProject(config);
		if (!project) {
			return false;
		}

		const filePath = uri.fsPath;
		const projectFiles = new Set([...project.sourceFiles, ...project.assemblerFiles].map(f => path.normalize(f)));
		return projectFiles.has(path.normalize(filePath));
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
		const standardLibPath = this.getStandardLibPath();
		const cpuDefine = this.getCpuDefine(project);

		const configuration: SourceFileConfiguration = {
			includePath: [...tpiPaths, standardLibPath],
			defines: [...(cpuDefine ? [cpuDefine] : []), ...BUILTIN_DEFINES],
			standard: 'c99',
			intelliSenseMode: 'gcc-x86',
			compilerPath: ''
		};

		for (const uri of uris) {
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
		const standardLibPath = this.getStandardLibPath();

		if (project) {
			includePaths.push(...(await this.readTpiIncludePaths(project)));
		}

		return {
			browsePath: [...includePaths, standardLibPath],
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

	private getStandardLibPath(): string {
		return path.join(this.context.extensionPath, 'res', 'compiler', 'Lib', '896', 'INCLUDE');
	}

	private getCpuDefine(project: F2mcProjectInfo): string | undefined {
		if (!project.cpuName) {
			return undefined;
		}
		return `__CPU_${project.cpuName}__`;
	}

	private async readTpiIncludePaths(project: F2mcProjectInfo): Promise<string[]> {
		if (!project.directories?.obj) {
			return [];
		}

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
		return [...dirSet];
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
