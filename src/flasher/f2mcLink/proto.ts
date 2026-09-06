// L1 命令集封装：16 条 vendor 命令的强类型客户端，含 BEGIN/DATA/COMMIT 分块流。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/proto.rs。
//
// 帧格式：请求 [0x80][CMD][LEN_L][LEN_H][PAYLOAD≤56B]，响应 [0x80][STATUS][DATA]。
// 状态机：IDLE →(ENTER_PGM)→ SYNCED →(ERASE)→ ERASED →(FLASH_INIT)→ RW_MODE。

import { ProgError } from './errors';
import { MAX_PAYLOAD, transact, type DapTransport } from './vendor';

/** L1 命令 ID 表 */
export const Cmd = {
	PING: 0x01,
	SET_POWER: 0x02,
	ENTER_PGM: 0x03,
	ERASE: 0x04,
	FLASH_INIT: 0x05,
	WRITE_BEGIN: 0x06,
	WRITE_DATA: 0x07,
	WRITE_COMMIT: 0x08,
	READ_BEGIN: 0x09,
	READ_DATA: 0x0A,
	CR_TRIM_WRITE: 0x0B,
	QUIT: 0x0C,
	RESET_RUN: 0x0D,
	GET_STATE: 0x0E,
	WRITE_SECURE: 0x0F,
	SEND_BREAK: 0x10,
	DISCONNECT: 0x11,
	ABORT: 0x12
} as const;

/** 各命令的单条响应等待超时（毫秒）；ERASE 上限 90 s：固件侧 60 s + 余量，超时≠失败 */
export const Timeout = {
	PING: 1_000,
	SET_POWER: 5_000,
	ENTER_PGM: 10_000,
	ERASE: 90_000,
	FLASH_INIT: 5_000,
	WRITE_BEGIN: 1_000,
	WRITE_DATA: 1_000,
	WRITE_COMMIT: 5_000,
	READ_BEGIN: 2_000,
	READ_DATA: 1_000,
	QUIT: 2_000,
	RESET_RUN: 2_000,
	GET_STATE: 1_000,
	WRITE_SECURE: 2_000,
	DISCONNECT: 1_000
} as const;

/** 单块写上限（WRITE_BEGIN/DATA/COMMIT 一个事务的总数据量） */
export const WRITE_BLOCK_MAX = 512;
/** 单块读上限（READ_BEGIN/DATA 一个事务的总数据量） */
export const READ_BLOCK_MAX = 1024;

/** F2MC-8FX 编程器 L1 客户端（泛型于传输层，真机/模拟器可互换） */
export class F2mcLinkClient {
	/** 固件版本（PING 后填充） */
	public fwVersion: [number, number, number] | undefined;

	public constructor(private readonly transport: DapTransport) {
	}

	/** PING(0x01)：连接握手。返回设备标识字符串（应为 "F2MC-LINK"） */
	public async ping(): Promise<string> {
		// 响应固定 12 B："F2MC-LINK"(9B) + FW版本(3B)
		// 不能用尾零裁剪：版本号如 [1,0,0] 的尾零会被误裁导致版本解析失败
		const data = await transact(this.transport, Cmd.PING, Buffer.alloc(0), 12, Timeout.PING);
		this.fwVersion = [data[9], data[10], data[11]];
		return data.subarray(0, 9).toString('latin1');
	}

	/** SET_POWER(0x02)：目标供电开关 */
	public async setPower(on: boolean): Promise<void> {
		await transact(this.transport, Cmd.SET_POWER, Buffer.from([on ? 1 : 0]), 0, Timeout.SET_POWER);
	}

	/**
	 * ENTER_PGM(0x03)：与目标握手进入编程模式（仅 IDLE 态可用）。
	 * 目标无响应时固件失败路径最长 ~7 s 才返回，超时后不得立即发新命令。
	 */
	public async enterPgm(): Promise<void> {
		await transact(this.transport, Cmd.ENTER_PGM, Buffer.alloc(0), 0, Timeout.ENTER_PGM);
	}

	/** ERASE(0x04)：擦除（仅 SYNCED 态可用）。addr=0x0000 整片擦除（同时解除安全锁），否则扇区擦除 */
	public async erase(addr: number): Promise<void> {
		await transact(this.transport, Cmd.ERASE, Buffer.from([(addr >> 8) & 0xFF, addr & 0xFF]), 0, Timeout.ERASE);
	}

	/** FLASH_INIT(0x05)：初始化目标 Flash 接口并切高速时钟（SYNCED/ERASED 可用），成功后进入 RW_MODE */
	public async flashInit(xx: number, yy: number): Promise<void> {
		await transact(this.transport, Cmd.FLASH_INIT, Buffer.from([xx, yy]), 0, Timeout.FLASH_INIT);
	}

	/** 大块写（≤512B，仅 RW_MODE）：WRITE_BEGIN → WRITE_DATA×N（每包 ≤56B）→ WRITE_COMMIT */
	public async writeBlock(addr: number, data: Buffer): Promise<void> {
		if (data.length === 0 || data.length > WRITE_BLOCK_MAX) {
			throw ProgError.badParam(`writeBlock 长度 ${data.length} 超出 1..=${WRITE_BLOCK_MAX}`);
		}
		const begin = Buffer.from([(addr >> 8) & 0xFF, addr & 0xFF, (data.length >> 8) & 0xFF, data.length & 0xFF]);
		await transact(this.transport, Cmd.WRITE_BEGIN, begin, 0, Timeout.WRITE_BEGIN);
		for (let offset = 0; offset < data.length; offset += MAX_PAYLOAD) {
			await transact(this.transport, Cmd.WRITE_DATA, Buffer.from(data.subarray(offset, offset + MAX_PAYLOAD)), 0, Timeout.WRITE_DATA);
		}
		await transact(this.transport, Cmd.WRITE_COMMIT, Buffer.alloc(0), 0, Timeout.WRITE_COMMIT);
	}

	/** 大块读（≤1024B，仅 RW_MODE）：READ_BEGIN → READ_DATA×N（固件在 BEGIN 时已完成 L2 读） */
	public async readBlock(addr: number, len: number): Promise<Buffer> {
		if (len === 0 || len > READ_BLOCK_MAX) {
			throw ProgError.badParam(`readBlock 长度 ${len} 超出 1..=${READ_BLOCK_MAX}`);
		}
		const begin = Buffer.from([(addr >> 8) & 0xFF, addr & 0xFF, (len >> 8) & 0xFF, len & 0xFF]);
		await transact(this.transport, Cmd.READ_BEGIN, begin, 0, Timeout.READ_BEGIN);
		const chunks: Buffer[] = [];
		let received = 0;
		while (received < len) {
			const want = Math.min(len - received, MAX_PAYLOAD);
			const chunk = await transact(this.transport, Cmd.READ_DATA, Buffer.alloc(0), want, Timeout.READ_DATA);
			chunks.push(chunk);
			received += chunk.length;
		}
		return Buffer.concat(chunks);
	}

	/**
	 * QUIT(0x0C)：退出读写模式回 SYNCED（仅 RW_MODE 可用）。
	 * QUIT 后握手失效（目标退回 bootloader 世界），下次擦除/读写前必须复位状态机并重新 ENTER_PGM。
	 */
	public async quit(): Promise<void> {
		await transact(this.transport, Cmd.QUIT, Buffer.alloc(0), 0, Timeout.QUIT);
	}

	/**
	 * RESET_RUN(0x0D)：复位目标运行用户程序。
	 * 编程器无复位硬件，固件恒回 UNSUPPORTED 并把状态机复位到 IDLE——该错误码属预期，调用侧应容错。
	 */
	public async resetRun(): Promise<void> {
		await transact(this.transport, Cmd.RESET_RUN, Buffer.alloc(0), 0, Timeout.RESET_RUN);
	}

	/** GET_STATE(0x0E)：查询状态机。返回 [state, lastErr]：state 0=IDLE 1=SYNCED 2=ERASED 3=RW_MODE */
	public async getState(): Promise<[number, number]> {
		const data = await transact(this.transport, Cmd.GET_STATE, Buffer.alloc(0), 2, Timeout.GET_STATE);
		return [data[0], data[1]];
	}

	/** WRITE_SECURE(0x0F)：写 0xFFFC 安全位（仅 RW_MODE），QUIT/断电复位后生效 */
	public async writeSecure(): Promise<void> {
		await transact(this.transport, Cmd.WRITE_SECURE, Buffer.alloc(0), 0, Timeout.WRITE_SECURE);
	}

	/** DISCONNECT(0x11)：上位机断开通知——固件熄 LED、状态机复位 IDLE。关闭设备前应发送 */
	public async disconnect(): Promise<void> {
		await transact(this.transport, Cmd.DISCONNECT, Buffer.alloc(0), 0, Timeout.DISCONNECT);
	}
}
