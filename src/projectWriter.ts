import * as path from 'node:path';

import { readTextFile, writeTextFile } from './fileSystem';
import type { F2mcProjectConfig, F2mcProjectInfo, F2mcProjectMember } from './types';

export async function saveProjectFiles(config: F2mcProjectConfig): Promise<void> {
	await Promise.all(config.projects.map(project => saveProjectFile(project)));
	await saveWorkspaceFile(config);
}

async function saveProjectFile(project: F2mcProjectInfo): Promise<void> {
	if (!project.path) {
		return;
	}

	const projectRootPath = path.dirname(project.path);
	const content = await readTextFile(project.path);
	const memberContent = replaceIniSection(content, 'MEMBER', createMemberSectionLines(project.members, projectRootPath));
	const dirInfoContent = replaceIniSection(memberContent, 'DirInfo', [`PRJ=${ensureTrailingBackslash(projectRootPath)}`]);
	const configurationContent = project.activeConfiguration && project.directories
		? replaceIniSection(dirInfoContent, `DirInfo-${project.activeConfiguration}`, createConfigurationDirInfoLines(project, projectRootPath))
		: dirInfoContent;
	const cpuContent = project.activeConfiguration && project.cpuName
		? replaceCpuNameInConfiguration(configurationContent, project)
		: configurationContent;
	const nextContent = project.activeConfiguration && project.loadModule
		? replaceLoadModuleInConfiguration(cpuContent, project, projectRootPath)
		: cpuContent;
	await writeTextFile(project.path, nextContent);
}

async function saveWorkspaceFile(config: F2mcProjectConfig): Promise<void> {
	const content = await readTextFile(config.wspPath);
	const activeProject = config.projects.find(project => project.isActive && project.path) ?? config.projects.find(project => project.path);
	if (!activeProject?.path) {
		return;
	}

	const relativeActiveProjectPath = toProjectRelativePath(activeProject.path, config.rootPath);
	const projectLines = config.projects
		.filter(project => project.path)
		.map((project, index) => `FILE-${index}=${toProjectRelativePath(project.path!, config.rootPath)}`);
	const sectionLines = [
		`Count=${projectLines.length}`,
		...projectLines,
		`ActivePrj=${relativeActiveProjectPath}`
	];
	const prjFileContent = replaceIniSection(content, 'PrjFile', sectionLines);
	const nextContent = replaceIniSection(prjFileContent, 'DirInfo', [`WSP=${ensureTrailingBackslash(config.rootPath)}`]);
	await writeTextFile(config.wspPath, nextContent);
}

function replaceCpuNameInConfiguration(content: string, project: F2mcProjectInfo): string {
	if (!project.activeConfiguration || !project.cpuName) {
		return content;
	}

	const sectionName = `CPUTYPE-${project.activeConfiguration}`;
	const sectionLines = readIniSection(content, sectionName);
	let didReplace = false;
	const nextLines = sectionLines.map(line => {
		if (!/^CpuName\s*=/i.test(line.trim())) {
			return line;
		}

		didReplace = true;
		return `CpuName=${project.cpuName}`;
	});
	if (!didReplace) {
		nextLines.push(`CpuName=${project.cpuName}`);
	}

	return replaceIniSection(content, sectionName, nextLines);
}

function replaceLoadModuleInConfiguration(content: string, project: F2mcProjectInfo, projectRootPath: string): string {
	if (!project.activeConfiguration || !project.loadModule) {
		return content;
	}

	const sectionName = `MEMBER-${project.activeConfiguration}`;
	const sectionLines = readIniSection(content, sectionName);
	let didReplace = false;
	const loadModulePath = toProjectRelativePath(project.loadModule, projectRootPath);
	const nextLines = sectionLines.map(line => {
		const match = /^(F\d+\s*=\s*\d+\s+m\s+(?:\d+\s+)?)(.+)$/i.exec(line.trim());
		if (!match) {
			return line;
		}

		didReplace = true;
		return `${match[1]}${loadModulePath}`;
	});

	return didReplace ? replaceIniSection(content, sectionName, nextLines) : content;
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

function replaceIniSection(content: string, sectionName: string, sectionLines: string[]): string {
	const lines = content.split(/\r?\n/);
	const sectionHeader = `[${sectionName}]`;
	const sectionStart = lines.findIndex(line => line.trim().toLowerCase() === sectionHeader.toLowerCase());

	if (sectionStart < 0) {
		const separator = content.endsWith('\n') || content.length === 0 ? '' : '\r\n';
		return ensureFinalNewline(`${content}${separator}${sectionHeader}\r\n${sectionLines.join('\r\n')}\r\n`);
	}

	let sectionEnd = lines.length;
	for (let index = sectionStart + 1; index < lines.length; index += 1) {
		if (/^\s*\[.+\]\s*$/.test(lines[index])) {
			sectionEnd = index;
			break;
		}
	}

	const nextSectionLines = lines.slice(sectionEnd);
	const nextLines = [
		...lines.slice(0, sectionStart + 1),
		...sectionLines,
		'',
		...dropLeadingEmptyLines(nextSectionLines)
	];
	return ensureFinalNewline(nextLines.join('\r\n'));
}

function dropLeadingEmptyLines(lines: string[]): string[] {
	let firstContentIndex = 0;
	while (firstContentIndex < lines.length && lines[firstContentIndex].trim() === '') {
		firstContentIndex += 1;
	}
	return lines.slice(firstContentIndex);
}

function ensureFinalNewline(content: string): string {
	return content.endsWith('\r\n') ? content : `${content}\r\n`;
}

function createMemberSectionLines(members: F2mcProjectMember[], projectRootPath: string): string[] {
	const memberLines: string[] = [];
	let index = 1;
	const orderedMembers = orderMembersForProjectFile(members);

	for (const member of orderedMembers) {
		if (member.kind === 'folder') {
			memberLines.push(`F${index}=0 f ${member.name}`);
			index += 1;
			for (const child of member.children) {
				if (child.kind === 'file' && child.path) {
					memberLines.push(`F${index}=0 ${child.fileType ?? getFileType(child.path)} ${toProjectRelativePath(child.path, projectRootPath)}`);
					index += 1;
				}
			}
			continue;
		}

		if (member.path) {
			memberLines.push(`F${index}=0 ${member.fileType ?? getFileType(member.path)} ${toProjectRelativePath(member.path, projectRootPath)}`);
			index += 1;
		}
	}

	return [`F0=${memberLines.length}`, ...memberLines];
}

function orderMembersForProjectFile(members: F2mcProjectMember[]): F2mcProjectMember[] {
	return [
		...members.filter(member => member.kind === 'file'),
		...members.filter(member => member.kind === 'folder')
	];
}

function createConfigurationDirInfoLines(project: F2mcProjectInfo, projectRootPath: string): string[] {
	return [
		`CONFIG=${toProjectRelativeDirectory(project.directories?.config, projectRootPath)}`,
		`OBJ=${toProjectRelativeDirectory(project.directories?.obj, projectRootPath)}`,
		`LST=${toProjectRelativeDirectory(project.directories?.lst, projectRootPath)}`,
		`OPT=${toProjectRelativeDirectory(project.directories?.opt, projectRootPath)}`
	];
}

function toProjectRelativeDirectory(directoryPath: string | undefined, basePath: string): string {
	if (!directoryPath) {
		return '';
	}

	return ensureTrailingBackslash(toProjectRelativePath(directoryPath, basePath));
}

function toProjectRelativePath(filePath: string, basePath: string): string {
	const relativePath = path.relative(basePath, filePath);
	return relativePath && !relativePath.startsWith('..') && !path.isAbsolute(relativePath)
		? relativePath.replace(/\\/g, '\\')
		: filePath;
}

function ensureTrailingBackslash(value: string): string {
	return value.endsWith('\\') || value.endsWith('/') ? value : `${value}\\`;
}

function getFileType(filePath: string): string {
	const extension = path.extname(filePath).toLowerCase();
	if (extension === '.asm') {
		return 'a';
	}
	if (extension === '.lib') {
		return 'l';
	}
	return 'c';
}
