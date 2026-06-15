import * as path from 'node:path';

import * as vscode from 'vscode';

import { CONFIG_FILE_NAME, EXTENSION_ID } from './constants';
import { readTextFile, writeJsonFile } from './fileSystem';
import type { F2mcProjectConfig } from './types';

export async function discoverProjectConfig(): Promise<F2mcProjectConfig | undefined> {
	const folders = vscode.workspace.workspaceFolders ?? [];
	for (const folder of folders) {
		const config = await readProjectConfig(path.join(folder.uri.fsPath, '.f2mc-helper', CONFIG_FILE_NAME));
		if (config) {
			return config;
		}
	}

	return undefined;
}

export async function persistProjectConfig(config: F2mcProjectConfig): Promise<void> {
	await vscode.workspace.fs.createDirectory(vscode.Uri.file(path.join(config.rootPath, '.f2mc-helper')));
	await writeJsonFile(path.join(config.rootPath, '.f2mc-helper', CONFIG_FILE_NAME), config);
}

export async function createVsCodeWorkspace(config: F2mcProjectConfig): Promise<string> {
	const workspaceFile = path.join(config.rootPath, `${path.basename(config.wspPath, path.extname(config.wspPath))}.code-workspace`);
	const workspaceContent = {
		folders: [
			{
				path: '.'
			}
		],
		settings: {
			'f2mc-8fx-workbench.wspPath': path.basename(config.wspPath),
			'f2mc-8fx-workbench.buildWorkingDirectory': '.',
			'f2mc-8fx-workbench.buildCommandTemplate': ''
		},
		extensions: {
			recommendations: [EXTENSION_ID]
		}
	};
	config.workspaceFile = workspaceFile;
	await writeJsonFile(workspaceFile, workspaceContent);
	return workspaceFile;
}

async function readProjectConfig(configPath: string): Promise<F2mcProjectConfig | undefined> {
	try {
		const content = await readTextFile(configPath);
		const parsed = JSON.parse(content) as F2mcProjectConfig;
		if (parsed.wspPath && parsed.rootPath) {
			return parsed;
		}
	} catch {
		// Ignore invalid config files and continue discovery.
	}
	return undefined;
}
