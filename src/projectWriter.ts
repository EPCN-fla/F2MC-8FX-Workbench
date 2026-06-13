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
	const nextContent = project.activeConfiguration && project.directories
		? replaceIniSection(dirInfoContent, `DirInfo-${project.activeConfiguration}`, createConfigurationDirInfoLines(project, projectRootPath))
		: dirInfoContent;
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
