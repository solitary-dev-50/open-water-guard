# AGENTS.md

## 项目定位

本仓库是一个基于 ESP32/ESP32-S3 的家庭漏水监测与自动关阀开源项目，目标是在本地完成漏水检测、异常用水判断、报警、人工确认和安全关阀。

正式项目名为 `Open Water Guard (OWG)`，口号是 `My Water, My Guard.`，核心理念是 `Driven by Iris.`。

项目第一原则：

- 本地优先，不依赖云端作为核心能力。
- 默认保守，第一版默认只报警，不自动关阀。
- 人工优先，用户必须能随时手动开阀、关阀、消音、取消倒计时和进入维护模式。
- 多证据判断，不能因为单个传感器触发就自动关阀。
- 失败可见，传感器离线、阀门失败、电源异常、网络异常都必须显示和记录。

## 文档结构

整理后的知识库放在 `DOC/` 目录：

- `DOC/00-知识库索引.md`：知识库索引。
- `DOC/01-项目定位.md`：项目定位、目标用户和边界。
- `DOC/02-安全边界.md`：安全声明、默认策略和责任边界。
- `DOC/03-系统架构.md`：系统组成、模块关系和固件模块化架构。
- `DOC/04-检测策略.md`：漏水、持续水流、小流量异常等检测策略。
- `DOC/05-阀门控制.md`：阀门状态、关阀、开阀、反馈和维护策略。
- `DOC/06-网页控制台与日志.md`：网页控制台、事件日志和配置项。
- `DOC/07-第一版硬件.md`：第一版硬件、BOM 和扩展件。
- `DOC/08-开发路线.md`：分阶段开发路线。
- `DOC/09-开源发布.md`：开源发布、演示视频和社区策略。
- `DOC/10-商业笔记.md`：商业化可能性和边界。
- `DOC/11-PCB设计笔记.md`：PCB、接口、电源、保护、测试点和可制造性。
- `DOC/archive/`：归档草稿，只作为想法来源参考，不作为正式维护入口。

## 编辑规则

- 不把工程方案、营销话术、商业想法混在同一篇文档里。
- 不在正式工程文档中使用夸张承诺，例如“永远防止漏水损失”。
- 不使用情绪化、攻击性或过度口语化表达作为正式对外内容。
- 新增安全相关功能时，必须写清楚触发条件、取消方式、失败状态和日志事件。
- 自动关阀相关内容必须包含倒计时、用户取消、维护模式旁路和手动开阀确认。
- “持续小流量异常检测”是独立能力，不要和地面漏水探头混成一个规则。
- OWG 永远按离线设备设计；不要引入云端控制、远程关阀授权或额外的物理钥匙概念。
- `Haptic Water-Pulse` 是 v2 预研能力，不进入第一版默认功能或正式安全承诺。
- 阀门控制必须强调闭环验证：关阀不是结束，确认下游流量归零才是闭环。
- 第一版硬件必须考虑多漏水点扩展，优先预留 3-4 路探头接口或 Iris Node/ESP-NOW 扩展路径。
- 备用电池/UPS 是安全相关部件；硬件和 BOM 文档必须写清断电、低电量和至少一次关阀动作的供电策略。
- PCB 文档必须覆盖接口防呆、输入保护、阀门驱动保护、电源路径、测试点、丝印和可制造性。

## 固件模块化架构约束

第一版固件从一开始就按模块化和单文件单一职责设计。禁止把传感器读取、规则判断、阀门动作、网页接口和日志都塞进 `main.cpp`。

推荐目录结构：

```text
firmware/
  src/
    main.cpp
    app/
      AppController.h/.cpp
    sensors/
      LeakSensor.h/.cpp
      LeakSensorManager.h/.cpp
      FlowSensor.h/.cpp
    valve/
      ValveController.h/.cpp
    alarm/
      Buzzer.h/.cpp
      StatusLed.h/.cpp
    rules/
      RuleEngine.h/.cpp
      WaterRiskState.h
    config/
      ConfigManager.h/.cpp
      ConfigTypes.h
    logs/
      EventLog.h/.cpp
      EventTypes.h
    power/
      PowerManager.h/.cpp
    web/
      WebConsole.h/.cpp
    time/
      TimeUtils.h/.cpp
```

模块边界：

- `main.cpp` 只负责创建对象、注入依赖、调用 `setup()` / `loop()` 调度入口。
- `AppController` 是系统调度层，串联传感器、规则、阀门、报警、日志和网页。
- `LeakSensor` 只负责单个漏水探头输入读取和基础状态。
- `LeakSensorManager` 只负责多路漏水探头管理、防抖、在线状态、启用/禁用。
- `FlowSensor` 只负责水流脉冲采集、流量计算、持续水流和小流量基础数据。
- `RuleEngine` 只根据传感器状态、配置和系统状态生成风险判断，不直接驱动阀门、蜂鸣器或状态灯。
- `ValveController` 只负责开阀、关阀、动作超时、失败状态和关阀后流量闭环验证。
- `Buzzer` 和 `StatusLed` 只负责输出，不参与风险判断。
- `ConfigManager` 负责配置读取、保存、默认值和集中校验。
- `EventLog` 只记录事实，不反向触发动作。
- `PowerManager` 负责主电源、备用电源、电池电量和断电状态。
- `WebConsole` 只展示状态和接收用户操作，不私自做安全决策。
- `TimeUtils` 负责防抖、超时、倒计时、持续时间、夜间时段和白名单时段的公共时间工具。

单文件单一职责规则：

- 一个 `.h/.cpp` 文件只维护一个清晰模块或一组紧密相关的数据类型。
- 不创建万能工具文件，不把无关函数塞进 `utils.cpp`。
- 不让 `WebConsole` 直接改阀门 GPIO；用户操作必须经过 `AppController` 或明确的应用层接口。
- 不让 `RuleEngine` 直接调用蜂鸣器或阀门；它只输出判断结果。
- 不让 `ValveController` 读取配置 JSON；配置由上层解析后传入。
- 硬件驱动、规则判断、状态展示和持久化必须分层。

## 第一版基线

第一版优先实现：

1. ESP32-S3 主控。
2. 3-4 路漏水探头接口。
3. 1 路水流传感器。
4. 电动球阀手动控制。
5. 蜂鸣器和状态灯。
6. 本地网页控制台。
7. 事件日志。
8. 只报警模式、人工确认关阀模式、维护模式。
9. 主电源和备用电源路径。

第一版不默认开启：

- 自动关阀。
- 云端通知。
- 复杂波形算法。
- 微动作水压提醒。
- 自动重新开阀。

## 代码质量与现代 C++ 约束规则

你是本项目的本地代码助手。以后在本项目中写代码、改代码、重构代码时，必须遵守以下规则。

### 总原则

OWG 不是随手拼出来的 Arduino 小玩具，而是一个需要长期维护、可被别人阅读、可被社区审查的开源硬件项目。

写代码时优先考虑：

1. 可读性。
2. 生命周期清晰。
3. 小范围修改。
4. 可审查。
5. 可回滚。
6. 不引入无意义复杂度。
7. 不为了“看起来安全”堆满防御性空指针判断。

不要一次性大规模重构。每次修改必须能解释：为什么改、改了什么、不改功能在哪里、风险在哪里。

### 1. 必须存在的对象优先用引用

如果一个对象在系统启动后必须存在，例如：

- `Buzzer`
- `StatusLed`
- `ValveController`
- `FlowSensor`
- `LeakSensorManager`
- `ConfigManager`
- `EventLog`
- `PowerManager`
- `WebConsole`
- `RuleEngine`
- `MaintenanceModeManager`

并且它由上层以引用形式传入，例如：

```cpp
begin(Buzzer& buzzer, StatusLed& led, ValveController& valve)
```

那么内部也应优先保存为引用，而不是再降级成可空指针。

优先：

```cpp
Buzzer& _buzzer;
StatusLed& _led;
ValveController& _valve;
```

避免：

```cpp
Buzzer* _buzzer = nullptr;
StatusLed* _led = nullptr;
ValveController* _valve = nullptr;
```

如果对象本来就必须存在，就不要把它设计成“可能不存在”。这会制造无意义的 `nullptr` 判断，也会让对象生命周期变得不清楚。

### 2. 真正可选的对象才允许使用指针或可选包装

只有在对象确实可能不存在时，才允许使用指针、可选对象或类似设计。

例如：

- 可选水压传感器。
- 可选显示屏。
- 可选 ESP-NOW / Iris Node 无线扩展。
- 可选电池电量检测模块。
- 可选家庭自动化接口。
- 初始化失败后仍允许系统降级运行的模块。
- 测试环境中可能缺失的对象。

这种情况下可以保留：

```cpp
if (_pressureSensor != nullptr) {
    _pressureSensor->update();
}
```

但必须说明为什么它是可选的、没有它时系统如何降级、是否需要在网页/状态灯/日志中提示用户。

### 3. 不要用 `nullptr` 判断掩盖生命周期问题

不要为了“看起来安全”，到处写：

```cpp
if (_valve != nullptr) {
    _valve->update();
}
```

如果 `_valve` 按设计应该永远存在，这类判断是噪音。必须存在就用引用；可选存在才用指针。

### 4. 容器遍历优先使用范围遍历

如果不需要下标，不要写：

```cpp
for (size_t i = 0; i < sensors.size(); ++i) {
    const Sensor sensor = sensors[i];
}
```

优先写：

```cpp
for (const auto& sensor : sensors) {
}
```

不修改元素时用 `const auto&`，需要修改元素时用 `auto&`，确实需要下标时才保留下标循环。

### 5. 不要无意义复制对象

如果只是读取对象，不要写：

```cpp
const LeakSensorConfig sensor = config.leakSensors[index];
```

优先写：

```cpp
const auto& sensor = config.leakSensors[index];
```

### 6. 时间处理要集中

漏水防抖、持续水流、小流量持续时间、倒计时关阀、维护模式超时、阀门动作超时、夜间时段、白名单时段等逻辑，必须尽量集中处理。

不要在多个地方重复写 `millis()` 差值判断、字符串时间解析、小时分钟拆分、倒计时拼接、`time_t` / `struct tm` 转换。

如果已有函数或模块，例如：

```cpp
parseTimeString()
isValidTimeString()
hasElapsed()
remainingDuration()
isWithinQuietHours()
```

则应复用，不要重复造一遍。能安全使用 `std::chrono` 的地方，优先考虑 `std::chrono`，但不要改变原有水流判断、报警或关阀行为。

### 7. 配置校验要集中、清楚、可解释

配置校验逻辑应当集中在配置管理模块中，例如自动关阀开关、倒计时、探头数量和名称、水流阈值、小流量阈值、夜间时段、白名单时段、维护模式时长、阀门动作超时、传感器 ID、规则 ID、节点 ID 重复检查。

不要把同一套规则散落在多个文件里。

### 8. 重复编号检查不要低效绕圈

如果要检查重复编号，不要每次都全表计数。可以使用已见集合或已见列表：

```cpp
std::vector<String> seenIds;

for (const auto& sensor : sensors) {
    if (std::find(seenIds.begin(), seenIds.end(), sensor.id) != seenIds.end()) {
        return false;
    }

    seenIds.push_back(sensor.id);
}
```

如果后续规模变大，再考虑更合适的数据结构。

### 9. 修改必须小步提交

不要一次性修改太多文件。优先拆成小提交，例如文档入口优化、网页状态展示优化、配置校验集中化、事件日志字段补充、`ValveController` 闭环验证优化、`LeakSensorManager` 输入防抖优化、`FlowSensor` 持续小流量判断优化、时间处理集中化。

不要把文档修改、代码重构、功能新增、格式化、硬件引脚变更、PCB/原理图变更混在同一个提交里。

### 10. 不要批量格式化整个项目

除非用户明确要求，不要对整个项目执行批量格式化。如果只改一小段，就只格式化这一小段。

### 11. 不要乱引入大型第三方库

除非明确必要，不要引入大型库。优先使用标准库、Arduino/ESP32 平台已有能力、项目已有工具函数、小而清楚的本地实现。

### 12. 不要改硬件边界

除非用户明确要求，禁止修改引脚定义、PCB 文件、原理图、阀门驱动方式、电源相关参数、传感器接线逻辑、外设初始化顺序、Pi 4B 外壳适配板框和安装孔策略。

如果某个代码优化可能影响硬件行为，必须先说明，不要直接改。

### 13. 不要改变已有数据格式

除非用户明确要求，禁止随意改变配置 JSON 字段、事件日志 JSON 字段、网页接口字段、本地存储路径、LittleFS 文件结构、API 路由、传感器 ID、规则 ID、节点 ID 的格式。

如果确实需要改，必须说明兼容策略。

### 14. 写代码和文档时要考虑英文读者

本项目面向海外开源硬件社区展示。README 默认英文优先；中文文档可以保留，但不能挡住英文入口；面向社区的说明尽量英文；关键安全说明最好有英文补充；接口命名、事件类型、配置字段优先使用清楚的英文。

### 15. 不要夸大项目能力

OWG 是家庭用水异常监测和本地关阀辅助装置，不是认证水管设备、保险公司认证防损设备或专业施工替代品。

不要写：

- `guaranteed water damage prevention`
- `insurance-certified protection`
- `certified plumbing safety system`
- `professional fire protection system`
- `100% leak-proof`

可以写：

- `offline-first water safety prototype`
- `local leak monitor`
- `main valve shutoff prototype`
- `local event logs`
- `manual confirmation workflow`
- `closed-loop shutoff verification`

### 16. 使用智能助手时必须可审查

可以使用智能助手辅助生成初稿、小范围代码清理、改文档、找重复逻辑、改现代 C++ 写法。

禁止让智能助手一次性大规模重构、不理解就提交、不验证就推送、把多个不相关改动混在一起、擅自改硬件文件、修改许可证。

每次修改后必须输出修改文件列表、每个文件改了什么、是否影响功能、验证结果和风险点。

### 17. 每次任务的标准输出格式

每次完成较大任务后，按这个格式汇报：

```text
结论
修改文件列表
每个文件改了什么
为什么这样改
是否影响产品功能
验证结果
风险点
是否还有未提交改动
建议提交信息
```

简单文档修改可以简化，但必须说清改了哪些文件和是否影响功能。

### 18. 当前重点遗留问题

当前已经明确的后续优化方向：

- `ValveController` 的闭环验证逻辑需要单独设计和测试。
- 如果 `begin()` 接收 `Buzzer&` / `StatusLed&` / `ValveController&` / `EventLog&`，内部应考虑持续使用引用，而不是保存成可空指针。
- 必须存在的硬件模块使用引用。
- 真正可选的模块才允许指针。
- 不要把这项改动和其他不相关改动混在一起。

建议提交信息：

```text
refactor: keep required hardware dependencies as references
```

最终原则：

> 必须存在的东西，不要写成可能不存在；真正可选的东西，才设计成可选。

这条原则优先级很高。
