// F2MC-LINK 型号库单元测试（移植自 f2mc-core chipdef.rs 测试）。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal } from 'node:assert/strict';
import { describe, it } from 'node:test';

import { findChipByName, isValidAddr, parseChipsCsv, rangesDesc } from '../../../flasher/f2mcLink/chipdef';

const SAMPLE_CSV = [
	'08,33,01_2012.06.01,,,',
	'MB95F636H,FMC8FX,0x8000:0xFFFF,0',
	'MB95F632H,FMC8FX,0xF000:0xFFFF,0',
	'MB95R203,FMC8FX,0xE000:0xFFFF,0',
	'MB90F123,FMC8L,0x8000:0xFFFF,0'
].join('\n');

describe('f2mcLink/chipdef', () => {
	it('只收录 FMC8FX 家族，并按名称排序', () => {
		const chips = parseChipsCsv(SAMPLE_CSV);
		deepEqual(chips.map(chip => chip.name), ['MB95F632H', 'MB95F636H', 'MB95R203']);
	});

	it('F630 家族 Flash 布局：双 bank = 下 bank 4KB + 上 bank', () => {
		const chips = parseChipsCsv(SAMPLE_CSV);
		const f636 = findChipByName(chips, 'MB95F636H');
		if (!f636) {
			throw new Error('MB95F636H 应存在');
		}
		equal(f636.upperLow, 0x8000);
		equal(f636.flashBytes, 36 * 1024);
		equal(isValidAddr(f636, 0x8000), true);
		equal(isValidAddr(f636, 0x1000), true);
		equal(isValidAddr(f636, 0x7000), false);
		equal(isValidAddr(f636, 0xFFFF), true);
		equal(isValidAddr(f636, 0x10000), false); // 超出 16 位地址空间（HEX 扩展地址/S3 记录），防止 proto 截断回绕
		equal(isValidAddr(f636, 0x1FFBB), false);
		equal(rangesDesc(f636), '0x1000~0x1FFF + 0x8000~0xFFFF');

		const f632 = findChipByName(chips, 'MB95F632H');
		equal(f632?.upperLow, 0xF000);
		equal(f632?.flashBytes, 8 * 1024);
	});

	it('非 MB95F 前缀标记为 FRAM（串行编程不适用）', () => {
		const chips = parseChipsCsv(SAMPLE_CSV);
		equal(findChipByName(chips, 'MB95R203')?.fram, true);
		equal(findChipByName(chips, 'MB95F636H')?.fram, false);
	});

	it('按名称查找大小写不敏感，未知型号返回 undefined', () => {
		const chips = parseChipsCsv(SAMPLE_CSV);
		equal(findChipByName(chips, 'mb95f636h')?.name, 'MB95F636H');
		equal(findChipByName(chips, 'MB95F999'), undefined);
	});
});
