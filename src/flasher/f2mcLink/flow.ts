// 烧录流程状态机：完整烧录，含安全锁自动解锁、CR Trimming 检查回写、超时恢复与取消支持。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/flow.rs。
//
// 完整流程：PING → ENTER_PGM（锁则自动整片擦除解锁重试一次）→ ERASE →
// FLASH_INIT(0x02,0x7C) → CR Trimming 检查 → 分块 WRITE(≤512B) →
// READ 校验(跳过 0xFFBB/BC/BD) → [WRITE_SECURE] → QUIT → RESET_RUN

import { ProgError, StatusCode } from './errors';
import type { HexImage } from './hexfile';
import { CR_NVR_ADDRS, CR_RAM_ADDRS, FLASH_INIT_XX, FLASH_INIT_YY, VERIFY_SKIP } from './new8fx';
import { F2mcLinkClient, READ_BLOCK_MAX, WRITE_BLOCK_MAX } from './proto';

export type FlowStage = 'ping' | 'enterPgm' | 'erase' | 'flashInit' | 'crTrim' | 'write' | 'verify' | 'secure' | 'done';

export const STAGE_LABELS: Record<FlowStage, string> = {
	ping: '连接握手',
	enterPgm: '进入编程模式',
	erase: '擦除',
	flashInit: '初始化',
	crTrim: 'CR 校准检查',
	write: '写入',
	verify: '校验',
	secure: '写入安全位',
	done: '完成'
};

export interface FlowOptions {
	/** 烧录后写 0xFFFC 安全位 */
	writeSecure: boolean;
	/** 烧录完成后复位运行 */
	resetAfter: boolean;
}

export type FlowEvent =
	| { type: 'stage'; stage: FlowStage }
	| { type: 'progress'; stage: FlowStage; done: number; total: number }
	| { type: 'log'; message: string }
	| { type: 'warn'; message: string };

export interface FlowReport {
	bytesWritten: number;
	bytesVerified: number;
	crTrimFixed: number;
	/** 本次流程是否执行过自动解锁（整片擦除） */
	unlocked: boolean;
	elapsedSecs: number;
}

/** 取消令牌：置 cancelled=true 后流程在下一个检查点抛 cancelled；HID 传输层在等待期间据其发 ABORT */
export interface CancelToken {
	cancelled: boolean;
}

function sleep(ms: number): Promise<void> {
	return new Promise(resolve => setTimeout(resolve, ms));
}

function checkCancel(cancel: CancelToken): void {
	if (cancel.cancelled) {
		throw ProgError.cancelled();
	}
}

/** 完整烧录流程（擦除 + 写入 + 校验） */
export async function program(
	client: F2mcLinkClient,
	image: HexImage,
	opts: FlowOptions,
	onEvent: (event: FlowEvent) => void,
	cancel: CancelToken
): Promise<FlowReport> {
	const t0 = Date.now();
	const report: FlowReport = { bytesWritten: 0, bytesVerified: 0, crTrimFixed: 0, unlocked: false, elapsedSecs: 0 };
	const total = image.segments.reduce((sum, segment) => sum + segment.data.length, 0);

	onEvent({ type: 'stage', stage: 'ping' });
	const id = await client.ping();
	onEvent({ type: 'log', message: `PING: ${id}，固件版本 v${client.fwVersion?.join('.') ?? '?'}` });
	if (id !== 'F2MC-LINK') {
		throw ProgError.transport(`设备标识 "${id}" 不是 F2MC-LINK 编程器，已中止（可能选错了 CMSIS-DAP 设备）`);
	}
	checkCancel(cancel);

	// 到 SYNCED（安全锁自动解锁一次）
	onEvent({ type: 'stage', stage: 'enterPgm' });
	try {
		const lockedHint = await sessionBeginSynced(client, onEvent, cancel);
		if (lockedHint) {
			onEvent({ type: 'warn', message: '目标已加安全锁（last_error=0x02），整片擦除将自动解锁' });
			report.unlocked = true;
		}
	} catch (error) {
		if (!(error instanceof ProgError && error.kind === 'securityLocked')) {
			throw error;
		}
		onEvent({ type: 'warn', message: '目标已加安全锁，执行整片擦除解锁后重试' });
		await eraseWithRecovery(client, 0x0000, onEvent, cancel);
		report.unlocked = true;
		try {
			await enterPgmWithRecovery(client, onEvent, cancel);
		} catch (retryError) {
			if (retryError instanceof ProgError && retryError.kind === 'securityLocked') {
				throw ProgError.transport('整片擦除解锁后仍处于安全锁状态');
			}
			throw retryError;
		}
	}
	checkCancel(cancel);

	onEvent({ type: 'stage', stage: 'erase' });
	await eraseWithRecovery(client, 0x0000, onEvent, cancel);
	checkCancel(cancel);

	// FLASH_INIT（500 Kbps 切换由固件完成）
	onEvent({ type: 'stage', stage: 'flashInit' });
	await client.flashInit(FLASH_INIT_XX, FLASH_INIT_YY);
	checkCancel(cancel);

	// CR Trimming 检查（Spec 7.11）
	onEvent({ type: 'stage', stage: 'crTrim' });
	report.crTrimFixed = await crTrimCheck(client, onEvent);
	checkCancel(cancel);

	// 写入（分块 ≤512B）
	onEvent({ type: 'stage', stage: 'write' });
	let done = 0;
	for (const segment of image.segments) {
		let offset = 0;
		while (offset < segment.data.length) {
			const count = Math.min(segment.data.length - offset, WRITE_BLOCK_MAX);
			const addr = segment.start + offset;
			await client.writeBlock(addr, segment.data.subarray(offset, offset + count));
			offset += count;
			done += count;
			onEvent({ type: 'progress', stage: 'write', done, total });
			checkCancel(cancel);
		}
	}
	report.bytesWritten = done;

	// 校验（读回比对，跳过 0xFFBB/BC/BD）
	onEvent({ type: 'stage', stage: 'verify' });
	report.bytesVerified = await verifyImage(client, image, total, onEvent, cancel);

	// 结束后再查一次 CR Trimming（写 0xFFBB 区后需再确认一致）
	report.crTrimFixed += await crTrimCheck(client, onEvent);

	if (opts.writeSecure) {
		onEvent({ type: 'stage', stage: 'secure' });
		await client.writeSecure();
		await client.quit();
		onEvent({ type: 'log', message: '已写入安全位 0xFFFC=0x01（断电复位后生效）' });
	}

	if (opts.resetAfter) {
		await resetRunGraceful(client, onEvent);
	} else {
		onEvent({ type: 'log', message: '保持编程模式：可连续执行烧录/校验/读取' });
	}

	onEvent({ type: 'stage', stage: 'done' });
	report.elapsedSecs = (Date.now() - t0) / 1000;
	return report;
}

/** 镜像读回比对（跳过 0xFFBB/BC/BD 三个 CR 校准字节），返回校验字节数 */
async function verifyImage(
	client: F2mcLinkClient,
	image: HexImage,
	total: number,
	onEvent: (event: FlowEvent) => void,
	cancel: CancelToken
): Promise<number> {
	let verified = 0;
	for (const segment of image.segments) {
		let offset = 0;
		while (offset < segment.data.length) {
			const count = Math.min(segment.data.length - offset, READ_BLOCK_MAX);
			const addr = segment.start + offset;
			const read = await client.readBlock(addr, count);
			for (let i = 0; i < count; i++) {
				const absolute = addr + i;
				if (VERIFY_SKIP.includes(absolute)) {
					continue;
				}
				const want = segment.data[offset + i];
				const got = read[i];
				if (want !== got) {
					const hex = (value: number): string => `0x${value.toString(16).toUpperCase().padStart(2, '0')}`;
					throw ProgError.transport(`校验失败 @0x${absolute.toString(16).toUpperCase().padStart(4, '0')}：写入 ${hex(want)}，读回 ${hex(got)}`);
				}
			}
			offset += count;
			verified += count;
			onEvent({ type: 'progress', stage: 'verify', done: verified, total });
			checkCancel(cancel);
		}
	}
	return verified;
}

/**
 * 会话入口：到达 SYNCED（握手有效）。
 * QUIT 后的 SYNCED 握手已失效（GET_STATE 无法区分），一律复位状态机后完整重进。
 * 返回 true 表示 GET_STATE 的 last_error 显示目标处于安全锁（0x02）。
 */
async function sessionBeginSynced(
	client: F2mcLinkClient,
	onEvent: (event: FlowEvent) => void,
	cancel: CancelToken
): Promise<boolean> {
	const [state, lastErr] = await client.getState();
	const lockedHint = lastErr === StatusCode.SECURITY_LOCKED;
	if (state === 3) {
		onEvent({ type: 'log', message: '编程器在读写模式，QUIT 退回 SYNCED' });
		await client.quit();
		onEvent({ type: 'log', message: '重新进入编程模式（QUIT 后握手已失效）' });
		await client.resetRun().catch(() => undefined);
		await enterPgmWithRecovery(client, onEvent, cancel);
		return lockedHint;
	}
	if (state === 1) {
		onEvent({ type: 'log', message: '重新进入编程模式（确保握手有效）' });
		await client.resetRun().catch(() => undefined);
		await enterPgmWithRecovery(client, onEvent, cancel);
		return lockedHint;
	}
	await enterPgmWithRecovery(client, onEvent, cancel);
	return false;
}

/**
 * CR Trimming 检查（Spec 7.11）：读 NVR 与 RAM 镜像，不一致则把 RAM 值写回 NVR。
 * 真机 DA 不实现 Spec 7.9 的 0x55 命令（CR_TRIM_WRITE 恒回 ACK_ERROR），必须用普通写路径写 0xFFBB 起。
 * 返回修复的字节数。
 */
async function crTrimCheck(client: F2mcLinkClient, onEvent: (event: FlowEvent) => void): Promise<number> {
	const hex = (value: number): string => `0x${value.toString(16).toUpperCase().padStart(2, '0')}`;
	const nvr = await client.readBlock(CR_NVR_ADDRS[0], 3);
	const ramLo = await client.readBlock(CR_RAM_ADDRS[1], 2); // 0x0FE4, 0x0FE5
	const ramHi = await client.readBlock(CR_RAM_ADDRS[0], 1); // 0x0FE7
	const ram = [ramHi[0], ramLo[0], ramLo[1]]; // 与 NVR 顺序对应：FFBB↔0FE7, FFBC↔0FE4, FFBD↔0FE5

	let fixed = 0;
	for (let i = 0; i < 3; i++) {
		if (nvr[i] === ram[i]) {
			continue;
		}
		if (ram[i] === 0xFF) {
			onEvent({ type: 'warn', message: `CR 校准失配 ${hex(CR_NVR_ADDRS[i])}: NVR=${hex(nvr[i])} 但 RAM 镜像为空(0xFF)，跳过回写` });
			continue;
		}
		onEvent({ type: 'warn', message: `CR 校准失配 ${hex(CR_NVR_ADDRS[i])}: NVR=${hex(nvr[i])} RAM=${hex(ram[i])}，将 RAM 值经普通写路径回写 NVR` });
		await client.writeBlock(CR_NVR_ADDRS[i], Buffer.from([ram[i]]));
		fixed++;
	}
	return fixed;
}

/** 等待固件从长命令中返回（GET_STATE 轮询），每秒检查取消令牌 */
async function waitFirmware(
	client: F2mcLinkClient,
	onEvent: (event: FlowEvent) => void,
	cancel: CancelToken,
	maxSecs: number
): Promise<void> {
	for (let i = 0; i < maxSecs; i++) {
		await sleep(1000);
		checkCancel(cancel);
		try {
			const [state, lastErr] = await client.getState();
			onEvent({ type: 'log', message: `固件已返回：state=${state} last_error=0x${lastErr.toString(16).toUpperCase().padStart(2, '0')}` });
			return;
		} catch {
			// 固件仍忙，继续等
		}
	}
	throw ProgError.transport('编程器长时间无响应');
}

/** ERASE 超时恢复：固件侧擦除等待上限 60 s，上位机超时≠失败——先 GET_STATE 轮询等固件返回，再报错 */
async function eraseWithRecovery(
	client: F2mcLinkClient,
	addr: number,
	onEvent: (event: FlowEvent) => void,
	cancel: CancelToken
): Promise<void> {
	try {
		await client.erase(addr);
	} catch (error) {
		if (!(error instanceof ProgError && error.kind === 'timeout')) {
			throw error;
		}
		onEvent({ type: 'warn', message: 'ERASE 超时：等待固件返回（最长 ~90 s）…' });
		await waitFirmware(client, onEvent, cancel, 90);
		throw ProgError.transport('擦除失败：目标无响应，请检查接线后重试');
	}
}

/**
 * ENTER_PGM 超时恢复：目标无响应时固件失败路径最长 ~7 s，已在 10 s 超时覆盖范围内；
 * 此处仅作保底——超时后不得立即发新命令，先 GET_STATE 轮询等固件返回，再报错。
 */
async function enterPgmWithRecovery(
	client: F2mcLinkClient,
	onEvent: (event: FlowEvent) => void,
	cancel: CancelToken
): Promise<void> {
	await ensureIdle(client, onEvent, cancel);
	try {
		await client.enterPgm();
	} catch (error) {
		if (!(error instanceof ProgError && error.kind === 'timeout')) {
			throw error;
		}
		onEvent({ type: 'warn', message: 'ENTER_PGM 超时：固件可能仍在重试握手（最长 ~7 s），等待其返回…' });
		await waitFirmware(client, onEvent, cancel, 15);
		throw ProgError.transport('进入编程模式失败：目标无响应，请检查目标板供电与 DBG 接线后重试');
	}
}

/** 确保编程器状态机处于 IDLE（ENTER_PGM 仅在 IDLE 可用）。固件忙时 GET_STATE 会超时，轮询等待 */
async function ensureIdle(
	client: F2mcLinkClient,
	onEvent: (event: FlowEvent) => void,
	cancel: CancelToken
): Promise<void> {
	for (let attempt = 0; attempt < 15; attempt++) {
		try {
			const [state] = await client.getState();
			if (state !== 0) {
				onEvent({ type: 'log', message: `编程器状态非 IDLE（state=${state}），RESET_RUN 复位状态机` });
				await client.resetRun().catch(() => undefined);
			}
			return;
		} catch (error) {
			if (!(error instanceof ProgError && error.kind === 'timeout')) {
				throw error;
			}
			checkCancel(cancel);
			if (attempt === 0) {
				onEvent({ type: 'warn', message: '编程器仍忙，等待其返回…' });
			}
			await sleep(1000);
		}
	}
	throw ProgError.transport('编程器长时间无响应');
}

/**
 * RESET_RUN 容错：编程器无复位硬件，固件恒回 UNSUPPORTED 并把状态机复位到 IDLE——
 * F2MC-LINK v1.1 起有目标电源开关 → 自动断电→上电运行用户程序。
 */
async function resetRunGraceful(client: F2mcLinkClient, onEvent: (event: FlowEvent) => void): Promise<void> {
	try {
		await client.resetRun();
		onEvent({ type: 'log', message: '已复位运行用户程序' });
	} catch (error) {
		if (!(error instanceof ProgError && error.kind === 'deviceStatus' && error.status === StatusCode.UNSUPPORTED)) {
			throw error;
		}
		onEvent({ type: 'log', message: '编程器无复位硬件，自动断电重启以运行用户程序' });
		await client.setPower(false);
		await sleep(300);
		try {
			await client.setPower(true);
			onEvent({ type: 'log', message: '已自动上电，目标运行用户程序' });
		} catch (powerError) {
			if (powerError instanceof ProgError && powerError.kind === 'deviceStatus' && powerError.status === StatusCode.PWR_FAULT) {
				onEvent({ type: 'warn', message: '目标电源故障（过载/短路/未接目标，已自动关断），请人工检查供电' });
			}
			throw powerError;
		}
	}
}
