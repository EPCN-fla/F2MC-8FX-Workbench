// 编程器设置存储：持久化到 globalState（Memento），不注册到 package.json configuration——
// 这些选项只在插件“设置”视图中编辑，VS Code 不允许写入未注册的配置键。
// 兼容：早期版本写入 settings.json 的同名键作为回退值读取（只读，不再写入）。

import * as vscode from 'vscode';

export type ProgrammerType = 'zezhao' | 'f2mcLink';
export type ProgrammerMode = 'online' | 'offline';
export type ProgrammerPower = '5V' | '3.3V';

export interface ProgrammerSettings {
	programmerType: ProgrammerType;
	programmerMode: ProgrammerMode;
	programmerPower: ProgrammerPower;
	f2mcLinkSecure: boolean;
	f2mcLinkReset: boolean;
}

const STORAGE_KEY = 'f2mc-8fx-workbench.programmerSettings';
const CONFIG_SECTION = 'f2mc-8fx-workbench';

const DEFAULTS: ProgrammerSettings = {
	programmerType: 'zezhao',
	programmerMode: 'offline',
	programmerPower: '5V',
	f2mcLinkSecure: false,
	f2mcLinkReset: true
};

let storage: vscode.Memento | undefined;

export function initProgrammerSettings(memento: vscode.Memento): void {
	storage = memento;
}

export function getProgrammerSettings(): ProgrammerSettings {
	const stored = storage?.get<Partial<ProgrammerSettings>>(STORAGE_KEY) ?? {};
	const legacy = vscode.workspace.getConfiguration(CONFIG_SECTION);
	return {
		programmerType: stored.programmerType ?? legacy.get<ProgrammerType>('programmerType') ?? DEFAULTS.programmerType,
		programmerMode: stored.programmerMode ?? legacy.get<ProgrammerMode>('programmerMode') ?? DEFAULTS.programmerMode,
		programmerPower: stored.programmerPower ?? legacy.get<ProgrammerPower>('programmerPower') ?? DEFAULTS.programmerPower,
		f2mcLinkSecure: stored.f2mcLinkSecure ?? legacy.get<boolean>('f2mcLinkSecure') ?? DEFAULTS.f2mcLinkSecure,
		f2mcLinkReset: stored.f2mcLinkReset ?? legacy.get<boolean>('f2mcLinkReset') ?? DEFAULTS.f2mcLinkReset
	};
}

export async function updateProgrammerSetting<K extends keyof ProgrammerSettings>(key: K, value: ProgrammerSettings[K]): Promise<void> {
	if (!storage) {
		throw new Error('编程器设置存储未初始化');
	}
	await storage.update(STORAGE_KEY, { ...getProgrammerSettings(), [key]: value });
}
