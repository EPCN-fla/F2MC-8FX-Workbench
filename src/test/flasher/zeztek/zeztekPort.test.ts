// 泽兆烧录器 CP210x 串口自动检测单元测试。
// 运行：npm run compile && node --test dist/test/flasher/
import { deepEqual, equal } from 'node:assert/strict';
import { describe, it } from 'node:test';

import { isZeztekProgrammerPort, selectZeztekPorts } from '../../../flasher/zeztek/zeztekPort';

describe('zeztekPort', () => {
	it('按 vendorId/productId 匹配（serialport 可能返回小写）', () => {
		equal(isZeztekProgrammerPort({ path: 'COM8', vendorId: '10C4', productId: 'EA60' }), true);
		equal(isZeztekProgrammerPort({ path: 'COM8', vendorId: '10c4', productId: 'ea60' }), true);
		equal(isZeztekProgrammerPort({ path: 'COM3', vendorId: '1A86', productId: '7523' }), false);
	});

	it('按 pnpId 匹配（Windows 设备实例路径）', () => {
		equal(isZeztekProgrammerPort({ path: 'COM8', pnpId: 'USB\\VID_10C4&PID_EA60&SER=0001' }), true);
		equal(isZeztekProgrammerPort({ path: 'COM8', pnpId: 'usb\\vid_10c4&pid_ea60&ser=0001' }), true);
		equal(isZeztekProgrammerPort({ path: 'COM3', pnpId: 'USB\\VID_1A86&PID_7523' }), false);
	});

	it('不按厂商名兜底匹配（CP210x 开发板常见，避免误判）', () => {
		equal(isZeztekProgrammerPort({ path: 'COM8', manufacturer: 'Silicon Laboratories' }), false);
		equal(isZeztekProgrammerPort({ path: 'COM3', manufacturer: 'wch.cn' }), false);
		equal(isZeztekProgrammerPort({ path: 'COM1' }), false);
	});

	it('从串口列表过滤出烧录器', () => {
		const ports = [
			{ path: 'COM1', manufacturer: 'Microsoft' },
			{ path: 'COM8', pnpId: 'USB\\VID_10C4&PID_EA60&SER=0001' },
			{ path: 'COM9', vendorId: '10c4', productId: 'ea60' }
		];
		deepEqual(selectZeztekPorts(ports).map(port => port.path), ['COM8', 'COM9']);
	});
});
