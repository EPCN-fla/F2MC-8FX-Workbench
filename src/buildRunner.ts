import * as childProcess from 'node:child_process';
import * as fs from 'node:fs';
import * as path from 'node:path';

import * as vscode from 'vscode';

import { convertFileToAnsiEncoding, readTextFile, writeTextFile } from './fileSystem';
import { findMissingCompilerTools, resolveCompilerDirectory } from './toolchain';
import type { BuildKind, F2mcProjectConfig, F2mcProjectInfo } from './types';

interface CommandSpec {
	commandLines: string[];
	cwd: string;
	compilerDirectory?: string;
}

interface BuildLayout {
	project: F2mcProjectInfo;
	projectRootPath: string;
	objDirectory: string;
	lstDirectory: string;
	optDirectory: string;
	projectName: string;
	optionBaseName: string;
	activeCfgBaseName?: string;
	loadModulePath: string;
	convertedModulePath: string;
	mapFilePath: string;
	objectFiles: string[];
}

interface DatOptions {
	compiler: string[];
	assembler: string[];
	linker: string[];
	librarian: string[];
	converter: string[];
}

const CMD_LINE_LENGTH_LIMIT = 6000;

const UNSAFE_CMD_VALUE_PATTERN = /["\r\n]/;

const UNSAFE_CMD_DISPLAY_PATTERN = /["\r\n&|%()^<>]/;

function isCmdSafeValue(value: string): boolean {
	return !UNSAFE_CMD_VALUE_PATTERN.test(value);
}

let sharedTerminal: vscode.Terminal | undefined;

export async function runProjectTask(
	config: F2mcProjectConfig,
	kind: BuildKind,
	outputChannel: vscode.OutputChannel,
	extensionPath: string
): Promise<void> {
	const command = await createBuiltInCommand(config, kind, extensionPath);
	if (!command) {
		void vscode.window.showWarningMessage('未找到可执行的编译命令，请检查工程配置和编译器路径（f2mc-8fx-workbench.compilerPath）。');
		return;
	}

	if (!isCmdSafeValue(command.cwd)) {
		void vscode.window.showWarningMessage('工作目录包含非法字符（"），无法执行构建。');
		return;
	}

	outputChannel.appendLine(`[${kind}] cwd: ${command.cwd}`);
	for (const commandLine of command.commandLines) {
		outputChannel.appendLine(`[${kind}] command: ${commandLine}`);
	}

	sharedTerminal?.dispose();
	const pty = new F2mcBuildPseudoterminal(command.commandLines.join(' & '), command.cwd, command.compilerDirectory);
	sharedTerminal = vscode.window.createTerminal({ name: 'F2MC-8FX', pty, isTransient: true });
	sharedTerminal.show(true);
}

class F2mcBuildPseudoterminal implements vscode.Pseudoterminal {
	private readonly writeEmitter = new vscode.EventEmitter<string>();
	private readonly closeEmitter = new vscode.EventEmitter<void | number>();
	public readonly onDidWrite = this.writeEmitter.event;
	public readonly onDidClose = this.closeEmitter.event;
	private child: childProcess.ChildProcess | undefined;
	private finished = false;

	public constructor(
		private readonly commandLine: string,
		private readonly cwd: string,
		private readonly compilerDirectory: string | undefined
	) {
	}

	public open(): void {
		const env = this.compilerDirectory
			? { ...process.env, PATH: `${this.compilerDirectory}${path.delimiter}${process.env.PATH ?? ''}` }
			: { ...process.env };
		const writeOutput = (data: Buffer): void => {
			this.writeEmitter.fire(decodeToolOutput(data));
		};

		this.child = childProcess.spawn('cmd.exe', ['/d', '/c', this.commandLine], { cwd: this.cwd, env, windowsVerbatimArguments: true });
		this.child.stdout?.on('data', writeOutput);
		this.child.stderr?.on('data', writeOutput);
		this.child.on('error', error => {
			this.finished = true;
			this.writeEmitter.fire(`\r\nFailed to start build: ${error.message}\r\nPress any key to close...\r\n`);
		});
		this.child.on('close', () => {
			this.finished = true;
			this.writeEmitter.fire('\r\nPress any key to close...\r\n');
		});
	}

	public close(): void {
		this.child?.kill();
	}

	public handleInput(): void {
		if (this.finished) {
			this.closeEmitter.fire(0);
		}
	}
}

const CODEPAGE_ENCODINGS: Record<string, string> = {
	'936': 'gbk',
	'950': 'big5',
	'932': 'shift-jis',
	'949': 'euc-kr',
	'65001': 'utf-8'
};

let cachedToolEncoding: string | undefined;

function getToolOutputEncoding(): string {
	if (!cachedToolEncoding) {
		try {
			const output = childProcess.execFileSync('cmd.exe', ['/d', '/c', 'chcp'], { encoding: 'utf8' });
			const match = /(\d+)/.exec(output);
			cachedToolEncoding = (match && CODEPAGE_ENCODINGS[match[1]]) || 'utf-8';
		} catch {
			cachedToolEncoding = 'utf-8';
		}
	}
	return cachedToolEncoding;
}

let cachedDecoder: TextDecoder | undefined;

function decodeToolOutput(data: Buffer): string {
	if (!cachedDecoder) {
		cachedDecoder = new TextDecoder(getToolOutputEncoding());
	}
	return cachedDecoder.decode(data, { stream: true });
}

async function createBuiltInCommand(config: F2mcProjectConfig, kind: BuildKind, extensionPath: string): Promise<CommandSpec | undefined> {
	const project = getActiveProject(config);
	if (!project?.path) {
		return undefined;
	}

	if (kind === 'download') {
		void vscode.window.showWarningMessage('下载功能暂不支持');
		return undefined;
	}

	const compilerDirectory = resolveCompilerDirectory(extensionPath);
	if (!compilerDirectory) {
		void vscode.window.showWarningMessage('未找到编译器。请在设置中配置 f2mc-8fx-workbench.compilerPath 指向 SOFTUNE 编译器目录（Bin 目录或其上一级）。');
		return undefined;
	}

	const missingTools = findMissingCompilerTools(compilerDirectory);
	if (missingTools.length > 0) {
		void vscode.window.showWarningMessage(`编译器目录缺少工具: ${missingTools.join(', ')}（${compilerDirectory}）`);
		return undefined;
	}

	const layout = createBuildLayout(project);
	if (!layout) {
		return undefined;
	}

	const unsafeValue = findUnsafeCmdValue(layout);
	if (unsafeValue) {
		void vscode.window.showWarningMessage(`工程配置包含非法字符（"），无法构建：${unsafeValue}`);
		return undefined;
	}

	if (kind === 'build') {
		await writeOptionFiles(layout);
		await ensureBuildDirectories(layout);
	}

	return {
		cwd: layout.projectRootPath,
		compilerDirectory,
		commandLines: kind === 'clean' ? [createCleanCommand(layout)] : createBuildCommandLines(layout)
	};
}

function findUnsafeCmdValue(layout: BuildLayout): string | undefined {
	const unsafeDisplayValue = [layout.projectName, layout.activeCfgBaseName ?? '']
		.find(value => UNSAFE_CMD_DISPLAY_PATTERN.test(value));
	if (unsafeDisplayValue) {
		return unsafeDisplayValue;
	}

	const values = [
		layout.projectRootPath,
		layout.objDirectory,
		layout.lstDirectory,
		layout.optDirectory,
		layout.projectName,
		layout.activeCfgBaseName ?? '',
		layout.loadModulePath,
		layout.convertedModulePath,
		layout.mapFilePath,
		...layout.project.sourceFiles,
		...layout.project.assemblerFiles,
		...layout.project.libraryFiles
	];
	return values.find(value => !isCmdSafeValue(value));
}

async function ensureBuildDirectories(layout: BuildLayout): Promise<void> {
	await Promise.all([
		fs.promises.mkdir(layout.objDirectory, { recursive: true }),
		fs.promises.mkdir(layout.lstDirectory, { recursive: true }),
		fs.promises.mkdir(layout.optDirectory, { recursive: true })
	]);
}

function createBuildLayout(project: F2mcProjectInfo): BuildLayout | undefined {
	if (!project.path || !project.optionFile || !project.activeConfiguration || !project.directories?.config || !project.directories.obj || !project.directories.lst || !project.directories.opt) {
		return undefined;
	}

	const projectRootPath = path.dirname(project.path);
	const projectName = path.basename(project.path);
	const optionBaseName = path.basename(project.optionFile, path.extname(project.optionFile));
	const activeCfgBaseName = project.activeConfiguration;
	const loadModulePath = project.loadModule ?? path.join(project.directories.config, 'ABS', `${project.name}.abs`);
	const loadModuleBaseName = path.basename(loadModulePath, path.extname(loadModulePath));
	const outputExt = resolveOutputExtensionFromOptPath(
		path.join(project.directories.opt, `${optionBaseName}.opv`)
	);
	const convertedModulePath = path.join(path.dirname(loadModulePath), `${loadModuleBaseName}${outputExt}`);
	const mapFilePath = path.join(project.directories.lst, `${loadModuleBaseName}.mp1`);
	const objectFiles = [...project.sourceFiles, ...project.assemblerFiles]
		.map(file => path.join(project.directories?.obj ?? projectRootPath, `${path.basename(file, path.extname(file))}.obj`));

	return {
		project,
		projectRootPath,
		objDirectory: project.directories.obj,
		lstDirectory: project.directories.lst,
		optDirectory: project.directories.opt,
		projectName,
		optionBaseName,
		activeCfgBaseName,
		loadModulePath,
		convertedModulePath,
		mapFilePath,
		objectFiles
	};
}

async function writeOptionFiles(layout: BuildLayout): Promise<void> {
	const options = await readDatOptions(layout.project.optionFile);
	const outputExt = resolveOutputExtensionFromOpt(layout);
	await Promise.all([
		writeTextFile(createOptionFilePath(layout, 'opc'), createCompileOptions(layout, options)),
		writeTextFile(createOptionFilePath(layout, 'opa'), createAssemblerOptions(layout, options)),
		writeAnsiTextFile(createOptionFilePath(layout, 'opl'), createLinkerOptions(layout, options)),
		writeAnsiTextFile(createOptionFilePath(layout, 'opb'), createLibrarianOptions(layout, options)),
		writeAnsiTextFile(createOptionFilePath(layout, 'opv'), createConverterOptions(layout, options, outputExt))
	]);
}

async function writeAnsiTextFile(filePath: string, content: string): Promise<void> {
	await writeTextFile(filePath, content);
	convertFileToAnsiEncoding(filePath);
}

async function readDatOptions(optionFile: string | undefined): Promise<DatOptions> {
	if (!optionFile) {
		return { compiler: [], assembler: [], linker: [], librarian: [], converter: [] };
	}

	const content = await readTextFile(optionFile);
	return {
		compiler: readDatSection(content, '0'),
		assembler: readDatSection(content, '1'),
		linker: readDatSection(content, '2'),
		librarian: readDatSection(content, '3'),
		converter: readDatSection(content, '4')
	};
}

function readDatSection(content: string, section: string): string[] {
	const lines = content.split(/\r?\n/).map(line => line.trim()).filter(Boolean);
	const result: string[] = [];
	let inSection = false;
	let skipMetadataValue = false;

	for (const line of lines) {
		if (line === `$${section}`) {
			inSection = true;
			continue;
		}

		if (!inSection) {
			continue;
		}

		if (line === '$end' || (line.startsWith('$') && line !== '$other' && line !== '$time')) {
			break;
		}

		if (line === '$other') {
			skipMetadataValue = false;
			continue;
		}

		if (line === '$time') {
			skipMetadataValue = true;
			continue;
		}

		if (skipMetadataValue) {
			skipMetadataValue = false;
			continue;
		}

		result.push(line);
	}

	return result;
}

function createCompileOptions(layout: BuildLayout, options: DatOptions): string {
	return normalizeOptionLines([
		...removeDuplicateOptions(options.compiler, ['-Xdof', '-INF STACK']),
		'-c',
		'-cwno',
		...(layout.project.cpuName ? [`-cpu ${layout.project.cpuName}`] : [])
	]);
}

function createAssemblerOptions(layout: BuildLayout, options: DatOptions): string {
	return normalizeOptionLines([
		...removeDuplicateOptions(options.assembler, ['-Xdof']),
		'-cwno',
		...(layout.project.cpuName ? [`-cpu ${layout.project.cpuName}`] : [])
	]);
}

function createLinkerOptions(layout: BuildLayout, options: DatOptions): string {
	return normalizeOptionLines([
		...removeDuplicateOptions(options.linker, ['-Xdof', '-m']),
		`-m ${quoteOptionPath(layout.mapFilePath)}`,
		`-alin ${quoteOptionPath(layout.lstDirectory)}`,
		`-alout ${quoteOptionPath(layout.lstDirectory)}`,
		'-Xset_rora',
		'-cwno',
		'-a',
		...(layout.project.cpuName ? [`-cpu ${layout.project.cpuName}`] : []),
		`-o ${quoteOptionPath(layout.loadModulePath)}`,
		...layout.project.libraryFiles.map(file => `-l ${quoteOptionPath(file)}`),
		'',
		...layout.objectFiles.map(file => quoteOptionPath(file))
	]);
}

function createLibrarianOptions(layout: BuildLayout, options: DatOptions): string {
	return normalizeOptionLines([
		...removeDuplicateOptions(options.librarian, ['-Xdof']),
		'-cwno',
		...(layout.project.cpuName ? [`-cpu ${layout.project.cpuName}`] : [])
	]);
}

function createConverterOptions(layout: BuildLayout, options: DatOptions, outputExt: string): string {
	const modulePath = path.join(path.dirname(layout.convertedModulePath), `${path.basename(layout.convertedModulePath, path.extname(layout.convertedModulePath))}${outputExt}`);
	return normalizeOptionLines([
		...removeDuplicateOptions(options.converter, ['-Xdof']),
		'-cwno',
		`-o ${quoteOptionPath(modulePath)}`,
		quoteOptionPath(layout.loadModulePath)
	]);
}

function normalizeOptionLines(lines: string[]): string {
	const filtered = lines.map(line => line.trim()).filter(line => line.length > 0);
	return filtered.length > 0 ? `${filtered.join('\r\n')}\r\n` : '\r\n';
}

function removeDuplicateOptions(lines: string[], removePrefixes: string[]): string[] {
	return lines.filter(line => !removePrefixes.some(prefix => line.toLowerCase().startsWith(prefix.toLowerCase())));
}

function quoteOptionPath(value: string): string {
	return `"${value.replace(/"/g, '\\"')}"`;
}

function createBuildCommandLines(layout: BuildLayout): string[] {
	const parts = createBuildCommandParts(layout);
	const lines = ['set "__F2MC_ERR="'];
	let current = '';
	for (const part of parts) {
		const candidate = current ? `${current} && ${part}` : part;
		if (current && candidate.length > CMD_LINE_LENGTH_LIMIT) {
			lines.push(createGuardedChunk(current));
			current = part;
		} else {
			current = candidate;
		}
	}
	if (current) {
		lines.push(createGuardedChunk(current));
	}
	return lines;
}

function createGuardedChunk(chain: string): string {
	return `if not defined __F2MC_ERR ( ${chain} || set "__F2MC_ERR=1" )`;
}

function createBuildCommandParts(layout: BuildLayout): string[] {
	const converterExe = resolveConverterExe(layout);
	return [
		'echo Now building...',
		`echo --------------------Configuration: ${layout.projectName} - ${layout.activeCfgBaseName}--------------------`,
		...layout.project.sourceFiles.flatMap(sourceFile => createCompileCommand(layout, sourceFile)),
		...layout.project.assemblerFiles.flatMap(assemblerFile => createAssemblerCommand(layout, assemblerFile)),
		'echo Now linking...',
		`flnk896s.exe -f "${createOptionFilePath(layout, 'opl')}" -Xdof`,
		`echo "${layout.loadModulePath}"`,
		'echo Now starting load module converter...',
		`${converterExe} -f "${createOptionFilePath(layout, 'opv')}" -Xdof`,
		`echo "${layout.convertedModulePath}"`,
		'echo ------------------------------',
		'echo No Error.'
	];
}

function createOptionFilePath(layout: BuildLayout, extension: string): string {
	return path.join(layout.optDirectory, `${layout.optionBaseName}.${extension}`);
}

function resolveConverterExe(layout: BuildLayout): string {
	const outputExt = resolveOutputExtensionFromOpt(layout);
	if (outputExt === '.ihx') return 'f2is.exe';
	if (outputExt === '.ehx') return 'f2es.exe';
	if (outputExt === '.hex') return 'f2hs.exe';
	return 'f2ms.exe';
}

function resolveOutputExtensionFromOpt(layout: BuildLayout): string {
	const opvPath = createOptionFilePath(layout, 'opv');
	return resolveOutputExtensionFromOptPath(opvPath);
}

function resolveOutputExtensionFromOptPath(opvPath: string): string {
	try {
		const content = fs.readFileSync(opvPath, 'utf-8');
		const lines = content.split(/\r?\n/).map(line => line.trim()).filter(Boolean);
		for (const line of lines) {
			const trimmed = line.trim().toLowerCase();
			if (trimmed.startsWith('-o "') && trimmed.endsWith('"')) {
				const value = trimmed.slice(4, -1);
				if (value.endsWith('.ihx')) return '.ihx';
				if (value.endsWith('.ehx')) return '.ehx';
				if (value.endsWith('.hex')) return '.hex';
				return '.mhx';
			}
		}
	} catch {
		// fall through to default
	}
	return '.mhx';
}

function createCompileCommand(layout: BuildLayout, sourceFile: string): string[] {
	const baseName = path.basename(sourceFile, path.extname(sourceFile));
	return [
		`echo "${path.basename(sourceFile)}"`,
		`fcc896s.exe -f "${createOptionFilePath(layout, 'opc')}" -Xdof -o "${path.join(layout.objDirectory, `${baseName}.obj`)}" "${sourceFile}" -INF STACK="${path.join(layout.objDirectory, `${baseName}.stk`)}" -@Hf "${path.join(layout.objDirectory, `${baseName}.tpi`)}"`
	];
}

function createAssemblerCommand(layout: BuildLayout, assemblerFile: string): string[] {
	const baseName = path.basename(assemblerFile, path.extname(assemblerFile));
	return [
		`echo "${path.basename(assemblerFile)}"`,
		`fasm896s.exe -f "${createOptionFilePath(layout, 'opa')}" -Xdof -o "${path.join(layout.objDirectory, `${baseName}.obj`)}" "${assemblerFile}"`
	];
}

function createCleanCommand(layout: BuildLayout): string {
	const parts = [
		'echo Now cleaning...',
		...createCleanDirectoryCommands(layout.objDirectory, ['*.obj', '*.stk', '*.tpi']),
		...createCleanDirectoryCommands(layout.lstDirectory, ['*.lst', '*.map']),
		...createCleanDirectoryCommands(path.dirname(layout.loadModulePath), ['*.abs', '*.mhx', '*.ihx', '*.ehx', '*.hex', '*.s19']),
		'echo Clean complete.'
	];
	return parts.join(' & ');
}

function createCleanDirectoryCommands(directoryPath: string, patterns: string[]): string[] {
	return patterns.map(pattern => `del /q "${path.join(directoryPath, pattern)}" 2>nul`);
}

function getActiveProject(config: F2mcProjectConfig): F2mcProjectInfo | undefined {
	return config.projects.find(project => project.isActive) ?? config.projects[0];
}
