import * as path from 'node:path';

import * as vscode from 'vscode';

interface F2mcSettingsNodeInit {
	label: string;
	iconName: string;
	command?: vscode.Command;
}

export class F2mcSettingsNode extends vscode.TreeItem {
	public constructor(init: F2mcSettingsNodeInit, extensionPath: string) {
		super(init.label, vscode.TreeItemCollapsibleState.None);
		this.contextValue = 'f2mc.setting';
		this.iconPath = vscode.Uri.file(path.join(extensionPath, 'res', 'icon', init.iconName));
		this.command = init.command;
	}
}

export class F2mcSettingsTreeProvider implements vscode.TreeDataProvider<F2mcSettingsNode> {
	private readonly nodes: F2mcSettingsNode[];

	public constructor(extensionPath: string) {
		this.nodes = [
			new F2mcSettingsNode({ label: '项目属性', iconName: 'project.svg' }, extensionPath),
			new F2mcSettingsNode({ label: '芯片选择', iconName: 'chip.svg' }, extensionPath),
			new F2mcSettingsNode({ label: '构建器选项', iconName: 'builder.svg' }, extensionPath)
		];
	}

	public getTreeItem(element: F2mcSettingsNode): vscode.TreeItem {
		return element;
	}

	public getChildren(): F2mcSettingsNode[] {
		return this.nodes;
	}
}
