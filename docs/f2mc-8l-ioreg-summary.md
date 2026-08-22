# 富士通 F2MC-8L 系列单片机 I/O 定义总结

> 来源：`docs/softune/ioreg.txt` 与 `docs/softune/ioreg_a.txt`
> 文档：FUJITSU《SAMPLE I/O REGISTER FILES FOR F2MC-8L FAMILY USERS MANUAL》Version 2.2（IO3603C-02E）

## 1. 概述

富士通为 F2MC-8L 系列 8 位单片机提供了一套**示例 I/O 寄存器文件（Sample I/O Register Files）**，把各芯片的 I/O 寄存器声明/定义为可直接在程序中使用的名字：

- **`ioreg.txt`** — **C 语言版**：I/O 寄存器以 **C 变量**（`union` / 位域）形式声明，供 `fcc896s` 编译器使用。
- **`ioreg_a.txt`** — **汇编版**：I/O 寄存器以 **汇编符号（Assembler Symbol）** 形式声明，供 `fasm896s` 汇编器使用。

两个手册结构相同，均覆盖 **MB891xx / MB895xx / MB896xx / MB898xx / MB899xx** 五大系列共 42 个产品系列。

## 2. 支持的芯片型号（MB Number）

| 系列组 | 覆盖型号 |
|---|---|
| MB891xx | MB89120/120A、MB89130/130A、MB89140、MB89143A/144A、MB89150/150A、MB89160/160A、MB89170/170A/170L、MB89180、MB89190/190A |
| MB895xx | MB89530、MB89550A、MB89560、MB89570、MB89580、MB89590 |
| MB896xx | MB89601、MB89610/610R、MB89620、MB89630/630R、MB89640、MB89650A、MB89660/660R、MB89670/670A、MB89680、MB89690A |
| MB898xx | MB89800、MB89810A、MB89820、MB89830、MB89860/850、MB89863、MB89870、MB89880、MB89890 |
| MB899xx | MB89910、MB89920、MB89930A、MB89940、MB89950、MB89960、MB89980、MB89990 |

## 3. 文件构成

位于 `${FETOOL}\lib\896\include\sample\` 目录下：

```
${FETOOL}
└─ lib
   └─ 896
      └─ include
         └─ sample
            ├─ _ffmc8l.h     F2MC-8L 家族 I/O 寄存器声明文件（总入口，程序 #include 用）
            ├─ _ffmc8ls.h    可用系列声明文件（按 -cpu 选项选择型号，不匹配时报 #error）
            ├─ _mb891xx.h / _mb895xx.h / _mb896xx.h / _mb898xx.h / _mb899xx.h
            │                各系列组的 I/O 寄存器结构体声明（汇编版文件名加 _a 后缀）
            ├─ _mb89*.h      每个具体系列的 I/O 寄存器声明文件
            ├─ _ffmc8l.c     C 版定义文件（定义变量并指定映射地址）
            └─ _ffmc8l_a.asm 汇编版定义文件
```

- **声明文件（.h）**：声明与 I/O 寄存器对应的变量/符号，供用户程序包含。
- **定义文件（.c / .asm）**：定义变量/符号并指定其在 I/O 地址空间的配置地址。

## 4. 命名规则

### 4.1 C 语言版（ioreg.txt）

- **寄存器变量名**：寄存器名前加 `IO_` 前缀，如 `PDR0` → `IO_PDR0`。
- **可按位/字节/字访问**的寄存器声明为 **union 类型**：
  ```c
  union io_pdr0 {
      unsigned char byte;            /* 字节访问: IO_PDR0.byte */
      struct {
          unsigned char P00:1;       /* 位访问:   IO_PDR0.bit.P00 */
          ...
      } bit;
  };
  extern __io union io_pdr0 IO_PDR0;
  ```
- **只能按 1/2/4 字节访问**的寄存器声明为**整型**（无位域）。
- **位域成员名** = 寄存器位名；连续多位的字段合并为一个成员，用 `[起始位 - 结束位]` 标注，如 `IO_ADC1.bit.ANS [ANS0 - ANS3]`。
- 为方便访问，多个寄存器可能合并为一个变量，如 `T1DR/T2DR` → `IO_T12DR.word` / `IO_T12DR.byte.T1DR`。

### 4.2 汇编版（ioreg_a.txt）

- **寄存器符号名**：`_IO_` + 寄存器名，如 `_IO_PDR0`。
- **位符号名**：`_IO_寄存器名_位名`，如 `_IO_PDR0_PD00`、`SETB IO_TCCS_MODE`。
- 通过宏（`#macro` + `BYTE_MEM` / `STRUCT_TYPE_B` / `UCHARBIT` / `__IO_EXTERN UNION_D`）声明，展开为 `.res.b` / `.RES.i` 伪指令，位符号为 bit 类型、字节符号为 byte 类型。

### 4.3 命名对照表

| 访问方式 | C 版 | 汇编版 |
|---|---|---|
| 字节/字访问 | `IO_寄存器名.byte` / `.word` | `_IO_寄存器名` |
| 位访问 | `IO_寄存器名.bit.位名` | `_IO_寄存器名_位名` |
| 多寄存器合并 | `IO_T12DR.byte.T1DR` | `_IO_T12DR_T1DR` |

## 5. 使用方法

### C 版

```bat
:: (1) 编译定义文件并打包为可重定位模块
fcc896s  -cpu mb89620 -c *.c
flnk896s -cpu mb89620 -r -o io89620.rel *.obj

:: (2) 应用程序中 #include "_ffmc8l.h"，如：IO_TCCS.bit.MODE = 1;
:: (3) 带 -cpu 编译应用程序
fcc896s  -cpu mb89620 -c sample.c

:: (4) 链接（需把 IO 段固定到 0x0000，消除 W1373L 警告）
flnk896s -cpu mb89620 -o sample.abs io89620.rel sample.obj -sc IO/IO=0x0000
```

### 汇编版

```bat
fasm896s -cpu mb89620 _ffmc8l_a.asm
fasm896s -cpu mb89620 sample.asm
flnk896s -cpu mb89620 -o sample.abs _ffmc8l_a.obj sample.obj
```

`-cpu` 指定的型号不在支持列表时会报：
`#error "The I/O register file of the specified CPU option does not exist"`

## 6. 重要注意事项

1. **寄存器文件与系列绑定**，移植到其他系列前必须修改；访问时序需参考硬件手册。
2. **位写操作陷阱（C 版）**：向 `__io` 位域赋**变量**时，编译器生成的是 load → AND/OR → store 序列而非 RMW 指令（SETB/CLRB），若期间其他位变化会造成误改写。应先判断变量 0/1 再赋**常量**：
   ```c
   if (RAM_A) { IO_PDR0.bit.P00 = 1; } else { IO_PDR0.bit.P00 = 0; }
   ```
   RMW 指令生成条件：① 位域宿主为 1 字节 char 类型；② 位宽为 1 bit；③ 寄存器位于直接寻址 I/O 区（0000H–007FH）。增强 I/O 区（0F80H–0FFFH）无法生成 RMW 指令。
3. **保留位**：整体写字节时须按手册写固定值（如 ADC2 的 reserve 位必须写 1，MB89140/143A 的 T1CR bit4-5 必须写 0）。
4. **不存在的位不声明成员**：如 MB89120 的 PDR4 的 P44–P47、MB89190 的 STBC.TMD 等，强行访问无对应成员。

## 7. 各系列外设/寄存器一览

### 7.1 MB891xx 系列（Chapter 5）

10 位/8 位 A/D 转换器、8/16 位定时计数器、8 位 PWM 定时器、8 位串行 I/O（SMR/SDR）、DTMF 发生器、I/O 端口（PDR/DDR/PCR/ENI）、LCD 控制器/驱动器（LCR1 + VRAM）、看门狗定时器（WDTC）、系统时钟控制（SYCC）、低功耗模式（STBC）、时基定时器（TBTC）、蜂鸣器输出（BZCR）、MPG（MCNT/INTSTR/CMCLBR/OUTCBR）、遥控载波发生器（RCR1/RCR2）、外部中断电路 1（边沿 EIC/EIE/EIF）、外部中断电路 2（电平）、中断控制器、时钟预分频器、外围控制时钟输出。

### 7.2 MB895xx 系列（Chapter 6）

10 位 A/D、12 位 PPG、16 位定时计数器、6 位 PPG 定时器、8/16 位定时计数器、8 位 PWM、8 位串行 I/O、D/A 转换器、I/O 端口、IIC 总线接口、LCD 控制器/驱动器、UART、UART/SIO、USB Hub、USB Function、看门狗、时钟输出、比较器、系统时钟控制、低功耗模式、时基定时器、并行端口、PWC、桥接电路、上拉（选项）、多地址 IIC、复位标志、Wild 寄存器功能、外部中断 1（边沿）/2（电平）、中断控制器、时钟预分频器。

### 7.3 MB896xx 系列（Chapter 7）

10 位 A/D、16 位输入捕获、16 位定时计数器、带 1 字节缓冲的串行 I/O、8 位 PWM（2CH）、8/16 位增减计数/定时器、8/16 位定时计数器、8 位 A/D、8 位 PWM、8 位串行 I/O、D/A、I/O 端口、LAN 通信电路、LCD、UART、输出比较、看门狗、时钟监视功能、系统时钟控制、串行 I/O 端口切换、低功耗模式、时基定时器、PWC、蜂鸣器、上拉电阻寄存器、Modem 信号输出电路、Modem 定时器、复位标志、外部总线引脚、外部中断 0 引脚、外部中断 1（边沿）/2（电平）、中断控制器、时钟预分频器。

### 7.4 MB898xx 系列（Chapter 8）

10 位 A/D、16 位输入捕获、16 位定时计数器、带 1 字节缓冲串行 I/O、32 字节串行 I/O、8/16 位定时计数器、8 位 A/D、8 位 PWM、8 位串行 I/O、DTMF 发生器、I/O 端口、LCD、运算放大器（OP amp）、UART、看门狗、系统时钟控制、串口切换电路、低功耗模式、定时器单元、时基定时器、PWC、蜂鸣器、MPG、Modem 定时器、Modem 信号输出、外部总线引脚、外部中断 1（边沿）/2（电平）、中断控制器、小型 LC、时钟预分频器。

### 7.5 MB899xx 系列（Chapter 9）

10 位 A/D、12 位 PPG、16 位输入捕获、16 位定时计数器、8/16 位定时计数器、8 位 A/D、8 位 PWM、8 位串行 I/O、I/O 端口、IIC、LCD、UART、输出比较、看门狗、系统时钟控制、低功耗模式、步进电机控制、时基定时器、PWC、蜂鸣器、上拉电阻寄存器、复位标志、遥控载波发生器、Wild 寄存器功能、外部电压监视中断、外部中断 1（边沿）/2（电平）、中断控制器、时钟预分频器、低电压检测电路（LVD）。

## 8. 版本变更要点

- **V1.0 → V2.0**：新增 MB89170L、MB89570/580/590、MB89800、MB89930、MB89980；MB89550→MB89550A、MB89930→MB89930A 更名；`IO_ADD` 成员在 MB89540/550A/560 上由 `word`/`bit.DATA10` 改为 `ADDL`/`ADDH`，MB89930A 则相反。
- **V2.1 → V2.2**：使用说明新增链接选项 `-sc IO/IO=0x0000`；新增位写注意事项（RMW 相关说明）。
