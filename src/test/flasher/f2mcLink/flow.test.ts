// F2MC-LINK 烧录流程端到端测试（模拟器驱动，移植自 f2mc-core flow.rs 测试）。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal, rejects } from 'node:assert/strict';
import { describe, it } from 'node:test';

import type { ChipDef } from '../../../flasher/f2mcLink/chipdef';
import { ProgError } from '../../../flasher/f2mcLink/errors';
import { program, type CancelToken, type FlowEvent, type FlowStage } from '../../../flasher/f2mcLink/flow';
import { parseHexImage } from '../../../flasher/f2mcLink/hexfile';
import { F2mcLinkClient } from '../../../flasher/f2mcLink/proto';
import { SimProgrammer, SimState } from '../../../flasher/f2mcLink/sim';

const CHIP: ChipDef = { name: 'MB95F636H', upperLow: 0x8000, flashBytes: 36 * 1024, fram: false };
const DEFAULT_OPTIONS = { writeSecure: false, resetAfter: true };

function makeHex(data: Array<[number, number[]]>): string {
	let text = '';
	for (const [addr, bytes] of data) {
		for (let i = 0; i < bytes.length; i += 16) {
			const chunk = bytes.slice(i, i + 16);
			const recordAddr = addr + i;
			const record = [chunk.length, (recordAddr >> 8) & 0xFF, recordAddr & 0xFF, 0, ...chunk];
			const sum = record.reduce((acc, byte) => (acc + byte) & 0xFF, 0);
			const checksum = (~sum + 1) & 0xFF;
			text += `:${[...record, checksum].map(byte => byte.toString(16).toUpperCase().padStart(2, '0')).join('')}\n`;
		}
	}
	return text + ':00000001FF\n';
}

function noCancel(): CancelToken {
	return { cancelled: false };
}

describe('f2mcLink/flow', () => {
	it('全流程：写入 600B 跨两个 WRITE 块，校验通过，模拟器 flash 内容一致', async () => {
		const payload = Array.from({ length: 600 }, (_, index) => index % 251);
		const image = parseHexImage(makeHex([[0x8000, payload]]), CHIP);
		const sim = new SimProgrammer();
		const client = new F2mcLinkClient(sim);
		const stages: FlowStage[] = [];
		const report = await program(client, image, DEFAULT_OPTIONS, (event: FlowEvent) => {
			if (event.type === 'stage') {
				stages.push(event.stage);
			}
		}, noCancel());

		equal(report.bytesWritten, 600);
		equal(report.bytesVerified, 600);
		equal(report.unlocked, false);
		for (let i = 0; i < payload.length; i++) {
			equal(sim.flash.get(0x8000 + i), payload[i], `mismatch at ${i}`);
		}
		deepEqual(stages, ['ping', 'enterPgm', 'erase', 'flashInit', 'crTrim', 'write', 'verify', 'done']);
		equal(sim.state, SimState.IDLE); // resetAfter → RESET_RUN 归位 IDLE
	});

	it('安全锁：ENTER_PGM 返回锁 → 自动整片擦除解锁 → 重试成功', async () => {
		const image = parseHexImage(makeHex([[0x8000, Array(16).fill(0xAA)]]), CHIP);
		const sim = new SimProgrammer();
		sim.locked = true;
		const client = new F2mcLinkClient(sim);
		const report = await program(client, image, DEFAULT_OPTIONS, () => undefined, noCancel());
		equal(report.unlocked, true);
		equal(sim.locked, false);
	});

	it('写安全位选项：0xFFFC 写入 0x01 且 QUIT 后生效', async () => {
		const image = parseHexImage(makeHex([[0x8000, Array(8).fill(0x55)]]), CHIP);
		const sim = new SimProgrammer();
		const client = new F2mcLinkClient(sim);
		await program(client, image, { writeSecure: true, resetAfter: true }, () => undefined, noCancel());
		equal(sim.locked, true); // QUIT 使安全位生效
	});

	it('取消令牌在块间生效', async () => {
		const image = parseHexImage(makeHex([[0x8000, Array(1024).fill(0x11)]]), CHIP); // 两个 WRITE 块
		const sim = new SimProgrammer();
		const client = new F2mcLinkClient(sim);
		const cancel = noCancel();
		let writes = 0;
		await rejects(
			program(client, image, DEFAULT_OPTIONS, (event: FlowEvent) => {
				if (event.type === 'progress' && event.stage === 'write') {
					writes++;
					if (writes === 1) {
						cancel.cancelled = true; // 第一块后取消
					}
				}
			}, cancel),
			(error: ProgError) => error.kind === 'cancelled'
		);
	});

	it('校验失败能检出（写不进的目标）', async () => {
		const image = parseHexImage(makeHex([[0x8000, Array(64).fill(0x42)]]), CHIP);
		// 注入：WRITE_COMMIT 正常写入，但读回全 0xFF（模拟写不进）
		class CorruptSim extends SimProgrammer {
			protected override readFlash(): number {
				return 0xFF;
			}
		}
		const client = new F2mcLinkClient(new CorruptSim());
		await rejects(
			program(client, image, DEFAULT_OPTIONS, () => undefined, noCancel()),
			(error: ProgError) => error.message.includes('校验失败')
		);
	});
});
