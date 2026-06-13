# F2MC-8FX-Workbench

## 📖 插件简介

本插件旨在替代 F2MC-8L/8FX Family SOFTUNE Workbench V30L34 软件，在 VSC 上实现富士通 F2MC-8FX 系列单片机完整的开发流程。

*注：核心代码均由 GPT-5.5 生成*

## 🛠️ 功能特性

- 支持导入 SOFTUNE 工作区
- 支持类似 SOFTUNE 工作区目录显示
- 可一键编译，生成 mhx 文件

## 🏃‍♀️ 快速上手

1. 打开扩展活动栏，点击“导入工程”
2. 选择工程文件 (.wsp)
3. 插件会自动解析内容，并创建对应的 VS Code 工作区
4. 选择“打开工作区”后，在活动栏中可以查看工程结构
5. 点击编译按钮，生成 mhx 文件

## 🗒️ 开发进度

- [x] 实现SOFTUNE工作区和项目文件解析
- [x] 利用SOFTUNE工具链，实现项目编译功能
- [x] 支持增减项目文件，创建虚拟文件夹等
- [ ] 支持项目自定义设置
- [ ] 支持编译器参数修改
- [ ] 支持烧录器，实现烧录和在线仿真功能

## 🙋 协助开发

欢迎各位对本插件进行功能完善、拓展。

以下是开发环境搭建流程：

> 💡 **注意**
>
> 请确保你已经安装了以下软件：
>
> - Python (>= 3.10)
> - Microsoft Visual Studio & Desktop development with C++ (>= 2017)

1. 安装 *NodeJS*（推荐使用 nvm 工具，版本选择 v20.20.2）
2. 启用 *yarn* 包管理工具
   ```shell
   corepack enable yarn
   ```
3. 安装 *vsce*
   ```shell
   yarn global add @vscode/vsce
   ```
4. Clone 仓库，在根目录下执行

   ```shell
   yarn install
   ```
5. 使用 VS Code 打开工程，按 **F5** 进行调试

6. 在根目录下执行

   ```shell
   vsce package --yarn
   ```
   完成打包