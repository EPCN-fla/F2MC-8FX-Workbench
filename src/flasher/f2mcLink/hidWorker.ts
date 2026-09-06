// F2MC-LINK HID 工作线程：独占全部 node-hid 同步原生调用（枚举/打开/读/写），
// 通过 postMessage 与扩展宿主进程的 HidTransport 协作，避免阻塞扩展宿主事件循环。
// ⚠ 本模块依赖 node-hid 原生库，仅以 worker 形式由 hidTransport.ts 按编译产物路径加载，单元测试不得 import。

import { parentPort } from 'node:worker_threads';

import { devices, HID } from 'node-hid';

/** ABORT 帧（0x12）：带外强制中止当前长操作 */
const ABORT_FRAME = Buffer.from([0x80, 0x12, 0x00, 0x00]);
/** CMSIS-DAP v1 HID 报告：主机侧 65B（ReportID=0x00 + 64B 包，零填充），设备侧 64B 包 */
const HID_PACKET_SIZE = 64;
/** 读等待 tick：超时轮询间隔 */
const READ_TICK_MS = 50;

export type HidWorkerRequest =
	| { id: number; type: 'enumerate' }
	| { id: number; type: 'open'; path: string }
	| { id: number; type: 'transfer'; request: number[]; timeoutMs: number }
	| { id: number; type: 'read'; timeoutMs: number }
	| { id: number; type: 'abort' }
	| { id: number; type: 'close' };

/** 宿主侧可发起并等待响应的调用（不含 id，由 HidTransport 分配） */
export type HidWorkerCall =
	| { type: 'open'; path: string }
	| { type: 'transfer'; request: number[]; timeoutMs: number }
	| { type: 'read'; timeoutMs: number };

export type HidWorkerResponse =
	| { id: number; type: 'enumerateResult'; channels: Array<{ path: string; product: string; serial: string | undefined; vendorId: number; productId: number }> }
	| { id: number; type: 'result'; data: number[] | undefined }
	| { id: number; type: 'error'; message: string }
	| { id: 0; type: 'deviceError'; message: string };

let device: HID | undefined;
const responses: Buffer[] = [];
let waiter: ((data: Buffer | undefined) => void) | undefined;

function post(message: HidWorkerResponse): void {
	parentPort?.postMessage(message);
}

function settleWaiter(data: Buffer | undefined): void {
	const pending = waiter;
	waiter = undefined;
	pending?.(data);
}

function nextResponse(timeoutMs: number): Promise<Buffer | undefined> {
	const queued = responses.shift();
	if (queued) {
		return Promise.resolve(queued);
	}
	return new Promise<Buffer | undefined>(resolve => {
		const deadline = Date.now() + timeoutMs;
		const timer = setInterval(() => {
			if (Date.now() >= deadline) {
				clearInterval(timer);
				settleWaiter(undefined);
			}
		}, READ_TICK_MS);
		waiter = data => {
			clearInterval(timer);
			resolve(data);
		};
	});
}

function writeFrame(request: Buffer): void {
	if (!device) {
		throw new Error('设备未打开');
	}
	const frame = Buffer.alloc(HID_PACKET_SIZE + 1);
	request.copy(frame, 1);
	device.write(frame);
}

function enumerateChannels(): Array<{ path: string; product: string; serial: string | undefined; vendorId: number; productId: number }> {
	return devices()
		.filter(info =>
			(info.product?.includes('CMSIS-DAP') ?? false) ||
			(info.manufacturer?.includes('CMSIS-DAP') ?? false))
		.filter(info => info.path !== undefined)
		.map(info => ({
			path: info.path as string,
			product: info.product ?? '(unknown)',
			serial: info.serialNumber,
			vendorId: info.vendorId,
			productId: info.productId
		}));
}

function openDevice(path: string): void {
	const opened = new HID(path);
	opened.on('data', (data: Buffer) => {
		if (waiter) {
			settleWaiter(Buffer.from(data));
		} else {
			responses.push(Buffer.from(data));
		}
	});
	opened.on('error', (error: Error) => {
		// 读线程错误（如设备拔出）：先上报宿主（宿主立即拒绝所有挂起操作），再按超时收尾等待方
		post({ id: 0, type: 'deviceError', message: error.message });
		settleWaiter(undefined);
	});
	device = opened;
}

parentPort?.on('message', (message: HidWorkerRequest) => {
	void (async () => {
		try {
			switch (message.type) {
				case 'enumerate':
					post({ id: message.id, type: 'enumerateResult', channels: enumerateChannels() });
					break;
				case 'open':
					openDevice(message.path);
					post({ id: message.id, type: 'result', data: [] });
					break;
				case 'transfer': {
					writeFrame(Buffer.from(message.request));
					const data = await nextResponse(message.timeoutMs);
					post({ id: message.id, type: 'result', data: data ? [...data] : undefined });
					break;
				}
				case 'read': {
					const data = await nextResponse(message.timeoutMs);
					post({ id: message.id, type: 'result', data: data ? [...data] : undefined });
					break;
				}
				case 'abort':
					try {
						writeFrame(ABORT_FRAME);
					} catch {
						// 设备已断开时 ABORT 发送失败，忽略
					}
					break;
				case 'close':
					if (device) {
						try {
							device.close();
						} catch {
							// 设备已断开时 close 可能抛错，忽略
						}
						device = undefined;
					}
					post({ id: message.id, type: 'result', data: [] });
					break;
			}
		} catch (error) {
			post({ id: message.id, type: 'error', message: error instanceof Error ? error.message : String(error) });
		}
	})();
});
