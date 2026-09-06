// 协议层单元测试（黄金数据来自 Fujitsu_Pro_ZZ_V5.0.exe 反汇编结论，
// 与 fujitsu_programmer/tests/test_protocol.py 数值一致）。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal } from 'node:assert/strict';
import { describe, it } from 'node:test';

import {
	Cmd, FrameReader, Mode, Power, ProtocolError, Status, ZeztekProgrammer,
	buildDataHdrFrame, buildReadFrame, buildSetFrame, cmdFrame, dataBlock, type ByteStream
} from '../../../flasher/zeztek/protocol';

describe('protocol frames', () => {
	it('SET 在线/5V/不限次数', () => {
		deepEqual(buildSetFrame(Mode.ONLINE, Power.V5, [0, 0], 0x00), Buffer.from('680605555000000016', 'hex'));
	});

	it('SET 离线/3.3V/次数/使能', () => {
		deepEqual(buildSetFrame(Mode.OFFLINE, Power.V3_3, [0x12, 0x34], 0x55), Buffer.from('680605AA3312345516', 'hex'));
	});

	it('擦除/写入/校验/一键 命令帧', () => {
		deepEqual(cmdFrame(Cmd.ERASE), Buffer.from('68010016', 'hex'));
		deepEqual(cmdFrame(Cmd.WRITE), Buffer.from('68020016', 'hex'));
		deepEqual(cmdFrame(Cmd.CHECK), Buffer.from('68030016', 'hex'));
		deepEqual(cmdFrame(Cmd.EPC), Buffer.from('68050016', 'hex'));
	});

	it('数据头帧', () => {
		const frame = buildDataHdrFrame(0x24, 0x14, Buffer.from([0x12, 0x34, 0x56, 0x78, 0x90]), 1);
		deepEqual(frame, Buffer.from('680008241412345678900116', 'hex'));
		equal(frame.length, 12);
	});

	it('读出帧', () => {
		deepEqual(buildReadFrame(0x80, 0x00, 0x24), Buffer.from('68040380002416', 'hex'));
	});

	it('数据块校验和', () => {
		const block = dataBlock(0, 0x10, Buffer.alloc(0x1000, 0xAB));
		equal(block.length, 0x1006);
		deepEqual(block.subarray(0, 2), Buffer.from([0, 0x10]));
		deepEqual(block.subarray(block.length - 4), Buffer.from([0x00, 0x0A, 0xB0, 0x00])); // 0xAB * 0x1000 = 0xAB000
		const block8 = dataBlock(8, 0xF0, Buffer.alloc(0x1000, 0));
		deepEqual(block8.subarray(0, 2), Buffer.from([8, 0xF0]));
		deepEqual(block8.subarray(block8.length - 4), Buffer.from([0, 0, 0, 0]));
	});
});

describe('frame reader', () => {
	it('单帧', () => {
		const reader = new FrameReader();
		reader.feed(Buffer.from('68010016', 'hex'));
		deepEqual(reader.popFrame(), { cmd: 0x01, payload: Buffer.alloc(0) });
	});

	it('垃圾字节 + 带负载帧', () => {
		const reader = new FrameReader();
		reader.feed(Buffer.concat([Buffer.from([0x00, 0x01, 0x6A, 0x75, 0x6E, 0x6B]), Buffer.from('680302995516', 'hex'), Buffer.from([0x00])]));
		deepEqual(reader.popFrame(), { cmd: 0x03, payload: Buffer.from([0x99, 0x55]) });
		equal(reader.popFrame(), undefined);
	});

	it('分包到达', () => {
		const reader = new FrameReader();
		reader.feed(Buffer.from('6806', 'hex'));
		equal(reader.popFrame(), undefined);
		reader.feed(Buffer.from('05555000000016', 'hex'));
		deepEqual(reader.popFrame(), { cmd: 0x06, payload: Buffer.from([0x55, 0x50, 0, 0, 0]) });
	});

	it('伪帧头重新同步', () => {
		const reader = new FrameReader();
		reader.feed(Buffer.from('68FFFF68010016', 'hex'));
		deepEqual(reader.popFrame(), { cmd: 0x01, payload: Buffer.alloc(0) });
	});
});

class FakeStream implements ByteStream {
	public written: Buffer[] = [];
	public replyAfterWrite: Array<Buffer | undefined> = [];
	protected callback: ((chunk: Buffer) => void) | undefined;

	public constructor(replies: Array<Buffer | undefined>) {
		this.replyAfterWrite = replies;
	}

	public async open(): Promise<void> {}

	public onData(callback: (chunk: Buffer) => void): void {
		this.callback = callback;
	}

	public async write(data: Buffer): Promise<void> {
		this.written.push(data);
		const reply = this.replyAfterWrite[this.written.length - 1];
		if (reply && this.callback) {
			setTimeout(() => this.callback?.(Buffer.from(reply)), 1);
		}
	}

	public async close(): Promise<void> {}
}

describe('upload handshake', () => {
	it('ACK 驱动的按块传输', async () => {
		const blocks = [0, 1, 2].map(i =>
			dataBlock(i, i === 0 ? 0x10 : 0x80 + (i - 1) * 0x10, Buffer.alloc(0x1000, i)));
		// 盒子脚本(实测真实格式): 块 ACK = 68 00 22 55 NN 16 (byte2=0x22 非长度!)
		//                        完成    = 68 00 01 99 CS1 CS2 16
		const stream = new FakeStream([
			undefined,
			Buffer.from('680022550116', 'hex'),
			Buffer.from('680022550216', 'hex'),
			Buffer.from('68000199ABCD16', 'hex')
		]);
		const dev = new ZeztekProgrammer('FAKE', () => {}, stream);
		dev.HDR_DELAY = 0;
		const progressCalls: Array<[number, number]> = [];
		await dev.uploadImage(blocks, 12, 0x14, { progress: (done, total) => progressCalls.push([done, total]) });
		equal(stream.written.length, 4); // 头 + 块0..2
		deepEqual(stream.written[0], buildDataHdrFrame(12, 0x14));
		deepEqual(stream.written[1], blocks[0]);
		deepEqual(stream.written[2], blocks[1]);
		deepEqual(stream.written[3], blocks[2]);
		deepEqual(progressCalls[progressCalls.length - 1], [3, 3]);

		// 回归：装载阶段的 ACK/完成帧残留在接收解析器中时，紧跟的一键命令必须仍能收到应答
		stream.replyAfterWrite.push(Buffer.from('6805019916', 'hex'));
		dev.CMD_TIMEOUT = 2.0;
		await dev.oneKey();
		equal(stream.written.length, 5);
		deepEqual(stream.written[4], cmdFrame(Cmd.EPC));
	});

	it('盒子请求非法块号立即中止', async () => {
		const blocks = [dataBlock(0, 0x10, Buffer.alloc(0x1000, 0))];
		const stream = new FakeStream([
			undefined,
			Buffer.from('68002255FF16', 'hex') // 请求块 255
		]);
		const dev = new ZeztekProgrammer('FAKE', () => {}, stream);
		dev.HDR_DELAY = 0;
		await dev.uploadImage(blocks, 4, 0x14).then(
			() => { throw new Error('应当抛出 ProtocolError'); },
			error => {
				if (!(error instanceof ProtocolError) || !error.message.includes('非法块号')) {
					throw new Error(`异常类型不符: ${error.message}`);
				}
			});
	});
});

describe('status decoding', () => {
	it('校验失败显示地址/写入/读出', async () => {
		class MismatchStream extends FakeStream {
			public constructor() {
				super([]);
			}

			public override async write(data: Buffer): Promise<void> {
				// CHECK 应答: 0xEE + 地址 0x8123 + 写入 0x5A + 读出 0xA5 (LEN=5)
				this.written.push(data);
				this.callback?.(Buffer.from('680305EE81235AA516', 'hex'));
			}
		}
		const dev = new ZeztekProgrammer('FAKE', () => {}, new MismatchStream());
		await dev.check().then(
			() => { throw new Error('应当抛出 ProtocolError'); },
			error => {
				if (!(error instanceof ProtocolError)) {
					throw new Error('异常类型不符');
				}
				equal(error.status, Status.MISMATCH);
				if (!error.message.includes('0x8123') || !error.message.includes('5A') || !error.message.includes('A5')) {
					throw new Error(`错误信息缺少地址/数据: ${error.message}`);
				}
			});
	});
});
