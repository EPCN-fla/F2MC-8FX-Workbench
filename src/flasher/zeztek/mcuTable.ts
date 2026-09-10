// 芯片型号表：泽兆烧录器的型号 → 芯片代码/块地址映射。
// 数据来源：烧录器 MCUtype.txt（V5.1 厂商表）+ 上位机逆向的芯片代码分支规则。

export interface MCUType {
	name: string;
	start: number;
	end: number;
	kbLabel: string;
	chipCode: number;
	lowBank?: number;
}

export const BUILTIN_MCUS: MCUType[] = [
	{ name: 'MB95F636H/K', start: 0x8000, end: 0xFFFF, kbLabel: '32K', chipCode: 0x14, lowBank: 0x1000 },
	{ name: 'MB95F634H/K', start: 0x8000, end: 0xFFFF, kbLabel: '20K', chipCode: 0x10, lowBank: 0x1000 }
];

// "MB95F636H/K" 这类型号名按 "/" 拆分出具体型号别名（H 变体 + K 变体），
// 便于匹配工程 cpuName（如 896.csv 中的 MB95F636K）。
export function mcuAliases(mcu: MCUType): string[] {
	const aliases = [mcu.name];
	const slashIndex = mcu.name.indexOf('/');
	if (slashIndex > 0) {
		const left = mcu.name.slice(0, slashIndex);
		const right = mcu.name.slice(slashIndex + 1);
		aliases.push(left, left.slice(0, -right.length) + right);
	}
	return aliases.map(alias => alias.toUpperCase());
}

export function findMcuByCpuName(cpuName: string): MCUType | undefined {
	const name = cpuName.trim().toUpperCase();
	return BUILTIN_MCUS.find(mcu => mcuAliases(mcu).includes(name));
}

export function blockAddrs(mcu: MCUType): number[] {
	const addrs: number[] = [];
	if (mcu.lowBank !== undefined) {
		addrs.push(mcu.lowBank);
	}
	for (let addr = mcu.start; addr <= mcu.end; addr += 0x1000) {
		addrs.push(addr);
	}
	return addrs;
}

export function totalKb(mcu: MCUType): number {
	return blockAddrs(mcu).length * 4;
}
