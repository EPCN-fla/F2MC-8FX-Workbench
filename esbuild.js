// 发布打包：esbuild bundle → dist/extension.js + dist/hidWorker.js（hidWorker 由 Worker 按路径加载，须为独立文件）。
// node-hid / serialport 为原生模块，保持 external，随 node_modules 一起打包。

const fs = require('node:fs');
const path = require('node:path');

const esbuild = require('esbuild');

const production = process.argv.includes('--production');

const distDir = path.join(__dirname, 'dist');
fs.rmSync(distDir, { recursive: true, force: true });

/** @type {import('esbuild').BuildOptions} */
const options = {
	entryPoints: {
		extension: 'src/extension.ts',
		hidWorker: 'src/flasher/f2mcLink/hidWorker.ts'
	},
	bundle: true,
	format: 'cjs',
	platform: 'node',
	target: 'es2022',
	outdir: distDir,
	external: ['vscode', 'node-hid', 'serialport'],
	minify: production,
	sourcemap: !production,
	sourcesContent: false,
	logLevel: 'info'
};

esbuild.build(options).catch(() => process.exit(1));
