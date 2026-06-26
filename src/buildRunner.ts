import * as fs from 'node:fs';
import * as path from 'node:path';

import * as vscode from 'vscode';

import { convertFileToAnsiEncoding, readTextFile, writeTextFile } from './fileSystem';
import { quoteShell, resolvePath } from './pathUtils';
import type { BuildKind, F2mcProjectConfig, F2mcProjectInfo } from './types';

interface CommandSpec {
	commandLine: string;
	cwd: string;
}

interface BuildLayout {
	project: F2mcProjectInfo;
	projectRootPath: string;
	compilerDirectory: string;
	configDirectory: string;
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

const TASK_TITLES: Record<BuildKind, string> = {
	build: 'F2MC-8FX Build',
	clean: 'F2MC-8FX Clean',
	download: 'F2MC-8FX Download'
};

const COMPILER_TOOLS = [
	{ file: 'fcc896s.exe' },
	{ file: 'FASM896S.EXE' },
	{ file: 'FLNK896S.EXE' },
	{ file: 'F2MS.EXE' },
	{ file: 'F2IS.EXE' },
	{ file: 'F2ES.EXE' },
	{ file: 'F2HS.EXE' }
] as const;

let sharedTerminal: vscode.Terminal | undefined;

export async function runProjectTask(
	config: F2mcProjectConfig,
	kind: BuildKind,
	outputChannel: vscode.OutputChannel,
	extensionPath: string
): Promise<void> {
	const command = await resolveBuildCommand(config, kind, extensionPath);
	if (!command) {
		void vscode.window.showWarningMessage('未找到可执行的编译命令，请检查工程配置和 res/compiler。');
		return;
	}

	const terminal = getSharedTerminal(command.cwd);

	outputChannel.appendLine(`[${kind}] cwd: ${command.cwd}`);
	outputChannel.appendLine(`[${kind}] command: ${command.commandLine}`);
	terminal.show(true);
	terminal.sendText(`Set-Location -LiteralPath ${quotePowerShellLiteral(command.cwd)}`, true);
	terminal.sendText(`Clear-Host; ${command.commandLine}`, true);
}

async function resolveBuildCommand(config: F2mcProjectConfig, kind: BuildKind, extensionPath: string): Promise<CommandSpec | undefined> {
	const settings = vscode.workspace.getConfiguration('f2mc-8fx-workbench');
	const workingDirectory = settings.get<string>('buildWorkingDirectory') || '.';
	const cwd = resolvePath(replaceVariables(workingDirectory, config, kind), config.rootPath);
	const template = settings.get<string>('buildCommandTemplate') || '';

	if (template.trim()) {
		return {
			cwd,
			commandLine: replaceVariables(template, config, kind)
		};
	}

	return createBuiltInCommand(config, kind, extensionPath);
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

	const layout = createBuildLayout(project, extensionPath);
	if (!layout) {
		return undefined;
	}

	if (kind === 'build') {
		await writeOptionFiles(layout);
	}

	const scriptPath = path.join(layout.projectRootPath, '.f2mc-helper', kind === 'clean' ? 'clean.bat' : 'build.bat');
	const scriptContent = kind === 'clean'
		? createCleanScript(layout)
		: createBuildScript(layout);
	await writeTextFile(scriptPath, scriptContent);

	return {
		cwd: layout.projectRootPath,
		commandLine: createScriptExecutionCommand(scriptPath)
	};
}

function createBuildLayout(project: F2mcProjectInfo, extensionPath: string): BuildLayout | undefined {
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
		compilerDirectory: path.join(extensionPath, 'res', 'compiler', 'Bin'),
		configDirectory: project.directories.config,
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
	const optDirectory = layout.optDirectory;
	const optionBaseName = layout.optionBaseName;
	const outputExt = resolveOutputExtensionFromOpt(layout);
	await Promise.all([
		writeTextFile(path.join(optDirectory, `${optionBaseName}.opc`), createCompileOptions(layout, options)),
		writeTextFile(path.join(optDirectory, `${optionBaseName}.opa`), createAssemblerOptions(layout, options)),
		writeAnsiTextFile(path.join(optDirectory, `${optionBaseName}.opl`), createLinkerOptions(layout, options)),
		writeAnsiTextFile(path.join(optDirectory, `${optionBaseName}.opb`), createLibrarianOptions(layout, options)),
		writeAnsiTextFile(path.join(optDirectory, `${optionBaseName}.opv`), createConverterOptions(layout, options, outputExt))
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

function createScriptExecutionCommand(scriptPath: string): string {
	const quotedPath = quoteShell(scriptPath);
	const psPath = scriptPath.replace(/'/g, "''");
	return `& ${quotedPath}; Remove-Item -LiteralPath '${psPath}' -Force`;
}

function getSharedTerminal(cwd: string): vscode.Terminal {
	if (!sharedTerminal || sharedTerminal.exitStatus) {
		sharedTerminal = vscode.window.createTerminal({
			name: 'F2MC-8FX',
			cwd
		});
	}

	return sharedTerminal;
}

function quotePowerShellLiteral(value: string): string {
	return `'${value.replace(/'/g, "''")}'`;
}

function createBuildScript(layout: BuildLayout): string {
	const converterExe = resolveConverterExe(layout);
	const lines = [
		'@echo off',
		'setlocal enabledelayedexpansion',
		'chcp 65001 >nul',
		'',
		`set "COMPILER_DIR=${layout.compilerDirectory}"`,
		'set "PATH=%COMPILER_DIR%;%PATH%"',
		`set "CONFIG_DIR=${layout.configDirectory}"`,
		`set "OBJ_DIR=${layout.objDirectory}"`,
		`set "LST_DIR=${layout.lstDirectory}"`,
		`set "OPT_DIR=${layout.optDirectory}"`,
		'',
		...COMPILER_TOOLS.flatMap(tool => [
			`if not exist "%COMPILER_DIR%\\${tool.file}" (`,
			`    echo Error: ${tool.file} not found in %COMPILER_DIR%`,
			'    exit /b 1',
			')'
		]),
		'',
		'if not exist "%OBJ_DIR%" mkdir "%OBJ_DIR%"',
		'if not exist "%LST_DIR%" mkdir "%LST_DIR%"',
		'if not exist "%OPT_DIR%" mkdir "%OPT_DIR%"',
		'',
		'echo Now building...',
		`echo --------------------Configuration: ${layout.projectName} - ${layout.activeCfgBaseName}--------------------`,
		...layout.project.sourceFiles.flatMap(sourceFile => createCompileCommand(layout, sourceFile)),
		...layout.project.assemblerFiles.flatMap(assemblerFile => createAssemblerCommand(layout, assemblerFile)),
		'',
		'echo Now linking...',
		`flnk896s.exe -f "%OPT_DIR%\\${layout.optionBaseName}.opl" -Xdof`,
		'if errorlevel 1 exit /b 1',
		`echo ${layout.loadModulePath}`,
		'',
		'echo Now starting load module converter...',
		`${converterExe} -f "%OPT_DIR%\\${layout.optionBaseName}.opv" -Xdof`,
		'if errorlevel 1 exit /b 1',
		`echo ${layout.convertedModulePath}`,
		'',
		'echo.',
		'echo ------------------------------',
		'echo No Error.',
		'echo ------------------------------',
		'endlocal'
	];
	return joinScriptLines(lines);
}

function resolveConverterExe(layout: BuildLayout): string {
	const outputExt = resolveOutputExtensionFromOpt(layout);
	if (outputExt === '.ihx') return 'f2is.exe';
	if (outputExt === '.ehx') return 'f2es.exe';
	if (outputExt === '.hex') return 'f2hs.exe';
	return 'f2ms.exe';
}

function resolveOutputExtensionFromOpt(layout: BuildLayout): string {
	const opvPath = path.join(layout.optDirectory, `${layout.optionBaseName}.opv`);
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
		`echo ${path.basename(sourceFile)}`,
		`fcc896s.exe -f "%OPT_DIR%\\${layout.optionBaseName}.opc" -Xdof -o "%OBJ_DIR%\\${baseName}.obj" "${sourceFile}" -INF STACK="%OBJ_DIR%\\${baseName}.stk" -@Hf "%OBJ_DIR%\\${baseName}.tpi"`,
		'if errorlevel 1 exit /b 1'
	];
}

function createAssemblerCommand(layout: BuildLayout, assemblerFile: string): string[] {
	const baseName = path.basename(assemblerFile, path.extname(assemblerFile));
	return [
		`echo ${path.basename(assemblerFile)}`,
		`fasm896s.exe -f "%OPT_DIR%\\${layout.optionBaseName}.opa" -Xdof -o "%OBJ_DIR%\\${baseName}.obj" "${assemblerFile}"`,
		'if errorlevel 1 exit /b 1',
	];
}

function createCleanScript(layout: BuildLayout): string {
	const lines = [
		'@echo off',
		'setlocal',
		'chcp 65001 >nul',
		'',
		'echo Now cleaning...',
		...createCleanDirectoryCommands(layout.objDirectory, ['*.obj', '*.stk', '*.tpi']),
		...createCleanDirectoryCommands(layout.lstDirectory, ['*.lst', '*.map']),
		...createCleanDirectoryCommands(path.dirname(layout.loadModulePath), ['*.abs', '*.mhx', '*.ihx', '*.ehx', '*.hex', '*.s19']),
		'echo Clean complete.',
		'endlocal'
	];
	return joinScriptLines(lines);
}

function createCleanDirectoryCommands(directoryPath: string, patterns: string[]): string[] {
	return patterns.map(pattern => `if exist "${path.join(directoryPath, pattern)}" del /q "${path.join(directoryPath, pattern)}"`);
}

function joinScriptLines(lines: string[]): string {
	return lines.length > 0 ? `${lines.join('\r\n')}\r\n` : '\r\n';
}

function replaceVariables(template: string, config: F2mcProjectConfig, kind: BuildKind): string {
	const activeProject = getActiveProject(config);
	const projectPath = activeProject?.path ?? '';
	return template
		.replace(/\$\{kind\}/g, kind)
		.replace(/\$\{workspaceFolder\}/g, config.rootPath)
		.replace(/\$\{wspPath\}/g, config.wspPath)
		.replace(/\$\{projectPath\}/g, projectPath)
		.replace(/\$\{projectName\}/g, activeProject?.name ?? '')
		.replace(/\$\{projectDir\}/g, projectPath ? path.dirname(projectPath) : config.rootPath);
}

function getActiveProject(config: F2mcProjectConfig): F2mcProjectInfo | undefined {
	return config.projects.find(project => project.isActive) ?? config.projects[0];
}
