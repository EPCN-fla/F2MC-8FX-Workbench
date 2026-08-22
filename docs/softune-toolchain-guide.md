# SOFTUNE 工具链使用指南（F2MC-8L/8FX）

> 整理自 `docs/softune/` 下的 12 份 CHM 官方手册（Professional Pack REV:300019，2013-05）。
> 版本基线：Workbench V30L34 / C 编译器 V30L14 / Assembler Pack REV:300015。
> 本指南聚焦**命令行使用**，作为本扩展编译流程重构（见 `build-refactor-plan.md`）的工具链依据。

## 1. 工具链构成与构建流程

SOFTUNE Professional Pack 由三部分组成：

| 组件 | 可执行文件 | 说明 |
|---|---|---|
| SOFTUNE Workbench | （GUI） | IDE + Simulator/Emulator/Monitor 三种调试器 |
| SOFTUNE C Compiler | `fcc896s.exe` | C 编译器驱动，内部串联 cpps（预处理）→ ccoms（编译）→ 汇编 → 链接 |
| SOFTUNE Assembler Pack | `fasm896s.exe` | 汇编器 |
| | `flnk896s.exe` | 链接器 |
| | `flib896s.exe` | 库管理器（Librarian） |
| | `f2ms/f2hs/f2is/f2es.exe` | 目标码转换器 |

标准构建流程：

```
*.c ──fcc896s──▶ *.obj ─┐
*.asm ─fasm896s─▶ *.obj ─┼─flnk896s─▶ *.abs ─f2ms/f2hs─▶ *.mhx / *.hex
                         │
                *.lib ───┘（flib896s 建库，flnk896s 经 -l 引用）
```

- `fcc896s` 可一步从 C 源直接生成 `.abs`（内部自动调用汇编器与链接器），也可 `-c` 停在 obj。
- 各工具通用约定：选项以 `-` 开头、位置任意、区分大小写；同名选项后者生效（`-D/-U/-I/-f/-l/-L` 等累加型除外）。
- **`-cpu <MB号>` 为强制选项**（编译器 V30L08 / 汇编包 REV:300010 起，四工具均必须），用于校验片内 ROM/RAM；芯片定义取自 CPU 信息文件 `896.csv`（可用 `-cif` 另指）。

### 统一返回值（errorlevel）

| errorlevel | 含义 |
|---|---|
| 0 | 正常结束（或仅有警告，默认） |
| 1 | 指定 `-cwno` 时发生了警告 |
| 2 | 错误，输出结果不可用 |
| 3 | 致命错误，处理无法继续 |

cmd 脚本中用 `if errorlevel 2 exit /b 2` 判断失败；终端 `&&` 串联时 errorlevel 1（-cwno 警告）也会中断，需注意。

### 选项文件（-f）与默认选项文件

- 各工具均支持 `-f <文件>` 把文件内容当命令行读入；注释支持 `#`、`;`、`//`、`/* */`；可嵌套最多 8 层。
- 手册中选项文件扩展名**不固定**（默认补 `.opt`）；`.opc/.opa/.opl/.opb/.opv` 是 Workbench 的惯例命名（本扩展沿用）。
- 每个工具启动时自动读取默认选项文件（`fcc896.opt`、`FASM896.OPT`、`flnk896.opt`、`flib896.opt`、`f2m.opt` 等，位于 `%OPT896%` 或 `%FETOOL%\lib\896`），**`-Xdof` 禁止读取**——自动化构建应始终加 `-Xdof` 保证可复现。
- 限制：链接器选项文件一行 ≤ 1023 字节、不能再含 `-f`/`-Xdof`；C 编译器选项文件每行 ≤ 4095 字符。

### 环境变量

| 变量 | 用途 | 默认值 |
|---|---|---|
| `FETOOL` | 安装根目录（定位消息文件/库/头文件） | 未设置时取 exe 所在目录的上一级 |
| `LIB896` | 库检索目录 | `%FETOOL%\lib\896` |
| `INC896` | 头文件追加搜索路径 | `%FETOOL%\lib\896\include` |
| `OPT896` | 默认选项文件目录 | `%FETOOL%\lib\896` |
| `FELANG` | 消息语言（ASCII 默认 / SJIS / EUC） | ASCII |
| `TMP` | 临时文件目录 | 当前目录 |

> 对本扩展的启示：终端 `env` 注入 `PATH` 指向 Bin 目录后，`FETOOL` 缺省回退为「exe 上级目录」，与 SOFTUNE 标准布局（`Bin/` + `Lib/896/`）吻合，自定义编译器路径时无需额外设置环境变量。

### 安装目录结构约定

```
%FETOOL%\
├─ Bin\            全部工具 exe（fcc896s/fasm896s/flnk896s/flib896s/f2ms...）
└─ Lib\896\
   ├─ 896.csv            CPU 信息文件
   ├─ fcc896.opt / FASM896.OPT / FLNK896.OPT / FLIB896.OPT   默认选项文件
   ├─ lib896.lib（8L）/ lib950.lib（8FX）                     标准库
   ├─ lib896if.lib / lib950if.lib                            调试器底层库
   ├─ startup.asm / startup.obj / start950.*                 启动例程
   ├─ lib896.stk                                           库函数栈数据
   ├─ *.MSG / *.CNT / Wd896.def / SiMan896.dat              消息/计数/仿真文件
   └─ include\           标准头文件（stdio.h 等；sample\ 下为各型号 IO 寄存器头）
```

> 本扩展的工具链压缩包（`toolchain/f2mc-8fx-toolchain-v30lXX.tar.gz`）即按此布局组织（`Bin` + `Lib/896`），解压后直接将 `compilerPath` 指向其根目录即可。

## 2. C 编译器 fcc896s

```text
fcc896s [options] file1.c [file2.asm file3.obj ...]
```

- 输入按扩展名决定处理起点：`.c`（预处理起）、`.i`（编译起）、`.asm`（汇编起）、`.obj`（只链接）。
- 同名选项后者生效；`-D -f -I -INF -K -L -l -ra -ro -sc -T -U -x -Y` 可多次累加。

### 关键选项

| 选项 | 含义 |
|---|---|
| `-cpu <MB号>` | 目标芯片（必选），如 `-cpu MB95F636K` |
| `-c` | 编译到 obj 为止（分步构建时使用） |
| `-S` / `-E` / `-P` | 停在汇编源 / 预处理（优先级 -E > -P > -S > -c） |
| `-o <文件>` | 输出文件名 |
| `-Xdof` | 禁止默认选项文件（自动化必加） |
| `-f <文件>` | 选项文件（本扩展用 `.opc`） |
| `-cwno` | 有警告时 errorlevel=1（用于让 `&&` 链在警告处停下，可选） |
| `-cmsg` | 输出完成消息 |
| `-w <0-8>` | 警告级别，默认 1 |
| `-D <名>[=值]` / `-U <名>` | 宏定义 / 取消（含空白写 `-D "UB=unsigned char"`） |
| `-I <目录>` | 头文件搜索路径（目录末尾不要带 `\`） |
| `-g` | 生成调试信息（obj 内） |
| `-O[0-4]` | 优化级别，省略为 -O2 |
| `-K SIZE` / `-K SPEED` | 体积 / 速度优先组合 |
| `-K EOPT/LIB/UNROLL/ALIAS/ADDSP...` | 细粒度优化开关（`-K NOxxx` 取消） |
| `-J a/c/n` | 语言规范：扩展（默认）/ 严格 ANSI / 扩展+非兼容规格 |
| `-K SCHAR/UBIT/FCONST/NOINTLIB/NOVOLATILE/REALOS...` | 语言细节开关 |
| `-INF LIST` | 生成 `.lst` 列表 |
| `-INF STACK[=file]` | 生成 `.stk` 栈使用量数据（本扩展构建命令在用） |
| `-B` | 允许 `//` 注释 |
| `-V` | 版本信息 |

### 输出文件

`.obj`（-c）、`.asm`（-S）、`.i`（-P）、`.lst`（-INF LIST）、`.stk`（-INF STACK）、`.abs`（直接链接时）、`.map`（链接 -m）。

本扩展现行编译命令（`buildRunner.ts`）：

```bat
fcc896s.exe -f "<OPT>\<base>.opc" -Xdof -o "<OBJ>\<base>.obj" "<src>" -INF STACK="<OBJ>\<base>.stk" -@Hf "<OBJ>\<base>.tpi"
```

## 3. 汇编器 fasm896s

```text
fasm896s [options] prog.asm
```

- 仅能接受**一个**源文件；省略扩展名补 `.asm`。
- 默认选项文件 `FASM896.OPT`（`-Xdof` 抑制）。

### 关键选项

| 选项 | 含义 |
|---|---|
| `-cpu <MB号>` | 目标芯片（必选） |
| `-cif <文件>` | CPU 信息文件（默认 `lib\896\896.csv`；多目录安装时必须与编译器/链接器指向同一 csv） |
| `-o <文件>` / `-Xo` | obj 输出 / 不生成 |
| `-f <文件>` | 选项文件（本扩展用 `.opa`） |
| `-Xdof` | 禁止默认选项文件 |
| `-g` | obj 带调试信息（与 C 联合调试需要） |
| `-l` / `-lf <文件>` | 生成 `.lst` 列表 |
| `-D/-U/-I` | 预处理宏 / include 路径 |
| `-p` | 跳过预处理（编译器输出的汇编源可加速） |
| `-cwno` | 警告时 errorlevel=1 |
| `-w [0-3]` | 警告级别，默认 2 |
| `-sa` / `-div_check` | 结构化语句累加器保护 / DIVU 检查（8FX 默认开） |

发生错误时不生成 obj；errorlevel 约定同总表（0/1/2/3）。

本扩展现行汇编命令：

```bat
fasm896s.exe -f "<OPT>\<base>.opa" -Xdof -o "<OBJ>\<base>.obj" "<src>"
```

### 与 C 的衔接

- 带初值数据 ROM→RAM 传送段统一用段名 `INIT`；链接时 `-sc @INIT=ROM,INIT=RAM ...` 生成 `_ROM_INIT/_RAM_INIT` 符号供启动代码拷贝。
- 汇编预处理器兼容 C 预处理指令，可与 C 共用头文件（仅限预处理部分）。
- 库段名约定：`CODE`（代码）`DATA`（数据）`INIT`（初值）`CONST`（常数）。

## 4. 链接器 flnk896s

```text
flnk896s [file.obj ...] [options]
```

- 输入：`.obj` 或相对格式 `.rel`；支持通配符；`-cpu` 必选。
- 默认选项文件 `flnk896.opt`（`-Xdof` 抑制）；选项文件内不能再写 `-f`。

### 关键选项

| 选项 | 含义 |
|---|---|
| `-o <文件>` | 输出加载模块（默认绝对格式 `.abs`，`-r` 输出相对格式 `.rel`） |
| `-a` / `-r` | 绝对（默认）/ 相对格式 |
| `-cpu <MB号>` | 必选 |
| `-set_rora`（默认开） | 按 896.csv 自动生成 `_ROM_n_/_RAM_n_` 区域名供 `-sc` 引用 |
| `-ro/-ra <名>=<起>/<止>` | 定义 ROM/RAM 区域（仅定义不生效，须 `-sc` 引用） |
| `-sc <段表>[/类型]=<地址\|区域>` | 段配置；`+` 连多段；`@段名` = ROM→RAM 传送段 ROM 侧地址；命令行含 `*` 需加引号 |
| `-AL 0/1/2` | 自动配置：0 关（默认）/ 1 绕开绝对段填充 / 2 按段属性自动分配（Workbench 新建工程默认 mode 2） |
| `-l <库>` | 检索库（逗号列举/通配符，先于默认库） |
| `-L <路径>` | 库检索路径 |
| `-e <符号>` | 入口符号（一般由启动例程定义，可省） |
| `-g` / `-Xg`（默认） | 保留/删除调试信息 |
| `-m <文件>` | map 列表，**默认输出** `<输出名>.mp1` |
| `-alin/-alout <目录>` | 相对汇编列表输入目录 / 绝对汇编列表输出目录 |
| `-als/-alr/-xl/-sl/-ml` | 绝对汇编列表 / ROM-RAM·ARRAY 列表 / 交叉引用 / 局部符号 / 段详细 map |
| `-cwno` | 警告时 errorlevel=1 |

典型命令：

```bat
flnk896s *.obj -o app.abs -cpu MB89P935B -set_rora -sc "*/code"=0xC100,D=0x100
```

本扩展现行链接命令（选项集中在 `.opl`）：

```bat
flnk896s.exe -f "<OPT>\<base>.opl" -Xdof
```

`.opl` 内容（本扩展生成）：`-m <map>`、`-alin/-alout <LST>`、`-Xset_rora`（注意：扩展当前显式关闭了自动区域）、`-cwno`、`-a`、`-cpu`、`-o <abs>`、`-l <库...>`，空行后逐行列出全部 obj。

## 5. 库管理器 flib896s

```text
flib896s <库文件.lib> [options]
```

| 选项 | 功能 |
|---|---|
| `-a <obj...>` | 追加模块（库不存在则新建；最多 65535 个模块） |
| `-r <obj...>` | 替换登录 |
| `-d <模块名>` | 删除（按模块名非文件名） |
| `-x <模块名>[,<输出>]` | 抽出模块回 obj |
| `-m <列表>` | 输出库内容列表（`.mp2`；`-m -` 到标准输出；默认不输出） |
| `-c` / `-O` | 检查库（单独使用）/ 删除调试信息缩小库（单独使用） |
| `-b` | 编辑前备份 `.bak` |
| `-cpu <MB号>` | 必选 |

默认选项文件 `flib896.opt`；本扩展用 `.opb`。

## 6. 目标码转换器（f2ms / f2hs / f2is / f2es）

命名规则 `x2ys`：f=.abs、m=S 格式、h=HEX 混合、b=二进制、i=仅 HEX8、e=仅 HEX16。

| 命令 | 转换 | 默认输出扩展名 |
|---|---|---|
| `f2ms` | .abs → Motorola S（S1/S2/S3 按地址自动） | `.mhx` |
| `f2hs` | .abs → Intel HEX（HEX8/16/32 自动，**推荐**） | `.hex` |
| `f2is` | .abs → 仅 HEX8（≤64KB，兼容保留） | `.ihx` |
| `f2es` | .abs → 仅 HEX16（≤1MB，扩展段地址记录） | `.ehx` |
| `m2bs` / `h2bs` | → 二进制镜像（需 `-ran`） | `.bin` |

```text
f2ms sample                 :: sample.abs → sample.mhx
f2ms ccp903 -o out.hex      :: 改名输出（扩展名不改变格式本身）
f2ms app -p 0xFF,0xE000,0xFFFF   :: 指定范围填充
```

- 选项：`-o` 输出、`-p <值>,<起>,<止>` 填充、`-S1/-S2/-S3`（f2ms 强制记录类型）、`-I16/-I20/-I32`（f2hs 强制 HEX 类型）、`-entry`（起始地址记录）、`-adjust`。
- 默认选项文件 `f2m.opt`/`f2h.opt`/`f2i.opt`/`f2e.opt`（`-Xdof` 抑制）。
- 本扩展按 `.opv` 中 `-o` 的扩展名选择转换器（`.ihx→f2is`、`.ehx→f2es`、`.hex→f2hs`、其他→f2ms），命令：`f2ms.exe -f "<OPT>\<base>.opv" -Xdof`。

## 7. Workbench 工程体系（兼容性参考）

本扩展解析/复现 Workbench 工程，要点：

- **.wsp → .prj → configuration**：workspace 管理多个工程与 active project；每个工程含多个 configuration（默认 `Debug`），构建按 active configuration 执行。
- **选项存储**：新格式（V30L26+）选项存在 `.prj` 内；旧 V3 格式选项在 `.dat`（本扩展 `readDatOptions` 解析的 `$0~$4` 段即 C 编译器/汇编器/链接器/库管理器/转换器选项）。
- **标准目录**（按 configuration 命名，可改）：

```
<工程目录>\<Configuration>\
├─ ABS\   目标文件（.abs / 转换后 hex）
├─ OBJ\   obj / stk / tpi
├─ LST\   列表 / map（.mp1）
└─ OPT\   IDE 每次构建生成的选项文件（.opc/.opa/.opl/.opb/.opv）
```

- **构建语义**：Make=增量（依 include 依赖）、Build=全量、Compile=仅单文件；子工程先于父工程构建（ABS/LIB 型子工程不链接进父工程）。
- **工程类型**（General tab）：ABS / REL / LIB / REALOS-ABS——决定走链接器还是库管理器、Converter 是否启动。
- **新建工程时** IDE 按 MCU 自动生成链接器选项：`_INROMxx/_INRAMxx` 区域 + 自动配置 mode 2。
- **无 headless 构建接口**：Workbench 不支持命令行整工程构建，故本扩展自行生成选项文件 + 命令行调用是官方推荐路径的等价实现。
- 其他需兼容特性：individual option（文件级覆盖）、remove from build、链接顺序（Set Linkage Order）、Customize Build 前后钩子。

## 8. 注意事项汇总

- 所有自动化命令加 `-Xdof`，避免用户机器上的默认选项文件干扰构建可复现性。
- 目录路径末尾不要带反斜杠；含空格路径用双引号；`-sc` 含 `*` 时命令行加引号、选项文件中不加。
- 编译器/汇编器/链接器分散安装时必须用 `-cif` 指向同一个 `896.csv`。
- 工具输出为 ANSI 编码（日文 SJIS / 中文 GBK），终端代码页需匹配（详见 `build-refactor-plan.md` 编码章节）。
- `-cwno` 使警告返回 1：配合 `&&` 串联时警告即中断，若不希望中断则不要加。
- fcc896s 一条命令可完成「编译+链接」（省略 `-c`），分步构建（逐文件 obj + 统一链接）更利于并行与错误定位——本扩展采用分步方式。
- 旧工程转换备份：`.p03`（旧 prj）、`.d03`（旧 dat）、`.v01`（Manager V01/V02）。

## 9. 扩展功能设计：工具链安装（设置页）

扩展不再内置编译器，工具链以 tar.gz 形式存放在 GitHub 仓库 `toolchain/` 目录，由用户在插件内按需下载。

### 9.1 安装包

| 包 | 文件 | 内容 |
|---|---|---|
| V30L14 | `toolchain/f2mc-8fx-toolchain-v30l14.tar.gz` | C 编译器 V30L14 工具链（Bin + Lib/896） |
| V30L15 | `toolchain/f2mc-8fx-toolchain-v30l15.tar.gz` | V30L15 工具链（Bin + Lib/896，含 FLIB896S.EXE） |

下载地址（raw）：

```text
https://raw.githubusercontent.com/EPCN-fla/F2MC-8FX-Workbench/main/toolchain/f2mc-8fx-toolchain-v30l14.tar.gz
https://raw.githubusercontent.com/EPCN-fla/F2MC-8FX-Workbench/main/toolchain/f2mc-8fx-toolchain-v30l15.tar.gz
```

压缩包内顶层目录为 `V30L14/` / `V30L15/`，解压后即标准 `Bin/` + `Lib/896/` 布局，与 `resolveCompilerDirectory()` 的「根目录」形态匹配。

### 9.2 本地安装目录

```text
%USERPROFILE%\.f2mc-8fx-wb\toolchain\
├─ V30L14\   （解压后：Bin\ + Lib\）
└─ V30L15\
```

- 目录不存在时由扩展自动创建（含 `.f2mc-8fx-wb` 根目录）。
- 检测依据：`<安装目录>\<版本>\Bin\fcc896s.exe` 存在即视为该版本已安装。

### 9.3 交互流程

1. 「设置」视图根节点在「构建器选项」下方新增「工具链安装」节点。
2. 点击后 VS Code 顶部弹出 QuickPick，列出两个版本项，右侧（`description`）显示检测状态：
   - `V30L14    🗸` — 本机已检测到
   - `V30L15    🗴` — 未安装
   - 可附加第三项「浏览本地目录…」，供用户使用自行安装的 SOFTUNE（如 `C:\SOFTUNE`）。
3. 点击 🗴 项：自动从 GitHub 仓库下载对应 tar.gz → 解压到 `%USERPROFILE%\.f2mc-8fx-wb\toolchain\` → 校验 `Bin\fcc896s.exe` 存在 → 自动写入设置
   `f2mc-8fx-workbench.compilerPath = %USERPROFILE%\.f2mc-8fx-wb\toolchain\<版本>`（Workspace 或 Global，建议 Global，因工具链与工程无关）。
4. 点击 🗸 项：直接将该版本路径写入 `compilerPath`（即版本切换）。
5. 下载/解压过程用 `window.withProgress`（`ProgressLocation.Notification`）显示进度，失败时 `showErrorMessage` 并保留重试入口。

### 9.4 实现要点

- **检测**：`fs.existsSync(path.join(os.homedir(), '.f2mc-8fx-wb', 'toolchain', version, 'Bin', 'fcc896s.exe'))`。
- **下载**：Node `https.get`（跟随 302 重定向）流式写入临时文件 `*.tar.gz.download`，完成后改名，避免半截文件被误判。
- **解压**：Windows 10+ 自带 bsdtar，可 `child_process.execFile('tar', ['-xzf', pkg, '-C', toolchainDir])`；如需脱离外部命令则引入纯 JS tar 解析依赖（当前 package.json 无运行时依赖，优先 tar.exe 方案）。
- **清理**：解压成功后删除下载的 tar.gz 临时文件。
- **设置写入**：`workspace.getConfiguration().update('f2mc-8fx-workbench.compilerPath', installDir, ConfigurationTarget.Global)`。
- **联动**：安装/切换后若已实现终端 env 注入（重构步骤 4），需 dispose 旧终端使 PATH 重建；同时触发 cpptools 配置刷新。
- **离线场景**：下载失败时提示用户手动下载 tar.gz 并解压到上述目录，或在设置中直接填写本机 SOFTUNE 路径。
