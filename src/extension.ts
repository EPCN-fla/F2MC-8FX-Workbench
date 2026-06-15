import * as path from 'node:path';

import * as vscode from 'vscode';

import { runProjectTask } from './buildRunner';
import { applyChipToProjectFiles } from './chipProjectWriter';
import { findChipByModel, getChipCategories, loadChipCatalog } from './chipCatalog';
import type { F2mcChipInfo } from './chipCatalog';
import { PROJECT_CONTEXT } from './constants';
import { parsePrjProject, parseWspProject } from './projectParser';
import { createVsCodeWorkspace, discoverProjectConfig, persistProjectConfig } from './projectStorage';
import { F2mcProjectNode, F2mcProjectTreeProvider } from './projectTree';
import { saveProjectFiles } from './projectWriter';
import { F2mcChipSelectionKey, F2mcProjectPropertyKey, F2mcSettingsTreeProvider } from './settingsTree';
import type { BuildKind, F2mcProjectConfig, F2mcProjectInfo } from './types';

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
	const chips = await loadChipCatalog(context.extensionPath);
	settingsTreeProvider.setChips(chips);
	context.subscriptions.push(treeView, settingsTreeView, outputChannel);
	context.subscriptions.push(treeProvider.onDidChangeProjectConfig(async config => {
		try {
			await persistProjectConfig(config);
		} catch (error) {
			const message = error instanceof Error ? error.message : String(error);
			outputChannel.appendLine(`[project] 保存工程索引失败: ${message}`);
			void vscode.window.showErrorMessage(`保存 F2MC-8FX 工程索引失败：${message}`);
		}
	}));

	async function loadCurrentProject(showMessage = false): Promise<F2mcProjectConfig | undefined> {
		const config = await discoverProjectConfig();
		treeProvider.setProject(config);
		settingsTreeProvider.setProject(config);
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
		vscode.commands.registerCommand('f2mc_workbench.settings.editProjectProperty', async (propertyKey?: F2mcProjectPropertyKey) => {
			const config = treeProvider.getProjectConfig() ?? await ensureProjectLoaded(loadCurrentProject);
			if (config && propertyKey && await editProjectProperty(config, propertyKey)) {
				treeProvider.refresh();
				settingsTreeProvider.refresh();
				await persistProjectConfig(config);
				await saveProjectFiles(config);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.settings.selectChip', async (selectionKey?: F2mcChipSelectionKey) => {
			const config = treeProvider.getProjectConfig() ?? await ensureProjectLoaded(loadCurrentProject);
			if (config && selectionKey && await selectProjectChip(config, chips, selectionKey)) {
				treeProvider.refresh();
				settingsTreeProvider.refresh();
				await persistProjectConfig(config);
				await saveProjectFiles(config);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.importWsp', async () => {
			await importWspProject(outputChannel);
			await loadCurrentProject();
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.refresh', async () => {
			await loadCurrentProject(true);
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.build', async (node?: F2mcProjectNode) => {
			await runProjectCommand(treeProvider, loadCurrentProject, outputChannel, context.extensionPath, 'build', node);
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
		vscode.commands.registerCommand('f2mc_workbench.project.clean', async (node?: F2mcProjectNode) => {
			await runProjectCommand(treeProvider, loadCurrentProject, outputChannel, context.extensionPath, 'clean', node);
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.download', async () => {
			await runProjectCommand(treeProvider, loadCurrentProject, outputChannel, context.extensionPath, 'download');
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.addProject', async (node?: F2mcProjectNode) => {
			const config = treeProvider.getProjectConfig() ?? await ensureProjectLoaded(loadCurrentProject);
			if (config) {
				await addWorkspaceProject(treeProvider, config, node);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.setActive', async (node?: F2mcProjectNode) => {
			if (node?.project) {
				treeProvider.setActiveProject(node.project);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.removeNode', async (node?: F2mcProjectNode) => {
			await removeProjectNode(treeProvider, node);
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.removeProject', async (node?: F2mcProjectNode) => {
			await removeProjectNode(treeProvider, node);
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.openFile', async (node?: F2mcProjectNode) => {
			if (node?.resourceUri) {
				await vscode.commands.executeCommand('vscode.open', node.resourceUri);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.moveUp', (node?: F2mcProjectNode) => {
			if (node) {
				treeProvider.moveNode(node, -1);
			}
		}),
		vscode.commands.registerCommand('f2mc_workbench.project.moveDown', (node?: F2mcProjectNode) => {
			if (node) {
				treeProvider.moveNode(node, 1);
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
		title: '创建新文件夹',
		prompt: '请输入文件夹名称',
		placeHolder: 'New Folder',
		validateInput: value => value.trim().length > 0 ? undefined : '文件夹名称不能为空'
	});

	if (!folderName) {
		return;
	}

	treeProvider.addFolder(folderName.trim(), node);
}

async function addWorkspaceProject(treeProvider: F2mcProjectTreeProvider, config: F2mcProjectConfig, _node?: F2mcProjectNode): Promise<void> {
	const selected = await vscode.window.showOpenDialog({
		canSelectFiles: true,
		canSelectFolders: false,
		canSelectMany: false,
		defaultUri: vscode.Uri.file(config.rootPath),
		filters: {
			'F2MC-8FX Project': ['prj'],
			'All Files': ['*']
		},
		title: '添加项目'
	});

	if (!selected || selected.length === 0) {
		return;
	}

	const project = await parsePrjProject(selected[0].fsPath);
	treeProvider.addProject(project);
}

async function runProjectCommand(
	treeProvider: F2mcProjectTreeProvider,
	loader: () => Promise<F2mcProjectConfig | undefined>,
	outputChannel: vscode.OutputChannel,
	extensionPath: string,
	kind: BuildKind,
	node?: F2mcProjectNode
): Promise<void> {
	const config = treeProvider.getProjectConfig() ?? await ensureProjectLoaded(loader);
	if (!config) {
		return;
	}

	const taskConfig = node?.project
		? {
			...config,
			projects: config.projects.map(project => ({
				...project,
				isActive: project === node.project
			}))
		}
		: config;
	await runProjectTask(taskConfig, kind, outputChannel, extensionPath);
}

async function removeProjectNode(treeProvider: F2mcProjectTreeProvider, node?: F2mcProjectNode): Promise<void> {
	if (!node) {
		return;
	}

	const label = typeof node.label === 'string' ? node.label : node.label?.label ?? '所选节点';
	const isProject = node.kind === 'project';
	const message = isProject
		? `确认移除项目“${label}”吗？`
		: `确认移除“${label}”吗？本地文件仍保留`;
	const confirm = '移除';
	const choice = await vscode.window.showWarningMessage(message, { modal: true }, confirm);
	if (choice === confirm) {
		treeProvider.removeNode(node);
	}
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

async function selectProjectChip(config: F2mcProjectConfig, chips: F2mcChipInfo[], selectionKey: F2mcChipSelectionKey): Promise<boolean> {
	const project = config.projects.find(existingProject => existingProject.isActive) ?? config.projects[0];
	if (!project) {
		return false;
	}

	const selectedChip = selectionKey === 'category'
		? await selectChipByCategory(chips, project)
		: await selectChipByModelInCurrentCategory(chips, project);
	if (!selectedChip) {
		return false;
	}

	await applyChipToProjectFiles(project, selectedChip);
	void vscode.window.showInformationMessage(`已选择芯片：${selectedChip.model}`);
	return true;
}

async function selectChipByCategory(chips: F2mcChipInfo[], project: F2mcProjectInfo): Promise<F2mcChipInfo | undefined> {
	const currentChip = findChipByModel(chips, project.cpuName);
	const selectedCategory = await vscode.window.showQuickPick(getChipCategories(chips), {
		title: '选择芯片类别',
		placeHolder: currentChip?.category ?? '请选择芯片类别'
	});
	if (!selectedCategory) {
		return undefined;
	}

	return selectChipByModel(chips.filter(chip => chip.category === selectedCategory), project, selectedCategory);
}

async function selectChipByModelInCurrentCategory(chips: F2mcChipInfo[], project: F2mcProjectInfo): Promise<F2mcChipInfo | undefined> {
	const currentChip = findChipByModel(chips, project.cpuName);
	const category = currentChip?.category;
	const filteredChips = category ? chips.filter(chip => chip.category === category) : chips;
	return selectChipByModel(filteredChips, project, category);
}

async function selectChipByModel(chips: F2mcChipInfo[], project: F2mcProjectInfo, category?: string): Promise<F2mcChipInfo | undefined> {
	const selected = await vscode.window.showQuickPick(chips.map(chip => ({
		label: chip.model,
		description: chip.category,
		detail: `ROM ${chip.romStart}-${chip.romEnd} / RAM ${chip.ramStart}-${chip.ramEnd}`,
		chip
	})), {
		title: category ? `选择芯片型号 - ${category}` : '选择芯片型号',
		placeHolder: project.cpuName ?? '请选择芯片型号',
		matchOnDescription: true,
		matchOnDetail: true
	});
	return selected?.chip;
}

async function editProjectProperty(config: F2mcProjectConfig, propertyKey: F2mcProjectPropertyKey): Promise<boolean> {
	const project = config.projects.find(existingProject => existingProject.isActive) ?? config.projects[0];
	if (!project) {
		return false;
	}

	const currentValue = getProjectPropertyValue(config, project, propertyKey);
	const nextValue = await vscode.window.showInputBox({
		title: `编辑${getProjectPropertyLabel(propertyKey)}`,
		prompt: getProjectPropertyPrompt(propertyKey),
		value: currentValue,
		validateInput: value => validateProjectPropertyInput(value, propertyKey)
	});

	if (nextValue === undefined) {
		return false;
	}

	setProjectPropertyValue(config, project, propertyKey, nextValue.trim());
	void vscode.window.showInformationMessage(`已更新${getProjectPropertyLabel(propertyKey)}。`);
	return true;
}

function getProjectPropertyLabel(propertyKey: F2mcProjectPropertyKey): string {
	switch (propertyKey) {
		case 'loadModuleName':
			return '生成文件名称';
		case 'loadModuleDirectory':
			return '生成文件目录';
		case 'objectDirectory':
			return '编译文件目录';
		case 'listDirectory':
			return '列表文件目录';
	}
}

function getProjectPropertyValue(config: F2mcProjectConfig, project: F2mcProjectInfo, propertyKey: F2mcProjectPropertyKey): string {
	switch (propertyKey) {
		case 'loadModuleName':
			return stripAbsExtension(project.loadModule ? path.basename(project.loadModule) : `${project.name}.abs`);
		case 'loadModuleDirectory':
			return toWorkspaceRelativePath(project.loadModule ? path.dirname(project.loadModule) : project.directories?.config, config.rootPath);
		case 'objectDirectory':
			return toWorkspaceRelativePath(project.directories?.obj, config.rootPath);
		case 'listDirectory':
			return toWorkspaceRelativePath(project.directories?.lst, config.rootPath);
	}
}

function setProjectPropertyValue(config: F2mcProjectConfig, project: F2mcProjectInfo, propertyKey: F2mcProjectPropertyKey, value: string): void {
	const projectRootPath = project.path ? path.dirname(project.path) : undefined;
	const resolveWorkspacePath = (input: string): string => path.resolve(config.rootPath, input);

	if (!project.directories) {
		project.directories = {};
	}

	switch (propertyKey) {
		case 'loadModuleName': {
			const currentDirectory = project.loadModule ? path.dirname(project.loadModule) : project.directories.config ?? projectRootPath ?? '';
			const loadModuleName = `${stripAbsExtension(value)}.abs`;
			project.loadModule = currentDirectory ? path.join(currentDirectory, loadModuleName) : loadModuleName;
			return;
		}
		case 'loadModuleDirectory': {
			const currentName = project.loadModule ? path.basename(project.loadModule) : `${project.name}.abs`;
			project.loadModule = path.join(resolveWorkspacePath(value), currentName);
			return;
		}
		case 'objectDirectory':
			project.directories.obj = resolveWorkspacePath(value);
			return;
		case 'listDirectory':
			project.directories.lst = resolveWorkspacePath(value);
			return;
	}
}

function isDirectoryProjectProperty(propertyKey: F2mcProjectPropertyKey): boolean {
	return propertyKey === 'loadModuleDirectory' || propertyKey === 'objectDirectory' || propertyKey === 'listDirectory';
}

function validateProjectPropertyInput(value: string, propertyKey: F2mcProjectPropertyKey): string | undefined {
	const trimmed = value.trim();
	if (!trimmed) {
		return `${getProjectPropertyLabel(propertyKey)}不能为空`;
	}

	if (propertyKey === 'loadModuleName') {
		if (/[\\/]/.test(trimmed)) {
			return '生成文件名称不能包含路径分隔符';
		}
		if (path.extname(trimmed)) {
			return '生成文件名称只允许输入名称';
		}
	}

	if (isDirectoryProjectProperty(propertyKey) && path.isAbsolute(trimmed)) {
		return `${getProjectPropertyLabel(propertyKey)}必须是 VS Code 工作区的相对路径`;
	}

	return undefined;
}

function getProjectPropertyPrompt(propertyKey: F2mcProjectPropertyKey): string {
	if (propertyKey === 'loadModuleName') {
		return '请输入生成文件名称';
	}

	return isDirectoryProjectProperty(propertyKey)
		? `请输入${getProjectPropertyLabel(propertyKey)}的相对路径`
		: `请输入${getProjectPropertyLabel(propertyKey)}`;
}

function stripAbsExtension(fileName: string): string {
	return path.extname(fileName).toLowerCase() === '.abs'
		? fileName.slice(0, -path.extname(fileName).length)
		: fileName;
}

function toWorkspaceRelativePath(value: string | undefined, workspaceRootPath: string): string {
	if (!value) {
		return '';
	}

	const relativePath = path.relative(workspaceRootPath, value);
	return relativePath && !relativePath.startsWith('..') && !path.isAbsolute(relativePath)
		? relativePath.replace(/\\/g, '/')
		: value;
}
