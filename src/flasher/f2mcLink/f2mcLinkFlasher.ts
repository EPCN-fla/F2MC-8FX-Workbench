// F2MC-LINK 自制编程器一键烧录：原生实现 CMSIS-DAP v1(HID) + vendor 协议 + 烧录流程。
// 移植自 F2MC-8FX-Programmer 上位机（f2mc-core），不依赖 f2mc-programmer-cli。
// 烧录流程：PING → ENTER_PGM → 整片擦除 → FLASH_INIT → CR 校准检查 →
// 分块写入(≤512B) → 读回校验(跳过 0xFFBB/BC/BD) → [写安全位] → 复位运行。
// 使用约束：编程器 USB 免驱即插即用；目标板供电由编程器自动控制（通流 ≤50mA，仅裸片烧录）。

import * as fs from 'node:fs';
import * as path from 'node:path';

import * as vscode from 'vscode';

import type { BuildLayout } from '../../build/buildRunner';
import { getProgrammerSettings } from '../../common/programmerSettings';
import { findChipByName, parseChipsCsv, rangesDesc } from './chipdef';
import { ProgError } from './errors';
import { program, STAGE_LABELS, type CancelToken, type FlowEvent, type FlowReport } from './flow';
import { hexFormatLabel, parseHexImage, totalBytes } from './hexfile';
import { describeChannel, enumerateHidChannels, HidTransport, type F2mcLinkChannelInfo } from './hidTransport';
import { F2mcLinkClient } from './proto';

// 镜像按内容嗅探 Intel HEX 与 Motorola S-record，覆盖编译器全部转换器输出格式。
const IMAGE_EXTENSIONS = ['.mhx', '.s19', '.hex', '.ihx', '.ehx'];

async function pickChannel(): Promise<F2mcLinkChannelInfo | undefined> {
	let channels: F2mcLinkChannelInfo[];
	try {
		channels = await enumerateHidChannels();
	} catch (error) {
		const message = error instanceof Error ? error.message : String(error);
		void vscode.window.showErrorMessage(`枚举 USB HID 设备失败：${message}`);
		return undefined;
	}

	if (channels.length === 0) {
		void vscode.window.showWarningMessage('未发现 F2MC-LINK 编程器（CMSIS-DAP HID 设备），请确认编程器已通过 USB 连接。');
		return undefined;
	}
	if (channels.length === 1) {
		return channels[0];
	}

	const picked = await vscode.window.showQuickPick(channels.map(channel => ({
		label: channel.product,
		description: describeChannel(channel),
		channel
	})), {
		title: '检测到多个 F2MC-LINK 编程器，请选择'
	});
	return picked?.channel;
}

export async function runF2mcLinkDownload(layout: BuildLayout | undefined, outputChannel: vscode.OutputChannel, extensionPath: string): Promise<void> {
	if (!layout) {
		void vscode.window.showWarningMessage('工程配置不完整，无法确定烧录文件。');
		return;
	}

	const flashPath = layout.convertedModulePath;
	const extension = path.extname(flashPath).toLowerCase();
	if (!IMAGE_EXTENSIONS.includes(extension)) {
		void vscode.window.showWarningMessage(`F2MC-LINK 支持 Intel HEX 与 S-record 文件（${extension || '(无扩展名)'} 不在支持列表），请重新编译生成 .mhx/.hex 等格式。`);
		return;
	}
	if (!fs.existsSync(flashPath)) {
		void vscode.window.showWarningMessage(`未找到烧录文件 ${path.basename(flashPath)}，请先点击“编译”生成烧录产物。`);
		return;
	}

	const cpuName = layout.project.cpuName;
	if (!cpuName) {
		void vscode.window.showWarningMessage('未选择芯片型号，请先在插件“设置”视图中选择芯片。');
		return;
	}

	const log = (message: string): void => {
		outputChannel.appendLine(`[flash] ${message}`);
	};

	let chipTable;
	try {
		chipTable = parseChipsCsv(await fs.promises.readFile(path.join(extensionPath, 'res', '896.csv'), 'latin1'));
	} catch (error) {
		const message = error instanceof Error ? error.message : String(error);
		void vscode.window.showErrorMessage(`加载芯片型号库失败：${message}`);
		return;
	}
	const chip = findChipByName(chipTable, cpuName);
	if (!chip) {
		void vscode.window.showWarningMessage(`型号 ${cpuName} 不在 F2MC-8FX 型号库中（${chipTable.length} 款），请检查工程芯片选择。`);
		return;
	}
	if (chip.fram) {
		void vscode.window.showWarningMessage(`${chip.name} 为 FRAM/掩膜器件，New8FX 串行编程不适用，无法烧录。`);
		return;
	}

	let report: FlowReport | undefined;
	try {
		await vscode.window.withProgress({
			location: vscode.ProgressLocation.Notification,
			title: 'F2MC-LINK 烧录',
			cancellable: true
		}, async (progress, token) => {
			log(`文件: ${flashPath}`);
			log(`型号: ${chip.name} Flash ${chip.flashBytes / 1024}KB（${rangesDesc(chip)}）`);
			const image = parseHexImage((await fs.promises.readFile(flashPath)).toString('latin1'), chip);
			log(`镜像: ${hexFormatLabel(image.format)}，${totalBytes(image)} 字节，${image.segments.length} 个区间`);
			for (const warning of image.warnings) {
				log(`警告: ${warning}`);
			}

			progress.report({ message: '连接编程器…' });
			const channel = await pickChannel();
			if (!channel) {
				return; // pickChannel 已提示原因（未发现设备/用户取消选择）
			}
			log(`通道: ${describeChannel(channel)}`);

			const settings = getProgrammerSettings();
			const writeSecure = settings.f2mcLinkSecure;
			const resetAfter = settings.f2mcLinkReset;

			const cancel: CancelToken = { cancelled: false };
			const cancellation = token.onCancellationRequested(() => {
				cancel.cancelled = true;
			});
			const transport = new HidTransport(channel);
			transport.setCancel(cancel);
			const client = new F2mcLinkClient(transport);
			try {
				const onEvent = (event: FlowEvent): void => {
					if (event.type === 'stage') {
						progress.report({ message: `${STAGE_LABELS[event.stage]}…` });
						log(`=== ${STAGE_LABELS[event.stage]} ===`);
					} else if (event.type === 'progress') {
						progress.report({ message: `${STAGE_LABELS[event.stage]} ${event.done}/${event.total} 字节…` });
					} else if (event.type === 'warn') {
						log(`警告: ${event.message}`);
					} else {
						log(event.message);
					}
				};
				report = await program(client, image, { writeSecure, resetAfter }, onEvent, cancel);
			} finally {
				cancellation.dispose();
				try {
					await client.disconnect();
				} catch {
					// 断开通知失败不阻塞关闭
				}
				transport.close();
			}
		});
		if (report) {
			log(`烧录成功：写入 ${report.bytesWritten} 字节，校验 ${report.bytesVerified} 字节，用时 ${report.elapsedSecs.toFixed(1)} s`);
			const unlockNote = report.unlocked ? '（曾加安全锁，已整片擦除解锁）' : '';
			void vscode.window.showInformationMessage(`烧录成功：${path.basename(flashPath)}${unlockNote}（写入 ${report.bytesWritten} 字节，用时 ${report.elapsedSecs.toFixed(1)} s）。`);
		}
	} catch (error) {
		if (error instanceof ProgError && error.kind === 'cancelled') {
			outputChannel.appendLine('[flash] 已取消烧录');
			return;
		}
		const message = error instanceof Error ? error.message : String(error);
		outputChannel.appendLine(`[flash] 烧录失败: ${message}`);
		if (error instanceof Error && error.stack) {
			outputChannel.appendLine(error.stack);
		}
		void vscode.window.showErrorMessage(`烧录失败：${message}`);
	}
}
