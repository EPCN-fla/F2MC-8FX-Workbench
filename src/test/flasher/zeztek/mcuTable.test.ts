// 芯片型号表单元测试（数据来源：烧录器 MCUtype.txt V5.1 + 上位机逆向）。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal } from 'node:assert/strict';
import { describe, it } from 'node:test';

import { BUILTIN_MCUS, blockAddrs, findMcuByCpuName, mcuAliases, totalKb } from '../../../flasher/zeztek/mcuTable';

describe('mcuTable', () => {
	it('cpuName 精确匹配（896.csv 中的型号名）', () => {
		const mcu = findMcuByCpuName('MB95F636K');
		if (!mcu) {
			throw new Error('MB95F636K 应能匹配');
		}
		equal(mcu.chipCode, 0x14);
		equal(mcu.name, 'MB95F636H/K');
	});

	it('cpuName 大小写不敏感', () => {
		equal(findMcuByCpuName('mb95f636k')?.chipCode, 0x14);
		equal(findMcuByCpuName('MB95F636H')?.chipCode, 0x14);
		equal(findMcuByCpuName('MB95F634H')?.chipCode, 0x10);
	});

	it('未知型号返回 undefined', () => {
		equal(findMcuByCpuName('MB95FV100'), undefined);
	});

	it('别名拆分', () => {
		deepEqual(mcuAliases(BUILTIN_MCUS[0]), ['MB95F636H/K', 'MB95F636H', 'MB95F636K']);
	});

	it('块地址: 低 bank 在前 + 主区每 4KB', () => {
		deepEqual(blockAddrs(BUILTIN_MCUS[0]), [0x1000, 0x8000, 0x9000, 0xA000, 0xB000, 0xC000, 0xD000, 0xE000, 0xF000]);
		equal(blockAddrs(BUILTIN_MCUS[0]).length, 9);
	});

	it('总 KB 数与 DATA_HDR 的 kb 字段一致（0x24 = 36KB）', () => {
		equal(totalKb(BUILTIN_MCUS[0]), 36);
	});
});
