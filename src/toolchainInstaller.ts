import * as childProcess from 'node:child_process';
import * as crypto from 'node:crypto';
import * as fs from 'node:fs';
import * as https from 'node:https';
import * as os from 'node:os';
import * as path from 'node:path';
import * as util from 'node:util';

import * as vscode from 'vscode';

import { findCompilerBinDirectory, findMissingCompilerTools } from './toolchain';

interface ToolchainPackage {
	version: string;
	packageUrl: string;
	sha256: string;
}

const TOOLCHAIN_PACKAGES: ToolchainPackage[] = [
	{
		version: 'V30L14',
		packageUrl: 'https://raw.githubusercontent.com/EPCN-fla/F2MC-8FX-Workbench/main/toolchain/V30L14.tar.gz',
		sha256: '3d354526838a5d9ef4ef01eccfaf54c391a94eeaebdfc12f6a8063c23e589cc65'
	},
	{
		version: 'V30L15',
		packageUrl: 'https://raw.githubusercontent.com/EPCN-fla/F2MC-8FX-Workbench/main/toolchain/V30L15.tar.gz',
		sha256: '0b655d035e77483e56cc2640fe8db719f63e8cbd328654f20104bae627f265ef'
	}
];

const execFile = util.promisify(childProcess.execFile);

function getTarExecutable(): string {
	return path.join(process.env.SystemRoot ?? 'C:\\Windows', 'System32', 'tar.exe');
}

export function getToolchainInstallRoot(): string {
	return path.join(os.homedir(), '.f2mc-8fx-wb', 'toolchain');
}

export function getToolchainVersionDirectory(version: string): string {
	return path.join(getToolchainInstallRoot(), version);
}

export function isToolchainInstalled(version: string): boolean {
	const binDirectory = path.join(getToolchainVersionDirectory(version), 'Bin');
	return fs.existsSync(binDirectory) && findMissingCompilerTools(binDirectory).length === 0;
}

export async function pickAndSetupToolchain(): Promise<void> {
	interface ToolchainPickItem extends vscode.QuickPickItem {
		packageInfo?: ToolchainPackage;
	}

	const items: ToolchainPickItem[] = [
		...TOOLCHAIN_PACKAGES.map(packageInfo => ({
			label: packageInfo.version,
			description: isToolchainInstalled(packageInfo.version)
				? '🗸 已安装（点击切换到此版本）'
				: '🗴 未安装（点击下载安装）',
			packageInfo
		})),
		{
			label: '浏览本地目录…',
			description: '使用本机已安装的 SOFTUNE 目录'
		}
	];

	const picked = await vscode.window.showQuickPick(items, {
		title: '工具链安装',
		placeHolder: '选择要使用的工具链版本'
	});
	if (!picked) {
		return;
	}

	if (!picked.packageInfo) {
		await browseLocalToolchain();
		return;
	}

	const versionDirectory = getToolchainVersionDirectory(picked.packageInfo.version);
	if (!isToolchainInstalled(picked.packageInfo.version)) {
		const installed = await downloadAndInstallToolchain(picked.packageInfo);
		if (!installed) {
			return;
		}
	}

	await applyCompilerPath(versionDirectory);
}

async function browseLocalToolchain(): Promise<void> {
	const selected = await vscode.window.showOpenDialog({
		canSelectFiles: false,
		canSelectFolders: true,
		canSelectMany: false,
		title: '选择 SOFTUNE 编译器目录（Bin 目录或其上一级）'
	});
	if (!selected || selected.length === 0) {
		return;
	}

	const directory = selected[0].fsPath;
	const binDirectory = findCompilerBinDirectory(directory);
	if (!binDirectory) {
		void vscode.window.showErrorMessage(`所选目录未找到编译器工具：${directory}`);
		return;
	}

	const missingTools = findMissingCompilerTools(binDirectory);
	if (missingTools.length > 0) {
		void vscode.window.showErrorMessage(`所选目录缺少工具: ${missingTools.join(', ')}（${binDirectory}）`);
		return;
	}

	await applyCompilerPath(directory);
}

async function applyCompilerPath(directory: string): Promise<void> {
	await vscode.workspace.getConfiguration('f2mc-8fx-workbench').update('compilerPath', directory, vscode.ConfigurationTarget.Global);
	void vscode.window.showInformationMessage(`编译器路径已设置为：${directory}`);
}

async function downloadAndInstallToolchain(packageInfo: ToolchainPackage): Promise<boolean> {
	const installRoot = getToolchainInstallRoot();
	const packagePath = path.join(installRoot, `${path.basename(packageInfo.packageUrl)}.download`);
	try {
		await vscode.window.withProgress({
			location: vscode.ProgressLocation.Notification,
			title: `正在安装 ${packageInfo.version} 工具链…`,
			cancellable: false
		}, async progress => {
			await fs.promises.mkdir(installRoot, { recursive: true });
			progress.report({ message: '正在下载…' });
			await downloadFile(packageInfo.packageUrl, packagePath, progress);
			progress.report({ message: '正在校验…' });
			await verifyPackageHash(packagePath, packageInfo.sha256);
			progress.report({ message: '正在解压…' });
			await extractPackage(packagePath, installRoot);
			await fs.promises.rm(packagePath, { force: true });
		});
	} catch (error) {
		await fs.promises.rm(packagePath, { force: true }).catch(() => undefined);
		const message = error instanceof Error ? error.message : String(error);
		void vscode.window.showErrorMessage(`下载安装 ${packageInfo.version} 失败：${message}。可手动下载 tar.gz 解压到 ${installRoot}`);
		return false;
	}

	if (!isToolchainInstalled(packageInfo.version)) {
		void vscode.window.showErrorMessage(`${packageInfo.version} 解压后工具不完整，请检查安装包内容。`);
		return false;
	}

	return true;
}

async function verifyPackageHash(packagePath: string, expectedSha256: string): Promise<void> {
	const content = await fs.promises.readFile(packagePath);
	const actual = crypto.createHash('sha256').update(content).digest('hex');
	if (actual.toLowerCase() !== expectedSha256.toLowerCase()) {
		throw new Error(`安装包校验失败（SHA256 不匹配，期望 ${expectedSha256.slice(0, 12)}… 实际 ${actual.slice(0, 12)}…）`);
	}
}

async function extractPackage(packagePath: string, installRoot: string): Promise<void> {
	const tar = getTarExecutable();
	const { stdout } = await execFile(tar, ['-tzf', packagePath]);
	const unsafeEntry = stdout.split(/\r?\n/).map(line => line.trim()).filter(Boolean)
		.find(entry => /(^|[\\/])\.\.([\\/]|$)/.test(entry) || /^([a-zA-Z]:[\\/]|[\\/])/.test(entry));
	if (unsafeEntry) {
		throw new Error(`安装包包含非法条目：${unsafeEntry}`);
	}

	await execFile(tar, ['-xzf', packagePath, '-C', installRoot]);
}

async function downloadFile(
	url: string,
	destination: string,
	progress: vscode.Progress<{ message?: string; increment?: number }>,
	redirectCount = 0
): Promise<void> {
	return new Promise<void>((resolve, reject) => {
		const request = https.get(url, response => {
			const statusCode = response.statusCode ?? 0;
			if (statusCode >= 300 && statusCode < 400 && response.headers.location) {
				response.resume();
				if (redirectCount >= 5) {
					reject(new Error('重定向次数过多'));
					return;
				}
				resolve(downloadFile(response.headers.location, destination, progress, redirectCount + 1));
				return;
			}

			if (statusCode !== 200) {
				response.resume();
				reject(new Error(`HTTP ${statusCode}`));
				return;
			}

			const total = Number(response.headers['content-length'] ?? 0);
			let received = 0;
			let reported = 0;
			const stream = fs.createWriteStream(destination);
			response.on('data', (chunk: Buffer) => {
				received += chunk.length;
				if (total > 0) {
					const percent = Math.floor((received / total) * 100);
					if (percent > reported) {
						progress.report({ increment: percent - reported });
						reported = percent;
					}
				}
			});
			response.pipe(stream);
			stream.on('finish', () => {
				stream.close(error => error ? reject(error) : resolve());
			});
			stream.on('error', reject);
		});
		request.on('error', reject);
	});
}
