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
