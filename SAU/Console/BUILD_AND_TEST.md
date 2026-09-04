# 🚀 Console 数据记录功能 - 编译和测试指南

## ✅ 集成完成状态

所有代码已成功集成到 Console 项目中：

### 修改的文件
1. ✅ `mainwindow.h` - 添加了槽函数声明和成员变量（第 185-236 行）
2. ✅ `mainwindow.cpp` - 添加了初始化代码和功能实现（第 149-163 行，1788+ 行）
3. ✅ `mainwindow.ui` - 添加了数据记录面板（第 2134+ 行）

### 备份文件
- `mainwindow.h.backup`
- `mainwindow.cpp.backup`
- `mainwindow.ui.backup`

---

## 📝 编译步骤

### 方法 1: 使用 Qt Creator（推荐）

1. **打开项目**
   ```
   双击打开: SAU\Console\console.pro
   ```

2. **清理旧的编译文件**
   - 点击 `构建` → `清理项目 "console"`

3. **重新生成 UI 文件**
   - Qt Creator 会自动检测 `mainwindow.ui` 的修改
   - 会重新生成 `ui_mainwindow.h` 文件

4. **编译项目**
   - 点击 `构建` → `构建项目 "console"`
   - 或按快捷键 `Ctrl + B`

5. **运行**
   - 点击绿色播放按钮
   - 或按快捷键 `Ctrl + R`

---

### 方法 2: 使用命令行

```powershell
# 1. 进入 Console 目录
cd E:\MCP-IDL\SAU\Console

# 2. 清理旧文件
del ui_mainwindow.h
rmdir /S /Q debug release build

# 3. 重新生成 UI 文件（需要 Qt 环境）
uic mainwindow.ui -o ui_mainwindow.h

# 4. 编译（使用你现有的编译脚本）
# 例如：
qmake console.pro
nmake         # 或 mingw32-make，取决于你的编译器

# 5. 运行
.\debug\console.exe    # 或 .\release\console.exe
```

---

## 🧪 测试步骤

### 1. 启动 Console

```powershell
cd E:\MCP-IDL\SAU\Console
.\debug\console.exe
```

### 2. 查找数据记录面板

在 Console 主界面右上角，应该看到：

```
┌─────────────────────────────────┐
│  📊 实验数据记录                 │
├─────────────────────────────────┤
│  实验名称：[输入框]              │
│  天气条件：[输入框]              │
│  🔴 开始记录   ⏹️ 停止记录      │
│  状态: 就绪                      │
└─────────────────────────────────┘
```

### 3. 测试记录功能

#### 测试 1: 基本记录流程

1. **填写信息**
   - 实验名称：`test_scenario1`
   - 天气条件：`晴天,25°C,风速2m/s`

2. **开始记录**
   - 点击 `🔴 开始记录` 按钮
   - 应该看到：
     - ✅ 状态变为 "正在记录..."
     - ✅ 开始按钮变灰（禁用）
     - ✅ 停止按钮变绿（可用）
     - ✅ 输入框变灰（禁用）

3. **等待 10 秒**
   - 让系统记录一些数据

4. **停止记录**
   - 点击 `⏹️ 停止记录` 按钮
   - 应该看到弹窗：
     ```
     ✅ 数据记录完成
     实验名称: test_scenario1
     输出目录: experiments/test_scenario1_YYYYMMDD_HHMMSS/
     GPS 数据: X 条
     通信日志: X 条
     编队状态: X 条
     ```

5. **查看输出文件**
   ```powershell
   cd experiments\test_scenario1_*
   dir
   ```
   
   应该看到：
   ```
   metadata.json        # 实验元数据
   gps_data.csv         # GPS 数据
   comm_log.csv         # 通信日志
   formation_status.csv # 编队状态
   *.md5                # MD5 校验文件
   ```

#### 测试 2: 错误处理

1. **测试空名称**
   - 实验名称留空
   - 点击开始记录
   - 应该看到错误提示："请输入实验名称！"

2. **测试空天气**
   - 实验名称填写，天气留空
   - 点击开始记录
   - 应该看到错误提示："请输入天气条件！"

3. **测试重复开始**
   - 正在记录时，开始按钮应该是灰色的
   - 无法再次点击

#### 测试 3: 数据完整性

1. **检查 GPS 数据**
   ```powershell
   type gps_data.csv
   ```
   应该看到：
   ```csv
   timestamp,unit_id,latitude,longitude,altitude,heading
   1725350400,unit1,39.9042,116.4074,50.2,90.5
   ...
   ```

2. **检查通信日志**
   ```powershell
   type comm_log.csv
   ```
   应该看到：
   ```csv
   timestamp,source,target,message_type,payload_size
   1725350400,console,unit1,COMMAND,128
   ...
   ```

3. **检查 MD5 校验**
   ```powershell
   # 计算文件 MD5
   certutil -hashfile gps_data.csv MD5
   
   # 对比 gps_data.csv.md5 文件内容
   type gps_data.csv.md5
   ```

---

## ⚠️ 可能的问题和解决方案

### 问题 1: 找不到数据记录面板

**原因**: `ui_mainwindow.h` 没有重新生成

**解决**:
```powershell
cd E:\MCP-IDL\SAU\Console
del ui_mainwindow.h
uic mainwindow.ui -o ui_mainwindow.h
```

### 问题 2: 编译错误 "undefined reference to btnStartRecording"

**原因**: moc 文件没有重新生成

**解决**:
```powershell
# 在 Qt Creator 中
构建 → 清理项目
构建 → 重新构建项目
```

### 问题 3: 按钮点击无反应

**原因**: 信号槽连接可能有问题

**解决**:
1. 检查 `mainwindow.cpp` 第 149-163 行的初始化代码
2. 确保槽函数命名正确：
   - `on_btnStartRecording_clicked()`
   - `on_btnStopRecording_clicked()`

### 问题 4: 文件无法创建

**原因**: 权限问题或路径不存在

**解决**:
```powershell
# 手动创建 experiments 目录
cd E:\MCP-IDL\SAU\Console
mkdir experiments
```

### 问题 5: 中文显示乱码

**原因**: 编码问题

**解决**:
- 确保源文件使用 UTF-8 编码
- 或在代码中使用 `QString::fromUtf8()`

---

## 📊 验证清单

完成以下检查，确保功能正常：

- [ ] Console 成功启动
- [ ] 数据记录面板显示在右上角
- [ ] 输入框可以正常输入中文和英文
- [ ] 点击"开始记录"按钮后状态正确更新
- [ ] 记录过程中生成文件
- [ ] 点击"停止记录"按钮后显示摘要
- [ ] 生成的文件包含正确数据
- [ ] MD5 校验文件正确
- [ ] 错误提示功能正常
- [ ] 可以进行多次连续记录

---

## 🎯 下一步

测试通过后：

1. **集成到实验流程**
   - 将 Console 部署到实验用笔记本
   - 准备实验场地

2. **预实验验证**（2026-09-05）
   - 使用真实设备测试
   - 验证数据完整性
   - 调整参数（如记录频率）

3. **正式实验**（2026-09-06 起）
   - 每次实验使用新的实验名称
   - 及时备份数据

---

## 📞 需要帮助？

如果遇到问题，可以：

1. **检查日志**
   ```powershell
   type console_log
   ```

2. **恢复备份**
   ```powershell
   copy mainwindow.h.backup mainwindow.h
   copy mainwindow.cpp.backup mainwindow.cpp
   copy mainwindow.ui.backup mainwindow.ui
   ```

3. **联系开发者**
   - 提供详细的错误信息
   - 截图显示问题
   - 提供 console_log 文件

---

**祝编译顺利！🚀**
