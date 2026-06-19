import * as path from 'node:path';

import type { F2mcProjectMember } from './types';

export function orderProjectMembersForTree(members: F2mcProjectMember[]): F2mcProjectMember[] {
	return [
		...members.filter(member => member.kind === 'folder'),
		...members.filter(member => member.kind === 'file')
	];
}

export function getMemberFileType(filePath: string): string {
	const extension = path.extname(filePath).toLowerCase();
	if (extension === '.asm') {
		return 'a';
	}
	if (extension === '.lib') {
		return 'l';
	}
	return 'c';
}

export function collectFilesByTypeInFolder(members: F2mcProjectMember[], folderName: string, fileType: string): string[] {
	const folder = members.find(member => member.kind === 'folder' && member.name.toLowerCase() === folderName.toLowerCase());
	return folder ? collectFilesByType(folder.children, fileType) : [];
}

export function collectFilesByType(members: F2mcProjectMember[], fileType: string): string[] {
	return collectMemberPaths(members, member => member.kind === 'file' && member.fileType === fileType);
}

export function collectMemberPaths(members: F2mcProjectMember[], accept?: (member: F2mcProjectMember) => boolean): string[] {
	const files: string[] = [];
	for (const member of members) {
		if (member.kind === 'file' && member.path && (!accept || accept(member))) {
			files.push(member.path);
		}
		files.push(...collectMemberPaths(member.children, accept));
	}
	return files;
}
