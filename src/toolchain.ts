import * as fs from 'node:fs';
import * as path from 'node:path';

import * as vscode from 'vscode';

import { resolvePath } from './pathUtils';

export const COMPILER_TOOLS = [
	'fcc896s.exe',
	'FASM896S.EXE',
	'FLNK896S.EXE',
	'FLIB896S.EXE',
	'F2MS.EXE',
	'F2IS.EXE',
	'F2ES.EXE',
	'F2HS.EXE'
] as const;

export function resolveCompilerDirectory(extensionPath: string): string | undefined {
	const configured = vscode.workspace.getConfiguration('f2mc-8fx-workbench').get<string>('compilerPath')?.trim();
	if (configured) {
		const basePath = vscode.workspace.workspaceFolders?.[0]?.uri.fsPath ?? extensionPath;
		const configuredPath = resolvePath(configured.replace(/\$\{workspaceFolder\}/g, basePath), basePath);
		return [configuredPath, path.join(configuredPath, 'Bin')]
			.find(candidate => COMPILER_TOOLS.some(tool => fs.existsSync(path.join(candidate, tool))));
	}

	const bundledDirectory = path.join(extensionPath, 'res', 'compiler', 'Bin');
	return fs.existsSync(bundledDirectory) ? bundledDirectory : undefined;
}

export function findMissingCompilerTools(compilerDirectory: string): string[] {
	return COMPILER_TOOLS.filter(tool => !fs.existsSync(path.join(compilerDirectory, tool)));
}

export function resolveCompilerIncludeDirectory(extensionPath: string): string | undefined {
	const compilerDirectory = resolveCompilerDirectory(extensionPath);
	if (!compilerDirectory) {
		return undefined;
	}

	const includeDirectory = path.join(path.dirname(compilerDirectory), 'Lib', '896', 'include');
	return fs.existsSync(includeDirectory) ? includeDirectory : undefined;
}
