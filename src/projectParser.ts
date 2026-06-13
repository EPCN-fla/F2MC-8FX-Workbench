import * as path from 'node:path';

import { readTextFile } from './fileSystem';
import { resolvePath } from './pathUtils';
import type { F2mcProjectConfig, F2mcProjectDirectories, F2mcProjectInfo, F2mcProjectMember } from './types';

interface ParsedMemberLine {
	fileType: string;
	value: string;
}

export async function parseWspProject(wspPath: string): Promise<F2mcProjectConfig> {
	const rootPath = path.dirname(wspPath);
	const wspContent = await readTextFile(wspPath);
	const activeProjectPath = resolveActiveProjectPath(wspContent, rootPath);
	const projectPaths = resolveProjectPaths(wspContent, rootPath);
	const uniqueProjectPaths = [...new Set([...(activeProjectPath ? [activeProjectPath] : []), ...projectPaths])];
	const projects = uniqueProjectPaths.length > 0
		? await Promise.all(uniqueProjectPaths.map(projectPath => parsePrjProject(projectPath, isSamePath(projectPath, activeProjectPath))))
		: [createFallbackProject(wspPath, true)];

	if (!projects.some(project => project.isActive)) {
		projects[0].isActive = true;
	}

	return {
		wspPath,
		rootPath,
		projects
	};
}

export async function parsePrjProject(prjPath: string, isActive = false): Promise<F2mcProjectInfo> {
	const content = await readTextFile(prjPath);
	const projectRootPath = path.dirname(prjPath);
	const memberSection = readIniSection(content, 'MEMBER');
	const members = orderProjectMembersForTree(parseMemberSection(memberSection, projectRootPath));
	const optionFile = readOptionFile(content, projectRootPath);
	const activeConfiguration = readActiveConfiguration(content);
	const directories = activeConfiguration
		? readConfigurationDirectories(content, activeConfiguration, projectRootPath)
		: undefined;
	const cpuName = activeConfiguration ? readCpuName(content, activeConfiguration) : undefined;
	const loadModule = activeConfiguration ? readLoadModule(content, activeConfiguration, projectRootPath) : undefined;

	return {
		name: path.basename(prjPath, path.extname(prjPath)),
		path: prjPath,
		isActive,
		files: collectMemberPaths(members),
		members,
		optionFile,
		activeConfiguration,
		directories,
		sourceFiles: collectFilesByTypeInFolder(members, 'Source Files', 'c'),
		assemblerFiles: collectFilesByTypeInFolder(members, 'Source Files', 'a'),
		libraryFiles: collectFilesByType(members, 'l'),
		cpuName,
		loadModule
	};
}

function createFallbackProject(wspPath: string, isActive = false): F2mcProjectInfo {
	return {
		name: path.basename(wspPath, path.extname(wspPath)),
		path: wspPath,
		isActive,
		files: [],
		members: [],
		sourceFiles: [],
		assemblerFiles: [],
		libraryFiles: []
	};
}

function resolveActiveProjectPath(wspContent: string, rootPath: string): string | undefined {
	const prjFileSection = readIniSection(wspContent, 'PrjFile');
	const activePrj = readIniValue(prjFileSection, 'ActivePrj');
	if (activePrj) {
		return resolvePath(activePrj, rootPath);
	}

	const firstProject = prjFileSection
		.map(line => /^FILE-\d+\s*=\s*(.+)$/i.exec(line))
		.find((match): match is RegExpExecArray => Boolean(match))?.[1];
	return firstProject ? resolvePath(firstProject, rootPath) : undefined;
}

function resolveProjectPaths(wspContent: string, rootPath: string): string[] {
	return readIniSection(wspContent, 'PrjFile')
		.map(line => /^FILE-\d+\s*=\s*(.+)$/i.exec(line))
		.filter((match): match is RegExpExecArray => Boolean(match))
		.map(match => resolvePath(match[1].trim(), rootPath));
}

function isSamePath(left: string | undefined, right: string | undefined): boolean {
	return Boolean(left && right && path.normalize(left).toLowerCase() === path.normalize(right).toLowerCase());
}

function readOptionFile(content: string, projectRootPath: string): string | undefined {
	const optionFile = readIniValue(readIniSection(content, 'OPTIONFILE'), 'FILE');
	return optionFile ? resolvePath(optionFile, projectRootPath) : undefined;
}

function readActiveConfiguration(content: string): string | undefined {
	return readIniValue(readIniSection(content, 'PrjInfo'), 'Active');
}

function readConfigurationDirectories(content: string, activeConfiguration: string, projectRootPath: string): F2mcProjectDirectories {
	const section = readIniSection(content, `DirInfo-${activeConfiguration}`);
	return {
		config: resolveOptionalDirectory(readIniValue(section, 'CONFIG'), projectRootPath),
		obj: resolveOptionalDirectory(readIniValue(section, 'OBJ'), projectRootPath),
		lst: resolveOptionalDirectory(readIniValue(section, 'LST'), projectRootPath),
		opt: resolveOptionalDirectory(readIniValue(section, 'OPT'), projectRootPath)
	};
}

function resolveOptionalDirectory(value: string | undefined, projectRootPath: string): string | undefined {
	return value ? resolvePath(value, projectRootPath) : undefined;
}

function readCpuName(content: string, activeConfiguration: string): string | undefined {
	return readIniValue(readIniSection(content, `CPUTYPE-${activeConfiguration}`), 'CpuName');
}

function readLoadModule(content: string, activeConfiguration: string, projectRootPath: string): string | undefined {
	const memberLines = readIniSection(content, `MEMBER-${activeConfiguration}`);
	for (const line of memberLines) {
		const match = /^F\d+\s*=\s*\d+\s+m\s+(?:\d+\s+)?(.+)$/i.exec(line.trim());
		if (match) {
			return resolvePath(match[1].trim(), projectRootPath);
		}
	}
	return undefined;
}

function parseMemberSection(lines: string[], projectRootPath: string): F2mcProjectMember[] {
	const roots: F2mcProjectMember[] = [];
	let currentFolder: F2mcProjectMember | undefined;

	for (const line of lines) {
		const member = parseMemberLine(line);
		if (!member) {
			continue;
		}

		if (member.fileType.toLowerCase() === 'f') {
			currentFolder = {
				name: member.value,
				kind: 'folder',
				children: []
			};
			roots.push(currentFolder);
			continue;
		}

		const fileNode: F2mcProjectMember = {
			name: path.basename(member.value),
			kind: 'file',
			path: resolvePath(member.value, projectRootPath),
			fileType: member.fileType.toLowerCase(),
			children: []
		};

		if (currentFolder) {
			currentFolder.children.push(fileNode);
		} else {
			roots.push(fileNode);
		}
	}

	return roots;
}

function parseMemberLine(line: string): ParsedMemberLine | undefined {
	const match = /^F\d+\s*=\s*\d+\s+([A-Za-z])\s+(.+)$/i.exec(line.trim());
	if (!match) {
		return undefined;
	}

	return {
		fileType: match[1],
		value: match[2].trim()
	};
}

function orderProjectMembersForTree(members: F2mcProjectMember[]): F2mcProjectMember[] {
	return [
		...members.filter(member => member.kind === 'folder'),
		...members.filter(member => member.kind === 'file')
	];
}

function collectFilesByTypeInFolder(members: F2mcProjectMember[], folderName: string, fileType: string): string[] {
	const folder = members.find(member => member.kind === 'folder' && member.name.toLowerCase() === folderName.toLowerCase());
	return folder ? collectFilesByType(folder.children, fileType) : [];
}

function collectFilesByType(members: F2mcProjectMember[], fileType: string): string[] {
	return collectMemberPaths(members, member => member.kind === 'file' && member.fileType === fileType);
}

function collectMemberPaths(members: F2mcProjectMember[], accept?: (member: F2mcProjectMember) => boolean): string[] {
	const files: string[] = [];
	for (const member of members) {
		if (member.kind === 'file' && member.path && (!accept || accept(member))) {
			files.push(member.path);
		}
		files.push(...collectMemberPaths(member.children, accept));
	}
	return files;
}

function readIniSection(content: string, sectionName: string): string[] {
	const lines = content.split(/\r?\n/);
	const target = `[${sectionName.toLowerCase()}]`;
	const sectionLines: string[] = [];
	let inSection = false;

	for (const rawLine of lines) {
		const line = rawLine.trim();
		if (!line) {
			continue;
		}

		if (/^\[[^\]]+\]$/.test(line)) {
			if (inSection) {
				break;
			}
			inSection = line.toLowerCase() === target;
			continue;
		}

		if (inSection) {
			sectionLines.push(line);
		}
	}

	return sectionLines;
}

function readIniValue(lines: string[], key: string): string | undefined {
	const pattern = new RegExp(`^${escapeRegExp(key)}\\s*=\\s*(.+)$`, 'i');
	for (const line of lines) {
		const match = pattern.exec(line);
		if (match) {
			return match[1].trim();
		}
	}
	return undefined;
}

function escapeRegExp(value: string): string {
	return value.replace(/[.*+?^${}()|[\]\\]/g, '\\$&');
}
