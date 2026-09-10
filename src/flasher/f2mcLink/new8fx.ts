// New8FX 串行编程协议常量（目标侧 L2 层关键地址与参数）。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/new8fx.rs。

/** FLASH_INIT(0x05) 参数：MB95630H 时钟配置（固件据此完成 500 Kbps 切换） */
export const FLASH_INIT_XX = 0x02;
export const FLASH_INIT_YY = 0x7C;

/** NVR 校准区（CR Trimming 校准值存放地址，Blank Check / Verify 必须跳过） */
export const NVR_LOW = 0xFFBB;
export const NVR_HIGH = 0xFFBF;
/** Blank Check / Verify 必须跳过的三个地址（回写未生效前读回值可能与写入不一致） */
export const VERIFY_SKIP: readonly number[] = [0xFFBB, 0xFFBC, 0xFFBD];
/** 安全位地址（写 0x01 加锁，断电复位或 QUIT 后生效） */
export const SECURE_ADDR = 0xFFFC;

/** CR Trimming 比对地址表：NVR 与对应 RAM 镜像（Spec 7.11） */
export const CR_NVR_ADDRS: readonly number[] = [0xFFBB, 0xFFBC, 0xFFBD];
export const CR_RAM_ADDRS: readonly number[] = [0x0FE7, 0x0FE4, 0x0FE5];

// INIT DA.BIN：上位机不需要（由编程器固件内嵌执行 FLASH_INIT）。
// 勿把 Spec Table 7-1 的 198 字节版本拷入任何代码——真机实测不可用，
// 固件内嵌的是 YM02 嗅探提取的 141 字节版本。
