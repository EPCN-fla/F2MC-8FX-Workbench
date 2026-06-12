import * as path from 'node:path';

import * as vscode from 'vscode';

export async function readTextFile(filePath: string): Promise<string> {
	const bytes = await vscode.workspace.fs.readFile(vscode.Uri.file(filePath));
	return Buffer.from(bytes).toString('utf8');
}

export async function writeTextFile(filePath: string, content: string): Promise<void> {
	await vscode.workspace.fs.createDirectory(vscode.Uri.file(path.dirname(filePath)));
	await vscode.workspace.fs.writeFile(vscode.Uri.file(filePath), Buffer.from(content, 'utf8'));
}

export async function writeJsonFile(filePath: string, value: unknown): Promise<void> {
	const content = `${JSON.stringify(value, null, '\t')}\n`;
	await writeTextFile(filePath, content);
}
