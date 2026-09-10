// F2MC-LINK 烧录文件解析与清洗单元测试（移植自 f2mc-core hexfile.rs 测试）。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal, throws } from 'node:assert/strict';
import { describe, it } from 'node:test';

import type { ChipDef } from '../../../flasher/f2mcLink/chipdef';
import { parseHexImage } from '../../../flasher/f2mcLink/hexfile';

const CHIP: ChipDef = { name: 'MB95F636H', upperLow: 0x8000, flashBytes: 36 * 1024, fram: false };
const CHIP_8K: ChipDef = { name: 'MB95F632H', upperLow: 0xF000, flashBytes: 8 * 1024, fram: false };

function hexLine(addr: number, recordType: number, data: number[]): string {
	const bytes = [data.length, (addr >> 8) & 0xFF, addr & 0xFF, recordType, ...data];
	const sum = bytes.reduce((acc, byte) => (acc + byte) & 0xFF, 0);
	const checksum = (~sum + 1) & 0xFF;
	return `:${[...bytes, checksum].map(byte => byte.toString(16).toUpperCase().padStart(2, '0')).join('')}\n`;
}

function s1Line(addr: number, data: number[]): string {
	const bytes = [data.length + 3, (addr >> 8) & 0xFF, addr & 0xFF, ...data];
	const sum = bytes.reduce((acc, byte) => (acc + byte) & 0xFF, 0);
	const checksum = ~sum & 0xFF;
	return `S1${[...bytes, checksum].map(byte => byte.toString(16).toUpperCase().padStart(2, '0')).join('')}\n`;
}

describe('f2mcLink/hexfile', () => {
	it('Intel HEX 简单解析', () => {
		const image = parseHexImage(hexLine(0x8000, 0, [1, 2, 3]) + hexLine(0, 1, []), CHIP);
		equal(image.format, 'intelHex');
		equal(image.segments.length, 1);
		equal(image.segments[0].start, 0x8000);
		deepEqual([...image.segments[0].data], [1, 2, 3]);
		equal(image.warnings.length, 0);
	});

	it('剔除 NVR 区与 0xFFFC 安全位并告警', () => {
		const text = hexLine(0x8000, 0, [0xAA]) + hexLine(0xFFBB, 0, [1, 2, 3]) + hexLine(0xFFFC, 0, [0x01]) + hexLine(0, 1, []);
		const image = parseHexImage(text, CHIP);
		equal(image.segments.length, 1);
		deepEqual([...image.segments[0].data], [0xAA]);
		equal(image.warnings.length, 2);
		equal(image.warnings[0].includes('NVR'), true);
		equal(image.warnings[1].includes('0xFFFC'), true);
	});

	it('低于 0x1000 为硬错误', () => {
		throws(() => parseHexImage(hexLine(0x0800, 0, [1]) + hexLine(0, 1, []), CHIP));
	});

	it('超出所选型号 Flash 映射：剔除并告警', () => {
		const text = hexLine(0x9000, 0, [1, 2]) + hexLine(0x1000, 0, [9]) + hexLine(0xF000, 0, [3]) + hexLine(0, 1, []);
		const image = parseHexImage(text, CHIP_8K);
		deepEqual(image.segments.map(segment => segment.start), [0x1000, 0xF000]);
		equal(image.warnings.some(warning => warning.includes('型号')), true);
	});

	it('空洞不填充（拆分为独立区间）', () => {
		const image = parseHexImage(hexLine(0x8000, 0, [1]) + hexLine(0x8010, 0, [2]) + hexLine(0, 1, []), CHIP);
		equal(image.segments.length, 2);
	});

	it('S-record S1 解析', () => {
		const text = 'S0030000FC\n' + s1Line(0x8000, [0xDE, 0xAD, 0xBE, 0xEF]) + 'S9030000FC\n';
		const image = parseHexImage(text, CHIP);
		equal(image.format, 'srecord');
		equal(image.segments.length, 1);
		deepEqual([...image.segments[0].data], [0xDE, 0xAD, 0xBE, 0xEF]);
	});

	it('S-record 校验和错误检出', () => {
		const bad = s1Line(0x8000, [1, 2, 3]).replace(/..\n$/, '00\n');
		throws(() => parseHexImage(bad, CHIP));
	});

	it('Intel HEX 校验和错误检出', () => {
		const bad = hexLine(0x8000, 0, [1, 2, 3]).replace(/..\n$/, '00\n');
		throws(() => parseHexImage(bad, CHIP));
	});
});
