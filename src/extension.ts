import * as path from 'node:path';

import * as vscode from 'vscode';

import { runProjectTask } from './buildRunner';
import { PROJECT_CONTEXT } from './constants';
import { parseWspProject } from './projectParser';
import { createVsCodeWorkspace, discoverProjectConfig, persistProjectConfig } from './projectStorage';
import { F2mcProjectNode, F2mcProjectTreeProvider } from './projectTree';
import { saveProjectFiles } from './projectWriter';
import { F2mcSettingsTreeProvider } from './settingsTree';
import type { F2mcProjectConfig } from './types';

export async function activate(context: vscode.ExtensionContext): Promise<void> {
	const treeProvider = new F2mcProjectTreeProvider(context.extensionPath);
	const settingsTreeProvider = new F2mcSettingsTreeProvider(context.extensionPath);
	const treeView = vscode.window.createTreeView('fh.view', {
		treeDataProvider: treeProvider,
		dragAndDropController: treeProvider,
		showCollapseAll: true
	});
	const settingsTreeView = vscode.window.createTreeView('fh.settings', {
		treeDataProvider: settingsTreeProvider,
		showCollapseAll: false
	});

	const outputChannel = vscode.window.createOutputChannel('F2MC-8FX Build');
	context.subscriptions.push(treeView, settingsTreeView, outputChannel);

	async function loadCurrentProject(showMessage = false): Promise<F2mcProjectConfig | undefined> {
		const config = await discoverProjectConfig();
		treeProvider.setProject(config);
		await vscode.commands.executeCommand('setContext', PROJECT_CONTEXT, Boolean(config));

		if (showMessage) {
			if (config) {
				void vscode.window.showInformationMessage(`已加载 F2MC-8FX 工程：${path.basename(config.wspPath)}`);
			} else {
				void vscode.window.showInformationMessage('未在当前工作区发现 F2MC-8FX 工程');
			}
		}

		return config;
	}

	context.subscriptions.push(
		vscode.commands.registerCommand('f2mc_workbench.project.importWsp', async () => {
			await importWspProject(outputChannel);
			await loadCurrentProject();
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.refresh', async () => {
			await loadCurrentProject(true);
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.build', async () => {
			const config = await ensureProjectLoaded(loadCurrentProject);
			if (config) {
				await runProjectTask(config, 'build', outputChannel, context.extensionPath);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.addFile', async (node?: F2mcProjectNode) => {
			const config = treeProvider.getProjectConfig() ?? await ensureProjectLoaded(loadCurrentProject);
			if (config) {
				await addProjectFile(treeProvider, config, node);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.addFolder', async (node?: F2mcProjectNode) => {
			const config = treeProvider.getProjectConfig() ?? await ensureProjectLoaded(loadCurrentProject);
			if (config) {
				await addProjectFolder(treeProvider, config, node);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.save_all', async () => {
			const config = treeProvider.getProjectConfig() ?? await ensureProjectLoaded(loadCurrentProject);
			if (config) {
				await saveProjectFiles(config);
				await persistProjectConfig(config);
				void vscode.window.showInformationMessage('已保存 F2MC-8FX 工程配置。');
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.clean', async () => {
			const config = await ensureProjectLoaded(loadCurrentProject);
			if (config) {
				await runProjectTask(config, 'clean', outputChannel, context.extensionPath);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.download', async () => {
			const config = await ensureProjectLoaded(loadCurrentProject);
			if (config) {
				await runProjectTask(config, 'download', outputChannel, context.extensionPath);
			}
		})
	);

	await loadCurrentProject();
}

export function deactivate(): void {
	// No-op.
}

async function importWspProject(outputChannel: vscode.OutputChannel): Promise<void> {
	const selected = await vscode.window.showOpenDialog({
		canSelectFiles: true,
		canSelectFolders: false,
		canSelectMany: false,
		filters: {
			'F2MC-8FX Workspace': ['wsp'],
			'All Files': ['*']
		},
		title: '选择工程文件'
	});

	if (!selected || selected.length === 0) {
		return;
	}

	const wspUri = selected[0];
	const wspPath = wspUri.fsPath;
	const config = await parseWspProject(wspPath);
	await persistProjectConfig(config);
	const workspaceFile = await createVsCodeWorkspace(config);

	const openAction = '打开工作区';
	const laterAction = '稍后';
	const choice = await vscode.window.showInformationMessage(
		`已导入 ${path.basename(wspPath)}，是否切换至工作区？`,
		openAction,
		laterAction
	);

	outputChannel.appendLine(`[import] .wsp: ${wspPath}`);
	outputChannel.appendLine(`[import] workspace: ${workspaceFile}`);

	if (choice === openAction) {
		await vscode.commands.executeCommand('vscode.openFolder', vscode.Uri.file(workspaceFile), false);
	}
}

async function addProjectFile(treeProvider: F2mcProjectTreeProvider, config: F2mcProjectConfig, node?: F2mcProjectNode): Promise<void> {
	const selected = await vscode.window.showOpenDialog({
		canSelectFiles: true,
		canSelectFolders: false,
		canSelectMany: false,
		defaultUri: vscode.Uri.file(config.rootPath),
		filters: {
			'F2MC-8FX Files': ['c', 'asm', 'lib'],
			'All Files': ['*']
		},
		title: '添加文件'
	});

	if (!selected || selected.length === 0) {
		return;
	}

	treeProvider.addFile(selected[0].fsPath, node);
}

async function addProjectFolder(treeProvider: F2mcProjectTreeProvider, _config: F2mcProjectConfig, node?: F2mcProjectNode): Promise<void> {
	const folderName = await vscode.window.showInputBox({
		title: '添加虚拟文件夹',
		prompt: '请输入虚拟文件夹名称',
		placeHolder: 'New Folder',
		validateInput: value => value.trim().length > 0 ? undefined : '虚拟文件夹名称不能为空'
	});

	if (!folderName) {
		return;
	}

	treeProvider.addFolder(folderName.trim(), node);
}

async function ensureProjectLoaded(loader: () => Promise<F2mcProjectConfig | undefined>): Promise<F2mcProjectConfig | undefined> {
	const config = await loader();
	if (!config) {
		const action = '导入';
		const choice = await vscode.window.showWarningMessage('请先导入 F2MC-8FX 工程。', action);
		if (choice === action) {
			await vscode.commands.executeCommand('f2mc_workbench.project.importWsp');
		}
	}
	return config;
}
