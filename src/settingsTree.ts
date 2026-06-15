import * as path from 'node:path';

import * as vscode from 'vscode';

import type { F2mcChipInfo } from './chipCatalog';
import type { F2mcProjectConfig, F2mcProjectInfo } from './types';

export type F2mcSettingsNodeKind = 'section' | 'property' | 'chip' | 'empty';

export type F2mcProjectPropertyKey = 'loadModuleName' | 'loadModuleDirectory' | 'objectDirectory' | 'listDirectory';
export type F2mcChipSelectionKey = 'category' | 'model';

interface F2mcSettingsNodeInit {
	label: string;
	kind: F2mcSettingsNodeKind;
	iconName?: string;
	icon?: vscode.ThemeIcon;
	collapsibleState?: vscode.TreeItemCollapsibleState;
	command?: vscode.Command;
	project?: F2mcProjectInfo;
	propertyKey?: F2mcProjectPropertyKey;
	chipKey?: F2mcChipSelectionKey;
	description?: string;
	tooltip?: string;
}

interface ProjectPropertyDefinition {
	key: F2mcProjectPropertyKey;
	label: string;
	icon: vscode.ThemeIcon;
	value: (project: F2mcProjectInfo, workspaceRootPath: string) => string;
}

const PROJECT_PROPERTY_DEFINITIONS: ProjectPropertyDefinition[] = [
	{
		key: 'loadModuleName',
		label: '生成文件名称',
		icon: new vscode.ThemeIcon('symbol-file'),
		value: project => project.loadModule ? path.basename(project.loadModule) : `${project.name}.abs`
	},
	{
		key: 'loadModuleDirectory',
		label: '生成文件目录',
		icon: new vscode.ThemeIcon('folder-opened'),
		value: (project, workspaceRootPath) => toWorkspaceRelativePath(project.loadModule ? path.dirname(project.loadModule) : project.directories?.config, workspaceRootPath)
	},
	{
		key: 'objectDirectory',
		label: '编译文件目录',
		icon: new vscode.ThemeIcon('folder-library'),
		value: (project, workspaceRootPath) => toWorkspaceRelativePath(project.directories?.obj, workspaceRootPath)
	},
	{
		key: 'listDirectory',
		label: '列表文件目录',
		icon: new vscode.ThemeIcon('list-tree'),
		value: (project, workspaceRootPath) => toWorkspaceRelativePath(project.directories?.lst, workspaceRootPath)
	}
];

export class F2mcSettingsNode extends vscode.TreeItem {
	public readonly kind: F2mcSettingsNodeKind;
	public readonly project: F2mcProjectInfo | undefined;
	public readonly propertyKey: F2mcProjectPropertyKey | undefined;
	public readonly chipKey: F2mcChipSelectionKey | undefined;

	public constructor(init: F2mcSettingsNodeInit, extensionPath: string) {
		super(init.label, init.collapsibleState ?? vscode.TreeItemCollapsibleState.None);
		this.kind = init.kind;
		this.project = init.project;
		this.propertyKey = init.propertyKey;
		this.chipKey = init.chipKey;
		this.contextValue = `f2mc.setting.${init.kind}`;
		this.command = init.command;
		this.description = init.description;
		this.tooltip = init.tooltip;

		if (init.icon) {
			this.iconPath = init.icon;
		} else if (init.iconName) {
			this.iconPath = vscode.Uri.file(path.join(extensionPath, 'res', 'icon', init.iconName));
		}
	}
}

export class F2mcSettingsTreeProvider implements vscode.TreeDataProvider<F2mcSettingsNode> {
	private readonly onDidChangeTreeDataEmitter = new vscode.EventEmitter<F2mcSettingsNode | undefined | null | void>();
	public readonly onDidChangeTreeData = this.onDidChangeTreeDataEmitter.event;
	private config: F2mcProjectConfig | undefined;
	private chips: F2mcChipInfo[] = [];

	public constructor(private readonly extensionPath: string) {
	}

	public setProject(config: F2mcProjectConfig | undefined): void {
		this.config = config;
		this.onDidChangeTreeDataEmitter.fire();
	}

	public setChips(chips: F2mcChipInfo[]): void {
		this.chips = chips;
		this.onDidChangeTreeDataEmitter.fire();
	}

	public refresh(): void {
		this.onDidChangeTreeDataEmitter.fire();
	}

	public getTreeItem(element: F2mcSettingsNode): vscode.TreeItem {
		return element;
	}

	public getChildren(element?: F2mcSettingsNode): F2mcSettingsNode[] {
		if (!element) {
			return this.createRootNodes();
		}

		if (element.kind === 'section' && element.label === '项目属性') {
			return this.createProjectPropertyNodes();
		}

		if (element.kind === 'section' && element.label === '芯片选择') {
			return this.createChipSelectionNodes();
		}

		return [];
	}

	private createRootNodes(): F2mcSettingsNode[] {
		return [
			new F2mcSettingsNode({
				label: '项目属性',
				kind: 'section',
				iconName: 'project.svg',
				collapsibleState: vscode.TreeItemCollapsibleState.Collapsed
			}, this.extensionPath),
			new F2mcSettingsNode({
				label: '芯片选择',
				kind: 'section',
				iconName: 'chip.svg',
				collapsibleState: vscode.TreeItemCollapsibleState.Collapsed
			}, this.extensionPath),
			new F2mcSettingsNode({ label: '构建器选项', kind: 'section', iconName: 'builder.svg' }, this.extensionPath)
		];
	}

	private createProjectPropertyNodes(): F2mcSettingsNode[] {
		const project = this.getActiveProject();
		if (!project) {
			return [new F2mcSettingsNode({
				label: '请先导入工程',
				kind: 'empty',
				icon: new vscode.ThemeIcon('info'),
				description: '无可编辑项目'
			}, this.extensionPath)];
		}

		return PROJECT_PROPERTY_DEFINITIONS.map(definition => {
			const value = definition.value(project, this.config?.rootPath ?? '');
			return new F2mcSettingsNode({
				label: definition.label,
				kind: 'property',
				icon: definition.icon,
				project,
				propertyKey: definition.key,
				description: value,
				tooltip: value ? `${definition.label}: ${value}` : `${definition.label}: 未设置`,
				command: {
					command: 'f2mc_workbench.settings.editProjectProperty',
					title: `编辑${definition.label}`,
					arguments: [definition.key]
				}
			}, this.extensionPath);
		});
	}

	private createChipSelectionNodes(): F2mcSettingsNode[] {
		const project = this.getActiveProject();
		if (!project) {
			return [new F2mcSettingsNode({
				label: '请先导入工程',
				kind: 'empty',
				icon: new vscode.ThemeIcon('info'),
				description: '无可编辑项目'
			}, this.extensionPath)];
		}

		const chip = this.chips.find(item => item.model.toLowerCase() === project.cpuName?.toLowerCase());
		return [
			new F2mcSettingsNode({
				label: '类别',
				kind: 'chip',
				icon: new vscode.ThemeIcon('symbol-class'),
				chipKey: 'category',
				description: chip?.category ?? '未设置',
				tooltip: `类别: ${chip?.category ?? '未设置'}`,
				command: {
					command: 'f2mc_workbench.settings.selectChip',
					title: '选择芯片类别',
					arguments: ['category']
				}
			}, this.extensionPath),
			new F2mcSettingsNode({
				label: '型号',
				kind: 'chip',
				icon: new vscode.ThemeIcon('chip'),
				chipKey: 'model',
				description: project.cpuName ?? '未设置',
				tooltip: `型号: ${project.cpuName ?? '未设置'}`,
				command: {
					command: 'f2mc_workbench.settings.selectChip',
					title: '选择芯片型号',
					arguments: ['model']
				}
			}, this.extensionPath)
		];
	}

	private getActiveProject(): F2mcProjectInfo | undefined {
		return this.config?.projects.find(project => project.isActive) ?? this.config?.projects[0];
	}
}

function toWorkspaceRelativePath(value: string | undefined, workspaceRootPath: string): string {
	if (!value) {
		return '';
	}

	if (!workspaceRootPath) {
		return value;
	}

	const relativePath = path.relative(workspaceRootPath, value);
	return relativePath && !relativePath.startsWith('..') && !path.isAbsolute(relativePath)
		? relativePath.replace(/\\/g, '/')
		: value;
}
