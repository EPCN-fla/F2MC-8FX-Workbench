// Motorola S-record (S19/MHX) 解析与镜像组装。
// 协议来源：泽兆烧录器上位机逆向（docs/protocol.md），烧录文件为 S-record 格式。

export interface SRecordSegment {
	start: number;
	data: Buffer;
}

export class SRecordError extends Error {
	public constructor(message: string) {
		super(message);
		this.name = 'SRecordError';
	}
}

function hexToBytes(text: string, lineNo: number): Buffer {
	if (text.length % 2 !== 0) {
		throw new SRecordError(`第 ${lineNo} 行: 十六进制长度为奇数`);
	}
	const out = Buffer.alloc(text.length / 2);
	for (let i = 0; i < out.length; i++) {
		const value = Number.parseInt(text.slice(i * 2, i * 2 + 2), 16);
		if (Number.isNaN(value)) {
			throw new SRecordError(`第 ${lineNo} 行: 非法十六进制字符`);
		}
		out[i] = value;
	}
	return out;
}

export function parseS19(text: string): SRecordSegment[] {
	const cells = new Map<number, number>();
	const lines = text.split(/\r?\n/);
	for (let lineNo = 0; lineNo < lines.length; lineNo++) {
		const line = lines[lineNo].trim();
		if (!line || !line.toUpperCase().startsWith('S')) {
			continue;
		}
		const type = line[1];
		const body = hexToBytes(line.slice(2), lineNo + 1);
		if (body.length < 2) {
			throw new SRecordError(`第 ${lineNo + 1} 行: 记录过短`);
		}
		const count = body[0];
		if (count !== body.length - 1) {
			throw new SRecordError(`第 ${lineNo + 1} 行: 字节计数不符`);
		}
		const payload = body.subarray(1, body.length - 1);
		let checksum = 0;
		for (const byte of body.subarray(0, body.length - 1)) {
			checksum += byte;
		}
		checksum = (checksum + body[body.length - 1]) & 0xFF;
		if (checksum !== 0xFF) {
			throw new SRecordError(`第 ${lineNo + 1} 行: 校验和错误`);
		}
		let address: number;
		let data: Buffer;
		// 地址宽度按规范：S1=2 字节、S2=3 字节、S3=4 字节
		const addrLen = type === '1' ? 2 : type === '2' ? 3 : type === '3' ? 4 : 0;
		if (addrLen > 0) {
			if (payload.length < addrLen) {
				throw new SRecordError(`第 ${lineNo + 1} 行: 地址字段过短`);
			}
			address = payload.readUIntBE(0, addrLen);
			data = Buffer.from(payload.subarray(addrLen));
		} else {
			continue; // S0 头 / S5 计数 / S7~S9 结束记录
		}
		for (let i = 0; i < data.length; i++) {
			cells.set(address + i, data[i]);
		}
	}
	if (cells.size === 0) {
		throw new SRecordError('无有效数据记录');
	}

	const addrs = [...cells.keys()].sort((a, b) => a - b);
	const segments: SRecordSegment[] = [];
	let segStart = addrs[0];
	let prev = addrs[0];
	let buf = [cells.get(prev)!];
	for (let i = 1; i < addrs.length; i++) {
		const addr = addrs[i];
		if (addr === prev + 1) {
			buf.push(cells.get(addr)!);
		} else {
			segments.push({ start: segStart, data: Buffer.from(buf) });
			segStart = addr;
			buf = [cells.get(addr)!];
		}
		prev = addr;
	}
	segments.push({ start: segStart, data: Buffer.from(buf) });
	return segments;
}

export function validateRange(segments: SRecordSegment[], allowed: Array<[number, number]>): void {
	for (const segment of segments) {
		const end = segment.start + segment.data.length - 1;
		const ok = allowed.some(([lo, hi]) => segment.start >= lo && end <= hi);
		if (!ok) {
			throw new SRecordError(
				`所选型号跟烧写文件地址不符，请重新选择！(段 0x${segment.start.toString(16).toUpperCase().padStart(4, '0')}`
				+ `-0x${end.toString(16).toUpperCase().padStart(4, '0')} 超出范围)`);
		}
	}
}

export function buildImage(segments: SRecordSegment[], blockAddrs: number[], blockSize = 0x1000, fill = 0xFF): Buffer[] {
	const cells = new Map<number, number>();
	for (const segment of segments) {
		for (let i = 0; i < segment.data.length; i++) {
			cells.set(segment.start + i, segment.data[i]);
		}
	}
	const blocks: Buffer[] = [];
	for (const base of blockAddrs) {
		const block = Buffer.alloc(blockSize, fill);
		for (let i = 0; i < blockSize; i++) {
			const value = cells.get(base + i);
			if (value !== undefined) {
				block[i] = value;
			}
		}
		blocks.push(block);
	}
	return blocks;
}

export function imageChecksum(blocks: Buffer[]): number {
	let sum = 0;
	for (const block of blocks) {
		for (const byte of block) {
			sum += byte;
		}
	}
	return sum >>> 0;
}
