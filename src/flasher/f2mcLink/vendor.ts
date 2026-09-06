// L1 vendor 命令收发：组帧、响应解析、重试与迟到响应吸收。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/vendor.rs。
//
// 请求: [0x80] [CMD] [LEN_L] [LEN_H] [PAYLOAD(≤56B)]
// 响应: [0x80] [STATUS] [DATA...]

import { ProgError, StatusCode } from './errors';

/** CMSIS-DAP vendor 命令首字节（DAP_Transfer vendor ID 起点） */
export const ID_DAP_VENDOR0 = 0x80;
/** 单包应用层载荷上限（v1/v2 两通道取最小余量） */
export const MAX_PAYLOAD = 56;

/** DAP 传输抽象：发送一个请求包（首字节为命令 ID），返回响应包 */
export interface DapTransport {
	/** 发送一个 DAP 请求包并等待响应（timeoutMs 毫秒） */
	dapTransfer(request: Buffer, timeoutMs: number): Promise<Buffer>;
	/** 吸收超时后迟到的响应；无数据返回 undefined。HID 通道实现，模拟器可省略 */
	drain?(timeoutMs: number): Promise<Buffer | undefined>;
}

/**
 * 发送一条 vendor 命令，返回 STATUS 之后的 DATA。
 * expectLen 为调用方按命令语义期望的 DATA 长度；undefined 时按尾部 0x00 裁剪。
 * 传输层格式错误（首字节≠0x80 / 缺 STATUS / 长度不符）重试一次；
 * 设备状态码错误不重试；超时也不重试——固件可能仍在执行（如 ENTER_PGM 失败
 * 路径最长 ~7 s），先吸收迟到响应再上报，避免错位成下一命令的响应。
 */
export async function transact(
	transport: DapTransport,
	cmd: number,
	payload: Buffer,
	expectLen: number | undefined,
	timeoutMs: number
): Promise<Buffer> {
	if (payload.length > MAX_PAYLOAD) {
		throw ProgError.badParam(`vendor payload ${payload.length} > ${MAX_PAYLOAD} bytes`);
	}

	const request = Buffer.concat([
		Buffer.from([ID_DAP_VENDOR0, cmd, payload.length & 0xFF, payload.length >> 8]),
		payload
	]);

	let lastError: ProgError | undefined;
	for (let attempt = 0; attempt < 2; attempt++) {
		try {
			return await tryOnce(transport, request, expectLen, timeoutMs);
		} catch (error) {
			if (error instanceof ProgError && (error.kind === 'deviceStatus' || error.kind === 'securityLocked' || error.kind === 'cancelled')) {
				throw error;
			}
			if (error instanceof ProgError && error.kind === 'timeout') {
				await drainLate(transport);
				throw error;
			}
			await drainLate(transport);
			lastError = error instanceof ProgError ? error : ProgError.transport(String(error));
		}
	}
	throw lastError;
}

/** 吸收超时/错误后可能迟到的响应，防止错位成下一命令的响应 */
async function drainLate(transport: DapTransport): Promise<void> {
	if (!transport.drain) {
		return;
	}
	for (let i = 0; i < 3; i++) {
		try {
			const bytes = await transport.drain(300);
			if (!bytes) {
				return;
			}
		} catch {
			return;
		}
	}
}

async function tryOnce(
	transport: DapTransport,
	request: Buffer,
	expectLen: number | undefined,
	timeoutMs: number
): Promise<Buffer> {
	const response = await transport.dapTransfer(request, timeoutMs);
	if (response.length < 2) {
		throw ProgError.transport(`响应过短（${response.length} 字节）`);
	}
	if (response[0] !== ID_DAP_VENDOR0) {
		throw ProgError.transport(`响应首字节 0x${response[0].toString(16).toUpperCase().padStart(2, '0')} ≠ 0x80`);
	}

	const status = response[1];
	if (status === StatusCode.SECURITY_LOCKED) {
		throw ProgError.securityLocked();
	}
	if (status === StatusCode.ABORTED) {
		throw ProgError.cancelled();
	}
	if (status !== StatusCode.OK) {
		throw ProgError.deviceStatus(status);
	}

	let data = response.subarray(2);
	if (expectLen !== undefined) {
		if (data.length < expectLen) {
			throw ProgError.transport(`响应数据 ${data.length} < 期望 ${expectLen}`);
		}
		data = data.subarray(0, expectLen);
	} else {
		let end = data.length;
		while (end > 0 && data[end - 1] === 0) {
			end--;
		}
		data = data.subarray(0, end);
	}
	return Buffer.from(data);
}
