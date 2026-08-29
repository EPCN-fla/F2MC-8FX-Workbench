import { defineConfig } from '@vscode/test-cli';

// 仅运行需要 VS Code API 的集成测试（mocha）；
// src/test/flasher/ 下的纯逻辑单测使用 node:test，由 `node --test dist/test/flasher/` 运行。
export default defineConfig({
	files: 'dist/test/extension.test.js',
});
