// 烧录文件解析与清洗：Intel HEX / Motorola S-record 自动嗅探、越界过滤、
// NVR/安全位剔除、连续区间合并。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/hexfile.rs。

import { FLASH_LOW, isValidAddr, rangesDesc, type ChipDef } from './chipdef';
import { ProgError } from './errors';
import { NVR_HIGH, NVR_LOW, SECURE_ADDR } from './new8fx';

export type HexFormat = 'intelHex' | 'srecord';

export function hexFormatLabel(format: HexFormat): string {
	return format === 'intelHex' ? 'Intel HEX' : 'Motorola S-record';
}

/** 清洗后的烧录镜像：若干连续区间（升序、已合并、无空洞填充） */
export interface HexImage {
	/** (起始地址, 数据)，按起始地址升序，互不重叠 */
	segments: Array<{ start: number; data: Buffer }>;
	/** 解析/清洗过程产生的警告 */
	warnings: string[];
	/** 嗅探到的文件格式 */
	format: HexFormat;
}

export function totalBytes(image: HexImage): number {
	return image.segments.reduce((sum, segment) => sum + segment.data.length, 0);
}

/**
 * 解析烧录文件（Intel HEX / S-record 自动嗅探）并清洗：
 * - 越界 < 0x1000：硬错误
 * - NVR 区 0xFFBB~0xFFBF：剔除并告警（保护 CR 校准值）
 * - 0xFFFC 安全位：剔除并告警（由“写入安全位”选项单独处理）
 * - 超出所选型号 Flash 映射范围（下 bank 0x1000~0x1FFF + 上 bank）：剔除并告警
 */
export function parseHexImage(text: string, chip: ChipDef): HexImage {
	const format = sniffFormat(text);
	const sparse = format === 'intelHex' ? parseIntelHex(text) : parseSrecord(text);
	return wash(sparse, chip, format);
}

/** 内容嗅探：首个非空行 `:` → Intel HEX；`S` → S-record */
function sniffFormat(text: string): HexFormat {
	for (const rawLine of text.split(/\r?\n/)) {
		const line = rawLine.trim();
		if (!line) {
			continue;
		}
		if (line.startsWith(':')) {
			return 'intelHex';
		}
		if (line.toUpperCase().startsWith('S')) {
			return 'srecord';
		}
		throw ProgError.hexFile(`无法识别的文件格式（行: ${line.slice(0, 20)}）`);
	}
	throw ProgError.hexFile('空文件');
}

function hexByte(text: string, lineNo: number): number {
	const value = Number.parseInt(text, 16);
	if (text.length !== 2 || Number.isNaN(value)) {
		throw ProgError.hexFile(`第 ${lineNo} 行: 非法十六进制字符`);
	}
	return value;
}

/** Intel HEX：数据记录(00) + 扩展地址记录(02/04)，校验和逐行验证 */
function parseIntelHex(text: string): Array<[number, number]> {
	const sparse: Array<[number, number]> = [];
	let upperBase = 0;
	const lines = text.split(/\r?\n/);
	for (let index = 0; index < lines.length; index++) {
		const lineNo = index + 1;
		const line = lines[index].trim();
		if (!line) {
			continue;
		}
		if (!line.startsWith(':') || line.length < 11 || line.length % 2 === 0) {
			throw ProgError.hexFile(`第 ${lineNo} 行: Intel HEX 记录格式错误`);
		}
		const bytes: number[] = [];
		for (let i = 1; i < line.length; i += 2) {
			bytes.push(hexByte(line.slice(i, i + 2), lineNo));
		}
		const count = bytes[0];
		if (bytes.length !== count + 5) {
			throw ProgError.hexFile(`第 ${lineNo} 行: 字节计数不符`);
		}
		let sum = 0;
		for (const byte of bytes) {
			sum = (sum + byte) & 0xFF;
		}
		if (sum !== 0) {
			throw ProgError.hexFile(`第 ${lineNo} 行: 校验和错误`);
		}
		const address = (bytes[1] << 8) | bytes[2];
		const recordType = bytes[3];
		const data = bytes.slice(4, 4 + count);
		switch (recordType) {
			case 0x00: {
				for (let i = 0; i < data.length; i++) {
					sparse.push([upperBase + address + i, data[i]]);
				}
				break;
			}
			case 0x01:
				break;
			case 0x02:
				upperBase = (((data[0] << 8) | data[1]) << 4) >>> 0;
				break;
			case 0x04:
				upperBase = (((data[0] << 8) | data[1]) << 16) >>> 0;
				break;
			default:
				break;
		}
	}
	if (sparse.length === 0) {
		throw ProgError.hexFile('无数据记录');
	}
	return sparse;
}

/** Motorola S-record：S1(16bit)/S2(24bit)/S3(32bit) 数据记录；S0=头 S5=计数 S7/S8/S9=结束（忽略） */
function parseSrecord(text: string): Array<[number, number]> {
	const sparse: Array<[number, number]> = [];
	const lines = text.split(/\r?\n/);
	for (let index = 0; index < lines.length; index++) {
		const lineNo = index + 1;
		const line = lines[index].trim();
		if (!line) {
			continue;
		}
		const bytes: number[] = [];
		for (let i = 2; i + 2 <= line.length; i += 2) {
			bytes.push(hexByte(line.slice(i, i + 2), lineNo));
		}
		if (bytes.length < 2) {
			throw ProgError.hexFile(`第 ${lineNo} 行: 记录过短`);
		}
		let sum = 0;
		for (const byte of bytes) {
			sum = (sum + byte) & 0xFF;
		}
		if (sum !== 0xFF) {
			throw ProgError.hexFile(`第 ${lineNo} 行: 校验和错误`);
		}
		const count = bytes[0];
		if (count + 1 !== bytes.length) {
			throw ProgError.hexFile(`第 ${lineNo} 行: 字节计数不符`);
		}
		const type = line[1].toUpperCase();
		const addrLen = type === '1' ? 2 : type === '2' ? 3 : type === '3' ? 4 : 0;
		if (addrLen === 0) {
			if (type === '0' || type === '5' || type === '7' || type === '8' || type === '9') {
				continue;
			}
			throw ProgError.hexFile(`第 ${lineNo} 行: 未知记录 S${type}`);
		}
		const dataLen = count - addrLen - 1;
		if (dataLen < 0) {
			throw ProgError.hexFile(`第 ${lineNo} 行: 字节计数不符`);
		}
		let addr = 0;
		for (const byte of bytes.slice(1, 1 + addrLen)) {
			addr = (addr << 8) | byte;
		}
		for (let i = 0; i < dataLen; i++) {
			sparse.push([addr + i, bytes[1 + addrLen + i]]);
		}
	}
	if (sparse.length === 0) {
		throw ProgError.hexFile('无 S-record 数据');
	}
	return sparse;
}

/** 清洗：过滤 + 合并连续区间（空洞不填充） */
function wash(sparse: Array<[number, number]>, chip: ChipDef, format: HexFormat): HexImage {
	sparse.sort((left, right) => left[0] - right[0]);

	const warnings: string[] = [];
	let nvrDropped = 0;
	let secureDropped = 0;
	let belowLow = false;
	let outOfRange = 0;

	const kept = sparse.filter(([addr]) => {
		if (addr < FLASH_LOW) {
			belowLow = true;
			return false;
		}
		if (addr >= NVR_LOW && addr <= NVR_HIGH) {
			nvrDropped++;
			return false;
		}
		if (addr === SECURE_ADDR) {
			secureDropped++;
			return false;
		}
		if (!isValidAddr(chip, addr)) {
			outOfRange++;
			return false;
		}
		return true;
	});
	if (belowLow) {
		throw ProgError.hexFile(`数据低于 0x${FLASH_LOW.toString(16).toUpperCase().padStart(4, '0')}（越界硬错误）`);
	}
	if (nvrDropped > 0) {
		warnings.push(`剔除 NVR 区 0xFFBB~0xFFBF 共 ${nvrDropped} 字节（保护 CR 校准值）`);
	}
	if (secureDropped > 0) {
		warnings.push('剔除 0xFFFC 安全位（由“写入安全位”选项处理）');
	}
	if (outOfRange > 0) {
		warnings.push(`剔除超出 ${chip.name} Flash 映射（${rangesDesc(chip)}）共 ${outOfRange} 字节，请确认型号选择`);
	}
	if (kept.length === 0) {
		throw ProgError.hexFile('过滤后无可烧录数据（全部落在 NVR/安全位/越界区）');
	}

	const merged: Array<{ start: number; bytes: number[] }> = [];
	for (const [addr, byte] of kept) {
		const last = merged[merged.length - 1];
		if (last && addr === last.start + last.bytes.length) {
			last.bytes.push(byte);
		} else {
			merged.push({ start: addr, bytes: [byte] });
		}
	}
	const segments = merged.map(segment => ({ start: segment.start, data: Buffer.from(segment.bytes) }));
	return { segments, warnings, format };
}
