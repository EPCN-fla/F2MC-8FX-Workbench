// S-record 解析/镜像组装单元测试。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal, throws } from 'node:assert/strict';
import { describe, it } from 'node:test';

import { SRecordError, buildImage, imageChecksum, parseS19, validateRange } from '../../flasher/srecord';

// S1 记录: 0x8000 起 5 字节 11 22 33 44 55（拆成两条记录）
const S19_TEXT = [
	'S00600004844521B',
	'S107800011223344CE',
	'S10480045522',
	'S9030000FC',
	''
].join('\r\n');

describe('parseS19', () => {
	it('解析并合并连续段', () => {
		const segments = parseS19(S19_TEXT);
		equal(segments.length, 1);
		equal(segments[0].start, 0x8000);
		deepEqual([...segments[0].data], [0x11, 0x22, 0x33, 0x44, 0x55]);
	});

	it('计数不符报错', () => {
		throws(() => parseS19('S107800011223344CD\r\n'), SRecordError);
	});

	it('校验和错误报错', () => {
		// 0x8000 处 1 字节 0xAB: count=4, sum=4+0x80+0xAB=0x12F → cks=0xD0; 改成 0xD1 应报错
		throws(() => parseS19('S1048000ABD1\r\n'), SRecordError);
	});

	it('无有效数据报错', () => {
		throws(() => parseS19('S00600004844521B\r\nS9030000FC\r\n'), SRecordError);
	});
});

describe('validateRange', () => {
	it('范围内通过', () => {
		validateRange(parseS19(S19_TEXT), [[0x8000, 0xFFFF]]);
	});

	it('低 bank 范围内通过', () => {
		const segments = parseS19('S1041000AB40\r\n'); // 0x1000: count=4, sum=4+0x10+0xAB=0xBF → cks=0x40
		validateRange(segments, [[0x1000, 0x1FFF], [0x8000, 0xFFFF]]);
	});

	it('超范围报错（同原上位机提示）', () => {
		const segments = parseS19('S1040100AB4F\r\n'); // 0x0100: count=4, sum=4+0x01+0xAB=0xB0 → cks=0x4F
		throws(() => validateRange(segments, [[0x8000, 0xFFFF]]), /所选型号跟烧写文件地址不符/);
	});
});

describe('buildImage / imageChecksum', () => {
	it('未覆盖地址填充 0xFF', () => {
		const segments = parseS19(S19_TEXT);
		const blocks = buildImage(segments, [0x8000]);
		equal(blocks.length, 1);
		equal(blocks[0].length, 0x1000);
		deepEqual([...blocks[0].subarray(0, 5)], [0x11, 0x22, 0x33, 0x44, 0x55]);
		equal(blocks[0][0x1000 - 1], 0xFF);
		const expected = 0x11 + 0x22 + 0x33 + 0x44 + 0x55 + 0xFF * (0x1000 - 5);
		equal(imageChecksum(blocks), expected >>> 0);
	});
});
