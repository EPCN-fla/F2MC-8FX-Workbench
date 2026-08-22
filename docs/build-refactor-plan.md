# 编译流程重构方案：自定义编译器路径 + VS Code 终端直跑编译指令

## 1. 现状分析

当前编译链路（`src/buildRunner.ts`）存在两个待改造点：

### 1.1 编译器路径固定写死

- `createBuildLayout()`（src/buildRunner.ts:149）将编译器目录硬编码为扩展内置路径：
  `path.join(extensionPath, 'res', 'compiler', 'Bin')`
- 生成 bat 时通过 `set "COMPILER_DIR=..."` + `set "PATH=%COMPILER_DIR%;%PATH%"` 注入工具链。
- 用户无法使用自行安装的 SOFTUNE 编译器，也无法切换工具链版本。

### 1.2 编译指令经由 bat 文件间接执行

- `createBuiltInCommand()`（src/buildRunner.ts:115-124）将完整编译流程写入
  `.f2mc-helper/build.bat`（或 `clean.bat`），再向终端发送
  `& <scriptPath>; Remove-Item ...` 执行后自删除。
- 终端实际已在用（`getSharedTerminal()` + `sendText`），但只是充当 bat 的启动器：
  - 无法分步观察每条编译命令；
  - 错误处理依赖 bat 内的 `if errorlevel 1 exit /b 1`，扩展拿不到任何退出码；
  - 需要磁盘 I/O 写/删临时脚本，存在残留风险；
  - `chcp 65001`、`setlocal enabledelayedexpansion` 等 cmd 特性把实现绑定在 cmd 上，与 PowerShell 终端混用时行为隐晦。

### 1.3 其他受影响的代码

| 位置 | 原状 | 处理结果 |
|---|---|---|
| `src/cppConfigurationProvider.ts:171` | IntelliSense include 路径指向 `res/compiler/Lib/896/INCLUDE` | ✅ 已改为 `getStandardLibPaths()`，经 `resolveCompilerIncludeDirectory()` 推导 `<compilerRoot>/Lib/896/include` |
| `src/chipCatalog.ts:18` | 芯片表从 `res/compiler/Lib/896/896.csv` 读取 | ✅ 896.csv 作为芯片数据保留为 `res/896.csv`（与工具链解耦） |
| `package.json` `contributes.configuration` | 仅 `wspPath` / `buildWorkingDirectory` / `buildCommandTemplate` | ✅ 已新增 `f2mc-8fx-workbench.compilerPath` |
| `res/compiler/` | 内置整套编译器（fcc896s / FASM896S / FLNK896S / F2xS 等） | ✅ 已删除，不再随插件打包；工具链改为 `toolchain/*.tar.gz` 供用户自行下载 |

> **进度说明（2026-08-22）**：步骤 1、2、5 已完成（含 `res/compiler` 移除与 tar.gz 打包）；步骤 3、4（去 bat 化 + cmd 终端直跑）与步骤 6（设置页入口）待实施。已完成部分的描述已与实际代码同步。

## 2. 目标设计

```
设置页配置 compilerPath（或经「工具链安装」自动下载配置）
        │
        ▼
toolchain.ts: resolveCompilerDirectory()  ── 校验 fcc896s.exe 等工具存在 ──► 失败则警告并中止
        │
        ▼
生成指令序列（不再写 bat）──► 创建/复用 cmd 终端（shellPath=cmd.exe，env 注入 PATH，chcp 936）
        │
        ▼
terminal.sendText() 以 cmd 语法（&& 串联 / 逐条）执行
```

> 注：扩展已不再内置编译器，`compilerPath` 为空且不存在内置回退目录时构建直接中止并提示配置。

## 3. 实施步骤

### 步骤 1：新增设置项（package.json）✅ 已完成

已在 `contributes.configuration.properties` 中新增：

```jsonc
"f2mc-8fx-workbench.compilerPath": {
  "type": "string",
  "default": "",
  "scope": "machine-overridable",
  "markdownDescription": "SOFTUNE 编译器目录（Bin 目录或其上一级根目录，如 `C:\\SOFTUNE\\V30L15`）。扩展不再内置编译器，必须配置此项后才能编译。支持 `${workspaceFolder}` 变量。"
}
```

说明：
- `scope: "machine-overridable"` 允许远程/多机场景下按机器覆盖。
- 后续由「工具链安装」功能自动下载并写入该设置（见步骤 6 与工具链安装设计）。

### 步骤 2：编译器路径解析与校验（src/toolchain.ts）✅ 已完成

实际实现为独立模块 `src/toolchain.ts`（而非放在 buildRunner.ts 内），导出三个函数：

- `resolveCompilerDirectory(extensionPath)`：读取 `compilerPath` 设置（支持 `${workspaceFolder}` 变量），兼容用户填「Bin 目录」或「上一级根目录」两种形态（候选 `[configured, configured/Bin]`，以任一工具 exe 存在判定）；未配置时回退检测内置 `res/compiler/Bin`（已删除，仅作向后兼容）；均无则返回 `undefined`。
- `findMissingCompilerTools(compilerDirectory)`：遍历 `COMPILER_TOOLS`（fcc896s / FASM896S / FLNK896S / FLIB896S / F2MS / F2IS / F2ES / F2HS）返回缺失列表。
- `resolveCompilerIncludeDirectory(extensionPath)`：由 Bin 目录推导 `<root>/Lib/896/include`，供 IntelliSense 使用。

`buildRunner.ts` 侧接线（已完成）：

- `createBuiltInCommand()` 先解析编译器目录：未配置 → 警告「请在设置中配置 f2mc-8fx-workbench.compilerPath」并中止；缺工具 → 警告列出缺失文件并中止（把 bat 里的 `if not exist` 检查前移到 TS 侧）。
- `createBuildLayout()` 改为接收 `compilerDirectory` 参数，不再内部拼接 `res/compiler/Bin`。
- bat 内 `COMPILER_TOOLS` 存在性检查保留（双保险），常量改从 toolchain.ts 导入。

### 步骤 3：去除 bat，改为终端直接执行（待实施）

重构 `createBuiltInCommand()` / `createBuildScript()`：

1. 将 `createBuildScript()` 中的指令翻译为「命令数组」而非 bat 文本：
   - 编译类命令（`fcc896s.exe -f ...`、`fasm896s.exe -f ...`、链接、转换器）生成 `string[]`；
   - 目录创建（`mkdir OBJ/LST/OPT`）改由 TS 侧 `fs.promises.mkdir(..., { recursive: true })` 在发送命令前完成；
   - clean 的 `del /q` 可用 Node `fs` 直接实现，或翻译成 PowerShell `Remove-Item` 命令序列（终端执行方式下建议保留终端可见，便于用户核对）。
2. 终端 shell 明确使用 **cmd.exe**（Windows 主目标），不用 PowerShell；如需跨平台/兼容 git-bash，按 shell 类型生成两套命令文本（见步骤 4）。
3. 执行策略（cmd 语法）：
   - **单行串联**：用 cmd 的 `&&` 把「编译 → 链接 → 转换」拼成一条命令发送，任一失败即中断（`&&` 语义天然等价于 bat 里的 `if errorlevel 1 exit /b 1`），如：
     ```bat
     fcc896s.exe -f "..." -Xdof -o "..." "src.c" && fasm896s.exe -f "..." ... && flnk896s.exe -f "..." -Xdof && f2ms.exe -f "..." -Xdof
     ```
     提示性标题（`echo Now building...` 等）可用 `echo.` 穿插，但 echo 文本必须考虑编码（见步骤 4）。
   - **逐条 sendText**：可读性最好，但 VS Code API 无法感知每条命令的退出码，失败时后续命令仍会执行；如需逐条发送则每条命令后自行追加 `|| exit /b 1` 或改用 `&&` 前缀串联。shell integration（`onDidEndTerminalShellExecution`）可作为后续增强。
   - clean：删除命令翻译为 cmd 的 `if exist "<dir>\*.obj" del /q "<dir>\*.obj"` 序列，逐条发送，保持终端可见便于用户核对。
4. 删除/停用以下不再需要的内容：
   - `writeTextFile(scriptPath, ...)` 与 `.f2mc-helper` 临时目录；
   - `createScriptExecutionCommand()`（执行后自删脚本的逻辑）；
   - bat 专属的 `@echo off`、`setlocal` 等（`chcp` 处理下沉到终端初始化，见步骤 4）；
   - `runProjectTask()` 中 PowerShell 专属的 `Set-Location -LiteralPath`、`Clear-Host` 和 `quotePowerShellLiteral()`，改为 cmd 的 `cd /d "<cwd>"`（或创建终端时直接传 `cwd`，无需再发送 cd）。

### 步骤 4：终端创建（cmd/bash）与编码处理（待实施）

`getSharedTerminal()` 当前只传 `name/cwd`，且 `sendText` 前缀命令假定 PowerShell。改为显式指定 shell：

```ts
function getSharedTerminal(cwd: string, compilerDir: string): vscode.Terminal {
  if (!sharedTerminal || sharedTerminal.exitStatus) {
    sharedTerminal = vscode.window.createTerminal({
      name: 'F2MC-8FX',
      shellPath: 'cmd.exe',          // 显式 cmd，不受用户默认 shell 影响
      cwd,
      env: { PATH: `${compilerDir}${path.delimiter}${process.env.PATH ?? ''}` }
    });
  }
  return sharedTerminal;
}
```

要点：

- **shellPath 显式化**：`cmd.exe` 保证 `&&`、`if exist`、`del /q` 等命令文本语义稳定。若需支持 bash（git-bash/WSL），增加 shell 类型判定分支：bash 下用 `&&` 串联、`rm -f`、`mkdir -p`，路径分隔符与引号规则分别处理；Windows 编译器工具链下 cmd 为推荐默认。
- **编码（重点）**：
  - F2MC 编译器工具（fcc896s 等）输出为 ANSI 编码（中文系统即 GBK/CP936），错误信息含日文/中文时按 CP936 解码才能正确显示。
  - cmd 终端创建后先发送 `chcp 936 >nul`（或保持系统默认代码页不发送 chcp），使 conpty 按 GBK 解码，编译器中文输出不乱码。
  - 不要沿用 bat 方案的 `chcp 65001`：65001 下 GBK 工具输出会乱码。原 bat 设 65001 只是为了让 bat 文件内 UTF-8 的 echo 中文正常；终端直跑方案中 echo 文本由扩展以 Unicode 经 `sendText` 传入，VS Code 会正确处理，无需 65001。
  - 折中：若 echo 提示文本也出现乱码（某些 conpty 版本对 sendText 的非 ASCII 文本处理不一致），提示语改为纯英文/ASCII 最稳妥。
  - 由此 `sendText` 的命令文本只含 ASCII 命令 + 路径参数，路径含非 ASCII 时加双引号即可（cmd 对引号内 UTF-16 传入的路径处理正常）。
- **env 注入时机**：`env` 只在终端**创建时**生效，编译器路径变化后需 dispose 旧终端重建（监听 `onDidChangeConfiguration`，或每次构建前比对当前终端使用的 compilerDir，不一致则 `sharedTerminal.dispose()` 后置空重建）。这比 bat 里的 `set PATH=...` 干净，命令行直接写 `fcc896s.exe` 即可。

### 步骤 5：同步 IntelliSense include 路径（cppConfigurationProvider.ts）✅ 已完成

- `getStandardLibPath()` 已重构为 `getStandardLibPaths(): string[]`，经 `toolchain.ts` 的 `resolveCompilerIncludeDirectory()` 从 `compilerPath` 设置推导 `<root>/Lib/896/include`（Windows 文件系统大小写不敏感，原 `INCLUDE` 大写目录亦可命中）。
- 未配置编译器路径时返回空数组，cpptools 容忍缺失路径（IntelliSense 仅缺少标准头解析）。
- 芯片表 `896.csv` 与工具链解耦：`chipCatalog.ts` 已改为读取扩展内置的 `res/896.csv`（随插件打包的纯数据文件），不再依赖编译器目录。
- 待办：设置变更后调用 cpptools 的 `notifyDidChange` 刷新配置（当前 `refresh()` 为空实现）。

### 步骤 6：设置页便捷入口（待实施）

在 `settingsTree.ts` 的「设置」视图根节点新增「工具链安装」节点（位于「构建器选项」下方），交互设计详见 `softune-toolchain-guide.md` 第 9 章：

- 点击后 VS Code 顶部弹 QuickPick，列出 `V30L14` / `V30L15`，右侧以 ✓ / 🗴 标记本机检测结果；
- 检测路径：`%USERPROFILE%\.f2mc-8fx-wb\toolchain\<版本>\Bin\fcc896s.exe`（目录不存在则创建）；
- 🗴 项点击后从 GitHub 仓库 `toolchain/` 下载对应 tar.gz 并解压到检测目录，成功后自动写入 `compilerPath` 设置；
- 另可提供「浏览本地目录」项：弹 `showOpenDialog({ canSelectFolders: true })` 选择目录，校验含 `fcc896s.exe` 后写入 `compilerPath`。

### 步骤 7：清理与验证

1. 移除死代码：`createScriptExecutionCommand`、bat 生成函数中的 cmd 专用行、不再使用的 `quoteShell` 引用等，运行 `yarn lint` 确认无未使用告警。
2. `yarn compile` 通过。（步骤 1/2/5 变更后 `yarn compile` / `yarn lint` 已通过，0 errors。）
3. 手动验证矩阵：
   - 未设置 `compilerPath` → 构建前警告提示配置编译器路径（扩展已不内置编译器）；
   - 设置为有效 Bin 目录 → 终端 PATH 生效、编译成功；
   - 设置为安装根目录（自动补 `Bin`）→ 编译成功；
   - 设置为无效目录 → 构建前警告且不发送命令；
   - clean 命令 → 中间产物被正确删除；
   - 切换 `compilerPath` 后再次构建 → 终端重建且使用新路径；
   - 路径含空格/非 ASCII 字符 → 双引号包裹后 cmd 下解析正确，编译器中文输出无乱码（chcp 936）；
   - 「工具链安装」下载 V30L14/V30L15 → 解压到 `%USERPROFILE%\.f2mc-8fx-wb\toolchain` 后检测为 ✓ 且可编译。

## 4. 影响面汇总

| 文件 | 变更 | 状态 |
|---|---|---|
| `package.json` | 新增 `f2mc-8fx-workbench.compilerPath` 设置项 | ✅ |
| `src/toolchain.ts` | 新增模块：编译器路径解析 / 工具校验 / include 推导 | ✅ |
| `src/buildRunner.ts` | 路径解析/校验接线；去 bat 化、终端 env 注入、终端重建逻辑 | 部分（接线 ✅，去 bat 待实施） |
| `src/cppConfigurationProvider.ts` | include 路径改为跟随设置 | ✅ |
| `src/chipCatalog.ts` | 芯片表改读 `res/896.csv` | ✅ |
| `src/settingsTree.ts` | 新增「工具链安装」入口节点 | 待实施 |
| `src/extension.ts` | 注册工具链安装/选择目录命令；`onDidChangeConfiguration` 监听 | 待实施 |
| `res/compiler/` | 已删除，不再随插件打包 | ✅ |
| `res/896.csv` | 芯片目录数据（自 res/compiler 迁出） | ✅ |
| `toolchain/*.tar.gz` | V30L14 / V30L15 工具链压缩包，供用户自行下载 | ✅ |
| `.vscodeignore` | 排除 docs / toolchain / res/V30L14 / res/V30L15 / *.vsix | ✅ |

## 5. 风险与注意事项

- **终端退出码不可达**：`sendText` 无法回传结果，构建成功/失败只能依赖终端文本。若后续要做「构建成功自动下载」等联动，需引入 shell integration（`window.onDidEndTerminalShellExecution`，VS Code ≥1.93）或改用 `vscode.tasks` + `ShellExecution` + problem matcher。
- **env 注入时机**：Terminal 的 `env` 仅创建时生效，切换编译器路径必须重建终端，否则会沿用旧 PATH。
- **PowerShell vs cmd**：现有 `sendText` 前缀命令（`Set-Location -LiteralPath`、`Clear-Host`）假定 PowerShell。重构后显式 `shellPath: 'cmd.exe'` 创建终端，命令文本统一按 cmd 语法生成（`&&` 串联、`if exist`、`del /q`）；如需 bash 支持则按 shell 类型分支生成，不允许依赖用户默认 shell。
- **编码**：编译器输出为 ANSI/GBK，终端保持 CP936（发送 `chcp 936 >nul` 或沿用系统默认），**不要**沿用 bat 方案的 `chcp 65001`；`sendText` 的提示文本若出现乱码则降级为纯 ASCII。扩展侧写入 `.opl` 等选项文件的 ANSI 转换（`convertFileToAnsiEncoding`）保持不变。
- **兼容性**：扩展已不再内置编译器（`res/compiler` 已删除），未配置 `compilerPath` 的用户升级后需通过「工具链安装」下载或手动指定本机 SOFTUNE 目录；`toolchain.ts` 保留了对内置目录的回退检测，仅供开发调试时临时放回工具链使用。
