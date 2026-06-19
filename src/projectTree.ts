import * as fs from 'node:fs';
import * as path from 'node:path';

import * as vscode from 'vscode';

import { collectFilesByType, collectFilesByTypeInFolder, collectMemberPaths, getMemberFileType, orderProjectMembersForTree } from './memberUtils';
import { isSamePath, resolvePath } from './pathUtils';
import type { F2mcProjectConfig, F2mcProjectInfo, F2mcProjectMember } from './types';

interface F2mcProjectNodeInit {
	label: string;
	collapsibleState: vscode.TreeItemCollapsibleState;
	kind: F2mcProjectNodeKind;
	resourcePath?: string;
	children?: F2mcProjectNode[];
	iconPath?: vscode.Uri;
	project?: F2mcProjectInfo;
	member?: F2mcProjectMember;
}

type F2mcProjectNodeKind = 'action' | 'workspace' | 'project' | 'folder' | 'file';

interface ProjectDependencyInfo {
	dependenciesBySourcePath: Map<string, string[]>;
	projectRootPath: string;
	extensionPath: string;
	project: F2mcProjectInfo;
}

const SOURCE_FILES_FOLDER_NAME = 'Source Files';
const INCLUDE_FILES_FOLDER_NAME = 'Include Files';

export class F2mcProjectNode extends vscode.TreeItem {
	public readonly children: F2mcProjectNode[];
	public readonly kind: F2mcProjectNodeKind;
	public readonly project: F2mcProjectInfo | undefined;
	public readonly member: F2mcProjectMember | undefined;

	public constructor(init: F2mcProjectNodeInit) {
		const resourceUri = init.resourcePath ? vscode.Uri.file(init.resourcePath) : undefined;
		super(init.label, init.collapsibleState);
		this.label = init.label;
		this.kind = init.kind;
		this.project = init.project;
		this.member = init.member;
		this.contextValue = init.kind === 'project' && init.project?.isActive
			? 'f2mc.project.active'
			: `f2mc.${init.kind}`;
		this.children = init.children ?? [];

		if (init.iconPath) {
			this.iconPath = init.iconPath;
		}

		if (resourceUri) {
			this.resourceUri = resourceUri;
			this.tooltip = init.resourcePath;
		}

		if (init.kind === 'file' && init.resourcePath) {
			this.command = {
				command: 'vscode.open',
				title: '打开文件',
				arguments: [vscode.Uri.file(init.resourcePath)]
			};
		}
	}
}

export class F2mcProjectTreeProvider implements vscode.TreeDataProvider<F2mcProjectNode>, vscode.TreeDragAndDropController<F2mcProjectNode> {
	public readonly dragMimeTypes = ['application/vnd.code.tree.f2mcProjectTree'];
	public readonly dropMimeTypes = ['application/vnd.code.tree.f2mcProjectTree'];
	private readonly onDidChangeTreeDataEmitter = new vscode.EventEmitter<F2mcProjectNode | undefined | null | void>();
	public readonly onDidChangeTreeData = this.onDidChangeTreeDataEmitter.event;
	private readonly onDidChangeProjectConfigEmitter = new vscode.EventEmitter<F2mcProjectConfig>();
	public readonly onDidChangeProjectConfig = this.onDidChangeProjectConfigEmitter.event;
	private config: F2mcProjectConfig | undefined;

	public constructor(private readonly extensionPath: string) {
	}

	public setProject(config: F2mcProjectConfig | undefined): void {
		this.config = config;
		this.onDidChangeTreeDataEmitter.fire();
	}

	public refresh(): void {
		this.onDidChangeTreeDataEmitter.fire();
	}

	public getTreeItem(element: F2mcProjectNode): vscode.TreeItem {
		return element;
	}

	public getProjectConfig(): F2mcProjectConfig | undefined {
		return this.config;
	}

	public addFile(filePath: string, target?: F2mcProjectNode): void {
		const project = target?.project ?? this.config?.projects[0];
		if (!project) {
			return;
		}

		const member = createFileMember(filePath);
		const dependencyInfo = createProjectDependencyInfo(project, this.config?.rootPath ?? '', this.extensionPath);
		if (target?.member?.kind === 'folder') {
			target.member.children.push(member);
			target.children.push(createMemberNode(member, dependencyInfo));
			this.onDidChangeTreeDataEmitter.fire(target);
		} else {
			project.members.push(member);
			target?.children.push(createMemberNode(member, dependencyInfo));
			this.onDidChangeTreeDataEmitter.fire(target);
		}
		syncProjectFileLists(project);
		this.onDidChangeTreeDataEmitter.fire();
		this.fireProjectConfigChanged();
	}

	public addFolder(folderName: string, target?: F2mcProjectNode): void {
		const project = target?.project ?? this.config?.projects[0];
		if (!project) {
			return;
		}

		const member: F2mcProjectMember = {
			name: folderName,
			kind: 'folder',
			children: []
		};
		const targetSiblings = target?.member
			? findOwnerChildren(project.members, target.member) ?? project.members
			: project.members;
		const targetIndex = target?.member ? targetSiblings.indexOf(target.member) : -1;
		targetSiblings.splice(targetIndex >= 0 ? targetIndex + 1 : targetSiblings.length, 0, member);
		syncProjectFileLists(project);
		this.onDidChangeTreeDataEmitter.fire(target);
		this.onDidChangeTreeDataEmitter.fire();
		this.fireProjectConfigChanged();
	}

	public addProject(project: F2mcProjectInfo): void {
		if (!this.config || this.config.projects.some(existingProject => isSamePath(existingProject.path, project.path))) {
			return;
		}

		if (!this.config.projects.some(existingProject => existingProject.isActive)) {
			project.isActive = true;
		}
		this.config.projects.push(project);
		this.onDidChangeTreeDataEmitter.fire();
		this.fireProjectConfigChanged();
	}

	public setActiveProject(project: F2mcProjectInfo): void {
		if (!this.config || !this.config.projects.includes(project)) {
			return;
		}

		for (const existingProject of this.config.projects) {
			existingProject.isActive = existingProject === project;
		}
		this.onDidChangeTreeDataEmitter.fire();
		this.fireProjectConfigChanged();
	}

	public removeNode(node: F2mcProjectNode): void {
		if (node.kind === 'project' && node.project) {
			this.removeProject(node.project);
			return;
		}

		if ((node.kind === 'folder' || node.kind === 'file') && node.project && node.member) {
			this.removeMember(node.project, node.member);
		}
	}

	public moveNode(node: F2mcProjectNode, direction: -1 | 1): void {
		if (!node.project || !node.member) {
			return;
		}

		const siblings = findOwnerChildren(node.project.members, node.member);
		if (!siblings) {
			return;
		}

		const index = siblings.indexOf(node.member);
		const nextIndex = index + direction;
		if (index < 0 || nextIndex < 0 || nextIndex >= siblings.length) {
			return;
		}

		[siblings[index], siblings[nextIndex]] = [siblings[nextIndex], siblings[index]];
		syncProjectFileLists(node.project);
		this.onDidChangeTreeDataEmitter.fire();
		this.fireProjectConfigChanged();
	}

	public handleDrag(source: readonly F2mcProjectNode[], dataTransfer: vscode.DataTransfer): void {
		if (source.length === 0 || source.some(node => !isDraggableProjectMemberNode(node))) {
			throw new vscode.CancellationError();
		}

		dataTransfer.set(this.dragMimeTypes[0], new vscode.DataTransferItem(source));
	}

	public handleDrop(target: F2mcProjectNode | undefined, dataTransfer: vscode.DataTransfer): void {
		if (target && !isValidProjectMemberDropTarget(target)) {
			return;
		}

		const transferItem = dataTransfer.get(this.dragMimeTypes[0]);
		const sourceNodes = transferItem?.value as F2mcProjectNode[] | undefined;
		if (!sourceNodes || sourceNodes.length === 0 || sourceNodes.some(node => !isDraggableProjectMemberNode(node))) {
			return;
		}

		let didMove = false;
		for (const sourceNode of sourceNodes) {
			if (this.moveMember(sourceNode, target)) {
				didMove = true;
			}
		}

		if (didMove) {
			for (const project of this.config?.projects ?? []) {
				syncProjectFileLists(project);
			}
			this.onDidChangeTreeDataEmitter.fire();
			this.fireProjectConfigChanged();
		}
	}

	public getChildren(element?: F2mcProjectNode): F2mcProjectNode[] {
		if (element?.kind === 'project' && element.project) {
			return this.createProjectChildren(element.project);
		}

		if (element?.kind === 'folder' && element.project && element.member) {
			const rootPath = this.config?.rootPath ?? '';
			const dependencyInfo = createProjectDependencyInfo(element.project, rootPath, this.extensionPath);
			return element.member.children.map(member => createMemberNode(member, dependencyInfo));
		}

		if (element) {
			return element.children;
		}

		if (!this.config) {
			return [createImportNode()];
		}

		const workspaceName = path.basename(this.config.wspPath, path.extname(this.config.wspPath));
		const root = new F2mcProjectNode({
			label: `Workspace'${workspaceName}'`,
			collapsibleState: vscode.TreeItemCollapsibleState.Collapsed,
			kind: 'workspace',
			resourcePath: this.config.wspPath,
			children: this.config.projects.map(project => this.createProjectNode(project))
		});

		return [root];
	}

	private createProjectNode(project: F2mcProjectInfo): F2mcProjectNode {
		const rootPath = this.config?.rootPath ?? '';
		const projectPath = project.path ? resolvePath(project.path, rootPath) : undefined;
		const children = this.createProjectChildren(project);
		const label = createProjectLabel(project);
		const node = new F2mcProjectNode({
			label,
			collapsibleState: vscode.TreeItemCollapsibleState.Collapsed,
			kind: 'project',
			resourcePath: projectPath,
			children,
			project
		});

		if (project.isActive) {
			node.label = {
				label,
				highlights: [[0, label.length]]
			};
			node.description = 'Active';
		}

		return node;
	}

	private createProjectChildren(project: F2mcProjectInfo): F2mcProjectNode[] {
		const rootPath = this.config?.rootPath ?? '';
		const dependencyInfo = createProjectDependencyInfo(project, rootPath, this.extensionPath);
		return project.members.length > 0
			? orderProjectMembersForTree(project.members).map(member => createMemberNode(member, dependencyInfo))
			: project.files.map(file => createFileNodeWithDependencies(resolvePath(file, rootPath), dependencyInfo));
	}

	private removeProject(project: F2mcProjectInfo): void {
		if (!this.config) {
			return;
		}

		const index = this.config.projects.indexOf(project);
		if (index < 0) {
			return;
		}

		const wasActive = project.isActive;
		this.config.projects.splice(index, 1);
		if (wasActive && this.config.projects.length > 0) {
			this.config.projects[Math.min(index, this.config.projects.length - 1)].isActive = true;
		}
		this.onDidChangeTreeDataEmitter.fire();
		this.fireProjectConfigChanged();
	}

	private removeMember(project: F2mcProjectInfo, member: F2mcProjectMember): void {
		const siblings = findOwnerChildren(project.members, member);
		if (!siblings) {
			return;
		}

		const index = siblings.indexOf(member);
		if (index < 0) {
			return;
		}

		siblings.splice(index, 1);
		syncProjectFileLists(project);
		this.onDidChangeTreeDataEmitter.fire();
		this.fireProjectConfigChanged();
	}

	private fireProjectConfigChanged(): void {
		if (this.config) {
			this.onDidChangeProjectConfigEmitter.fire(this.config);
		}
	}

	private moveMember(sourceNode: F2mcProjectNode, target: F2mcProjectNode | undefined): boolean {
		const sourceProject = sourceNode.project;
		const sourceMember = sourceNode.member;
		if (!sourceProject || !sourceMember) {
			return false;
		}

		const targetProject = target?.project ?? sourceProject;
		const targetMember = target?.member;
		const sourceChildren = findOwnerChildren(sourceProject.members, sourceMember);
		if (!sourceChildren || targetMember === sourceMember || isDescendantMember(sourceMember, targetMember)) {
			return false;
		}

		const targetChildren = getDropTargetChildren(targetProject, targetMember);
		const sourceIndex = sourceChildren.indexOf(sourceMember);
		if (sourceIndex < 0) {
			return false;
		}

		const targetIndex = targetMember && targetMember.kind !== 'folder'
			? targetChildren.indexOf(targetMember)
			: targetChildren.length;
		if (sourceChildren === targetChildren && (sourceIndex === targetIndex || sourceIndex + 1 === targetIndex)) {
			return false;
		}

		sourceChildren.splice(sourceIndex, 1);
		const adjustedTargetIndex = sourceChildren === targetChildren && sourceIndex < targetIndex
			? targetIndex - 1
			: targetIndex;
		targetChildren.splice(Math.max(0, adjustedTargetIndex), 0, sourceMember);
		return true;
	}
}

function isDraggableProjectMemberNode(node: F2mcProjectNode): boolean {
	return Boolean(node.project && node.member && (node.kind === 'folder' || node.kind === 'file'));
}

function isValidProjectMemberDropTarget(node: F2mcProjectNode): boolean {
	return node.kind === 'project' || isDraggableProjectMemberNode(node);
}

function createImportNode(): F2mcProjectNode {
	const node = new F2mcProjectNode({
		label: '导入工程',
		collapsibleState: vscode.TreeItemCollapsibleState.None,
		kind: 'action'
	});
	node.iconPath = new vscode.ThemeIcon('add');
	node.command = {
		command: 'f2mc_workbench.project.importWsp',
		title: '导入工程'
	};
	return node;
}

function createMemberNode(member: F2mcProjectMember, dependencyInfo: ProjectDependencyInfo): F2mcProjectNode {
	if (member.kind === 'folder') {
		return new F2mcProjectNode({
			label: member.name,
			collapsibleState: vscode.TreeItemCollapsibleState.Collapsed,
			kind: 'folder',
			children: member.children.map(child => createMemberNode(child, dependencyInfo)),
			iconPath: getFolderIconPath(dependencyInfo.extensionPath),
			project: dependencyInfo.project,
			member
		});
	}

	return createFileNodeWithDependencies(member.path ?? member.name, dependencyInfo, member.name, member);
}

function createFileNode(filePath: string, extensionPath: string, label = path.basename(filePath), children: F2mcProjectNode[] = [], project?: F2mcProjectInfo, member?: F2mcProjectMember): F2mcProjectNode {
	return new F2mcProjectNode({
		label,
		collapsibleState: children.length > 0 ? vscode.TreeItemCollapsibleState.Collapsed : vscode.TreeItemCollapsibleState.None,
		kind: 'file',
		resourcePath: filePath,
		children,
		iconPath: getFileTypeIconPath(filePath, extensionPath),
		project,
		member
	});
}

function createFileNodeWithDependencies(filePath: string, dependencyInfo: ProjectDependencyInfo, label = path.basename(filePath), member?: F2mcProjectMember): F2mcProjectNode {
	const dependencyPaths = dependencyInfo.dependenciesBySourcePath.get(normalizePathKey(filePath)) ?? [];
	const dependencyNodes = dependencyPaths.map(dependencyPath => createFileNode(dependencyPath, dependencyInfo.extensionPath));
	return createFileNode(filePath, dependencyInfo.extensionPath, label, dependencyNodes, dependencyInfo.project, member);
}

function createProjectLabel(project: F2mcProjectInfo): string {
	const loadModuleName = project.loadModule ? path.basename(project.loadModule) : `${project.name}.abs`;
	const projectFileName = project.path ? path.basename(project.path) : `${project.name}.prj`;
	return `${loadModuleName} - "${projectFileName}"`;
}

function createProjectDependencyInfo(project: F2mcProjectInfo, rootPath: string, extensionPath: string): ProjectDependencyInfo {
	const projectRootPath = project.path ? path.dirname(project.path) : rootPath;
	const dependenciesBySourcePath = new Map<string, string[]>();
	const objDirectory = project.directories?.obj;

	if (!objDirectory) {
		return { dependenciesBySourcePath, projectRootPath, extensionPath, project };
	}

	for (const sourcePath of [...project.sourceFiles, ...project.assemblerFiles]) {
		const dependencyPaths = readTpiDependencies(sourcePath, objDirectory, projectRootPath);
		if (dependencyPaths.length > 0) {
			dependenciesBySourcePath.set(normalizePathKey(sourcePath), dependencyPaths);
		}
	}

	return { dependenciesBySourcePath, projectRootPath, extensionPath, project };
}

function createFileMember(filePath: string): F2mcProjectMember {
	return {
		name: path.basename(filePath),
		kind: 'file',
		path: filePath,
		fileType: getMemberFileType(filePath),
		children: []
	};
}

function syncProjectFileLists(project: F2mcProjectInfo): void {
	project.files = collectMemberPaths(project.members);
	project.sourceFiles = collectFilesByTypeInFolder(project.members, SOURCE_FILES_FOLDER_NAME, 'c');
	project.assemblerFiles = collectFilesByTypeInFolder(project.members, SOURCE_FILES_FOLDER_NAME, 'a');
	project.libraryFiles = collectFilesByType(project.members, 'l');
}

function getDropTargetChildren(project: F2mcProjectInfo, targetMember: F2mcProjectMember | undefined): F2mcProjectMember[] {
	if (!targetMember) {
		return project.members;
	}

	return targetMember.kind === 'folder'
		? targetMember.children
		: findOwnerChildren(project.members, targetMember) ?? project.members;
}

function findOwnerChildren(members: F2mcProjectMember[], target: F2mcProjectMember): F2mcProjectMember[] | undefined {
	if (members.includes(target)) {
		return members;
	}

	for (const member of members) {
		const ownerChildren = findOwnerChildren(member.children, target);
		if (ownerChildren) {
			return ownerChildren;
		}
	}

	return undefined;
}

function isDescendantMember(parent: F2mcProjectMember, maybeDescendant: F2mcProjectMember | undefined): boolean {
	if (!maybeDescendant) {
		return false;
	}

	return parent.children.some(child => child === maybeDescendant || isDescendantMember(child, maybeDescendant));
}

function readTpiDependencies(sourcePath: string, objDirectory: string, projectRootPath: string): string[] {
	const tpiPath = path.join(objDirectory, `${path.basename(sourcePath, path.extname(sourcePath))}.tpi`);
	if (!fs.existsSync(tpiPath)) {
		return [];
	}

	const seen = new Set<string>();
	const content = fs.readFileSync(tpiPath, 'utf8');
	return content
		.split(/\r?\n/)
		.map(line => line.trim())
		.filter(Boolean)
		.map(dependencyPath => resolvePath(dependencyPath, projectRootPath))
		.filter(dependencyPath => {
			const key = normalizePathKey(dependencyPath);
			if (seen.has(key)) {
				return false;
			}
			seen.add(key);
			return true;
		});
}

function normalizePathKey(filePath: string): string {
	return path.normalize(filePath).toLowerCase();
}

function getFileTypeIconPath(filePath: string, extensionPath: string): vscode.Uri {
	const iconName = getFileTypeIconName(path.extname(filePath).toLowerCase());
	return vscode.Uri.file(path.join(extensionPath, 'res', 'icon', iconName));
}

function getFolderIconPath(extensionPath: string): vscode.Uri {
	return vscode.Uri.file(path.join(extensionPath, 'res', 'icon', 'filetype_folder.svg'));
}

function getFileTypeIconName(extension: string): string {
	if (['.asm', '.inc', '.a', '.s'].includes(extension)) {
		return 'filetype_asm.svg';
	}

	if (['.abs', '.bin', '.hex', '.mhx', '.s19', '.obj', '.lib', '.rel', '.stk', '.tpi'].includes(extension)) {
		return 'filetype_bin.svg';
	}

	if (extension === '.c') {
		return 'filetype_cs.svg';
	}

	if (extension === '.h') {
		return 'filetype_ch.svg';
	}

	return 'filetype_bin.svg';
}
