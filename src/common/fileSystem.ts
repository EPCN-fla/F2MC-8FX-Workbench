import * as childProcess from 'node:child_process';
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

export function ensureFinalNewline(content: string): string {
	return content.endsWith('\r\n') ? content : `${content}\r\n`;
}

export function convertFileToAnsiEncoding(filePath: string): void {
	const psPath = filePath.replace(/'/g, "''");
	const cmd = `powershell -NoProfile -Command "$c = Get-Content -LiteralPath '${psPath}' -Raw -Encoding UTF8; [System.IO.File]::WriteAllText('${psPath}', $c, [System.Text.Encoding]::Default)"`;
	childProcess.execSync(cmd, { encoding: 'utf8' });
}

const ANSI_WEBNAME_TO_VSCODE_ENCODING: Record<string, string> = {
	'gb2312': 'gb2312',
	'gbk': 'gbk',
	'big5': 'big5',
	'shift_jis': 'shiftjis',
	'euc-jp': 'eucjp',
	'ks_c_5601-1987': 'euckr',
	'windows-1250': 'windows1250',
	'windows-1251': 'windows1251',
	'windows-1252': 'windows1252',
	'windows-1253': 'windows1253',
	'windows-1254': 'windows1254',
	'windows-1255': 'windows1255',
	'windows-1256': 'windows1256',
	'windows-1257': 'windows1257',
	'windows-1258': 'windows1258'
};

export async function getSystemAnsiEncodingLabel(): Promise<string | undefined> {
	const cmd = `powershell -NoProfile -Command "[Console]::OutputEncoding = [System.Text.Encoding]::UTF8; [Console]::Write([System.Text.Encoding]::Default.WebName)"`;
	return new Promise<string | undefined>(resolve => {
		childProcess.exec(cmd, { encoding: 'utf8' }, (error, stdout) => {
			if (error) {
				resolve(undefined);
				return;
			}
			resolve(ANSI_WEBNAME_TO_VSCODE_ENCODING[stdout.trim().toLowerCase()]);
		});
	});
}
