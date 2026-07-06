# Agent API v1.0 — HTTP 契约文档

**冻结日期**: 2026-07-02  
**基路径**: `http://{host}:{port}`  
**Content-Type**: `application/json; charset=utf-8`

## 通用响应 Envelope

```json
{
  "success": true | false,
  "message": "人类可读消息",
  "data": { ... }
}
```

## 1. GET /api/agent/list

列出 Qt 当前绑定表中的全部智能体及其缓存状态。

### 查询参数

无。

### 行为

- 只读缓存，不批量触发真实 RPC。
- 返回全部 Units_Hash_Table 中的绑定。
- 每个智能体带有完整的 binding_state、connection_state 和 status_freshness。

### 响应 200

```json
{
  "success": true,
  "message": "ok",
  "data": {
    "schema_version": "1.0",
    "generated_at_ms": 1782864000000,
    "agents": [
      {
        "unit_id": "GV1",
        "alias": "先锋车",
        "display_name": "先锋车",
        "unit_type": "ground",
        "binding_state": "bound",
        "binding_origin": "mock",
        "connection_state": "online",
        "status_freshness": "fresh",
        "mock": true,
        "run_mode": "sim",
        "role": "leader",
        "pose": {"x": 1.0, "y": 2.0, "yaw": 0.5},
        "speed": {"linear_m_s": 0.2, "angular_rad_s": 0.0},
        "battery_percent": null,
        "health": null,
        "last_seen_ms": 1782863999000,
        "observed_at_ms": 1782863999000,
        "last_error": null,
        "capabilities": ["pose", "speed", "role"]
      }
    ],
    "summary": {
      "total": 1,
      "online": 1,
      "offline": 0,
      "unknown": 0,
      "mock": 1,
      "real": 0
    }
  }
}
```

## 2. GET /api/agent/status

获取单个智能体状态。

### 查询参数

| 参数 | 必需 | 说明 |
|------|------|------|
| `agent` | 是 | unit_id 或 Qt 别名 |
| `unit_id` | 否(兼容) | 旧参数名，与 agent 等效 |
| `refresh` | 否 | `1` = 主动探测, `0` = 仅缓存 (默认) |

### 行为

- `refresh=1`: 执行一次主动状态探测（受 SAU_ENABLE_REAL_RPC 控制）。
- `refresh=0`: 仅返回缓存状态。
- 真实 RPC 被禁用时仍返回 HTTP 200，connection_state=unknown。

### 响应 200

```json
{
  "success": true,
  "message": "ok",
  "data": {
    "unit_id": "GV1",
    "alias": "先锋车",
    "display_name": "先锋车",
    "unit_type": "ground",
    "binding_state": "bound",
    "binding_origin": "mock",
    "connection_state": "online",
    "status_freshness": "fresh",
    "mock": true,
    "run_mode": "sim",
    "role": "leader",
    "pose": {"x": 1.0, "y": 2.0, "yaw": 0.5},
    "speed": {"linear_m_s": 0.2, "angular_rad_s": 0.0},
    "battery_percent": null,
    "health": null,
    "last_seen_ms": 1782863999000,
    "observed_at_ms": 1782863999000,
    "last_error": null,
    "capabilities": ["pose", "speed", "role"]
  }
}
```

### 错误响应

| HTTP | error code | 说明 |
|------|-----------|------|
| 400 | `missing_agent` | 缺少 agent/unit_id 参数 |
| 404 | `agent_not_found` | 智能体或别名不存在 |

## 3. POST /api/agent/alias/set

设置或重命名别名。

### 请求体

```json
{
  "agent": "GV1",
  "alias": "先锋车",
  "reserved_names": ["robot_1", "robot_2", "robot_3"]
}
```

| 字段 | 必需 | 说明 |
|------|------|------|
| `agent` | 是 | unit_id 或当前别名 |
| `alias` | 是 | 新别名（空字符串视为清除） |
| `reserved_names` | 否 | 额外保留名称列表 |

### 响应 200

```json
{
  "success": true,
  "message": "alias set",
  "data": {
    "unit_id": "GV1",
    "alias": "先锋车",
    "updated_at_ms": 1782864000000
  }
}
```

### 错误响应

| HTTP | error code | 说明 |
|------|-----------|------|
| 400 | `invalid_alias_format` | 别名格式无效 |
| 400 | `invalid_json` | JSON 解析失败 |
| 404 | `agent_not_found` | 智能体不存在 |
| 409 | `alias_conflict` | 别名与 UID/其他别名/保留名称冲突 |

## 4. POST /api/agent/alias/clear

清除别名。

### 请求体

```json
{
  "agent": "GV1"
}
```

### 响应 200

```json
{
  "success": true,
  "message": "alias cleared",
  "data": {
    "unit_id": "GV1",
    "updated_at_ms": 1782864000000
  }
}
```

### 错误响应

| HTTP | error code | 说明 |
|------|-----------|------|
| 404 | `agent_not_found` | 智能体不存在 |

## 5. 字段语义参考

### binding_state

- `bound` — 当前在绑定表中

### binding_origin

- `runtime` — 本次运行期间通过 bind/rebind 加入
- `restored` — 启动时从 BackupFile.txt 恢复
- `mock` — 通过 -mockRobots 注册

### connection_state

- `online` — Mock 已注册或最近主动 RPC 成功
- `offline` — 明确连接/传输失败
- `unknown` — 尚未探测、仅从备份恢复或真实 RPC 被禁用

### status_freshness

- `fresh` — 状态年龄 ≤ 3000 ms
- `stale` — 有历史状态但超过阈值
- `unavailable` — 尚无成功状态

### 别名规则

- 去除首尾空白
- Unicode NFKC 兼容归一化
- Unicode case folding 用于唯一性比较
- 允许中文、英文、数字、内部空格、连字符、下划线
- 禁止空名称、控制字符、换行符、英文逗号
- 归一化后不超过 32 个字符
- 不得与任何 unit_id、其他别名或 reserved_names 冲突
