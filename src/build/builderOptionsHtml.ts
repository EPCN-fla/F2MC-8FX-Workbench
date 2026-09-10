import type { Webview } from 'vscode';

import type { BuilderOptionsViewModel } from './builderOptionsConstants';
import { BUILDER_TABS } from './builderOptionsConstants';

export function createBuilderOptionsHtml(webview: Webview, viewModel: BuilderOptionsViewModel): string {
	const nonce = getNonce();
	const initialTab = BUILDER_TABS[0];
	const initialSection = initialTab.sections[0];

	return `<!DOCTYPE html>
<html lang="zh-CN">
<head>
	<meta charset="UTF-8">
	<meta http-equiv="Content-Security-Policy" content="default-src 'none'; style-src ${webview.cspSource} 'unsafe-inline'; script-src 'nonce-${nonce}';">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>构建器选项</title>
	<style>
		:root {
			color-scheme: light dark;
			--border: var(--vscode-panel-border, rgba(128, 128, 128, 0.35));
			--muted: var(--vscode-descriptionForeground);
			--active-bg: var(--vscode-list-activeSelectionBackground);
			--active-fg: var(--vscode-list-activeSelectionForeground);
			--hover-bg: var(--vscode-list-hoverBackground);
			--input-bg: var(--vscode-input-background);
			--input-border: var(--vscode-input-border, transparent);
		}

		body {
			padding: 0;
			margin: 0;
			font-family: var(--vscode-font-family);
			font-size: var(--vscode-font-size);
			color: var(--vscode-foreground);
			background: var(--vscode-editor-background);
		}

		.builder-options {
			display: flex;
			flex-direction: column;
			height: 100vh;
			min-height: 600px;
		}

		.header-bar {
			display: flex;
			align-items: center;
			background: var(--vscode-sideBar-background);
			border-bottom: 1px solid var(--border);
		}

		.tabs {
			display: flex;
			gap: 4px;
			padding: 0 16px;
			overflow-x: auto;
			flex: 1;
		}

		.tab {
			appearance: none;
			border: none;
			border-bottom: 2px solid transparent;
			padding: 12px 16px 10px;
			color: var(--vscode-foreground);
			background: transparent;
			font: inherit;
			white-space: nowrap;
			cursor: pointer;
		}

		.tab:hover {
			background: var(--hover-bg);
		}

		.tab.active {
			border-bottom-color: var(--vscode-focusBorder);
			color: var(--vscode-focusBorder);
			font-weight: 600;
		}

		.save-button {
			appearance: none;
			border: none;
			padding: 6px 16px;
			margin-right: 12px;
			border-radius: 4px;
			color: #fff;
			background: #6c757d;
			font: inherit;
			font-size: 13px;
			cursor: pointer;
			white-space: nowrap;
		}

		.save-button:disabled {
			opacity: 0.5;
			cursor: not-allowed;
		}

		.save-button.modified {
			background: #28a745;
			opacity: 1;
			cursor: pointer;
		}

		.save-button.modified:hover {
			background: #218838;
		}

		.content {
			display: grid;
			grid-template-columns: minmax(190px, 260px) 1fr;
			min-height: 0;
			flex: 1;
		}

		.sidebar {
			border-right: 1px solid var(--border);
			background: var(--vscode-sideBar-background);
			overflow-y: auto;
			padding: 12px;
		}

		.section-button {
			display: block;
			width: 100%;
			margin: 0 0 6px;
			padding: 9px 10px;
			border: 1px solid transparent;
			border-radius: 4px;
			color: var(--vscode-foreground);
			background: transparent;
			font: inherit;
			text-align: left;
			cursor: pointer;
		}

		.section-button:hover {
			background: var(--hover-bg);
		}

		.section-button.active {
			color: var(--active-fg);
			background: var(--active-bg);
		}

		.detail {
			display: grid;
			grid-template-rows: minmax(0, 1fr) 320px;
			min-height: 0;
		}

		.config-panel,
		.option-panel {
			overflow-y: auto;
			padding: 20px 24px;
		}

		.option-panel {
			padding-top: 12px;
		}

		.config-panel {
			border-bottom: 1px solid var(--border);
		}

		.detail-card,
		.option-card {
			max-width: 960px;
			padding: 20px;
			border: 1px solid var(--border);
			border-radius: 6px;
			background: var(--vscode-editorWidget-background, var(--vscode-editor-background));
		}

		.option-heading {
			margin: 0 0 10px;
			font-size: 18px;
		}

		.option-card p {
			margin: 0;
			color: var(--muted);
		}

		.form-grid {
			display: grid;
			gap: 12px;
		}

		.option-row,
		.select-row {
			display: grid;
			grid-template-columns: minmax(220px, 1fr) auto;
			gap: 12px;
			align-items: center;
			padding: 8px 0;
			border-bottom: 1px solid var(--border);
		}

		.option-row:last-child,
		.select-row:last-child {
			border-bottom: none;
		}

		.option-title {
			display: flex;
			gap: 8px;
			align-items: center;
		}

		select,
		input[type='text'] {
			padding: 4px 8px;
			border: 1px solid var(--input-border);
			color: var(--vscode-input-foreground);
			background: var(--input-bg);
			font: inherit;
		}

		select {
			min-width: 150px;
		}

		input[type='checkbox'] {
			width: 16px;
			height: 16px;
		}

		input:disabled {
			color: var(--muted);
		}

		textarea {
			width: 100%;
			padding: 4px 8px;
			border: 1px solid var(--input-border);
			color: var(--vscode-input-foreground);
			background: var(--input-bg);
			font: inherit;
			resize: vertical;
			min-height: 60px;
		}

		.placeholder {
			display: grid;
			gap: 12px;
		}

		.placeholder-row {
			display: grid;
			grid-template-columns: 180px 1fr;
			gap: 12px;
			align-items: center;
		}

		.placeholder-label {
			color: var(--muted);
		}

		.placeholder-control {
			height: 30px;
			border: 1px dashed var(--input-border);
			border-radius: 4px;
			background: var(--input-bg);
			opacity: 0.7;
		}

		.option-list {
			display: block;
			margin: 0;
			padding: 0;
			list-style: none;
		}

		.option-item {
			display: block;
			padding: 2px 0;
		}

		.option-item code {
			font-family: var(--vscode-editor-font-family);
		}

		.empty-options {
			color: var(--muted);
			font-style: italic;
		}

		.macro-input-row {
			display: grid;
			grid-template-columns: 140px 1fr;
			gap: 12px;
			align-items: center;
			padding: 8px 0;
			border-bottom: 1px solid var(--border);
		}

		.macro-input-row label {
			color: var(--vscode-foreground);
		}

		.macro-list-header {
			display: flex;
			justify-content: space-between;
			align-items: center;
			padding: 10px 0;
			border-bottom: 1px solid var(--border);
		}

		.macro-list-title {
			font-weight: 500;
		}

		.macro-list {
			list-style: none;
			margin: 6px 0 0;
			padding: 0;
		}

		.macro-item {
			display: flex;
			gap: 8px;
			align-items: center;
			padding: 6px 8px;
			border-radius: 4px;
			cursor: pointer;
		}

		.macro-item:hover {
			background: var(--hover-bg);
		}

		.macro-item.selected {
			color: var(--active-fg);
			background: var(--active-bg);
		}

		.macro-item-text {
			font-family: var(--vscode-editor-font-family);
		}

		.macro-empty {
			color: var(--muted);
			font-style: italic;
			padding: 6px 0;
		}

		.macro-button {
			padding: 4px 14px;
			border: 1px solid var(--input-border);
			border-radius: 4px;
			background: var(--vscode-button-secondaryBackground);
			color: var(--vscode-button-secondaryForeground);
			font: inherit;
			font-size: 13px;
			cursor: pointer;
		}

		.macro-button:disabled {
			opacity: 0.4;
			cursor: default;
		}

		.overlay {
			position: fixed;
			top: 0; left: 0; right: 0; bottom: 0;
			background: rgba(0,0,0,0.5);
			display: flex;
			align-items: center;
			justify-content: center;
			z-index: 1000;
		}

		.modal-card {
			position: relative;
			background: var(--vscode-editor-background);
			border: 1px solid var(--border);
			border-radius: 8px;
			padding: 24px;
			max-width: 600px;
			width: 90%;
			max-height: 80vh;
			overflow-y: auto;
		}

		.modal-title {
			font-size: 18px;
			font-weight: 600;
			margin: 0 0 16px;
		}

		.modal-close {
			position: absolute;
			top: 12px;
			right: 16px;
			background: none;
			border: none;
			font-size: 20px;
			cursor: pointer;
			color: var(--vscode-foreground);
		}

		@media (max-width: 760px) {
			.content {
				grid-template-columns: 1fr;
			}

			.sidebar {
				border-right: none;
				border-bottom: 1px solid var(--border);
			}

			.detail {
				grid-template-rows: minmax(320px, 1fr) 320px;
			}

			.option-row,
			.select-row,
			.placeholder-row {
				grid-template-columns: 1fr;
			}
		}
	</style>
</head>
<body>
	<div class="builder-options">
		<div class="header-bar">
			<nav class="tabs" aria-label="构建器类别">
				${BUILDER_TABS.map(tab => `<button class="tab${tab.id === initialTab.id ? ' active' : ''}" type="button" data-tab-id="${escapeHtml(tab.id)}">${escapeHtml(tab.label)}</button>`).join('')}
			</nav>
			<button class="save-button" type="button" id="save-button">保存</button>
		</div>
		<main class="content">
			<aside class="sidebar" aria-label="子选栏" id="section-list"></aside>
			<section class="detail" aria-live="polite">
				<div class="config-panel">
					<div class="detail-card">
						<div id="config-content"></div>
					</div>
				</div>
				<div class="option-panel">
					<h2 class="option-heading">Option:</h2>
					<div class="option-card">
						<p id="option-description"></p>
						<ul class="option-list" id="option-list"></ul>
					</div>
				</div>
			</section>
		</main>
	</div>
	<script nonce="${nonce}">
		const vscode = acquireVsCodeApi();
		const tabs = ${JSON.stringify(BUILDER_TABS)};
		const viewModel = ${JSON.stringify(viewModel)};
		const optionState = JSON.parse(JSON.stringify(viewModel.options));
		const initialOptionState = JSON.parse(JSON.stringify(viewModel.options));
		const C_COMPILER_PREDEFINED = ['-v', '-g', '-inf stack', '-inf list', '-xdof'];
		const initialOtherOptions = {};
		for (const tabId of Object.keys(optionState)) {
			const opts = optionState[tabId] || [];
			initialOtherOptions[tabId] = opts.filter(item => {
				const v = item.value.trim().toLowerCase();
				return !C_COMPILER_PREDEFINED.includes(v) && !v.startsWith('-w');
			}).map(item => item.value);
		}
		let activeTabId = ${JSON.stringify(initialTab.id)};
		let activeSectionId = ${JSON.stringify(initialSection.id)};
		let macroEntries = {};
		let selectedMacroIndex = {};
		let includePaths = {};
		let selectedIncludePathIndex = {};

		(function initDerivedState() {
			for (const tabId of Object.keys(optionState)) {
				macroEntries[tabId] = [];
				selectedMacroIndex[tabId] = -1;
				includePaths[tabId] = [];
				selectedIncludePathIndex[tabId] = -1;
				const opts = optionState[tabId] || [];
				for (const item of opts) {
					const dm = /^-D\\s+(.+)$/i.exec(item.value.trim());
					if (dm) {
						const eqIdx = dm[1].indexOf('=');
						if (eqIdx > 0) {
							macroEntries[tabId].push({ name: dm[1].slice(0, eqIdx).trim(), value: dm[1].slice(eqIdx + 1).trim(), checked: true });
						}
					}
					const im = /^-I\\s+(.+)$/i.exec(item.value.trim());
					if (im) {
						includePaths[tabId].push(im[1].replace(/^"|"$/g, ''));
					}
				}
			}
		})();

		const tabButtons = [...document.querySelectorAll('.tab')];
		const sectionList = document.getElementById('section-list');
		const configContent = document.getElementById('config-content');
		const optionDescription = document.getElementById('option-description');
		const optionList = document.getElementById('option-list');
		const saveButton = document.getElementById('save-button');

		let hasEverChanged = false;

		saveButton.disabled = true;
		saveButton.addEventListener('click', () => {
			if (!hasEverChanged) return;
			vscode.postMessage({ type: 'save', options: optionState });
			saveButton.textContent = '已保存';
			for (const tabId of Object.keys(optionState)) {
				initialOptionState[tabId] = JSON.parse(JSON.stringify(optionState[tabId]));
			}
			hasEverChanged = false;
			updateSaveButton();
			setTimeout(() => { saveButton.textContent = '保存'; }, 500);
		});

		function updateSaveButton() {
			if (!hasEverChanged) {
				const changed = JSON.stringify(optionState) !== JSON.stringify(initialOptionState);
				if (changed) hasEverChanged = true;
			}
			saveButton.classList.toggle('modified', hasEverChanged);
			saveButton.disabled = !hasEverChanged;
		}

		let pendingPathInput = null;
		window.addEventListener('message', event => {
			const message = event.data;
			if (message && message.type === 'includePathSelected') {
				if (pendingPathInput) {
					pendingPathInput.value = message.path;
					pendingPathInput.dispatchEvent(new Event('input'));
				}
			}
		});

		function getActiveTab() {
			return tabs.find(tab => tab.id === activeTabId) || tabs[0];
		}

		function getActiveSection(tab) {
			return tab.sections.find(section => section.id === activeSectionId) || tab.sections[0];
		}

		function renderSections() {
			const tab = getActiveTab();
			sectionList.innerHTML = '';

			for (const section of tab.sections) {
				const button = document.createElement('button');
				button.type = 'button';
				button.className = 'section-button' + (section.id === activeSectionId ? ' active' : '');
				button.textContent = section.label;
				button.addEventListener('click', () => {
					activeSectionId = section.id;
					render();
				});
				sectionList.appendChild(button);
			}
		}

		function renderDetail() {
			const tab = getActiveTab();
			const section = getActiveSection(tab);
			configContent.innerHTML = '';

			if (tab.id === 'c-compiler' && section.id === 'general') {
				renderCCompilerGeneral();
				return;
			}

			if (section.id === 'define-macro' && (tab.id === 'c-compiler' || tab.id === 'assembler')) {
				renderDefineMacro(tab.id);
				return;
			}

			if (section.id === 'include-path' && (tab.id === 'c-compiler' || tab.id === 'assembler')) {
				renderIncludePath(tab.id);
				return;
			}

			if (tab.id === 'c-compiler' && section.id === 'optimize') {
				renderOptimize();
				return;
			}

			if (tab.id === 'c-compiler' && section.id === 'language') {
				renderLanguage();
				return;
			}

			if (tab.id === 'assembler' && section.id === 'general') {
				renderAssemblerGeneral();
				return;
			}

			if (tab.id === 'assembler' && section.id === 'target-depend') {
				renderTargetDepend();
				return;
			}

			if (tab.id === 'assembler' && section.id === 'output-list') {
				renderOutputList();
				return;
			}

			if (tab.id === 'linker' && section.id === 'general') {
				renderLinkerGeneral();
				return;
			}

			if (tab.id === 'linker') {
				renderDeveloping();
				return;
			}

			if (tab.id === 'librarian' && section.id === 'general') {
				renderLibrarianGeneral();
				return;
			}

			if (tab.id === 'librarian' && section.id === 'output-list') {
				renderLibrarianOutputList();
				return;
			}

			if (tab.id === 'converter') {
				renderConverter();
				return;
			}

			renderPlaceholder(section);
		}

		function getOptionValues(tabId) {
			return (optionState[tabId] || []).map(item => item.value);
		}

		function hasOption(tabId, optionValue) {
			const expected = optionValue.toLowerCase();
			return getOptionValues(tabId).some(value => value.toLowerCase() === expected);
		}

		function setOptionEnabled(tabId, optionValue, enabled) {
			const expected = optionValue.toLowerCase();
			const options = optionState[tabId] || [];
			const nextOptions = options.filter(item => item.value.toLowerCase() !== expected);
			if (enabled) {
				nextOptions.push({ value: optionValue });
			}
			optionState[tabId] = nextOptions;
		}

		function getWarningLevel(tabId) {
			const option = getOptionValues(tabId).find(value => value.trim().toLowerCase().startsWith('-w'));
			const match = option ? /^-w\\s*(\\d+)/i.exec(option) : undefined;
			return match?.[1] || '1';
		}

		function setWarningLevel(tabId, level) {
			const options = optionState[tabId] || [];
			optionState[tabId] = options.filter(item => !item.value.trim().toLowerCase().startsWith('-w'));
			optionState[tabId].push({ value: '-w ' + level });
		}

		function getNumericOpt(tabId, prefix) {
			const vals = getOptionValues(tabId);
			for (const v of vals) {
				const trimmed = v.trim().toLowerCase();
				if (trimmed.startsWith(prefix.toLowerCase()) && /^\\S+\\s+\\d+$/.test(trimmed)) {
					return trimmed.slice(prefix.length).trim();
				}
			}
			return '';
		}

		function setNumericOpt(tabId, prefix, value) {
			const opts = optionState[tabId] || [];
			let next = opts.filter(item => {
				const v = item.value.trim().toLowerCase();
				return !(v.startsWith(prefix.toLowerCase()) && /^\\S+\\s+\\d+$/.test(v) && v !== '-pl 0');
			});
			if (value) {
				next.push({ value: prefix + value });
			}
			optionState[tabId] = next;
		}

		function appendCheckboxOptions(form, tabId, checkboxOptions) {
			for (const item of checkboxOptions) {
				const row = document.createElement('label');
				row.className = 'option-row';
				const title = document.createElement('span');
				title.className = 'option-title';
				title.textContent = item.label;
				const checkbox = document.createElement('input');
				checkbox.type = 'checkbox';
				checkbox.dataset.option = item.option;
				checkbox.checked = hasOption(tabId, item.option);
				checkbox.addEventListener('change', () => {
					setOptionEnabled(tabId, item.option, checkbox.checked);
					renderOptions();
				});
				row.appendChild(title);
				row.appendChild(checkbox);
				form.appendChild(row);
			}
		}

		function insertWarningLevelSelect(form, tabId, maxLevel, atIndex) {
			const warningRow = document.createElement('label');
			warningRow.className = 'select-row';
			const warningTitle = document.createElement('span');
			warningTitle.className = 'option-title';
			warningTitle.textContent = 'Warning level';
			const select = document.createElement('select');
			for (let level = 0; level <= maxLevel; level++) {
				const option = document.createElement('option');
				option.value = String(level);
				option.textContent = 'level ' + level;
				select.appendChild(option);
			}
			select.value = getWarningLevel(tabId);
			select.addEventListener('change', () => {
				setWarningLevel(tabId, select.value);
				renderOptions();
			});
			warningRow.appendChild(warningTitle);
			warningRow.appendChild(select);
			form.insertBefore(warningRow, form.children[atIndex]);
		}

		function appendOtherOptionTextarea(form, tabId) {
			const otherOptionRow = document.createElement('div');
			otherOptionRow.style.cssText = 'display:flex;flex-direction:column;gap:6px;padding:8px 0;border-bottom:1px solid rgba(128,128,128,0.35);';
			const otherLabel = document.createElement('span');
			otherLabel.className = 'option-title';
			otherLabel.textContent = 'Other Option:';
			const otherInput = document.createElement('textarea');
			otherInput.setAttribute('rows', '4');
			otherInput.setAttribute('placeholder', 'Enter additional options...');
			otherInput.value = '';
			otherInput.addEventListener('change', () => {
				setOtherOptions(tabId, otherInput.value);
				renderOptions();
			});
			otherOptionRow.appendChild(otherLabel);
			otherOptionRow.appendChild(otherInput);
			form.appendChild(otherOptionRow);
		}

		function sortByOrderPatterns(options, orderPatterns) {
			return [...options].sort((a, b) => {
				const va = a.value.trim().toLowerCase();
				const vb = b.value.trim().toLowerCase();
				const ai = orderPatterns.findIndex(p => { const pl = p.toLowerCase(); return va === pl || va.startsWith(pl + ' '); });
				const bi = orderPatterns.findIndex(p => { const pl = p.toLowerCase(); return vb === pl || vb.startsWith(pl + ' '); });
				if (ai >= 0 && bi >= 0) return ai - bi;
				if (ai >= 0) return -1;
				if (bi >= 0) return 1;
				return 0;
			});
		}

		function setOtherOptions(tabId, text) {
			const options = optionState[tabId] || [];
			const savedOthers = (initialOtherOptions[tabId] || []).map(s => s.toLowerCase());
			const nextOptions = options.filter(item => {
				const v = item.value.trim().toLowerCase();
				return C_COMPILER_PREDEFINED.includes(v) || v.startsWith('-w') || savedOthers.includes(v);
			});
			const lines = text.split(/\\n/);
			for (const line of lines) {
				const trimmed = line.trim();
				if (!trimmed || !trimmed.startsWith('-')) continue;
				let inSingleQuote = false;
				let inDoubleQuote = false;
				let extraDash = false;
				for (let i = 1; i < trimmed.length; i++) {
					const ch = trimmed[i];
					if (ch === "'" && !inDoubleQuote) { inSingleQuote = !inSingleQuote; }
					else if (ch === '"' && !inSingleQuote) { inDoubleQuote = !inDoubleQuote; }
					else if (ch === '-' && !inSingleQuote && !inDoubleQuote) { extraDash = true; break; }
				}
				if (extraDash) continue;
				if (!nextOptions.some(item => item.value.toLowerCase() === trimmed.toLowerCase())) {
					nextOptions.push({ value: trimmed });
				}
			}
			optionState[tabId] = nextOptions;
		}

		function renderCCompilerGeneral() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const checkboxOptions = [
				{ label: 'Outputs start message', option: '-V' },
				{ label: 'Outputs debug information', option: '-g' },
				{ label: 'Outputs used stack information file', option: '-INF STACK' },
				{ label: 'Creates an assembly list file', option: '-INF LIST' },
				{ label: 'Control of default option file', option: '-Xdof' }
			];

			appendCheckboxOptions(form, 'c-compiler', checkboxOptions);
			insertWarningLevelSelect(form, 'c-compiler', 8, 2);
			appendOtherOptionTextarea(form, 'c-compiler');

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering General options: ' + (err && err.message ? err.message : String(err));
			}
		}

		function syncMacrosToOptions(tabId) {
			const options = optionState[tabId] || [];
			let nextOptions = options.filter(item => !/^-D\\s/i.test(item.value.trim()));
			const entries = macroEntries[tabId] || [];
			for (const entry of entries) {
				if (entry.checked) {
					nextOptions.push({ value: '-D ' + entry.name + '=' + entry.value });
				}
			}
			optionState[tabId] = nextOptions;
		}

		function renderDefineMacro(tabId) {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const nameRow = document.createElement('div');
			nameRow.className = 'macro-input-row';
			const nameLabel = document.createElement('label');
			nameLabel.textContent = 'Macro Name:';
			const nameInput = document.createElement('input');
			nameInput.type = 'text';
			nameInput.placeholder = 'English only';
			nameInput.addEventListener('input', () => {
				nameInput.value = nameInput.value.replace(/[^a-zA-Z0-9_]/g, '');
				updateMacroSetButton();
			});
			nameRow.appendChild(nameLabel);
			nameRow.appendChild(nameInput);
			form.appendChild(nameRow);

			const valueRow = document.createElement('div');
			valueRow.className = 'macro-input-row';
			const valueLabel = document.createElement('label');
			valueLabel.textContent = 'Value:';
			const valueInput = document.createElement('input');
			valueInput.type = 'text';
			valueInput.addEventListener('input', () => {
				updateMacroSetButton();
			});
			valueRow.appendChild(valueLabel);
			valueRow.appendChild(valueInput);
			form.appendChild(valueRow);

			const listHeader = document.createElement('div');
			listHeader.className = 'macro-list-header';
			const listTitle = document.createElement('span');
			listTitle.className = 'macro-list-title';
			listTitle.textContent = 'Macro Name List';
			const btnGroup = document.createElement('div');
			btnGroup.style.cssText = 'display:flex;gap:8px;';
			const setBtn = document.createElement('button');
			setBtn.type = 'button';
			setBtn.className = 'macro-button';
			setBtn.textContent = 'Set';
			setBtn.id = 'macro-set-btn';
			const delBtn = document.createElement('button');
			delBtn.type = 'button';
			delBtn.className = 'macro-button';
			delBtn.textContent = 'Delete';
			delBtn.id = 'macro-del-btn';
			delBtn.disabled = true;
			btnGroup.appendChild(setBtn);
			btnGroup.appendChild(delBtn);
			listHeader.appendChild(listTitle);
			listHeader.appendChild(btnGroup);
			form.appendChild(listHeader);

			function updateMacroSetButton() {
				setBtn.disabled = !(nameInput.value.trim() && valueInput.value.trim());
			}
			updateMacroSetButton();

			const macroListEl = document.createElement('ul');
			macroListEl.className = 'macro-list';
			form.appendChild(macroListEl);

			const entries = macroEntries[tabId] || [];
			let selIdx = selectedMacroIndex[tabId] || -1;

			function renderMacroList() {
				macroListEl.innerHTML = '';
				if (entries.length === 0) {
					const empty = document.createElement('li');
					empty.className = 'macro-empty';
					empty.textContent = '空';
					macroListEl.appendChild(empty);
				} else {
					for (let i = 0; i < entries.length; i++) {
						const entry = entries[i];
						const row = document.createElement('li');
						row.className = 'macro-item' + (i === selIdx ? ' selected' : '');
						const cb = document.createElement('input');
						cb.type = 'checkbox';
						cb.checked = entry.checked;
						cb.addEventListener('change', () => {
							entry.checked = cb.checked;
							syncMacrosToOptions(tabId);
							renderOptions();
						});
						const text = document.createElement('span');
						text.className = 'macro-item-text';
						text.textContent = entry.name + '=' + entry.value;
						row.appendChild(cb);
						row.appendChild(text);
						row.addEventListener('click', (e) => {
							if (e.target === cb) return;
							selIdx = (selIdx === i) ? -1 : i;
							selectedMacroIndex[tabId] = selIdx;
							delBtn.disabled = selIdx < 0;
							renderMacroList();
						});
						macroListEl.appendChild(row);
					}
				}
			}

			setBtn.addEventListener('click', () => {
				const name = nameInput.value.trim();
				const value = valueInput.value.trim();
				if (!name || !value) return;
				if (entries.some(e => e.name === name)) return;
				entries.push({ name, value, checked: true });
				nameInput.value = '';
				valueInput.value = '';
				updateMacroSetButton();
				syncMacrosToOptions(tabId);
				renderMacroList();
				renderOptions();
			});

			delBtn.addEventListener('click', () => {
				if (selIdx < 0 || selIdx >= entries.length) return;
				entries.splice(selIdx, 1);
				selIdx = -1;
				selectedMacroIndex[tabId] = selIdx;
				delBtn.disabled = true;
				syncMacrosToOptions(tabId);
				renderMacroList();
				renderOptions();
			});

			renderMacroList();
			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Define Macro: ' + (err && err.message ? err.message : String(err));
			}
		}

		function syncIncludePathsToOptions(tabId) {
			const options = optionState[tabId] || [];
			let nextOptions = options.filter(item => !/^-I\\s/i.test(item.value.trim()));
			const paths = includePaths[tabId] || [];
			for (const p of paths) {
				nextOptions.push({ value: '-I "' + p + '"' });
			}
			optionState[tabId] = nextOptions;
		}

		function renderIncludePath(tabId) {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const inputRow = document.createElement('div');
			inputRow.className = 'macro-input-row';
			const inputLabel = document.createElement('label');
			inputLabel.textContent = 'Include Path:';
			const inputWrap = document.createElement('div');
			inputWrap.style.cssText = 'display:flex;gap:6px;align-items:center;';
			const pathInput = document.createElement('input');
			pathInput.type = 'text';
			pathInput.style.cssText = 'flex:1;';
			pathInput.placeholder = 'Select or enter a path';
			pendingPathInput = pathInput;
			pathInput.addEventListener('input', () => {
				updateIncludePathButtons();
			});
			const browseBtn = document.createElement('button');
			browseBtn.type = 'button';
			browseBtn.className = 'macro-button';
			browseBtn.textContent = '...';
			browseBtn.title = 'Browse for path';
			browseBtn.addEventListener('click', () => {
				vscode.postMessage({ type: 'pickIncludePath' });
			});
			inputWrap.appendChild(pathInput);
			inputWrap.appendChild(browseBtn);
			inputRow.appendChild(inputLabel);
			inputRow.appendChild(inputWrap);
			form.appendChild(inputRow);

			const listHeader = document.createElement('div');
			listHeader.className = 'macro-list-header';
			const listTitle = document.createElement('span');
			listTitle.className = 'macro-list-title';
			listTitle.textContent = 'Include Path List';
			const btnGroup = document.createElement('div');
			btnGroup.style.cssText = 'display:flex;gap:6px;';
			const addBtn = document.createElement('button');
			addBtn.type = 'button';
			addBtn.className = 'macro-button';
			addBtn.textContent = 'Add';
			addBtn.id = 'incl-add-btn';
			addBtn.disabled = true;
			const delBtn = document.createElement('button');
			delBtn.type = 'button';
			delBtn.className = 'macro-button';
			delBtn.textContent = 'Delete';
			delBtn.id = 'incl-del-btn';
			delBtn.disabled = true;
			const upBtn = document.createElement('button');
			upBtn.type = 'button';
			upBtn.className = 'macro-button';
			upBtn.textContent = 'Up';
			upBtn.id = 'incl-up-btn';
			upBtn.disabled = true;
			const downBtn = document.createElement('button');
			downBtn.type = 'button';
			downBtn.className = 'macro-button';
			downBtn.textContent = 'Down';
			downBtn.id = 'incl-down-btn';
			downBtn.disabled = true;
			btnGroup.appendChild(addBtn);
			btnGroup.appendChild(delBtn);
			btnGroup.appendChild(upBtn);
			btnGroup.appendChild(downBtn);
			listHeader.appendChild(listTitle);
			listHeader.appendChild(btnGroup);
			form.appendChild(listHeader);

			function updateIncludePathButtons() {
				addBtn.disabled = !pathInput.value.trim();
			}

			const pathListEl = document.createElement('ul');
			pathListEl.className = 'macro-list';
			form.appendChild(pathListEl);

			const paths = includePaths[tabId] || [];
			let selIdx = selectedIncludePathIndex[tabId] || -1;

			function renderPathList() {
				pathListEl.innerHTML = '';
				if (paths.length === 0) {
					const empty = document.createElement('li');
					empty.className = 'macro-empty';
					empty.textContent = '空';
					pathListEl.appendChild(empty);
				} else {
					for (let i = 0; i < paths.length; i++) {
						const row = document.createElement('li');
						row.className = 'macro-item' + (i === selIdx ? ' selected' : '');
						const text = document.createElement('span');
						text.className = 'macro-item-text';
						text.textContent = paths[i];
						row.appendChild(text);
						row.addEventListener('click', () => {
							selIdx = (selIdx === i) ? -1 : i;
							selectedIncludePathIndex[tabId] = selIdx;
							delBtn.disabled = selIdx < 0;
							upBtn.disabled = selIdx <= 0;
							downBtn.disabled = selIdx < 0 || selIdx >= paths.length - 1;
							renderPathList();
						});
						pathListEl.appendChild(row);
					}
				}
			}

			addBtn.addEventListener('click', () => {
				const p = pathInput.value.trim();
				if (!p) return;
				if (paths.indexOf(p) >= 0) return;
				paths.push(p);
				pathInput.value = '';
				updateIncludePathButtons();
				syncIncludePathsToOptions(tabId);
				renderPathList();
				renderOptions();
			});

			delBtn.addEventListener('click', () => {
				if (selIdx < 0 || selIdx >= paths.length) return;
				paths.splice(selIdx, 1);
				selIdx = -1;
				selectedIncludePathIndex[tabId] = selIdx;
				delBtn.disabled = true;
				upBtn.disabled = true;
				downBtn.disabled = true;
				syncIncludePathsToOptions(tabId);
				renderPathList();
				renderOptions();
			});

			function moveSelected(delta) {
				if (selIdx < 0) return;
				const newIdx = selIdx + delta;
				if (newIdx < 0 || newIdx >= paths.length) return;
				const tmp = paths[selIdx];
				paths[selIdx] = paths[newIdx];
				paths[newIdx] = tmp;
				selIdx = newIdx;
				selectedIncludePathIndex[tabId] = selIdx;
				delBtn.disabled = false;
				upBtn.disabled = selIdx <= 0;
				downBtn.disabled = selIdx >= paths.length - 1;
				syncIncludePathsToOptions(tabId);
				renderPathList();
				renderOptions();
			}

			upBtn.addEventListener('click', () => moveSelected(-1));
			downBtn.addEventListener('click', () => moveSelected(1));

			renderPathList();
			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Include Path: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderOptimize() {
			try {
			const optimizeLevels = [
				{ label: 'None', id: '0', opts: ['-O 0'] },
				{ label: 'Level 1', id: '1', opts: ['-O 1'] },
				{ label: 'Level 2', id: '2', opts: ['-O 2'] },
				{ label: 'Level 3', id: '3', opts: ['-O 3'] },
				{ label: 'Level 4', id: '4', opts: ['-O 4'] },
				{ label: 'Speed Priority', id: 'speed', opts: ['-O 4', '-K SPEED'] },
				{ label: 'Size Priority', id: 'size', opts: ['-O 3', '-K SIZE'] }
			];

			function getCurrentOptimizeId() {
				const vals = getOptionValues('c-compiler').map(v => v.toLowerCase().trim());
				const hasSpeedK = vals.includes('-k speed');
				const hasSizeK = vals.includes('-k size');
				const hasO4 = vals.includes('-o 4');
				const hasO3 = vals.includes('-o 3');
				if (hasSpeedK && hasO4) return 'speed';
				if (hasSizeK && hasO3) return 'size';
				for (const level of optimizeLevels) {
					if (level.id === 'speed' || level.id === 'size') continue;
					if (vals.includes(level.opts[0].toLowerCase())) return level.id;
				}
				return '0';
			}

			function setOptimizeValue(id) {
				const options = optionState['c-compiler'] || [];
				let nextOptions = options.filter(item => {
					const v = item.value.trim().toLowerCase();
					return !v.startsWith('-o ') && v !== '-k speed' && v !== '-k size';
				});
				const level = optimizeLevels.find(l => l.id === id);
				if (level) {
					for (const opt of level.opts) {
						nextOptions.push({ value: opt });
					}
				}
				optionState['c-compiler'] = nextOptions;
				applyOptDefaults(id);
				renderOptions();
			}

			function applyOptDefaults(id) {
				const constraints = getOptConstraints(id);
				const toggleItems = [
					{ active: '-K UNROLL', inactive: '-K NOUNROLL' },
					{ active: '-K LIB', inactive: '-K NOLIB' },
					{ active: '-K EOPT', inactive: '-K NOEOPT' },
					{ active: '-K ADDSP', inactive: '-K NOADDSP' }
				];
				for (let idx = 0; idx < toggleItems.length; idx++) {
					const item = toggleItems[idx];
					setToggleValue(item.active, item.inactive, constraints.defaults.has(idx) ? constraints.defaults.get(idx) : false);
				}
				setOptionEnabled('c-compiler', '-K NOALIAS', !(constraints.defaults.has(4) ? constraints.defaults.get(4) : false));
				if (constraints.disabled.has(5)) {
					setXautoValue('');
				}
			}

			const form = document.createElement('div');
			form.className = 'form-grid';
			const headerRow = document.createElement('div');
			headerRow.style.cssText = 'padding:8px 0;border-bottom:1px solid var(--border);';
			const headerTitle = document.createElement('span');
			headerTitle.className = 'option-title';
			headerTitle.textContent = 'General-purpose Optimization Level';
			headerRow.appendChild(headerTitle);
			form.appendChild(headerRow);

			const selectRow = document.createElement('div');
			selectRow.style.cssText = 'display:flex;gap:8px;align-items:center;padding:8px 0;border-bottom:1px solid var(--border);';
			const optimizeSelect = document.createElement('select');
			optimizeSelect.style.cssText = 'flex:1;';
			for (const level of optimizeLevels) {
				const option = document.createElement('option');
				option.value = level.id;
				option.textContent = level.label;
				optimizeSelect.appendChild(option);
			}
			optimizeSelect.value = getCurrentOptimizeId();
			optimizeSelect.addEventListener('change', () => {
				setOptimizeValue(optimizeSelect.value);
			});
			const detailBtn = document.createElement('button');
			detailBtn.type = 'button';
			detailBtn.className = 'macro-button';
			detailBtn.textContent = 'Detail optimize';
			selectRow.appendChild(optimizeSelect);
			selectRow.appendChild(detailBtn);
			form.appendChild(selectRow);

			function getToggleValue(activeVal, inactiveVal) {
				const vals = getOptionValues('c-compiler').map(v => v.toLowerCase().trim());
				if (vals.includes(activeVal.toLowerCase())) return true;
				if (vals.includes(inactiveVal.toLowerCase())) return false;
				return false;
			}

			function setToggleValue(activeVal, inactiveVal, checked) {
				const opts = optionState['c-compiler'] || [];
				let next = opts.filter(item => {
					const v = item.value.trim().toLowerCase();
					return v !== activeVal.toLowerCase() && v !== inactiveVal.toLowerCase();
				});
				next.push({ value: checked ? activeVal : inactiveVal });
				optionState['c-compiler'] = next;
			}

			function getXautoValue() {
				const vals = getOptionValues('c-compiler');
				for (const v of vals) {
					const m = /^-xauto\\s+(\\d+)$/i.exec(v.trim());
					if (m) return m[1];
				}
				return '';
			}

			function setXautoValue(value) {
				const opts = optionState['c-compiler'] || [];
				let next = opts.filter(item => !/^-xauto\\s/i.test(item.value.trim()));
				if (value) {
					next.push({ value: '-xauto ' + value });
				}
				optionState['c-compiler'] = next;
			}

			let overlayEl = null;
			detailBtn.addEventListener('click', () => {
				if (overlayEl) {
					overlayEl.remove();
					overlayEl = null;
				}
				overlayEl = buildOptimizationModal();
				document.body.appendChild(overlayEl);
			});

			function buildOptimizationModal() {
				const currentId = getCurrentOptimizeId();
				const constraints = getOptConstraints(currentId);

				const modalOverlay = document.createElement('div');
				modalOverlay.className = 'overlay';
				modalOverlay.addEventListener('click', (e) => { if (e.target === modalOverlay) { modalOverlay.remove(); overlayEl = null; } });

				const card = document.createElement('div');
				card.className = 'modal-card';

				const title = document.createElement('div');
				title.className = 'modal-title';
				title.textContent = 'Optimization';
				card.appendChild(title);

				const closeBtn = document.createElement('button');
				closeBtn.type = 'button';
				closeBtn.className = 'modal-close';
				closeBtn.textContent = '\u00D7';
				closeBtn.addEventListener('click', () => { modalOverlay.remove(); overlayEl = null; });
				card.appendChild(closeBtn);

				const form = document.createElement('div');
				form.className = 'form-grid';
				card.appendChild(form);

				const toggleItems = [
					{ label: 'Loop unrolling', active: '-K UNROLL', inactive: '-K NOUNROLL' },
					{ label: 'In-line expansion of standard library functions, or replacement to expansion', active: '-K LIB', inactive: '-K NOLIB' },
					{ label: 'Optimization of changing the evaluation method of arithmetic operation', active: '-K EOPT', inactive: '-K NOEOPT' },
					{ label: 'Optimization of argument area on', active: '-K ADDSP', inactive: '-K NOADDSP' }
				];

				for (let idx = 0; idx < toggleItems.length; idx++) {
					const item = toggleItems[idx];
					const row = document.createElement('label');
					row.className = 'option-row';
					const span = document.createElement('span');
					span.className = 'option-title';
					span.textContent = item.label;
					const cb = document.createElement('input');
					cb.type = 'checkbox';
					cb.disabled = constraints.disabled.has(idx);
					if (cb.disabled) {
						span.style.color = 'var(--muted)';
					}
					cb.checked = getToggleValue(item.active, item.inactive);
					cb.addEventListener('change', () => {
						setToggleValue(item.active, item.inactive, cb.checked);
						renderOptions();
					});
					row.appendChild(span);
					row.appendChild(cb);
					form.appendChild(row);
				}

				const aliasRow = document.createElement('label');
				aliasRow.className = 'option-row';
				const aliasTitle = document.createElement('span');
				aliasTitle.className = 'option-title';
				aliasTitle.textContent = 'Control optimization of pointer aliasing';
				const aliasCb = document.createElement('input');
				aliasCb.type = 'checkbox';
				aliasCb.disabled = constraints.disabled.has(4);
				if (aliasCb.disabled) {
					aliasTitle.style.color = 'var(--muted)';
				}
				aliasCb.checked = !hasOption('c-compiler', '-K NOALIAS');
				aliasCb.addEventListener('change', () => {
					setOptionEnabled('c-compiler', '-K NOALIAS', !aliasCb.checked);
					renderOptions();
				});
				aliasRow.appendChild(aliasTitle);
				aliasRow.appendChild(aliasCb);
				form.appendChild(aliasRow);

				const xautoRow = document.createElement('div');
				xautoRow.style.cssText = 'display:grid;grid-template-columns:auto 1fr;gap:12px;align-items:center;padding:8px 0;border-bottom:1px solid var(--border);';
				const xautoLabel = document.createElement('label');
				xautoLabel.style.cssText = 'white-space:nowrap;';
				xautoLabel.textContent = 'In-line expansion of function below the specified number:';
				const xautoInput = document.createElement('input');
				xautoInput.type = 'text';
				xautoInput.placeholder = 'Enter number';
				xautoInput.value = getXautoValue();
				xautoInput.disabled = constraints.disabled.has(5);
				if (xautoInput.disabled) {
					xautoLabel.style.color = 'var(--muted)';
				}
				xautoInput.addEventListener('input', () => {
					xautoInput.value = xautoInput.value.replace(/[^0-9]/g, '');
					setXautoValue(xautoInput.value);
					renderOptions();
				});
				xautoRow.appendChild(xautoLabel);
				xautoRow.appendChild(xautoInput);
				form.appendChild(xautoRow);

				modalOverlay.appendChild(card);
				return modalOverlay;
			}

			function getOptConstraints(id) {
				switch (id) {
					case '0': // None
						return { disabled: new Set([0, 1, 2, 4, 5]), defaults: new Map() };
					case '1': // Level 1
						return { disabled: new Set([0]), defaults: new Map([[4, true]]) };
					case '2': // Level 2
					case '3': // Level 3
						return { disabled: new Set(), defaults: new Map([[0, true], [4, true]]) };
					case '4': // Level 4
					case 'speed': // Speed Priority
						return { disabled: new Set(), defaults: new Map([[0, true], [1, true], [2, true], [4, true]]) };
					case 'size': // Size Priority
						return { disabled: new Set(), defaults: new Map([[2, true], [4, true]]) };
					default:
						return { disabled: new Set(), defaults: new Map() };
				}
			}

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Optimize: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderLanguage() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const languageCheckboxes = [
				{ label: 'Treat floating-point numbers for which suffixes not specified as float type', option: '-K FCONST' },
				{ label: "In-line expansion of the function which qualified by '__interrupt'", option: '-K NOINTLIB', invert: true },
				{ label: "Treat as 'volatile' the variable which qualified by '__io'", option: '-K NOVOLATILE', invert: true },
				{ label: 'Treat most significant bit of char type as sign bit', option: '-K SCHAR' },
				{ label: 'In-line of ITRON system call development', option: '-K REALOS' },
				{ label: 'If int type specified in bit field, treat most significant bit as sign bit', option: '-K SBIT' },
				{ label: 'Treat items following // as comments in C source', option: '-B' }
			];

			for (const item of languageCheckboxes) {
				const row = document.createElement('label');
				row.className = 'option-row';
				const title = document.createElement('span');
				title.className = 'option-title';
				title.textContent = item.label;
				const checkbox = document.createElement('input');
				checkbox.type = 'checkbox';
				checkbox.dataset.option = item.option;
				checkbox.checked = item.invert ? !hasOption('c-compiler', item.option) : hasOption('c-compiler', item.option);
				checkbox.addEventListener('change', () => {
					setOptionEnabled('c-compiler', item.option, item.invert ? !checkbox.checked : checkbox.checked);
					renderOptions();
				});
				row.appendChild(title);
				row.appendChild(checkbox);
				form.appendChild(row);
			}

			const langSpecLevels = [
				{ label: 'ANSI+FUJITSU extensions', value: '' },
				{ label: 'ANSI', value: '-J c' }
			];

			function getLangSpecValue() {
				return hasOption('c-compiler', '-J c') ? '-J c' : '';
			}

			function setLangSpecValue(value) {
				setOptionEnabled('c-compiler', '-J c', value === '-J c');
			}

			const langSpecRow = document.createElement('label');
			langSpecRow.className = 'select-row';
			const langSpecTitle = document.createElement('span');
			langSpecTitle.className = 'option-title';
			langSpecTitle.textContent = 'Language specification level';
			const langSpecSelect = document.createElement('select');
			for (const level of langSpecLevels) {
				const option = document.createElement('option');
				option.value = level.value;
				option.textContent = level.label;
				langSpecSelect.appendChild(option);
			}
			langSpecSelect.value = getLangSpecValue();
			langSpecSelect.addEventListener('change', () => {
				setLangSpecValue(langSpecSelect.value);
				renderOptions();
			});
			langSpecRow.appendChild(langSpecTitle);
			langSpecRow.appendChild(langSpecSelect);
			form.appendChild(langSpecRow);

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Language: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderAssemblerGeneral() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const checkboxOptions = [
				{ label: 'Outputs start message', option: '-V' },
				{ label: 'Outputs debug information', option: '-g' },
				{ label: 'Control of default option file', option: '-Xdof' }
			];

			appendCheckboxOptions(form, 'assembler', checkboxOptions);
			insertWarningLevelSelect(form, 'assembler', 3, 2);

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering General: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderTargetDepend() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const row = document.createElement('label');
			row.className = 'option-row';
			const title = document.createElement('span');
			title.className = 'option-title';
			title.textContent = 'Outputs accumulator protection code';
			const checkbox = document.createElement('input');
			checkbox.type = 'checkbox';
			checkbox.checked = hasOption('assembler', '-sa');
			checkbox.addEventListener('change', () => {
				setOptionEnabled('assembler', '-sa', checkbox.checked);
				renderOptions();
			});
			row.appendChild(title);
			row.appendChild(checkbox);
			form.appendChild(row);

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Target Depend: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderOutputList() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const mainRow = document.createElement('label');
			mainRow.className = 'option-row';
			const mainTitle = document.createElement('span');
			mainTitle.className = 'option-title';
			mainTitle.textContent = 'Creates a list file';
			const mainCb = document.createElement('input');
			mainCb.type = 'checkbox';
			mainCb.checked = hasOption('assembler', '-lf');
			mainRow.appendChild(mainTitle);
			mainRow.appendChild(mainCb);
			form.appendChild(mainRow);

			const subSection = document.createElement('div');
			subSection.className = 'form-grid';
			subSection.style.cssText = 'padding-left:16px;';
			form.appendChild(subSection);

			function updateSubVisibility() {
				subSection.style.display = mainCb.checked ? '' : 'none';
			}

			mainCb.addEventListener('change', () => {
				setOptionEnabled('assembler', '-lf', mainCb.checked);
				updateSubVisibility();
				renderOptions();
			});

			const listOptions = [
				{ label: 'Outputs information list', option: '-linf' },
				{ label: 'Outputs source list', option: '-lsrc' },
				{ label: 'Outputs section list', option: '-lsec' },
				{ label: 'Outputs cross-reference list', option: '-lcros' },
				{ label: 'Outputs include list', option: '-linc' }
			];

			for (const item of listOptions) {
				const row = document.createElement('label');
				row.className = 'option-row';
				const title = document.createElement('span');
				title.className = 'option-title';
				title.textContent = item.label;
				const cb = document.createElement('input');
				cb.type = 'checkbox';
				cb.checked = hasOption('assembler', item.option + ' ON');
				cb.addEventListener('change', () => {
					setOptionEnabled('assembler', item.option + ' ON', false);
					setOptionEnabled('assembler', item.option + ' OFF', false);
					setOptionEnabled('assembler', item.option + ' ' + (cb.checked ? 'ON' : 'OFF'), true);
					renderOptions();
				});
				row.appendChild(title);
				row.appendChild(cb);
				subSection.appendChild(row);
			}

			const pageCtrlRow = document.createElement('label');
			pageCtrlRow.className = 'option-row';
			const pageCtrlTitle = document.createElement('span');
			pageCtrlTitle.className = 'option-title';
			pageCtrlTitle.textContent = 'Control of changing page';
			const pageCtrlCb = document.createElement('input');
			pageCtrlCb.type = 'checkbox';
			pageCtrlCb.checked = hasOption('assembler', '-pl 0');
			pageCtrlRow.appendChild(pageCtrlTitle);
			pageCtrlRow.appendChild(pageCtrlCb);
			subSection.appendChild(pageCtrlRow);

			let lineInput = null;
			let lineLabel = null;

			pageCtrlCb.addEventListener('change', () => {
				setOptionEnabled('assembler', '-pl 0', pageCtrlCb.checked);
				if (pageCtrlCb.checked) {
					setNumericOpt('assembler', '-pl ', '');
				} else if (lineInput && lineInput.value) {
					setNumericOpt('assembler', '-pl ', lineInput.value);
				}
				if (lineInput) {
					lineInput.disabled = pageCtrlCb.checked;
				}
				if (lineLabel) {
					lineLabel.style.color = pageCtrlCb.checked ? 'var(--muted)' : '';
				}
				renderOptions();
			});

			const lexpValues = [
				{ label: "No Output", value: '-lexp OFF' },
				{ label: "SRC/OBJ", value: '-lexp ON' },
				{ label: "OBJ", value: '-lexp OBJ' }
			];

			const lexpRow = document.createElement('label');
			lexpRow.className = 'select-row';
			const lexpTitle = document.createElement('span');
			lexpTitle.className = 'option-title';
			lexpTitle.textContent = "Macro Development Department I";
			const lexpSelect = document.createElement('select');
			for (const lv of lexpValues) {
				const opt = document.createElement('option');
				opt.value = lv.value;
				opt.textContent = lv.label;
				lexpSelect.appendChild(opt);
			}
			lexpSelect.value = getLexpValue();
			lexpSelect.addEventListener('change', () => {
				setLexpValue(lexpSelect.value);
				renderOptions();
			});
			lexpRow.appendChild(lexpTitle);
			lexpRow.appendChild(lexpSelect);
			subSection.appendChild(lexpRow);

			function getLexpValue() {
				const vals = getOptionValues('assembler').map(v => v.toLowerCase().trim());
				if (vals.includes('-lexp on')) return '-lexp ON';
				if (vals.includes('-lexp obj')) return '-lexp OBJ';
				return '-lexp OFF';
			}

			function setLexpValue(value) {
				const opts = optionState['assembler'] || [];
				let next = opts.filter(item => {
					const v = item.value.trim().toLowerCase();
					return v !== '-lexp on' && v !== '-lexp off' && v !== '-lexp obj';
				});
				next.push({ value: value });
				optionState['assembler'] = next;
			}

			const numericInputs = [
				{ label: 'Line:', valuePrefix: '-pl ' },
				{ label: 'Column:', valuePrefix: '-pw ' },
				{ label: 'Tab:', valuePrefix: '-tab ' }
			];

			for (const ni of numericInputs) {
				const inputRow = document.createElement('div');
				inputRow.className = 'macro-input-row';
				const inputLabel = document.createElement('label');
				inputLabel.textContent = ni.label;
				const numInput = document.createElement('input');
				numInput.type = 'text';
				numInput.placeholder = 'Enter number';
				numInput.value = getNumericOpt('assembler', ni.valuePrefix);
				numInput.addEventListener('input', () => {
					numInput.value = numInput.value.replace(/[^0-9]/g, '');
					setNumericOpt('assembler', ni.valuePrefix, numInput.value);
					renderOptions();
				});
				if (ni.label === 'Line:') {
					lineInput = numInput;
					lineLabel = inputLabel;
					numInput.disabled = pageCtrlCb.checked;
					inputLabel.style.color = pageCtrlCb.checked ? 'var(--muted)' : '';
				}
				inputRow.appendChild(inputLabel);
				inputRow.appendChild(numInput);
				subSection.appendChild(inputRow);
			}

			updateSubVisibility();
			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Output List: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderLinkerGeneral() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const checkboxOptions = [
				{ label: 'Outputs start message', option: '-V' },
				{ label: 'Outputs debug information', option: '-g' },
				{ label: 'Control of default option file', option: '-Xdof' }
			];

			appendCheckboxOptions(form, 'linker', checkboxOptions);
			insertWarningLevelSelect(form, 'linker', 2, 2);
			appendOtherOptionTextarea(form, 'linker');

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering General: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderDeveloping() {
			const el = document.createElement('div');
			el.style.cssText = 'padding:40px 24px;text-align:center;color:var(--muted);font-size:16px;';
			el.textContent = '开发中...';
			configContent.appendChild(el);
		}

		function renderLibrarianGeneral() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const checkboxOptions = [
				{ label: 'Outputs start message', option: '-V' },
				{ label: 'Outputs debug information', option: '-g' },
				{ label: 'Control of default option file', option: '-Xdof' }
			];

			appendCheckboxOptions(form, 'librarian', checkboxOptions);

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering General: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderLibrarianOutputList() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const mainRow = document.createElement('label');
			mainRow.className = 'option-row';
			const mainTitle = document.createElement('span');
			mainTitle.className = 'option-title';
			mainTitle.textContent = 'Creates a list file';
			const mainCb = document.createElement('input');
			mainCb.type = 'checkbox';
			mainCb.checked = hasOption('librarian', '-m');
			mainRow.appendChild(mainTitle);
			mainRow.appendChild(mainCb);
			form.appendChild(mainRow);

			const subSection = document.createElement('div');
			subSection.className = 'form-grid';
			subSection.style.cssText = 'padding-left:16px;';
			form.appendChild(subSection);

			function updateSubVisibility() {
				subSection.style.display = mainCb.checked ? '' : 'none';
			}

			mainCb.addEventListener('change', () => {
				setOptionEnabled('librarian', '-m', mainCb.checked);
				updateSubVisibility();
				renderOptions();
			});

			const dtOptions = [
				{ label: 'Outputs section name and size for the module', suffix: 's' },
				{ label: 'Outputs external define symbol for the module', suffix: 'd' },
				{ label: 'Outputs external browse symbol for the module', suffix: 'r' },
				{ label: 'Outputs all external define symbol and unsolved external define symbol', suffix: 'a' }
			];

			function getDtSuffixes() {
				const vals = getOptionValues('librarian');
				for (const v of vals) {
					const match = /^-dt\\s+(.+)$/i.exec(v.trim());
					if (match) return match[1].toLowerCase().replace(/\\s/g, '').split(',');
				}
				return [];
			}

			function setDtSuffixes(suffixes) {
				const opts = optionState['librarian'] || [];
				let next = opts.filter(item => !/^-dt\\s/i.test(item.value.trim()));
				if (suffixes.length > 0) {
					next.push({ value: '-dt ' + suffixes.join(',') });
				}
				optionState['librarian'] = next;
			}

			const currentDt = getDtSuffixes();
			const dtCbs = [];

			for (const dt of dtOptions) {
				const row = document.createElement('label');
				row.className = 'option-row';
				const title = document.createElement('span');
				title.className = 'option-title';
				title.textContent = dt.label;
				const cb = document.createElement('input');
				cb.type = 'checkbox';
				cb.checked = currentDt.includes(dt.suffix);
				cb.addEventListener('change', () => {
					const suffixes = [];
					for (const d of dtCbs) {
						if (d.cb.checked) suffixes.push(d.suffix);
					}
					setDtSuffixes(suffixes);
					renderOptions();
				});
				dtCbs.push({ cb, suffix: dt.suffix });
				row.appendChild(title);
				row.appendChild(cb);
				subSection.appendChild(row);
			}

			const pageCtrlRow = document.createElement('label');
			pageCtrlRow.className = 'option-row';
			const pageCtrlTitle = document.createElement('span');
			pageCtrlTitle.className = 'option-title';
			pageCtrlTitle.textContent = 'Control of changing page';
			const pageCtrlCb = document.createElement('input');
			pageCtrlCb.type = 'checkbox';
			pageCtrlCb.checked = hasOption('librarian', '-pl 0');
			pageCtrlRow.appendChild(pageCtrlTitle);
			pageCtrlRow.appendChild(pageCtrlCb);
			subSection.appendChild(pageCtrlRow);

			let lineInput = null;
			let lineLabel = null;

			pageCtrlCb.addEventListener('change', () => {
				setOptionEnabled('librarian', '-pl 0', pageCtrlCb.checked);
				if (pageCtrlCb.checked) {
					setNumericOpt('librarian', '-pl ');
				} else if (lineInput && lineInput.value) {
					setNumericOpt('librarian', '-pl ', lineInput.value);
				}
				if (lineInput) lineInput.disabled = pageCtrlCb.checked;
				if (lineLabel) lineLabel.style.color = pageCtrlCb.checked ? 'var(--muted)' : '';
				renderOptions();
			});

			const numericInputs = [
				{ label: 'Line:', prefix: '-pl ' },
				{ label: 'Column:', prefix: '-pw ' }
			];

			for (const ni of numericInputs) {
				const inputRow = document.createElement('div');
				inputRow.className = 'macro-input-row';
				const inputLabel = document.createElement('label');
				inputLabel.textContent = ni.label;
				const numInput = document.createElement('input');
				numInput.type = 'text';
				numInput.placeholder = 'Enter number';
				numInput.value = getNumericOpt('librarian', ni.prefix);
				numInput.addEventListener('input', () => {
					numInput.value = numInput.value.replace(/[^0-9]/g, '');
					setNumericOpt('librarian', ni.prefix, numInput.value);
					renderOptions();
				});
				if (ni.label === 'Line:') {
					lineInput = numInput;
					lineLabel = inputLabel;
					numInput.disabled = pageCtrlCb.checked;
					inputLabel.style.color = pageCtrlCb.checked ? 'var(--muted)' : '';
				}
				inputRow.appendChild(inputLabel);
				inputRow.appendChild(numInput);
				subSection.appendChild(inputRow);
			}

			updateSubVisibility();
			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Output List: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderConverter() {
			try {
			const form = document.createElement('div');
			form.className = 'form-grid';

			const formatOptions = [
				{ label: 'Motorola S format (f2ms)', ext: '.mhx', flag: '-F2MC_FMT_MHX' },
				{ label: 'Intel HEX format (f2is)', ext: '.ihx', flag: '-F2MC_FMT_IHX' },
				{ label: 'Intel external HEX format (f2es)', ext: '.ehx', flag: '-F2MC_FMT_EHX' },
				{ label: '32-bit Intel HEX format (f2hs)', ext: '.hex', flag: '-F2MC_FMT_HEX' }
			];

			function getCurrentFormatExt() {
				const vals = getOptionValues('converter').map(v => v.toLowerCase().trim());
				for (const f of formatOptions) {
					if (vals.includes(f.flag.toLowerCase())) return f.ext;
				}
				return formatOptions[0].ext;
			}

			function setFormatExt(ext) {
				const opts = optionState['converter'] || [];
				let next = opts.filter(item => {
					const v = item.value.trim().toLowerCase();
					return !formatOptions.some(f => v === f.flag.toLowerCase());
				});
				const match = formatOptions.find(f => f.ext === ext);
				if (match) {
					next.push({ value: match.flag });
				}
				optionState['converter'] = next;
			}

			const formatRow = document.createElement('label');
			formatRow.className = 'select-row';
			const formatTitle = document.createElement('span');
			formatTitle.className = 'option-title';
			formatTitle.textContent = 'Output Data Formater';
			const formatSelect = document.createElement('select');
			for (const f of formatOptions) {
				const opt = document.createElement('option');
				opt.value = f.ext;
				opt.textContent = f.label;
				formatSelect.appendChild(opt);
			}
			formatSelect.value = getCurrentFormatExt();
			formatSelect.addEventListener('change', () => {
				setFormatExt(formatSelect.value);
				renderOptions();
			});
			formatRow.appendChild(formatTitle);
			formatRow.appendChild(formatSelect);
			form.appendChild(formatRow);

			const checkboxOptions = [
				{ label: 'Outputs start message', option: '-V' },
				{ label: 'Control of default option file', option: '-Xdof' }
			];

			appendCheckboxOptions(form, 'converter', checkboxOptions);
			appendOtherOptionTextarea(form, 'converter');

			configContent.appendChild(form);
			} catch (err) {
				configContent.textContent = 'Error rendering Converter: ' + (err && err.message ? err.message : String(err));
			}
		}

		function renderPlaceholder(section) {
			const placeholder = document.createElement('div');
			placeholder.className = 'placeholder';
			for (const label of ['配置项名称', '参数值', '说明']) {
				const row = document.createElement('div');
				row.className = 'placeholder-row';
				const labelElement = document.createElement('div');
				labelElement.className = 'placeholder-label';
				labelElement.textContent = label;
				const control = document.createElement('div');
				control.className = 'placeholder-control';
				row.appendChild(labelElement);
				row.appendChild(control);
				placeholder.appendChild(row);
			}
			configContent.appendChild(placeholder);
		}

		function renderOptions() {
			updateSaveButton();
			const tab = getActiveTab();
			let options = optionState[tab.id] || [];
			options = options.filter(item => !item.value.trim().toLowerCase().startsWith('-f2mc_fmt_'));
			optionDescription.textContent = '';
			optionList.innerHTML = '';

			if (tab.id === 'c-compiler') {
				const orderPatterns = ['-g','-V','-J c','-K FCONST','-K NOINTLIB','-K NOVOLATILE','-K SCHAR','-K SBIT','-w','-INF LIST','-D','-I','-O','-K REALOS','-B','-K ADDSP','-K NOADDSP','-xauto','-K NOEOPT','-K EOPT','-K LIB','-K NOLIB','-K UNROLL','-K NOUNROLL','-c','-cwno','-cpu','-Xdof','-INF STACK'];
				options = sortByOrderPatterns(options, orderPatterns);
			} else if (tab.id === 'assembler') {
				const orderPatterns = ['-g','-V','-w','-D','-I','-sa','-linf','-lsrc','-lsec','-lcros','-linc','-lexp','-pl','-pw','-tab','-lf','-Xdof','-cwno'];
				options = sortByOrderPatterns(options, orderPatterns);
			} else if (tab.id === 'librarian') {
				const orderPatterns = ['-m','-dt','-pl','-pw','-g','-V','-Xdof','-cwno'];
				options = sortByOrderPatterns(options, orderPatterns);
			} else if (tab.id === 'converter') {
				const orderPatterns = ['-V','-Xdof','-cwno'];
				options = sortByOrderPatterns(options, orderPatterns);
			}

			if (options.length === 0) {
				const empty = document.createElement('li');
				empty.className = 'empty-options';
				empty.textContent = '空';
				optionList.appendChild(empty);
				updateSaveButton();
				return;
			}

			for (const item of options) {
				const optionItem = document.createElement('li');
				optionItem.className = 'option-item';
				const code = document.createElement('code');
				code.textContent = item.value;
				optionItem.appendChild(code);
				optionList.appendChild(optionItem);
			}
			updateSaveButton();
		}

		function renderTabs() {
			for (const button of tabButtons) {
				button.classList.toggle('active', button.dataset.tabId === activeTabId);
			}
		}

		function render() {
			renderTabs();
			renderSections();
			renderDetail();
			renderOptions();
		}

		for (const button of tabButtons) {
			button.addEventListener('click', () => {
				activeTabId = button.dataset.tabId;
				activeSectionId = getActiveTab().sections[0].id;
				render();
			});
		}

		render();
	</script>
</body>
</html>`;
}

function escapeHtml(value: string): string {
	return value
		.replace(/&/g, '&amp;')
		.replace(/</g, '&lt;')
		.replace(/>/g, '&gt;')
		.replace(/"/g, '&quot;')
		.replace(/'/g, '&#39;');
}

function getNonce(): string {
	let text = '';
	const possible = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
	for (let index = 0; index < 32; index++) {
		text += possible.charAt(Math.floor(Math.random() * possible.length));
	}
	return text;
}
