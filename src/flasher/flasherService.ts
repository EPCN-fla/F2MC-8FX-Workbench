// 烧录分发器：按编程器设置 programmerType 选择烧录器实现。
// 泽兆（串口）见 zeztek/zeztekFlasher.ts；F2MC-LINK（CMSIS-DAP HID）见 f2mcLink/f2mcLinkFlasher.ts。

import * as vscode from 'vscode';

import type { BuildLayout } from '../build/buildRunner';
import { getProgrammerSettings } from '../common/programmerSettings';
import { runF2mcLinkDownload, runF2mcLinkErase } from './f2mcLink/f2mcLinkFlasher';
import { runZeztekDownload } from './zeztek/zeztekFlasher';

export async function runFlashDownload(layout: BuildLayout | undefined, outputChannel: vscode.OutputChannel, extensionPath: string): Promise<void> {
	if (getProgrammerSettings().programmerType === 'f2mcLink') {
		await runF2mcLinkDownload(layout, outputChannel, extensionPath);
		return;
	}
	await runZeztekDownload(layout, outputChannel);
}

export async function runFlashErase(outputChannel: vscode.OutputChannel): Promise<void> {
	if (getProgrammerSettings().programmerType === 'f2mcLink') {
		await runF2mcLinkErase(outputChannel);
		return;
	}
	void vscode.window.showWarningMessage('泽兆烧录器暂不支持单独擦除（烧录流程已包含自动擦除）。');
}
