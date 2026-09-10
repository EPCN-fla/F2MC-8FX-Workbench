// 泽兆烧录器串口协议层：帧构造/解析 + ZeztekProgrammer 设备类。
// 移植自已真机验证的 fujitsu_programmer/fujitsu/protocol.py，帧格式：
//     命令帧  = 68 | CMD | LEN | payload[LEN] | 16
//     应答    = 68 | CMD | LEN | payload[LEN] | 16   (payload[0] 为状态码)
//     数据块  = NN | AA | DATA[4096] | SUM32(大端)   (0x1006 字节, 无 68/16 包裹)

export const HEAD = 0x68;
export const TAIL = 0x16;
export const BLOCK_SIZE = 0x1000;
export const BLOCK_FRAME_SIZE = BLOCK_SIZE + 6;

export const Cmd = {
	DATA_HDR: 0x00,
	ERASE: 0x01,
	WRITE: 0x02,
	CHECK: 0x03,
	READ: 0x04,
	EPC: 0x05, // 一键 擦除+编程+校验
	SET: 0x06
} as const;

export const Status = {
	OK: 0x99,
	ACK: 0x55,
	ENCRYPTED: 0x11,
	MISMATCH: 0xEE,
	FAIL: 0x00
} as const;

export const Mode = {
	ONLINE: 0x55,
	OFFLINE: 0xAA
} as const;

export const Power = {
	OFF: 0x00,
	V5: 0x50,
	V3_3: 0x33
} as const;

export const PROGRAMMER_BAUD = 38400;

export interface ByteStream {
	open(): Promise<void>;
	write(data: Buffer): Promise<void>;
	onData(callback: (chunk: Buffer) => void): void;
	close(): Promise<void>;
}

export class ProtocolError extends Error {
	public readonly status?: number;

	public constructor(message: string, status?: number) {
		super(message);
		this.name = 'ProtocolError';
		this.status = status;
	}
}

export function cmdFrame(cmd: number, payload: Buffer = Buffer.alloc(0)): Buffer {
	if (payload.length > 0xFF) {
		throw new Error('payload 过长');
	}
	return Buffer.concat([Buffer.from([HEAD, cmd & 0xFF, payload.length]), payload, Buffer.from([TAIL])]);
}

export function buildSetFrame(mode: number, power: number, count: [number, number] = [0, 0], sel = 0x00): Buffer {
	return cmdFrame(Cmd.SET, Buffer.from([mode & 0xFF, power & 0xFF, count[0] & 0xFF, count[1] & 0xFF, sel & 0xFF]));
}

export function buildDataHdrFrame(kb: number, chipCode: number, sn: Buffer = Buffer.alloc(5), snFlag = 0): Buffer {
	if (sn.length !== 5) {
		throw new Error('序列号必须 5 字节');
	}
	return cmdFrame(Cmd.DATA_HDR, Buffer.concat([
		Buffer.from([kb & 0xFF, chipCode & 0xFF]),
		sn,
		Buffer.from([snFlag & 0xFF])
	]));
}

export function buildReadFrame(addrHi: number, addrLo: number, kb: number): Buffer {
	return cmdFrame(Cmd.READ, Buffer.from([addrHi & 0xFF, addrLo & 0xFF, kb & 0xFF]));
}

export function dataBlock(index: number, addrHi: number, data: Buffer): Buffer {
	if (data.length !== BLOCK_SIZE) {
		throw new Error(`数据块必须 ${BLOCK_SIZE} 字节`);
	}
	let sum = 0;
	for (const byte of data) {
		sum += byte;
	}
	const checksum = Buffer.alloc(4);
	checksum.writeUInt32BE(sum >>> 0, 0);
	return Buffer.concat([Buffer.from([index & 0xFF, addrHi & 0xFF]), data, checksum]);
}

const ACK_PATTERN = Buffer.from([HEAD, 0x00, 0x22, Status.ACK]); // 块 ACK: 68 00 22 55 NN 16 (byte2=0x22 非长度!)
const DONE_PATTERN = Buffer.from([HEAD, 0x00, 0x01, Status.OK]); // 完成: 68 00 01 99 CS1 CS2 16

const sleep = (ms: number): Promise<void> => new Promise(resolve => setTimeout(resolve, ms));

function hexPreview(data: Buffer): string {
	const head = data.subarray(0, 32).toString('hex').toUpperCase().replace(/(..)/g, '$1 ').trim();
	return data.length > 32 ? `${head} ...` : head;
}

export class FrameReader {
	private buf: Buffer = Buffer.alloc(0);

	public feed(data: Buffer): void {
		this.buf = Buffer.concat([this.buf, data]);
	}

	// 返回 {cmd, payload}；数据不足返回 undefined，遇到伪帧头(长度非法/帧尾不符)丢弃后重新同步。
	public popFrame(): { cmd: number; payload: Buffer } | undefined {
		for (;;) {
			const index = this.buf.indexOf(HEAD);
			if (index < 0) {
				this.buf = Buffer.alloc(0);
				return undefined;
			}
			if (index > 0) {
				this.buf = this.buf.subarray(index);
			}
			if (this.buf.length < 4) {
				return undefined;
			}
			const length = this.buf[2];
			if (length > 64) {
				this.buf = this.buf.subarray(1);
				continue;
			}
			const end = 3 + length + 1;
			if (this.buf.length < end) {
				return undefined;
			}
			if (this.buf[end - 1] !== TAIL) {
				this.buf = this.buf.subarray(1);
				continue;
			}
			const cmd = this.buf[1];
			const payload = Buffer.from(this.buf.subarray(3, end - 1));
			this.buf = this.buf.subarray(end);
			return { cmd, payload };
		}
	}

	public get pending(): number {
		return this.buf.length;
	}

	public take(n: number): Buffer {
		if (this.buf.length < n) {
			throw new Error('缓冲区数据不足');
		}
		const data = Buffer.from(this.buf.subarray(0, n));
		this.buf = this.buf.subarray(n);
		return data;
	}
}

export interface UploadOptions {
	sn?: Buffer;
	snFlag?: number;
	progress?: (done: number, total: number) => void;
}

export class ZeztekProgrammer {
	// 实测时序（详见 fujitsu_programmer docs/protocol.md）：盒子内部重试约 20s，超时不能低于 25s。
	public HDR_DELAY = 6.0;   // 数据头→块0 间隔(盒子需要数秒准备缓冲区)
	public OP_TIMEOUT = 120.0;
	public ACK_TIMEOUT = 15.0;
	public CMD_TIMEOUT = 120.0;

	private stream: ByteStream | undefined;
	private rx = new FrameReader();
	private rawBuf: Buffer = Buffer.alloc(0);

	public constructor(
		private readonly portName: string,
		private readonly log: (message: string) => void = () => {},
		stream?: ByteStream
	) {
		if (stream) {
			this.bindStream(stream);
		}
	}

	public async open(stream: ByteStream): Promise<void> {
		this.bindStream(stream);
		await stream.open();
		this.log(`串口 ${this.portName} 已打开 (38400-8N1, DTR/RTS=off)`);
	}

	public async close(): Promise<void> {
		if (this.stream) {
			await this.stream.close();
			this.stream = undefined;
		}
	}

	private bindStream(stream: ByteStream): void {
		this.stream = stream;
		this.rx = new FrameReader();
		this.rawBuf = Buffer.alloc(0);
		stream.onData(chunk => {
			this.rawBuf = Buffer.concat([this.rawBuf, chunk]);
			this.rx.feed(chunk);
		});
	}

	// 装载阶段的块 ACK 帧会同时进入 rx 但不被消费，其残留会卡住后续命令的应答解析
	// （如 ACK 帧 LEN=0x22 会被当作 38 字节帧等待）。每条命令发送前必须清空接收状态。
	private flushRx(): void {
		this.rx = new FrameReader();
		this.rawBuf = Buffer.alloc(0);
	}

	private async writeData(data: Buffer): Promise<void> {
		if (!this.stream) {
			throw new ProtocolError('串口未打开');
		}
		await this.stream.write(data);
		this.log(`TX ${data.length} B: ${hexPreview(data)}`);
	}

	private async readFrame(timeoutSec: number): Promise<{ cmd: number; payload: Buffer }> {
		const deadline = Date.now() + timeoutSec * 1000;
		while (Date.now() < deadline) {
			const frame = this.rx.popFrame();
			if (frame) {
				const whole = Buffer.concat([Buffer.from([HEAD, frame.cmd, frame.payload.length]), frame.payload, Buffer.from([TAIL])]);
				this.log(`RX ${frame.payload.length + 4} B: ${hexPreview(whole)}`);
				return frame;
			}
			await sleep(5);
		}
		throw new ProtocolError(`烧录器无响应(超时 ${timeoutSec}s)`);
	}

	private async cmdExpectOk(cmd: number, payload: Buffer, what: string, timeoutSec?: number, allowMismatch = false): Promise<Buffer> {
		this.flushRx();
		await this.writeData(cmdFrame(cmd, payload));
		const { payload: resp } = await this.readFrame(timeoutSec ?? this.CMD_TIMEOUT);
		const status = resp.length > 0 ? resp[0] : undefined;
		if (status === Status.OK) {
			return resp;
		}
		if (status === Status.ENCRYPTED) {
			throw new ProtocolError(`${what}失败: 目标芯片已加密`, status);
		}
		if (status === Status.MISMATCH) {
			if (allowMismatch && resp.length >= 5) {
				const addr = (resp[1] << 8) | resp[2];
				throw new ProtocolError(`${what}没通过，错误地址：0x${addr.toString(16).toUpperCase().padStart(4, '0')} 写入是 0x${resp[3].toString(16).toUpperCase().padStart(2, '0')} 读出是 0x${resp[4].toString(16).toUpperCase().padStart(2, '0')}`, status);
			}
			throw new ProtocolError(`${what}失败: 校验错误`, status);
		}
		if (status === undefined || status === Status.FAIL) {
			throw new ProtocolError(`${what}失败`, status);
		}
		throw new ProtocolError(`${what}失败: 未知状态 0x${status.toString(16).toUpperCase().padStart(2, '0')}`, status);
	}

	// 设置命令。实测 SET 会"武装"盒子，已武装的盒子忽略重复 SET(不回帧)，
	// 因此超时较短；无响应即残留会话，调用方必须中止并引导重新上电，不得继续装载。
	public async setup(mode: number, power: number, count: [number, number] = [0, 0], sel = 0x00): Promise<boolean> {
		this.flushRx();
		await this.writeData(buildSetFrame(mode, power, count, sel));
		const { payload: resp } = await this.readFrame(8.0);
		const status = resp.length > 0 ? resp[0] : undefined;
		if (status !== Status.OK) {
			throw new ProtocolError('设置失败,可能是目标已供电或连接线问题', status);
		}
		return true;
	}

	public async erase(): Promise<boolean> {
		await this.cmdExpectOk(Cmd.ERASE, Buffer.alloc(0), '擦除');
		return true;
	}

	public async write(): Promise<boolean> {
		await this.cmdExpectOk(Cmd.WRITE, Buffer.alloc(0), '写入', undefined, true);
		return true;
	}

	public async check(): Promise<boolean> {
		await this.cmdExpectOk(Cmd.CHECK, Buffer.alloc(0), '校验', undefined, true);
		return true;
	}

	// 一键 擦除+编程+校验。
	public async oneKey(): Promise<boolean> {
		await this.cmdExpectOk(Cmd.EPC, Buffer.alloc(0), '擦除、编程、校验', undefined, true);
		return true;
	}

	// 发送数据头 + 全部数据块。ACK 驱动握手，请求非法块号立即中止（防盒子挂死）。
	public async uploadImage(blocks: Buffer[], kb: number, chipCode: number, options: UploadOptions = {}): Promise<Buffer> {
		if (blocks.length === 0) {
			throw new Error('无数据块');
		}
		this.flushRx();
		const sn = options.sn ?? Buffer.alloc(5);
		const snFlag = options.snFlag ?? 0;
		await this.writeData(buildDataHdrFrame(kb, chipCode, sn, snFlag));
		if (this.HDR_DELAY > 0) {
			this.log(`等待 ${this.HDR_DELAY} 秒烧录器准备缓冲区…`);
			await sleep(this.HDR_DELAY * 1000);
		}
		await this.writeData(blocks[0]);
		let done = 1;
		let deadline = Date.now() + this.OP_TIMEOUT * 1000;
		for (;;) {
			if (Date.now() > deadline) {
				throw new ProtocolError(`数据传输超时(已完成 ${done}/${blocks.length} 块)`);
			}
			const raw = this.rawBuf;
			const ackIndex = raw.indexOf(ACK_PATTERN);
			if (ackIndex >= 0 && raw.length >= ackIndex + 6) {
				const next = raw[ackIndex + 4];
				this.rawBuf = raw.subarray(ackIndex + 6);
				if (next >= blocks.length) {
					throw new ProtocolError(`盒子请求非法块号 ${next}（残留上次烧录会话）。请给烧录器断电重新上电后重试`);
				}
				await this.writeData(blocks[next]);
				done = Math.max(done, next + 1);
				deadline = Date.now() + this.ACK_TIMEOUT * 1000;
				options.progress?.(done, blocks.length);
				continue;
			}
			const doneIndex = raw.indexOf(DONE_PATTERN);
			if (doneIndex >= 0 && raw.length >= doneIndex + 7) {
				const cs = (raw[doneIndex + 4] << 8) | raw[doneIndex + 5];
				options.progress?.(blocks.length, blocks.length);
				this.log(`传输完成(盒子附加码 0x${cs.toString(16).toUpperCase().padStart(4, '0')})`);
				return Buffer.from(raw.subarray(doneIndex, doneIndex + 7));
			}
			if (raw.length >= 5 && raw[0] === HEAD && raw[1] === 0x00 && raw[3] === Status.FAIL && raw[4] === TAIL) {
				throw new ProtocolError('数据传输失败(盒子返回 0x00)', Status.FAIL);
			}
			await sleep(10);
		}
	}

	// 读出芯片内容。返回按块序拼接的数据(每块 4096 字节, 已去掉块头 2 字节)。
	public async readChip(addr: number, nBlocks: number, kb: number, progress?: (done: number, total: number) => void): Promise<Buffer> {
		this.flushRx();
		await this.writeData(buildReadFrame((addr >> 8) & 0xFF, addr & 0xFF, kb & 0xFF));
		const chunks: Buffer[] = [];
		let received = 0;
		const deadline = Date.now() + this.OP_TIMEOUT * 1000;
		while (received < nBlocks * BLOCK_SIZE) {
			if (Date.now() > deadline) {
				throw new ProtocolError('读出超时');
			}
			const frame = this.rx.popFrame();
			if (frame) {
				const status = frame.payload.length > 0 ? frame.payload[0] : undefined;
				if (status === Status.ENCRYPTED) {
					throw new ProtocolError('目标芯片已加密，无法读出。', status);
				}
				if (status === undefined || status === Status.FAIL) {
					throw new ProtocolError('读 出 失 败！', status);
				}
				if (status === Status.OK) {
					break;
				}
				continue;
			}
			const want = BLOCK_SIZE + 2;
			if (this.rx.pending >= want) {
				const packet = this.rx.take(want);
				chunks.push(packet.subarray(2));
				received += BLOCK_SIZE;
				progress?.(chunks.length, nBlocks);
				continue;
			}
			await sleep(10);
		}
		return Buffer.concat(chunks);
	}
}
