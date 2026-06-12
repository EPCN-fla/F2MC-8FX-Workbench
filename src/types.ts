export type BuildKind = 'build' | 'clean' | 'download';

export type F2mcProjectMemberKind = 'folder' | 'file';

export interface F2mcProjectConfig {
	wspPath: string;
	rootPath: string;
	workspaceFile?: string;
	projects: F2mcProjectInfo[];
}

export interface F2mcProjectInfo {
	name: string;
	path?: string;
	files: string[];
	members: F2mcProjectMember[];
	optionFile?: string;
	activeConfiguration?: string;
	directories?: F2mcProjectDirectories;
	sourceFiles: string[];
	assemblerFiles: string[];
	libraryFiles: string[];
	cpuName?: string;
	loadModule?: string;
}

export interface F2mcProjectDirectories {
	config?: string;
	obj?: string;
	lst?: string;
	opt?: string;
}

export interface F2mcProjectMember {
	name: string;
	kind: F2mcProjectMemberKind;
	path?: string;
	fileType?: string;
	children: F2mcProjectMember[];
}
