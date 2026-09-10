// CMSIS-DAP v1（HID）传输层（扩展宿主侧）：枚举/打开编程器，DAP 包收发，取消令牌 → 带外 ABORT(0x12)。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/transport.rs 的 HidTransport。
// 固件同时暴露 v2（Bulk）接口，本实现固定走 v1 HID（全平台免驱，Win7 兼容）；
// 应用层协议两通道一致（单包载荷 ≤56B）。
//
// 全部 node-hid 同步原生调用在 hidWorker.ts 工作线程中执行（枚举/打开/读/写），
// 本模块只做消息收发与取消轮询，不阻塞扩展宿主事件循环。

import * as path from 'node:path';
import { Worker } from 'node:worker_threads';

import { ProgError } from './errors';
import type { CancelToken } from './flow';
import type { HidWorkerCall, HidWorkerRequest, HidWorkerResponse } from './hidWorker';
import type { DapTransport } from './vendor';

/** 读等待 tick：检查取消令牌的间隔 */
const CANCEL_TICK_MS = 100;
/** CMSIS-DAP v1 HID 报告：64B 包 */
const HID_PACKET_SIZE = 64;
/** 工作线程兜底超时（正常由工作线程侧 deadline 收尾，此为线程异常时的保险） */
const WORKER_GUARD_MS = 10_000;

export interface F2mcLinkChannelInfo {
	/** hidapi 设备路径（打开用） */
	path: string;
	/** USB 产品名 */
	product: string;
	/** USB 序列号（可能为空） */
	serial: string | undefined;
	/** USB VID / PID */
	vendorId: number;
	productId: number;
}

/** 枚举所有 CMSIS-DAP v1 HID 通道（产品/厂商名字符串含 "CMSIS-DAP"） */
export async function enumerateHidChannels(): Promise<F2mcLinkChannelInfo[]> {
	const worker = spawnWorker();
	try {
		const channels = await new Promise<F2mcLinkChannelInfo[]>((resolve, reject) => {
			const guard = setTimeout(() => reject(ProgError.transport('HID 枚举工作线程无响应')), WORKER_GUARD_MS);
			worker.once('error', error => {
				clearTimeout(guard);
				reject(ProgError.transport(error.message));
			});
			worker.once('message', (message: HidWorkerResponse) => {
				clearTimeout(guard);
				if (message.type === 'enumerateResult') {
					resolve(message.channels);
				} else if (message.type === 'error') {
					reject(ProgError.transport(message.message));
				} else {
					reject(ProgError.transport(`HID 枚举返回意外消息 ${message.type}`));
				}
			});
			worker.postMessage({ id: 1, type: 'enumerate' } satisfies HidWorkerRequest);
		});
		return channels;
	} finally {
		await worker.terminate();
	}
}

export function describeChannel(channel: F2mcLinkChannelInfo): string {
	const vid = channel.vendorId.toString(16).toUpperCase().padStart(4, '0');
	const pid = channel.productId.toString(16).toUpperCase().padStart(4, '0');
	return `CMSIS-DAP v1 (HID) | ${channel.serial ?? '(no serial)'} | ${vid}:${pid}`;
}

function spawnWorker(): Worker {
	return new Worker(path.join(__dirname, 'hidWorker.js'));
}

interface PendingCall {
	resolve: (data: number[] | undefined) => void;
	reject: (error: Error) => void;
}

/** CMSIS-DAP v1 HID 传输：工作线程收发 + 宿主侧取消轮询，取消时带外发 ABORT(0x12) */
export class HidTransport implements DapTransport {
	private readonly worker: Worker;
	private readonly calls = new Map<number, PendingCall>();
	private nextId = 1;
	/** 打开握手（首条命令前必须完成） */
	private readonly ready: Promise<void>;
	private cancel: CancelToken | undefined;
	/** 本次传输是否已发过 ABORT（幂等：一次传输内只发一次） */
	private aborted = false;
	private closed = false;

	public constructor(private readonly channel: F2mcLinkChannelInfo) {
		this.worker = spawnWorker();
		this.worker.on('message', (message: HidWorkerResponse) => this.onMessage(message));
		this.worker.on('error', error => this.failAll(ProgError.transport(error.message)));
		this.worker.on('exit', code => {
			if (!this.closed) {
				this.failAll(ProgError.transport(`HID 工作线程意外退出（code ${code}）`));
			}
		});
		this.ready = this.call({ type: 'open', path: channel.path }).then(() => undefined);
		// open 失败由首条命令的 await this.ready 上报；此处吞掉避免未捕获拒绝
		this.ready.catch(() => undefined);
	}

	public setCancel(token: CancelToken): void {
		this.cancel = token;
	}

	public async dapTransfer(request: Buffer, timeoutMs: number): Promise<Buffer> {
		if (request.length > HID_PACKET_SIZE) {
			throw new Error(`DAP v1 请求包 ${request.length} > ${HID_PACKET_SIZE} 字节`);
		}
		await this.ready;
		this.aborted = false;
		const cancelTimer = setInterval(() => {
			if (!this.aborted && this.cancel?.cancelled) {
				this.aborted = true;
				this.post({ id: 0, type: 'abort' });
			}
		}, CANCEL_TICK_MS);
		try {
			const data = await this.call({ type: 'transfer', request: [...request], timeoutMs });
			if (!data) {
				throw ProgError.timeout();
			}
			return Buffer.from(data);
		} finally {
			clearInterval(cancelTimer);
		}
	}

	public async drain(timeoutMs: number): Promise<Buffer | undefined> {
		await this.ready;
		const data = await this.call({ type: 'read', timeoutMs });
		return data ? Buffer.from(data) : undefined;
	}

	public close(): void {
		if (!this.closed) {
			this.closed = true;
			this.post({ id: 0, type: 'close' });
			void this.worker.terminate();
		}
	}

	private call(message: HidWorkerCall): Promise<number[] | undefined> {
		return new Promise<number[] | undefined>((resolve, reject) => {
			const id = this.nextId++;
			this.calls.set(id, { resolve, reject });
			this.post({ ...message, id });
		});
	}

	private post(message: HidWorkerRequest): void {
		try {
			this.worker.postMessage(message);
		} catch (error) {
			if ('id' in message && message.id !== 0) {
				const pending = this.calls.get(message.id);
				this.calls.delete(message.id);
				pending?.reject(error instanceof Error ? error : new Error(String(error)));
			}
		}
	}

	private onMessage(message: HidWorkerResponse): void {
		if (message.type === 'deviceError') {
			// 设备读线程错误（如拔出）：立即拒绝所有挂起操作，不等超时
			this.failAll(ProgError.transport(`HID 设备错误：${message.message}`));
			return;
		}
		const pending = this.calls.get(message.id);
		if (!pending) {
			return;
		}
		this.calls.delete(message.id);
		if (message.type === 'error') {
			pending.reject(ProgError.transport(message.message));
		} else if (message.type === 'result') {
			pending.resolve(message.data);
		} else {
			pending.reject(ProgError.transport(`工作线程返回意外消息 ${message.type}`));
		}
	}

	private failAll(error: Error): void {
		const pending = [...this.calls.values()];
		this.calls.clear();
		for (const call of pending) {
			call.reject(error);
		}
	}
}
