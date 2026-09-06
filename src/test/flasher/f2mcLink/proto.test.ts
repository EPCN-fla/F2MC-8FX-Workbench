// F2MC-LINK L1 协议（vendor/proto）单元测试（移植自 f2mc-core proto.rs 测试）。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal, rejects } from 'node:assert/strict';
import { describe, it } from 'node:test';

import { ProgError } from '../../../flasher/f2mcLink/errors';
import { Cmd, F2mcLinkClient } from '../../../flasher/f2mcLink/proto';
import { SimProgrammer, SimState } from '../../../flasher/f2mcLink/sim';
import { transact, type DapTransport } from '../../../flasher/f2mcLink/vendor';

/** 恒超时传输层（验证超时不重试） */
class TimeoutTransport implements DapTransport {
	public calls = 0;
	public async dapTransfer(_request: Buffer, _timeoutMs: number): Promise<Buffer> {
		this.calls++;
		throw ProgError.timeout();
	}
}

describe('f2mcLink/vendor+proto', () => {
	it('ABORTED(0x0B) 状态码映射为用户取消', async () => {
		const abortedTransport: DapTransport = {
			dapTransfer: async () => Buffer.from([0x80, 0x0B])
		};
		await rejects(
			transact(abortedTransport, Cmd.ENTER_PGM, Buffer.alloc(0), 0, 1000),
			(error: ProgError) => error.kind === 'cancelled'
		);
	});

	it('传输层错误重试一次后成功（sim.failNext=1）', async () => {
		const sim = new SimProgrammer();
		sim.failNext = 1;
		const client = new F2mcLinkClient(sim);
		const id = await client.ping();
		equal(id, 'F2MC-LINK');
		deepEqual(client.fwVersion, [0, 1, 0]);
	});

	it('设备状态码错误不重试（安全锁）', async () => {
		const sim = new SimProgrammer();
		sim.locked = true;
		const client = new F2mcLinkClient(sim);
		await rejects(client.enterPgm(), (error: ProgError) => error.kind === 'securityLocked');
		const enterCount = sim.frameLog.filter(frame => frame[1] === Cmd.ENTER_PGM).length;
		equal(enterCount, 1);
	});

	it('命令超时不重试（固件可能仍在执行）', async () => {
		const transport = new TimeoutTransport();
		await rejects(
			transact(transport, Cmd.PING, Buffer.alloc(0), 12, 100),
			(error: ProgError) => error.kind === 'timeout'
		);
		equal(transport.calls, 1);
	});

	it('WRITE_BEGIN/DATA/COMMIT 帧格式与 ≤56B 拆包', async () => {
		const sim = new SimProgrammer();
		const client = new F2mcLinkClient(sim);
		await client.ping();
		await client.enterPgm();
		await client.erase(0);
		await client.flashInit(0x02, 0x7C);

		const data = Buffer.alloc(130, 0xAB); // 130 = 56+56+18 → 3 个 DATA 包
		await client.writeBlock(0x8123, data);

		const begin = sim.frameLog.find(frame => frame[1] === Cmd.WRITE_BEGIN);
		if (!begin) {
			throw new Error('缺少 WRITE_BEGIN 帧');
		}
		deepEqual([...begin.subarray(4, 8)], [0x81, 0x23, 0x00, 130]);
		const dataFrames = sim.frameLog.filter(frame => frame[1] === Cmd.WRITE_DATA);
		equal(dataFrames.length, 3);
		equal(dataFrames[0].length - 4, 56);
		equal(dataFrames[1].length - 4, 56);
		equal(dataFrames[2].length - 4, 18);
		equal(sim.flash.get(0x8123), 0xAB);
		equal(sim.flash.get(0x8123 + 129), 0xAB);
	});

	it('READ_BEGIN/DATA 分块取回', async () => {
		const sim = new SimProgrammer();
		const client = new F2mcLinkClient(sim);
		await client.ping();
		await client.enterPgm();
		await client.erase(0);
		await client.flashInit(0x02, 0x7C);
		await client.writeBlock(0x9000, Buffer.alloc(100, 7));

		const got = await client.readBlock(0x9000, 100);
		equal(got.length, 100);
		equal(got.every(byte => byte === 7), true);
		const readDataCount = sim.frameLog.filter(frame => frame[1] === Cmd.READ_DATA).length;
		equal(readDataCount, 2); // 56 + 44
	});

	it('状态机防呆：SYNCED 态发 WRITE_BEGIN → STATE_ERROR', async () => {
		const sim = new SimProgrammer();
		const client = new F2mcLinkClient(sim);
		await client.ping();
		await client.enterPgm();
		equal(sim.state, SimState.SYNCED);
		await rejects(
			client.writeBlock(0x8000, Buffer.from([1, 2, 3])),
			(error: ProgError) => error.kind === 'deviceStatus'
		);
	});
});
