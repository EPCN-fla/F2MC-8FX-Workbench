// 两套芯片表一致性：f2mcLink/chipdef（数据源 res/896.csv）与 zeztek/mcuTable
// 对重叠型号的 Flash 布局必须一致——否则切换 programmerType 会改变可烧录地址范围。
// 运行：npm run compile && npm run test:flasher
import * as fs from 'node:fs';
import * as path from 'node:path';
import { equal, ok } from 'node:assert/strict';
import { describe, it } from 'node:test';

import { findChipByName, LOWER_BANK_LOW, parseChipsCsv } from '../../flasher/f2mcLink/chipdef';
import { BUILTIN_MCUS, mcuAliases, totalKb } from '../../flasher/zeztek/mcuTable';

describe('chipTableConsistency', () => {
	it('mcuTable 全部型号与 896.csv 的 Flash 布局一致', () => {
		const csvPath = path.join(__dirname, '../../../res/896.csv');
		const chips = parseChipsCsv(fs.readFileSync(csvPath, 'latin1'));
		for (const mcu of BUILTIN_MCUS) {
			const matched = mcuAliases(mcu)
				.map(alias => findChipByName(chips, alias))
				.find(chip => chip !== undefined);
			ok(matched, `${mcu.name} 应在 896.csv 中存在`);
			equal(matched.upperLow, mcu.start, `${mcu.name} 上 bank 起始地址不一致`);
			equal(matched.flashBytes, totalKb(mcu) * 1024, `${mcu.name} Flash 容量不一致`);
			equal(mcu.lowBank, LOWER_BANK_LOW, `${mcu.name} 下 bank 起始地址不一致`);
		}
	});
});
