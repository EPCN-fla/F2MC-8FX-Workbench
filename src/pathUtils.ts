import * as path from 'node:path';

export function resolvePath(value: string, basePath: string): string {
	if (path.isAbsolute(value)) {
		return path.normalize(value);
	}
	return path.normalize(path.resolve(basePath, value));
}

export function quoteShell(value: string): string {
	return /\s/.test(value) ? `"${value.replace(/"/g, '\\"')}"` : value;
}

export function isSamePath(left: string | undefined, right: string | undefined): boolean {
	return Boolean(left && right && path.normalize(left).toLowerCase() === path.normalize(right).toLowerCase());
}

export function toWorkspaceRelativePath(value: string | undefined, workspaceRootPath: string): string {
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
