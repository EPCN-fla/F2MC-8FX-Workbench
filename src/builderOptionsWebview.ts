import * as path from 'node:path';

import * as vscode from 'vscode';

import type { BuilderOptionsViewModel, BuilderOptionLine, BuilderTabId } from './builderOptionsConstants';
import { BUILDER_TABS, EMPTY_VIEW_MODEL } from './builderOptionsConstants';
import { createBuilderOptionsHtml } from './builderOptionsHtml';
import { convertFileToAnsiEncoding, readTextFile, writeTextFile } from './fileSystem';
import type { F2mcProjectConfig } from './types';

const SECTION_TO_TAB: Record<string, BuilderTabId> = {};
for (const tab of BUILDER_TABS) {
	SECTION_TO_TAB[tab.datSection] = tab.id;
}

const OPT_EXTENSIONS: Record<BuilderTabId, string> = {
	'c-compiler': 'opc',
	assembler: 'opa',
	linker: 'opl',
	librarian: 'opb',
	converter: 'opv'
};

let currentConfig: F2mcProjectConfig | undefined;

export class BuilderOptionsWebview {
	private static panel: vscode.WebviewPanel | undefined;

	public static async open(context: vscode.ExtensionContext, config: F2mcProjectConfig | undefined): Promise<void> {
		currentConfig = config;
		const viewModel = await createBuilderOptionsViewModel(config);

		if (BuilderOptionsWebview.panel) {
			BuilderOptionsWebview.panel.reveal(vscode.ViewColumn.One);
			BuilderOptionsWebview.panel.webview.html = createBuilderOptionsHtml(BuilderOptionsWebview.panel.webview, viewModel);
			return;
		}

		const panel = vscode.window.createWebviewPanel(
			'f2mcBuilderOptions',
			'构建器选项',
			vscode.ViewColumn.One,
			{
				enableScripts: true,
				retainContextWhenHidden: true,
				localResourceRoots: [context.extensionUri]
			}
		);

		BuilderOptionsWebview.panel = panel;
		panel.webview.html = createBuilderOptionsHtml(panel.webview, viewModel);

		panel.webview.onDidReceiveMessage(async message => {
			if (message.type === 'save') {
				await handleSaveOptions(message.options);
			} else if (message.type === 'pickIncludePath') {
				const selected = await vscode.window.showOpenDialog({
					canSelectFiles: false,
					canSelectFolders: true,
					canSelectMany: false,
					title: '选择包含路径'
				});
				if (selected && selected.length > 0) {
					panel.webview.postMessage({ type: 'includePathSelected', path: selected[0].fsPath });
				}
			}
		});

		panel.onDidDispose(() => {
			BuilderOptionsWebview.panel = undefined;
			currentConfig = undefined;
		});
	}
}

async function createBuilderOptionsViewModel(config: F2mcProjectConfig | undefined): Promise<BuilderOptionsViewModel> {
	const project = config?.projects.find(existingProject => existingProject.isActive) ?? config?.projects[0];
	if (!project) {
		return EMPTY_VIEW_MODEL;
	}

	const entries = await Promise.all(BUILDER_TABS.map(async tab => [tab.id, await readDatOptionLines(project.optionFile, tab.datSection)] as const));
	const options = Object.fromEntries(entries) as Record<BuilderTabId, BuilderOptionLine[]>;

	if (project.optionFile && project.directories?.opt) {
		const baseName = path.basename(project.optionFile, path.extname(project.optionFile));
		const opvPath = path.join(project.directories.opt, `${baseName}.opv`);
		try {
			const opvContent = await readTextFile(opvPath);
			const lines = opvContent.split(/\r?\n/).map(line => line.trim()).filter(Boolean);
			for (const line of lines) {
				if (line.startsWith('-o "') && line.endsWith('"')) {
					const value = line.slice(4, -1).toLowerCase();
					if (value.endsWith('.ihx')) options.converter.push({ value: '-F2MC_FMT_IHX' });
					else if (value.endsWith('.ehx')) options.converter.push({ value: '-F2MC_FMT_EHX' });
					else if (value.endsWith('.hex')) options.converter.push({ value: '-F2MC_FMT_HEX' });
					else options.converter.push({ value: '-F2MC_FMT_MHX' });
					break;
				}
			}
		} catch {
			options.converter.push({ value: '-F2MC_FMT_MHX' });
		}
	}

	return {
		projectName: project.name,
		options
	};
}

async function readDatOptionLines(optionFile: string | undefined, section: string): Promise<BuilderOptionLine[]> {
	if (!optionFile) {
		return [];
	}

	try {
		const content = await readTextFile(optionFile);
		return readDatSection(content, section).map(value => ({ value }));
	} catch {
		return [];
	}
}

function readDatSection(content: string, section: string): string[] {
	const lines = content.split(/\r?\n/);
	const sectionHeader = `$${section}`;
	const startIndex = lines.findIndex(line => line.trim().toLowerCase() === sectionHeader.toLowerCase());
	if (startIndex < 0) {
		return [];
	}

	const result: string[] = [];
	for (let index = startIndex + 1; index < lines.length; index++) {
		const trimmed = lines[index].trim();
		if (/^\$\w+/i.test(trimmed)) {
			break;
		}
		result.push(lines[index]);
	}

	return normalizeOptionLines(result);
}

function normalizeOptionLines(lines: string[]): string[] {
	return lines
		.map(line => line.trim())
		.filter(line => line && !/^\$(other|time|end)$/i.test(line) && !/^\d+$/.test(line));
}

async function handleSaveOptions(options: Record<BuilderTabId, BuilderOptionLine[]>): Promise<void> {
	if (!currentConfig) {
		void vscode.window.showWarningMessage('未加载工程，无法保存。');
		return;
	}

	const project = currentConfig.projects.find(existingProject => existingProject.isActive) ?? currentConfig.projects[0];
	if (!project?.optionFile) {
		void vscode.window.showWarningMessage('未找到 option 文件，无法保存。');
		return;
	}

	const datOptions = stripInternalFlags(options);
	const fmtExt = detectFormatExt(options.converter || []);

	try {
		await writeDatSections(project.optionFile, datOptions);
		const optDir = project.directories?.opt;
		if (optDir) {
			const baseName = path.basename(project.optionFile, path.extname(project.optionFile));
			for (const tab of BUILDER_TABS) {
				const optPath = path.join(optDir, `${baseName}.${OPT_EXTENSIONS[tab.id]}`);
				await writeOptFile(optPath, tab, datOptions[tab.id], tab.id === 'converter' ? fmtExt : undefined);
				convertToAnsiSync(optPath);
			}
		}
		void vscode.window.showInformationMessage('构建器选项已保存。');
	} catch (error) {
		const message = error instanceof Error ? error.message : String(error);
		void vscode.window.showErrorMessage(`保存构建器选项失败：${message}`);
	}
}

function stripInternalFlags(options: Record<BuilderTabId, BuilderOptionLine[]>): Record<BuilderTabId, BuilderOptionLine[]> {
	const result = { ...options };
	for (const tabId of Object.keys(result) as BuilderTabId[]) {
		result[tabId] = result[tabId].filter(item => {
			const v = item.value.trim().toLowerCase();
			return !v.startsWith('-f2mc_fmt_');
		});
	}
	return result;
}

function convertToAnsiSync(filePath: string): void {
	try {
		convertFileToAnsiEncoding(filePath);
	} catch {
		// Ignore conversion errors
	}
}

function detectFormatExt(lines: BuilderOptionLine[]): string {
	for (const line of lines) {
		const v = line.value.trim().toLowerCase();
		if (v === '-f2mc_fmt_ihx') return '.ihx';
		if (v === '-f2mc_fmt_ehx') return '.ehx';
		if (v === '-f2mc_fmt_hex') return '.hex';
	}
	return '.mhx';
}

async function writeOptFile(filePath: string, tab: { id: BuilderTabId; datSection: string }, lines: BuilderOptionLine[], fmtExt?: string): Promise<void> {
	const managedLower = new Set(lines.map(l => l.value.trim().toLowerCase()));
	const sortedManaged = sortOptionLines(lines.map(l => l.value), tab.id);
	try {
		const existing = await readTextFile(filePath);
		const existingLines = existing.split(/\r?\n/);
		const preserved = existingLines.filter(l => {
			const trimmed = l.trim();
			if (!trimmed) return false;
			return !managedLower.has(trimmed.toLowerCase());
		});
		const updatedPreserved = fmtExt ? preserved.map(l => {
			const trimmed = l.trim();
			if (trimmed.startsWith('-o "') && trimmed.endsWith('"')) {
				const inner = trimmed.slice(4, -1);
				const dotIdx = inner.lastIndexOf('.');
				const newInner = dotIdx >= 0 ? inner.slice(0, dotIdx) + fmtExt : inner + fmtExt;
				return '-o "' + newInner + '"';
			}
			return l;
		}) : preserved;
		const sortedPreserved = sortOptionLines(updatedPreserved.map(l => l.trim()).filter(Boolean), tab.id);
		const allLines = [...sortedManaged, ...sortedPreserved];
		const content = allLines.join('\r\n') + (allLines.length > 0 ? '\r\n' : '');
		await writeTextFile(filePath, content);
	} catch {
		const content = sortedManaged.join('\r\n') + (sortedManaged.length > 0 ? '\r\n' : '');
		await writeTextFile(filePath, content);
	}
}

const OPTION_ORDER: Record<BuilderTabId, string[]> = {
	'c-compiler': ['-g','-V','-J c','-K FCONST','-K NOINTLIB','-K NOVOLATILE','-K SCHAR','-K SBIT','-w','-INF LIST','-D','-I','-O','-K REALOS','-B','-K ADDSP','-K NOADDSP','-xauto','-K NOEOPT','-K EOPT','-K LIB','-K NOLIB','-K UNROLL','-K NOUNROLL','-c','-cwno','-cpu','-Xdof','-INF STACK'],
	assembler: ['-g','-V','-w','-D','-I','-sa','-linf','-lsrc','-lsec','-lcros','-linc','-lexp','-pl','-pw','-tab','-lf','-Xdof','-cwno'],
	linker: ['-g','-V','-w','-Xdof','-cwno'],
	librarian: ['-m','-dt','-pl','-pw','-g','-V','-Xdof','-cwno'],
	converter: ['-V','-Xdof','-cwno']
};

function sortOptionLines(lines: string[], tabId: BuilderTabId): string[] {
	const orderPatterns = OPTION_ORDER[tabId] || [];
	const matched: { line: string; idx: number }[] = [];
	const unmatched: string[] = [];

	for (const line of lines) {
		const va = line.trim().toLowerCase();
		const idx = orderPatterns.findIndex(p => {
			const pl = p.toLowerCase();
			return va === pl || va.startsWith(pl + ' ');
		});
		if (idx >= 0) {
			matched.push({ line, idx });
		} else {
			unmatched.push(line);
		}
	}

	matched.sort((a, b) => a.idx - b.idx);
	return [...matched.map(m => m.line), ...unmatched];
}

async function writeDatSections(filePath: string, optionUpdates: Record<BuilderTabId, BuilderOptionLine[]>): Promise<void> {
	const content = await readTextFile(filePath);
	const lines = content.split(/\r?\n/);
	const result: string[] = [];
	let i = 0;

	while (i < lines.length) {
		const trimmed = lines[i].trim();
		const sectionMatch = /^\$(\w+)/i.exec(trimmed);

		if (sectionMatch) {
			const sectionId = sectionMatch[1];
			result.push(lines[i]);
			i++;

			const tabId = SECTION_TO_TAB[sectionId];
			if (tabId && optionUpdates[tabId]) {
				while (i < lines.length && !/^\$\w+/i.test(lines[i].trim())) {
					i++;
				}
				const sorted = sortOptionLines(optionUpdates[tabId].map(o => o.value), tabId);
				for (const opt of sorted) {
					result.push(opt);
				}
			} else {
				while (i < lines.length && !/^\$\w+/i.test(lines[i].trim())) {
					result.push(lines[i]);
					i++;
				}
			}
		} else {
			result.push(lines[i]);
			i++;
		}
	}

	const newContent = result.join('\n');
	await writeTextFile(filePath, newContent);
}
