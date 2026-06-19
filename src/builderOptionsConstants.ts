export type BuilderTabId = 'c-compiler' | 'assembler' | 'linker' | 'librarian' | 'converter';

export interface BuilderTabDefinition {
	id: BuilderTabId;
	label: string;
	datSection: string;
	sections: BuilderSectionDefinition[];
}

export interface BuilderSectionDefinition {
	id: string;
	label: string;
	description: string;
}

export interface BuilderOptionsViewModel {
	projectName: string;
	options: Record<BuilderTabId, BuilderOptionLine[]>;
}

export interface BuilderOptionLine {
	value: string;
}

export const BUILDER_TABS: BuilderTabDefinition[] = [
	{
		id: 'c-compiler',
		label: 'C Compiler',
		datSection: '0',
		sections: [
			{ id: 'general', label: 'General', description: 'C 编译器通用输出、调试、警告和默认选项控制。' },
			{ id: 'define-macro', label: 'Define Macro', description: '用于放置 C 编译器宏定义参数。' },
			{ id: 'include-path', label: 'Include Path', description: '用于放置 C 编译器头文件包含路径参数。' },
			{ id: 'optimize', label: 'Optimize', description: '用于放置 C 编译器优化相关参数。' },
			{ id: 'language', label: 'Language', description: '用于放置 C 语言方言和语言规则相关参数。' }
		]
	},
	{
		id: 'assembler',
		label: 'Assembler',
		datSection: '1',
		sections: [
			{ id: 'general', label: 'General', description: '用于放置汇编器通用参数。' },
			{ id: 'define-macro', label: 'Define Macro', description: '用于放置汇编器宏定义参数。' },
			{ id: 'include-path', label: 'Include Path', description: '用于放置汇编包含路径参数。' },
			{ id: 'target-depend', label: 'Target Depend', description: '用于放置目标依赖参数。' },
			{ id: 'output-list', label: 'Output List', description: '用于放置输出列表参数。' }
		]
	},
	{
		id: 'linker',
		label: 'Linker',
		datSection: '2',
		sections: [
			{ id: 'general', label: 'General', description: '用于放置链接器通用参数。' },
			{ id: 'disposition-connection', label: 'Disposition/Connection', description: '研发中' },
			{ id: 'register-bank', label: 'Register Bank', description: '研发中' },
			{ id: 'define-symbol', label: 'Define Symbol', description: '研发中' },
			{ id: 'output-list', label: 'Output List', description: '研发中' },
			{ id: 'absolute-assembly-list', label: 'Absolute Assembly List', description: '研发中' },
			{ id: 'control-library', label: 'Control Library', description: '研发中' }
		]
	},
	{
		id: 'librarian',
		label: 'Librarian',
		datSection: '3',
		sections: [
			{ id: 'general', label: 'General', description: '用于放置库管理器通用参数。' },
			{ id: 'output-list', label: 'Output List', description: '用于放置输出列表参数。' }
		]
	},
	{
		id: 'converter',
		label: 'Converter',
		datSection: '4',
		sections: [
			{ id: 'general', label: 'General', description: '用于放置转换器输出格式、调试等参数。' }
		]
	}
];

export const EMPTY_VIEW_MODEL: BuilderOptionsViewModel = {
	projectName: '未加载工程',
	options: {
		'c-compiler': [],
		assembler: [],
		linker: [],
		librarian: [],
		converter: []
	}
};
