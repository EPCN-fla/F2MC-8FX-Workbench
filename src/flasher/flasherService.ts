// 烧录分发器：按烧录器类型分发到具体实现（当前为泽兆串口烧录器，见 zeztek/zeztekFlasher.ts）。

import * as vscode from 'vscode';

import type { BuildLayout } from '../build/buildRunner';
import { runZeztekDownload } from './zeztek/zeztekFlasher';

export async function runFlashDownload(layout: BuildLayout | undefined, outputChannel: vscode.OutputChannel): Promise<void> {
	await runZeztekDownload(layout, outputChannel);
}
