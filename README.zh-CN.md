# Open Water Guard

Open Water Guard 是一个**完全离线**的 DIY 用水监测控制板项目，用于漏水探头、水流传感器、蜂鸣器、按钮、指示灯和可选显示屏。它**不联网、不接云、不上传家庭用水数据**。

## 第一版做什么

第一版只做**检测与本机报警层**，重点包括：

- 漏水探头检测
- 水流传感器检测
- 持续小流量提醒
- 蜂鸣器报警
- 按键消音 / 确认
- 指示灯状态输出
- 可选显示屏输出

## 第一版不做什么

第一版**不做**：

- 自动关阀承诺
- 联网功能
- 云端功能
- 手机应用
- 成品家用设备包装

## 项目边界

Open Water Guard 是：

- 完全离线项目
- DIY 控制板
- 检测与本机报警方案
- 面向个人实验和创客社区的板级知识整理

它不是：

- 成品防漏水设备
- 认证水管安全设备
- 保险级防护系统
- 水管安装服务项目

## 不卖什么

当前项目**不卖**：

- 成品
- 水管件
- 球阀
- 安装服务

视频或文档只作为**个人 DIY 实验过程参考**，不是施工交付说明书。

## 离线原则

这个项目不是“本地优先”，而是根本**不联网**：

- 不接互联网
- 不接云
- 不上传数据
- 不依赖服务器
- 不依赖手机应用

所有检测、判断和报警都在控制板本机完成。

## 第一版硬件方向

第一版开源检测层优先围绕这些东西展开：

- ESP32 / ESP32-S3 控制板
- 漏水探头
- 水流传感器
- 蜂鸣器
- 按键
- 指示灯
- 可选显示屏
- 电源模块
- 桌面水路测试接线

阀门执行器不是第一版必选项。

## 安全口径

这个项目是 DIY 控制板与检测实验，不承诺：

- 认证防水损
- 保险级防护
- 避免所有水损

建议先在安全桌面水路环境里测试，再决定你要不要把这块控制板接进自己的系统。

## 文档入口

- 开源边界与商用政策（英文）：[docs/open-source-boundary.md](docs/open-source-boundary.md)
- 检测架构：[docs/detection-architecture.md](docs/detection-architecture.md)
- 持续小流量检测：[docs/low-flow-detection.md](docs/low-flow-detection.md)
- 桌面测试方案：[docs/test-bench.md](docs/test-bench.md)
- 安全说明：[docs/safety-notes.md](docs/safety-notes.md)
- 第一版物料清单：[BOM.md](BOM.md)
- 中文知识库：[DOC/00-知识库索引.md](DOC/00-知识库索引.md)

## 许可说明

Open Water Guard 使用分层许可模式：

- 开源检测与本机报警层代码：Apache License 2.0。
- 文档、图示、照片、教程和桌面测试材料：CC BY-NC 4.0。
- 可选阀门执行器实验材料、商业固件、量产 PCB 文件、白牌资料和商业支持工具，不包含在开源代码许可内，后续按单独条款处理。

请查看：

- [LICENSE](LICENSE)
- [LICENSE-DOCS.md](LICENSE-DOCS.md)
- [LICENSE-BOUNDARY.md](LICENSE-BOUNDARY.md)
- [docs/open-source-boundary.md](docs/open-source-boundary.md)

## 支持项目开发

这是一个独立 DIY 开源硬件项目。

如果你觉得这个项目有用，可以支持后续传感器测试、板子改版、测试夹具、桌面水路实验和文档整理：

- Ko-fi: https://ko-fi.com/solitarydev50

这不是产品预购。赞助只用于支持元器件、测试和开源文档工作。
