# stm32-desk-pet-extension-playbook

[English Version](./README.md)

这个仓库主要是我整理 STM32 桌宠项目扩展思路和阅读笔记的地方。

这个项目让我感兴趣的，不只是最后那个“会动的成品”，而是背后的交互结构：蓝牙和语音命令怎么映射到动作、OLED 表情怎么跟动作状态同步、控制逻辑又怎样重构才更适合继续扩展。

## 上游项目

- 项目： [Sngels_wyh / STM32 Smart Desktop Pet](https://oshwhub.com/sngelswyh/stm32-smart-desktop-pet)
- 平台：`OSHWHub`
- 公开文章： [CSDN project article](https://blog.csdn.net/2402_83438920/article/details/145213286)
- 观察到的许可证：`GPL 3.0`

我分析过的本地源码在头注释里能对应到上面的 OSHWHub 项目。这个仓库主要保留我整理出的模块理解、结构拆分和一些 clean-room 小示例，真正的衍生固件工作会单独处理。

## 这里主要放什么

- 原项目的模块拆解笔记
- 动作状态机和命令路由方面的观察
- OLED 表情、舵机动作和输入处理的扩展思路
- 面向 dispatch table 重构的小型 clean-room 示例

## 仓库结构

- [`docs/upstream-reference.md`](./docs/upstream-reference.md) 来源关系和协议背景
- [`docs/module-breakdown.md`](./docs/module-breakdown.md) 模块级阅读整理
- [`docs/extension-roadmap.md`](./docs/extension-roadmap.md) 我认为适合继续推进的方向
- [`examples/command_map.example.json`](./examples/command_map.example.json) 动作命令映射
- [`examples/action_dispatch_example.c`](./examples/action_dispatch_example.c) dispatch table 重构草图
- [`NOTICE.md`](./NOTICE.md) 来源说明和发布边界

## 系统视图

```mermaid
flowchart LR
    A["蓝牙模块"] --> E["命令解析层"]
    B["语音模块"] --> E
    E --> F["动作状态机"]
    F --> G["舵机动作层"]
    F --> H["OLED 表情层"]
    F --> I["灯效层"]
    J["STM32F103 控制器"] --> E
    J --> G
    J --> H
    J --> I
```

## 我觉得这个项目有价值的地方

- 它已经有比较完整的“输入 -> 状态 -> 行为”结构
- 动作和表情耦合得很紧，扩展起来很有意思
- 很适合做命令归一化和分发表重构
- 它是一个很实在的嵌入式交互项目，不只是玩具级样例

## 后续方向

- 把命令解析和动作执行进一步拆开
- 把重复分支整理成 dispatch table
- 增加更多表情预设和情绪到动作的映射
- 给离线语音关键词或者 AI 辅助交互留出更清晰的接口

## 说明

如果后面要公开发布真正的衍生固件，还是应该先回到上游项目和它的协议要求：

- [Sngels_wyh / STM32 Smart Desktop Pet](https://oshwhub.com/sngelswyh/stm32-smart-desktop-pet)
