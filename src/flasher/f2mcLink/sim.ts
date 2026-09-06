// 编程器模拟器：按 L1 帧协议应答、维护固件状态机与虚拟 Flash——离线端到端测试用。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/sim.rs。
// 状态机：IDLE→SYNCED→ERASED→RW_MODE。

import { StatusCode } from './errors';
import { Cmd } from './proto';
import { ID_DAP_VENDOR0, type DapTransport } from './vendor';

/** 模拟器状态机（对应固件状态，GET_STATE 第 1 字节：0/1/2/3） */
export const SimState = {
	IDLE: 0,
	SYNCED: 1,
	ERASED: 2,
	RW_MODE: 3
} as const;

export class SimProgrammer implements DapTransport {
	public state: number = SimState.IDLE;
	/** 虚拟 flash：地址 → 字节（未写入地址视为 0xFF） */
	public readonly flash = new Map<number, number>();
	/** 安全锁 */
	public locked = false;
	/** 收到的帧日志（断言用） */
	public readonly frameLog: Buffer[] = [];
	/** 模拟故障注入：下 N 次传输直接返回传输错误 */
	public failNext = 0;
	/** 最近一次错误状态码（GET_STATE 第 2 字节） */
	private lastErr = 0;
	/** 安全位已写入但未生效（断电复位或 QUIT 后生效） */
	private pendingLock = false;
	private wbuf: number[] = [];
	private waddr = 0;
	private wexpect = 0;
	private rbuf: Buffer = Buffer.alloc(0);
	private rpos = 0;

	protected readFlash(addr: number): number {
		return this.flash.get(addr) ?? 0xFF;
	}

	private static resp(status: number, data: number[] | Buffer = []): Buffer {
		return Buffer.concat([Buffer.from([ID_DAP_VENDOR0, status]), Buffer.from(data)]);
	}

	public async dapTransfer(request: Buffer, _timeoutMs: number): Promise<Buffer> {
		this.frameLog.push(Buffer.from(request));
		if (this.failNext > 0) {
			this.failNext--;
			throw new Error('injected failure');
		}
		if (request.length < 4 || request[0] !== ID_DAP_VENDOR0) {
			throw new Error('bad frame');
		}
		const cmd = request[1];
		const len = request[2] | (request[3] << 8);
		if (request.length < 4 + len) {
			throw new Error('bad frame len');
		}
		const resp = this.handle(cmd, request.subarray(4, 4 + len));
		// 记录最近一次错误状态码（UNSUPPORTED 不经 set_err——RESET_RUN/SET_POWER 属预期返回，不记）
		if (resp[1] !== 0 && resp[1] !== StatusCode.UNSUPPORTED) {
			this.lastErr = resp[1];
		}
		return resp;
	}

	private handle(cmd: number, payload: Buffer): Buffer {
		// 安全锁目标：仅握手/整片擦除/L1 查询类命令可用，其余回 0xFD
		const lockAllowed = [
			Cmd.PING, Cmd.ERASE, Cmd.ENTER_PGM, Cmd.RESET_RUN, Cmd.GET_STATE,
			Cmd.SEND_BREAK, Cmd.DISCONNECT, Cmd.ABORT, Cmd.SET_POWER
		] as number[];
		if (this.locked && !lockAllowed.includes(cmd)) {
			return SimProgrammer.resp(StatusCode.SECURITY_LOCKED);
		}
		switch (cmd) {
			case Cmd.PING:
				return SimProgrammer.resp(StatusCode.OK, [...Buffer.from('F2MC-LINK', 'latin1'), 0, 1, 0]);
			case Cmd.SET_POWER: {
				const on = (payload[0] ?? 0) !== 0;
				if (!on) {
					this.state = SimState.IDLE;
				}
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.ENTER_PGM: {
				if (this.state !== SimState.IDLE) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				this.state = SimState.SYNCED;
				// 加锁目标：握手本身可成功（SYNCED），随后时钟切换时收到 0xFD
				return SimProgrammer.resp(this.locked ? StatusCode.SECURITY_LOCKED : StatusCode.OK);
			}
			case Cmd.ERASE: {
				if (this.state !== SimState.SYNCED) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				const addr = (payload[0] << 8) | payload[1];
				if (addr === 0) {
					this.flash.clear();
					this.locked = false;
					this.state = SimState.ERASED;
				}
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.FLASH_INIT: {
				if (this.state !== SimState.SYNCED && this.state !== SimState.ERASED) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				this.state = SimState.RW_MODE;
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.WRITE_BEGIN: {
				if (this.state !== SimState.RW_MODE) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				this.waddr = (payload[0] << 8) | payload[1];
				this.wexpect = (payload[2] << 8) | payload[3];
				if (this.wexpect === 0 || this.wexpect > 512) {
					return SimProgrammer.resp(StatusCode.BAD_PARAM);
				}
				this.wbuf = [];
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.WRITE_DATA: {
				if (this.state !== SimState.RW_MODE || this.wbuf.length + payload.length > this.wexpect) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				this.wbuf.push(...payload);
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.WRITE_COMMIT: {
				if (this.state !== SimState.RW_MODE || this.wbuf.length !== this.wexpect) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				for (let i = 0; i < this.wbuf.length; i++) {
					this.flash.set(this.waddr + i, this.wbuf[i]);
				}
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.READ_BEGIN: {
				if (this.state !== SimState.RW_MODE) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				const addr = (payload[0] << 8) | payload[1];
				const len = (payload[2] << 8) | payload[3];
				if (len === 0 || len > 1024) {
					return SimProgrammer.resp(StatusCode.BAD_PARAM);
				}
				const bytes: number[] = [];
				for (let i = 0; i < len; i++) {
					bytes.push(this.readFlash(addr + i));
				}
				this.rbuf = Buffer.from(bytes);
				this.rpos = 0;
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.READ_DATA: {
				if (this.state !== SimState.RW_MODE || this.rpos >= this.rbuf.length) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				const count = Math.min(this.rbuf.length - this.rpos, 56);
				const data = this.rbuf.subarray(this.rpos, this.rpos + count);
				this.rpos += count;
				return SimProgrammer.resp(StatusCode.OK, data);
			}
			case Cmd.CR_TRIM_WRITE:
				// 真机 DA 不实现 Spec 7.9 的 0x55 命令，固件恒回 ACK_ERROR；上位机应改用普通写路径
				return SimProgrammer.resp(StatusCode.ACK_ERROR);
			case Cmd.QUIT: {
				if (this.state !== SimState.RW_MODE) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				if (this.pendingLock) {
					this.locked = true;
					this.pendingLock = false;
				}
				this.state = SimState.SYNCED;
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.RESET_RUN: {
				if (this.pendingLock) {
					this.locked = true;
					this.pendingLock = false;
				}
				this.state = SimState.IDLE;
				// 无复位硬件，固件恒回 UNSUPPORTED 并把状态机复位到 IDLE
				return SimProgrammer.resp(StatusCode.UNSUPPORTED);
			}
			case Cmd.GET_STATE:
				return SimProgrammer.resp(StatusCode.OK, [this.state, this.lastErr]);
			case Cmd.WRITE_SECURE: {
				if (this.state !== SimState.RW_MODE) {
					return SimProgrammer.resp(StatusCode.STATE_ERROR);
				}
				this.flash.set(0xFFFC, 0x01);
				this.pendingLock = true;
				return SimProgrammer.resp(StatusCode.OK);
			}
			case Cmd.SEND_BREAK:
				return SimProgrammer.resp(StatusCode.OK);
			case Cmd.DISCONNECT:
				this.state = SimState.IDLE;
				return SimProgrammer.resp(StatusCode.OK);
			case Cmd.ABORT:
				return SimProgrammer.resp(StatusCode.OK);
			default:
				return SimProgrammer.resp(StatusCode.UNSUPPORTED);
		}
	}
}
