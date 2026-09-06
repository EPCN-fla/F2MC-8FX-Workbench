// 泽兆烧录器串口自动检测：烧录器为 CP210x USB 串口（VID 0x10C4 / PID 0xEA60）。
// 仅按 VID/PID（或 pnpId 等价信息）匹配；不按厂商名兜底——Silicon Labs CP210x
// 是开发板极常见的串口芯片，兜底会把无关设备误判为烧录器。
// 与 vscode 解耦，便于 node --test 单元测试；serialport 的 PortInfo 结构与本接口兼容。

export interface SerialPortInfoLike {
	path: string;
	manufacturer?: string;
	pnpId?: string;
	vendorId?: string;
	productId?: string;
}

const ZEZTEK_VID = '10C4';
const ZEZTEK_PID = 'EA60';

export function isZeztekProgrammerPort(info: SerialPortInfoLike): boolean {
	const vendorId = info.vendorId?.toUpperCase();
	const productId = info.productId?.toUpperCase();
	if (vendorId === ZEZTEK_VID && productId === ZEZTEK_PID) {
		return true;
	}

	const pnpId = info.pnpId?.toUpperCase() ?? '';
	return pnpId.includes(`VID_${ZEZTEK_VID}`) && pnpId.includes(`PID_${ZEZTEK_PID}`);
}

export function selectZeztekPorts<T extends SerialPortInfoLike>(ports: T[]): T[] {
	return ports.filter(isZeztekProgrammerPort);
}
