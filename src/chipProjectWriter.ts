import * as path from 'node:path';

import { readTextFile, writeTextFile } from './fileSystem';
import type { F2mcChipInfo } from './chipCatalog';
import type { F2mcProjectInfo } from './types';

export async function applyChipToProjectFiles(project: F2mcProjectInfo, chip: F2mcChipInfo): Promise<void> {
	project.cpuName = chip.model;
	await Promise.all([
		updateProjectDatFile(project, chip),
		updateGeneratedOptionFiles(project, chip)
	]);
}

async function updateProjectDatFile(project: F2mcProjectInfo, chip: F2mcChipInfo): Promise<void> {
	if (!project.optionFile) {
		return;
	}

	const content = await readTextFile(project.optionFile);
	const nextContent = replaceDatSectionLines(content, '2', lines => updateLinkerOptionLines(lines, chip));
	await writeTextFile(project.optionFile, nextContent);
}

async function updateGeneratedOptionFiles(project: F2mcProjectInfo, chip: F2mcChipInfo): Promise<void> {
	if (!project.optionFile || !project.directories?.opt) {
		return;
	}

	const optionBaseName = path.basename(project.optionFile, path.extname(project.optionFile));
	await Promise.all([
		updateGeneratedOptionFile(path.join(project.directories.opt, `${optionBaseName}.opl`), lines => updateLinkerOptionLines(lines, chip)),
		updateGeneratedOptionFile(path.join(project.directories.opt, `${optionBaseName}.opa`), lines => updateCpuOptionLines(lines, chip)),
		updateGeneratedOptionFile(path.join(project.directories.opt, `${optionBaseName}.opb`), lines => updateCpuOptionLines(lines, chip)),
		updateGeneratedOptionFile(path.join(project.directories.opt, `${optionBaseName}.opc`), lines => updateCpuOptionLines(lines, chip))
	]);
}

async function updateGeneratedOptionFile(optionPath: string, updater: (lines: string[]) => string[]): Promise<void> {
	try {
		const content = await readTextFile(optionPath);
		await writeTextFile(optionPath, ensureFinalNewline(updater(content.split(/\r?\n/)).join('\r\n')));
	} catch {
		// Generated option files may not exist until the first build; ignore missing/unreadable files.
	}
}

function replaceDatSectionLines(content: string, section: string, updater: (lines: string[]) => string[]): string {
	const lines = content.split(/\r?\n/);
	const sectionHeader = `$${section}`;
	const sectionStart = lines.findIndex(line => line.trim() === sectionHeader);
	if (sectionStart < 0) {
		return content;
	}

	let sectionEnd = lines.length;
	for (let index = sectionStart + 1; index < lines.length; index += 1) {
		const line = lines[index].trim();
		if (line === '$end' || (line.startsWith('$') && line !== '$other' && line !== '$time')) {
			sectionEnd = index;
			break;
		}
	}

	const nextLines = [
		...lines.slice(0, sectionStart + 1),
		...updater(lines.slice(sectionStart + 1, sectionEnd)),
		...lines.slice(sectionEnd)
	];
	return ensureFinalNewline(nextLines.join('\r\n'));
}

function updateCpuOptionLines(lines: string[], chip: F2mcChipInfo): string[] {
	let didReplaceCpu = false;
	const nextLines = lines.map(line => {
		if (!/^-cpu\s+/i.test(line.trim())) {
			return line;
		}

		didReplaceCpu = true;
		return `-cpu ${chip.model}`;
	});

	if (!didReplaceCpu && nextLines.some(line => line.trim().length > 0)) {
		nextLines.push(`-cpu ${chip.model}`);
	}

	return nextLines;
}

function updateLinkerOptionLines(lines: string[], chip: F2mcChipInfo): string[] {
	let didReplaceRam = false;
	let didReplaceRom = false;
	let didReplaceCpu = false;
	const nextLines = lines.map(line => {
		const trimmed = line.trim();
		if (/^-ra\s+_INRAM01=/i.test(trimmed)) {
			didReplaceRam = true;
			return `-ra _INRAM01=${chip.ramStart}/${chip.ramEnd}`;
		}
		if (/^-ro\s+_INROM01=/i.test(trimmed)) {
			didReplaceRom = true;
			return `-ro _INROM01=${chip.romStart}/${chip.romEnd}`;
		}
		if (/^-cpu\s+/i.test(trimmed)) {
			didReplaceCpu = true;
			return `-cpu ${chip.model}`;
		}
		return line;
	});

	const insertIndex = findLinkerInsertIndex(nextLines);
	if (!didReplaceRam) {
		nextLines.splice(insertIndex, 0, `-ra _INRAM01=${chip.ramStart}/${chip.ramEnd}`);
	}
	if (!didReplaceRom) {
		nextLines.splice(insertIndex + (didReplaceRam ? 0 : 1), 0, `-ro _INROM01=${chip.romStart}/${chip.romEnd}`);
	}
	if (!didReplaceCpu && shouldAddCpuOption(nextLines)) {
		nextLines.push(`-cpu ${chip.model}`);
	}

	return nextLines;
}

function shouldAddCpuOption(lines: string[]): boolean {
	return lines.some(line => /^-o\s+/i.test(line.trim()) || /^-l\s+/i.test(line.trim()) || /^".+\.obj"$/i.test(line.trim()));
}

function findLinkerInsertIndex(lines: string[]): number {
	const alIndex = lines.findIndex(line => /^-AL\s+/i.test(line.trim()));
	const firstContentIndex = lines.findIndex(line => line.trim().length > 0);
	return alIndex >= 0 ? alIndex + 1 : firstContentIndex >= 0 ? firstContentIndex + 1 : 0;
}

function ensureFinalNewline(content: string): string {
	return content.endsWith('\r\n') ? content : `${content}\r\n`;
}
