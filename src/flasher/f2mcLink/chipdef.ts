// F2MC-8FX 型号库。
// 移植自 F2MC-8FX-Programmer hmi/crates/f2mc-core/src/chipdef.rs。
// 数据源：res/896.csv（富士通 8FX 器件表，family 列 = FMC8FX，与上位机 data/896.csv 同源）。
// Flash 布局（MB95630H-HARDWARE-MANUAL §26.1）：双 bank，
// 下 bank 恒为 0x1000~0x1FFF（2KB×2），上 bank 起始地址由 CSV 第 3 列给出
// （如 MB95F636H：0x8000~0xFFFF 32KB + 下 bank 4KB = 36KB）。

/** 可烧录地址下限（所有型号一致） */
export const FLASH_LOW = 0x1000;
/** 下 bank 范围（所有 8FX 一致） */
export const LOWER_BANK_LOW = 0x1000;
export const LOWER_BANK_HIGH = 0x1FFF;
/** 地址空间上限 */
export const FLASH_HIGH = 0xFFFF;

export interface ChipDef {
	/** 型号名，如 "MB95F636H" */
	name: string;
	/** 上 bank 起始地址（CSV 第 3 列） */
	upperLow: number;
	/** Flash 总容量 = 下 bank 4KB + 上 bank */
	flashBytes: number;
	/** 非 MB95F 前缀（FRAM/掩膜器件，New8FX 串行编程不适用，仅列出提示） */
	fram: boolean;
}

/** 地址是否落在可烧录 Flash 映射内（下 bank 或上 bank）；空洞区与 >0xFFFF 为 false */
export function isValidAddr(chip: ChipDef, addr: number): boolean {
	return (addr >= LOWER_BANK_LOW && addr <= LOWER_BANK_HIGH) || (addr >= chip.upperLow && addr <= FLASH_HIGH);
}

/** 有效区间描述（如 "0x1000~0x1FFF + 0x8000~0xFFFF"） */
export function rangesDesc(chip: ChipDef): string {
	const hex = (value: number): string => `0x${value.toString(16).toUpperCase().padStart(4, '0')}`;
	return `${hex(LOWER_BANK_LOW)}~${hex(LOWER_BANK_HIGH)} + ${hex(chip.upperLow)}~${hex(FLASH_HIGH)}`;
}

/** "0x8000:0xFFFF" → 0x8000 */
function parseRangeLow(value: string): number | undefined {
	const low = value.split(':')[0]?.trim().replace(/^0x/i, '');
	if (!low) {
		return undefined;
	}
	const parsed = Number.parseInt(low, 16);
	return Number.isNaN(parsed) ? undefined : parsed;
}

/** 解析 896.csv 全文为型号表（按名称排序） */
export function parseChipsCsv(csvText: string): ChipDef[] {
	const chips: ChipDef[] = [];
	for (const line of csvText.split(/\r?\n/)) {
		const columns = line.split(',');
		const name = columns[0]?.trim() ?? '';
		if (columns.length < 3 || columns[1]?.trim() !== 'FMC8FX' || !name) {
			continue;
		}
		const upperLow = parseRangeLow(columns[2] ?? '');
		if (upperLow === undefined) {
			continue;
		}
		chips.push({
			name,
			upperLow,
			flashBytes: (LOWER_BANK_HIGH - LOWER_BANK_LOW + 1) + (0x10000 - upperLow),
			fram: !name.startsWith('MB95F')
		});
	}
	chips.sort((left, right) => left.name.localeCompare(right.name));
	return chips;
}

/** 按名称精确查找型号（大小写不敏感） */
export function findChipByName(chips: ChipDef[], name: string): ChipDef | undefined {
	const normalized = name.trim().toUpperCase();
	return chips.find(chip => chip.name.toUpperCase() === normalized);
}
