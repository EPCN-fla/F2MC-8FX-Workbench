import * as path from 'node:path';

import { readTextFile } from './fileSystem';

export interface F2mcChipInfo {
	model: string;
	category: string;
	romStart: string;
	romEnd: string;
	ramStart: string;
	ramEnd: string;
}

const ROM_AREA_COLUMN_INDEX = 39;
const RAM_AREA_COLUMN_INDEX = 40;

export async function loadChipCatalog(extensionPath: string): Promise<F2mcChipInfo[]> {
	const csvPath = path.join(extensionPath, 'res', 'compiler', 'Lib', '896', '896.csv');
	const content = await readTextFile(csvPath);
	return content
		.split(/\r?\n/)
		.map(line => line.trim())
		.filter(Boolean)
		.map(parseChipCsvLine)
		.filter((chip): chip is F2mcChipInfo => Boolean(chip));
}

export function getChipCategories(chips: F2mcChipInfo[]): string[] {
	return [...new Set(chips.map(chip => chip.category))].sort((left, right) => left.localeCompare(right));
}

export function findChipByModel(chips: F2mcChipInfo[], model: string | undefined): F2mcChipInfo | undefined {
	return model ? chips.find(chip => chip.model.toLowerCase() === model.toLowerCase()) : undefined;
}

function parseChipCsvLine(line: string): F2mcChipInfo | undefined {
	const columns = line.split(',');
	const model = columns[0]?.trim();
	const category = columns[1]?.trim();
	if (!model || !category || !model.startsWith('MB')) {
		return undefined;
	}

	const romArea = parseMemoryArea(columns[ROM_AREA_COLUMN_INDEX]);
	const ramArea = parseMemoryArea(columns[RAM_AREA_COLUMN_INDEX]);
	if (!romArea || !ramArea) {
		return undefined;
	}

	return {
		model,
		category,
		romStart: romArea.start,
		romEnd: romArea.end,
		ramStart: ramArea.start,
		ramEnd: ramArea.end
	};
}

function parseMemoryArea(value: string | undefined): { start: string; end: string } | undefined {
	const parts = value?.split(':').map(part => part.trim()).filter(Boolean) ?? [];
	const start = parts.find(part => /^0x[0-9a-f]+$/i.test(part));
	const end = start ? parts.slice(parts.indexOf(start) + 1).find(part => /^0x[0-9a-f]+$/i.test(part)) : undefined;
	if (!start || !end) {
		return undefined;
	}

	return {
		start: normalizeHex(start),
		end: normalizeHex(end)
	};
}

function normalizeHex(value: string): string {
	const hex = value.slice(2).toUpperCase();
	return `0x${hex.padStart(4, '0')}`;
}
