# IEEE T-RO 论文 Phase 1 基础实验

**状态**: ✅ Week 1 完成 (2026-09-03)  
**进度**: 25% (Week 1/4)

---

## 🚀 快速开始

### 查看文件索引
```bash
cat docs/FILE_INDEX.md
```

### Console 集成（推荐，简化操作）
```bash
cat SAU/Console/patches/INTEGRATION_STEPS.md
```

### 使用 Python 脚本（备用方案）
```bash
# 模拟测试
python scripts/data_collector.py --experiment test --duration 60 --simulate

# 分析数据
python scripts/analyze_experiment.py --experiment ./experiment_data/test
```

---

## 📚 重要文档

| 文档 | 描述 |
|------|------|
| [`docs/FILE_INDEX.md`](docs/FILE_INDEX.md) | 📖 所有文档索引 |
| [`docs/CONSOLE_INTEGRATION_SUMMARY.md`](docs/CONSOLE_INTEGRATION_SUMMARY.md) | 🎨 Console 简化方案 |
| [`SAU/Console/patches/INTEGRATION_STEPS.md`](SAU/Console/patches/INTEGRATION_STEPS.md) | 🔧 集成步骤 |
| [`docs/QUICK_REFERENCE.md`](docs/QUICK_REFERENCE.md) | ⚡ 现场快速参考 |
| [`docs/experiment_design_phase1.md`](docs/experiment_design_phase1.md) | 📊 实验设计 |

---

## ✅ Week 1 完成情况

- ✅ 5 个实验设计文档
- ✅ 3 个数据采集脚本
- ✅ 1 个数据分析工具
- ✅ 2 个问题已解决
- ✅ Console 集成方案（新增）

**完成度**: 120% (超额完成)

---

## 🎯 下一步

### 明天 (2026-09-04)
- [ ] 集成 Console 数据记录功能
- [ ] 准备硬件设备

### 预实验日 (2026-09-05)
- [ ] 场地准备
- [ ] 预实验执行（使用新按钮）
- [ ] 数据分析

### Week 2 (2026-09-06 起)
- [ ] 场景 1 实验 × 15
- [ ] 场景 2 实验 × 5

---

## 💡 核心亮点

### Console 简化方案

**操作简化**: 6 步 → 3 步 (-50%)

**原方案**:
1. 启动 Console
2. 重定向日志
3. 运行 Python 脚本
4. 指定参数
5. 等待/中断
6. 运行分析

**新方案**:
1. 启动 Console
2. 点击"开始记录"
3. 点击"停止记录"

---

## 📊 实验规模

- **总实验次数**: 49 次
- **预期数据量**: ~25 GB
- **预期时长**: 4 周
- **预期产出**: Section VII 初稿 + 6-8 张图表

---

## 📞 联系

遇到问题查看:
- [`docs/ISSUES_RESOLVED.md`](docs/ISSUES_RESOLVED.md) - 已解决问题
- [`SAU/Console/patches/INTEGRATION_STEPS.md`](SAU/Console/patches/INTEGRATION_STEPS.md) - 常见问题

---

**最后更新**: 2026-09-03 16:45  
**版本**: v1.0
