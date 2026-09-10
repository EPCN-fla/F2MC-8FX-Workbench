export function readIniSection(content: string, sectionName: string): string[] {
	const lines = content.split(/\r?\n/);
	const target = `[${sectionName.toLowerCase()}]`;
	const sectionLines: string[] = [];
	let inSection = false;

	for (const rawLine of lines) {
		const line = rawLine.trim();
		if (!line) {
			continue;
		}

		if (/^\[[^\]]+\]$/.test(line)) {
			if (inSection) {
				break;
			}
			inSection = line.toLowerCase() === target;
			continue;
		}

		if (inSection) {
			sectionLines.push(line);
		}
	}

	return sectionLines;
}
