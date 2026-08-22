import * as path from 'node:path';

import * as vscode from 'vscode';

import { CONFIG_FILE_NAME, EXTENSION_ID, HELPER_DIR_NAME, LEGACY_HELPER_DIR_NAME } from './constants';
import { readTextFile, writeJsonFile, getSystemAnsiEncodingLabel } from './fileSystem';
import { parsePrjProject, parseWspProject } from './projectParser';
import type { F2mcProjectConfig } from './types';

const LEGACY_CONFIG_FILE_NAMES = [CONFIG_FILE_NAME, 'f2mc_workbench.json'];

const GITIGNORE_MARKER = '# F2MC-8FX Workbench';
const GITIGNORE_BLOCK = [
	GITIGNORE_MARKER,
	`${HELPER_DIR_NAME}/intellisense/`,
	'',
	'# project out',
	'*.abs',
	'*.mhx',
	'*.ihx',
	'*.ehx',
	'*.hex',
	'',
	'# build files',
	'*.mp1',
	'*.obj',
	'*.lst',
	'*.map',
	'*.stk',
	'*.tpi',
	'*.sup'
];

export async function discoverProjectConfig(): Promise<F2mcProjectConfig | undefined> {
	const folders = vscode.workspace.workspaceFolders ?? [];
	for (const folder of folders) {
		const folderPath = folder.uri.fsPath;
		const legacyDir = path.join(folderPath, LEGACY_HELPER_DIR_NAME);
		if (await pathExists(legacyDir)) {
			const rebuilt = await rebuildFromLegacyHelper(folderPath, legacyDir);
			if (rebuilt) {
				return rebuilt;
			}
			// Rebuild failed (e.g. .wsp missing); fall back to the legacy persisted config.
			for (const fileName of LEGACY_CONFIG_FILE_NAMES) {
				const legacyConfig = await readProjectConfig(path.join(legacyDir, fileName));
				if (legacyConfig) {
					return legacyConfig;
				}
			}
		}
		const config = await readProjectConfig(path.join(folderPath, HELPER_DIR_NAME, CONFIG_FILE_NAME));
		if (config) {
			return config;
		}
	}

	return undefined;
}

async function rebuildFromLegacyHelper(folderPath: string, legacyDir: string): Promise<F2mcProjectConfig | undefined> {
	const wspPath = await findLegacyWspPath(folderPath, legacyDir);
	if (!wspPath) {
		return undefined;
	}

	let config: F2mcProjectConfig;
	try {
		config = await parseWspProject(wspPath);
	} catch {
		return undefined;
	}

	try {
		await persistProjectConfig(config);
		await vscode.workspace.fs.delete(vscode.Uri.file(legacyDir), { recursive: true, useTrash: false });
	} catch {
		// Cleanup failure is non-fatal; the rebuilt config is still usable.
	}
	return config;
}

async function findLegacyWspPath(folderPath: string, legacyDir: string): Promise<string | undefined> {
	for (const fileName of LEGACY_CONFIG_FILE_NAMES) {
		try {
			const content = await readTextFile(path.join(legacyDir, fileName));
			const parsed = JSON.parse(content) as Partial<F2mcProjectConfig>;
			if (parsed.wspPath) {
				return parsed.wspPath;
			}
		} catch {
			// Try the next candidate file.
		}
	}

	const matches = await vscode.workspace.findFiles(new vscode.RelativePattern(folderPath, '*.wsp'), undefined, 1);
	return matches[0]?.fsPath;
}

async function pathExists(targetPath: string): Promise<boolean> {
	try {
		await vscode.workspace.fs.stat(vscode.Uri.file(targetPath));
		return true;
	} catch {
		return false;
	}
}

export async function persistProjectConfig(config: F2mcProjectConfig): Promise<void> {
	await vscode.workspace.fs.createDirectory(vscode.Uri.file(path.join(config.rootPath, HELPER_DIR_NAME)));
	await writeJsonFile(path.join(config.rootPath, HELPER_DIR_NAME, CONFIG_FILE_NAME), config);
}

export async function createProjectGitignore(config: F2mcProjectConfig): Promise<string> {
	const gitignorePath = path.join(config.rootPath, '.gitignore');
	let existing = '';
	try {
		const bytes = await vscode.workspace.fs.readFile(vscode.Uri.file(gitignorePath));
		existing = Buffer.from(bytes).toString('utf8');
	} catch {
		// .gitignore does not exist yet.
	}

	if (!existing.includes(GITIGNORE_MARKER)) {
		const separator = existing.length > 0 ? (existing.endsWith('\n') ? '\n' : '\n\n') : '';
		await vscode.workspace.fs.writeFile(
			vscode.Uri.file(gitignorePath),
			Buffer.from(existing + separator + GITIGNORE_BLOCK.join('\n') + '\n', 'utf8')
		);
	}
	return gitignorePath;
}

export async function createVsCodeWorkspace(config: F2mcProjectConfig): Promise<string> {
	const workspaceFile = path.join(config.rootPath, `${path.basename(config.wspPath, path.extname(config.wspPath))}.code-workspace`);
	const ansiEncoding = await getSystemAnsiEncodingLabel();
	const workspaceContent = {
		folders: [
			{
				path: '.'
			}
		],
		settings: ansiEncoding
			? {
				'files.encoding': ansiEncoding
			}
			: undefined,
		extensions: {
			recommendations: [EXTENSION_ID]
		}
	};
	config.workspaceFile = workspaceFile;
	await writeJsonFile(workspaceFile, workspaceContent);
	return workspaceFile;
}

async function refreshStaleProjectFields(config: F2mcProjectConfig): Promise<void> {
	for (const project of config.projects ?? []) {
		if (project.memberDependencies !== undefined || !project.path || !/\.prj$/i.test(project.path)) {
			continue;
		}
		try {
			const refreshed = await parsePrjProject(project.path, project.isActive);
			project.memberDependencies = refreshed.memberDependencies ?? {};
		} catch {
			// Project file may be missing; record an empty map so we do not retry on every discovery.
			project.memberDependencies = {};
		}
	}
}

async function readProjectConfig(configPath: string): Promise<F2mcProjectConfig | undefined> {
	try {
		const content = await readTextFile(configPath);
		const parsed = JSON.parse(content) as F2mcProjectConfig;
		if (parsed.wspPath && parsed.rootPath) {
			await refreshStaleProjectFields(parsed);
			return parsed;
		}
	} catch {
		// Ignore invalid config files and continue discovery.
	}
	return undefined;
}
