// 泽兆烧录器一键烧录：解析工程产物 → 选串口 → 上传 → 一键擦除+编程+校验。
// 使用约束：目标板必须断电（由烧录器盒子控制上电）；烧录过程不可中断。

import * as fs from 'node:fs';
import * as path from 'node:path';

import * as vscode from 'vscode';
import { SerialPort } from 'serialport';

import type { BuildLayout } from '../../build/buildRunner';
import { BUILTIN_MCUS, blockAddrs, findMcuByCpuName, totalKb } from './mcuTable';
import { Mode, Power, PROGRAMMER_BAUD, ProtocolError, ZeztekProgrammer, dataBlock, type ByteStream } from './protocol';
import { buildImage, imageChecksum, parseS19, validateRange } from './srecord';

const CONFIG_SECTION = 'f2mc-8fx-workbench';

// 串口流要求：DTR 全程保持低电平（持续拉高时烧录器完全无应答；RTS 由绑定默认禁用，无影响）。
// serialport 绑定默认 hupcl=true，会在打开时拉高 DTR——必须显式传 hupcl:false 覆盖。
// 该参数未公开在类型声明里，但 Windows 绑定实现会读取它（@serialport/bindings-cpp win32.js 默认对象）。
function createSerialStream(portName: string, log: (message: string) => void): ByteStream {
	const openOptions = {
		path: portName,
		baudRate: PROGRAMMER_BAUD,
		dataBits: 8,
		parity: 'none' as const,
		stopBits: 1,
		hupcl: false,
		autoOpen: false
	};
	const port = new SerialPort(openOptions as ConstructorParameters<typeof SerialPort>[0]);
	port.on('error', error => log(`串口错误: ${error.message}`));
	return {
		open: () => new Promise<void>((resolve, reject) => {
			port.open(error => {
				if (error) {
					reject(new ProtocolError(`打开串口 ${portName} 失败：${error.message}`));
					return;
				}
				resolve();
			});
		}),
		write: data => new Promise<void>((resolve, reject) => {
			port.write(data, error => {
				if (error) {
					reject(new ProtocolError(`串口写入失败：${error.message}`));
					return;
				}
				port.drain(drainError => {
					if (drainError) {
						reject(new ProtocolError(`串口写入失败：${drainError.message}`));
						return;
					}
					resolve();
				});
			});
		}),
		onData: callback => port.on('data', chunk => callback(Buffer.from(chunk))),
		close: () => new Promise<void>(resolve => port.close(() => resolve()))
	};
}

// 设置命令必须收到 0x99。盒子完成一次烧录后会话保持"武装"，期间设置命令被静默忽略；
// 实测该状态仅能通过给烧录器断电重新上电可靠解除（原版上位机连续烧录同样需要重新上电）。
async function setupProgrammer(
	dev: ZeztekProgrammer,
	portName: string,
	mode: number,
	power: number,
	progress: vscode.Progress<{ message?: string }>,
	token: vscode.CancellationToken,
	log: (message: string) => void
): Promise<void> {
	const tryOnce = async (): Promise<boolean> => {
		await dev.open(createSerialStream(portName, log));
		try {
			await dev.setup(mode, power);
			log('设置命令已确认（0x99）');
			return true;
		} catch (error) {
			await dev.close();
			if (!(error instanceof ProtocolError) || error.status !== undefined) {
				throw error;
			}
			log('设置命令无响应（烧录器残留上次会话）');
			return false;
		}
	};

	if (await tryOnce()) {
		return;
	}

	const replug = '已重新上电，重试';
	const autoWait = '自动等待（每 60 秒探测，最长 10 分钟）';
	let strategy: string | undefined = replug;
	for (let round = 1; ; round++) {
		if (token.isCancellationRequested) {
			throw new ProtocolError('已取消烧录');
		}
		if (strategy === replug) {
			strategy = await vscode.window.showWarningMessage(
				'烧录器未响应设置命令（残留上次烧录会话）。\n请拔掉烧录器 USB 等 3 秒后重新插入，然后点击重试。',
				{ modal: true }, replug, autoWait);
		} else {
			progress.report({ message: `等待烧录器会话解除（每 60 秒探测，第 ${round} 轮）…` });
			log(`自动等待模式：60 秒后探测（第 ${round} 轮）`);
			await new Promise(resolve => setTimeout(resolve, 60_000));
		}
		if (!strategy) {
			throw new ProtocolError('已取消烧录');
		}
		if (await tryOnce()) {
			return;
		}
		if (round >= 10) {
			throw new ProtocolError('烧录器多次未响应设置命令，请检查 USB 连接后断电重新上电再试');
		}
	}
}

async function resolveProgrammerPort(outputChannel: vscode.OutputChannel): Promise<string | undefined> {
	const configuration = vscode.workspace.getConfiguration(CONFIG_SECTION);
	const saved = (configuration.get<string>('programmerPort') ?? '').trim();
	let ports;
	try {
		ports = await SerialPort.list();
	} catch (error) {
		const message = error instanceof Error ? error.message : String(error);
		void vscode.window.showErrorMessage(`枚举串口失败：${message}`);
		return undefined;
	}

	const normalize = (value: string): string => value.toUpperCase();
	if (saved && ports.some(info => normalize(info.path) === normalize(saved))) {
		outputChannel.appendLine(`[flash] 使用已配置串口: ${saved}`);
		return saved;
	}

	if (ports.length === 0) {
		void vscode.window.showWarningMessage('未发现串口设备，请确认烧录器已通过 USB 连接并安装驱动（CP210x）。');
		return undefined;
	}

	const picked = await vscode.window.showQuickPick(ports.map(info => ({
		label: info.path,
		description: info.manufacturer ?? undefined
	})), {
		title: '选择烧录器串口',
		placeHolder: saved || '泽兆烧录器使用 CP210x USB 串口（如 COM8）'
	});
	if (!picked) {
		return undefined;
	}
	await configuration.update('programmerPort', picked.label, vscode.ConfigurationTarget.Global);
	outputChannel.appendLine(`[flash] 已记住烧录器串口: ${picked.label}（可在设置 f2mc-8fx-workbench.programmerPort 修改）`);
	return picked.label;
}

export async function runZeztekDownload(layout: BuildLayout | undefined, outputChannel: vscode.OutputChannel): Promise<void> {
	if (!layout) {
		void vscode.window.showWarningMessage('工程配置不完整，无法确定烧录文件。');
		return;
	}

	const flashPath = layout.convertedModulePath;
	const extension = path.extname(flashPath).toLowerCase();
	if (extension !== '.mhx' && extension !== '.s19') {
		void vscode.window.showWarningMessage(`烧录器仅支持 S-record 文件（.mhx/.s19），当前输出为 ${extension || '(无扩展名)'}，请把输出格式改为 MHX 后重新编译。`);
		return;
	}
	if (!fs.existsSync(flashPath)) {
		void vscode.window.showWarningMessage(`未找到烧录文件 ${path.basename(flashPath)}，请先点击“编译”生成烧录产物。`);
		return;
	}

	const portName = await resolveProgrammerPort(outputChannel);
	if (!portName) {
		return;
	}

	const configuration = vscode.workspace.getConfiguration(CONFIG_SECTION);
	const modeSetting = configuration.get<'online' | 'offline'>('programmerMode') ?? 'offline';
	const powerSetting = configuration.get<'5V' | '3.3V'>('programmerPower') ?? '5V';
	const mode = modeSetting === 'online' ? Mode.ONLINE : Mode.OFFLINE;
	const power = powerSetting === '3.3V' ? Power.V3_3 : Power.V5;

	const log = (message: string): void => {
		outputChannel.appendLine(`[flash] ${message}`);
	};

	let checksumText = '';
	try {
		await vscode.window.withProgress({
			location: vscode.ProgressLocation.Notification,
			title: 'F2MC-8FX 烧录',
			cancellable: true
		}, async (progress, token) => {
			const cpuName = layout.project.cpuName;
			if (!cpuName) {
				throw new ProtocolError('未选择芯片型号，请先在插件“设置”视图中选择芯片。');
			}
			const mcu = findMcuByCpuName(cpuName);
			if (!mcu) {
				throw new ProtocolError(`烧录器不支持型号 ${cpuName}（支持：${BUILTIN_MCUS.map(item => item.name).join('、')}）`);
			}

			progress.report({ message: '解析烧录文件…' });
			log(`文件: ${flashPath}`);
			log(`型号: ${mcu.name} 芯片代码 0x${mcu.chipCode.toString(16).toUpperCase().padStart(2, '0')}`);
			const segments = parseS19((await fs.promises.readFile(flashPath)).toString('latin1'));
			const allowed: Array<[number, number]> = [];
			if (mcu.lowBank !== undefined) {
				allowed.push([mcu.lowBank, mcu.lowBank + 0xFFF]);
			}
			allowed.push([mcu.start, mcu.end]);
			validateRange(segments, allowed);
			const imageBlocks = buildImage(segments, blockAddrs(mcu));
			const checksum = imageChecksum(imageBlocks);
			checksumText = `0x${checksum.toString(16).toUpperCase().padStart(8, '0')}`;
			log(`加载 ${imageBlocks.length} 块 × 4KB，校验和 ${checksumText}`);

			progress.report({ message: '打开串口…' });
			const dev = new ZeztekProgrammer(portName, log);
			try {
				await setupProgrammer(dev, portName, mode, power, progress, token, log);

				const addresses = blockAddrs(mcu);
				const frameBlocks = imageBlocks.map((block, index) => dataBlock(index, addresses[index] >> 8, block));
				progress.report({ message: '装载固件：传输数据…' });
				await dev.uploadImage(frameBlocks, totalKb(mcu), mcu.chipCode, {
					progress: (done, total) => progress.report({ message: `传输数据块 ${done}/${total}…` })
				});

				progress.report({ message: '擦除、编程、校验中…' });
				await dev.oneKey();
			} finally {
				await dev.close();
			}
			log('烧录成功');
		});
		void vscode.window.showInformationMessage(`烧录成功：${path.basename(flashPath)}（校验和 ${checksumText}，盒子数码管应显示 ${checksumText.slice(-4)}）。连续烧录请先给烧录器重新上电。`);
	} catch (error) {
		const message = error instanceof Error ? error.message : String(error);
		// 用户主动取消不算烧录失败，仅记录日志，不弹错误窗
		if (message === '已取消烧录') {
			outputChannel.appendLine('[flash] 已取消烧录');
			return;
		}
		outputChannel.appendLine(`[flash] 烧录失败: ${message}`);
		if (error instanceof Error && error.stack) {
			outputChannel.appendLine(error.stack);
		}
		void vscode.window.showErrorMessage(`烧录失败：${message}`);
	}
}
