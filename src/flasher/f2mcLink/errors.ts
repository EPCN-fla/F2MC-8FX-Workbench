// 错误类型：L1 设备状态码与统一错误枚举。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/error.rs。

export const StatusCode = {
	OK: 0x00,
	TIMEOUT: 0x01,
	SECURITY_LOCKED: 0x02,
	ACK_ERROR: 0x03,
	TARGET_CHK_ERROR: 0x04,
	BAD_PARAM: 0x05,
	UART_ERROR: 0x06,
	STATE_ERROR: 0x07,
	FRAME_CRC_ERROR: 0x08,
	BUSY: 0x09,
	UNSUPPORTED: 0x0A,
	ABORTED: 0x0B,
	PWR_FAULT: 0x0C
} as const;

const STATUS_NAMES: Record<number, string> = {
	[StatusCode.TIMEOUT]: '目标应答超时',
	[StatusCode.SECURITY_LOCKED]: '目标已加安全锁',
	[StatusCode.ACK_ERROR]: '目标 ACK 错误',
	[StatusCode.TARGET_CHK_ERROR]: '目标侧校验和错误',
	[StatusCode.BAD_PARAM]: '请求参数非法',
	[StatusCode.UART_ERROR]: 'UART 底层错误',
	[StatusCode.STATE_ERROR]: '当前状态不允许该命令',
	[StatusCode.FRAME_CRC_ERROR]: '帧 CRC 错误',
	[StatusCode.BUSY]: '编程器忙',
	[StatusCode.UNSUPPORTED]: '硬件/固件不支持',
	[StatusCode.ABORTED]: '操作被中止',
	[StatusCode.PWR_FAULT]: '目标电源故障（过载/短路/未接目标，已自动关断）'
};

export function statusCodeText(code: number): string {
	return STATUS_NAMES[code] ?? `未知状态码 0x${code.toString(16).toUpperCase().padStart(2, '0')}`;
}

export type ProgErrorKind =
	| 'deviceStatus'     // 设备返回非零状态码
	| 'securityLocked'   // 目标已加安全锁（需整片擦除解锁）
	| 'transport'        // 传输层错误（USB/帧格式）
	| 'timeout'          // 命令响应超时（固件可能仍在执行，调用侧须先吸收迟到响应）
	| 'hexFile'          // 烧录文件解析/清洗错误
	| 'badParam'         // 调用参数非法
	| 'cancelled';       // 用户取消（含 ABORTED(0x0B) 映射）

export class ProgError extends Error {
	public readonly status: number | undefined;

	public constructor(
		public readonly kind: ProgErrorKind,
		message: string,
		status?: number
	) {
		super(message);
		this.name = 'ProgError';
		this.status = status;
	}

	public static deviceStatus(code: number): ProgError {
		return new ProgError('deviceStatus', `设备状态：${statusCodeText(code)}`, code);
	}

	public static securityLocked(): ProgError {
		return new ProgError('securityLocked', '目标已加安全锁（需整片擦除解锁）', StatusCode.SECURITY_LOCKED);
	}

	public static transport(message: string): ProgError {
		return new ProgError('transport', `传输错误：${message}`);
	}

	public static timeout(): ProgError {
		return new ProgError('timeout', '命令响应超时');
	}

	public static hexFile(message: string): ProgError {
		return new ProgError('hexFile', `烧录文件错误：${message}`);
	}

	public static badParam(message: string): ProgError {
		return new ProgError('badParam', `参数非法：${message}`);
	}

	public static cancelled(): ProgError {
		return new ProgError('cancelled', '已取消');
	}
}
