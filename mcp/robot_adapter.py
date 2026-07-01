"""
机器人适配层（RobotAdapter）。

职责：
1) 根据 robots.json 维护 robot_id -> unit_id（主控台 UnitID）及 per-robot 异步锁。
2) 将 MCP 工具转为 HTTP 请求，对接 SAU HttpPlugin（/api/robot/*）。
3) 统一错误处理、超时、HTTP 状态码映射，返回固定 JSON 字符串（success/message/data）。

说明：主控台 JSON 使用 unit_id（GV1 等）；MCP 工具对外仍用 robot_id，在适配层解析。
"""

from __future__ import annotations

import asyncio
import itertools
import json
import math
import time
from dataclasses import dataclass
from typing import Any
from urllib.parse import quote

from config import (
    ANGULAR_VELOCITY_MAX_ABS_RAD_S,
    DEFAULT_TOOL_TIMEOUT_S,
    LINEAR_VELOCITY_MAX_ABS_M_S,
    QT_HTTP_TIMEOUT_S,
    QT_LIST_PATH,
    QT_RESET_RELATIONS_PATH,
    QT_SEND_MOVE_PATH,
    QT_SET_GROUP_MINOR_MODE_PATH,
    QT_SET_GROUP_MODE_PATH,
    QT_SET_LEADER_PATH,
    QT_STOP_ALL_PATH,
    QT_STOP_PATH,
    QT_STATUS_PATH,
    QT_TASK_PATH_PATH,
    QT_TASK_POINT_PATH,
    QT_TRAP_ADD_PATH,
    QT_TRAP_CLEAR_PATH,
    load_robot_configs,
    qt_url,
)
def make_tool_response(*, success: bool, message: str, data: Any | None = None) -> str:
    """
    生成统一的工具返回字符串（JSON 字符串）。

    @param success: 是否成功。
    @param message: 人类可读的反馈信息（错误时要说明原因）。
    @param data: 成功时返回的业务数据（可为 dict / 列表 / 原始值）。
    @returns: JSON 字符串（FastMCP 会原样返回给 MCP 客户端）。
    """

    payload: dict[str, Any] = {"success": success, "message": message, "data": data}
    return json.dumps(payload, ensure_ascii=False)

from qt_http_client import http_request
from utils.logging_setup import get_logger

# NOTE (MCP tool `message` field): keep ASCII-only for client display stability on Windows.


def _message_unit_not_bound(robot_id_raw: str) -> str:
    """
    @param robot_id_raw: 工具入参中的机器人标识原文
    @returns: 统一拒绝文案（MCP 未映射 robot_id / unit_id）
    """

    rid = robot_id_raw.strip()
    return (
        f'unit_not_bound: robot_id "{rid}" has no MCP mapping (robots.json alias or unit_id); '
        "use list_robots for the live console bind table."
    )


def _message_speed_linear_out_of_bounds(linear_velocity: float) -> str:
    """@param linear_velocity: 线速度 m/s @returns: 线速度越界说明"""

    return (
        f"speed_out_of_bounds: linear_velocity abs={abs(float(linear_velocity))} exceeds max_safe="
        f"{LINEAR_VELOCITY_MAX_ABS_M_S} m/s"
    )


def _message_speed_angular_out_of_bounds(angular_velocity: float) -> str:
    """@param angular_velocity: 角速度 rad/s @returns: 角速度越界说明"""

    return (
        f"speed_out_of_bounds: angular_velocity abs={abs(float(angular_velocity))} exceeds max_safe="
        f"{ANGULAR_VELOCITY_MAX_ABS_RAD_S} rad/s"
    )


def _normalize_group_mode(mode: str) -> str | None:
    key = mode.strip().lower()
    aliases = {
        "0": "none",
        "none": "none",
        "off": "none",
        "null": "none",
        "无": "none",
        "1": "follow",
        "follow": "follow",
        "fw": "follow",
        "跟随": "follow",
        "2": "imitate",
        "imitate": "imitate",
        "imitation": "imitate",
        "copy": "imitate",
        "模拟": "imitate",
        "模仿": "imitate",
        "3": "mate",
        "mate": "mate",
        "cooperate": "mate",
        "协同": "mate",
    }
    return aliases.get(key)


def _normalize_minor_mode(mode: str) -> str | None:
    key = mode.strip().lower()
    aliases = {
        "0": "none",
        "none": "none",
        "off": "none",
        "null": "none",
        "无": "none",
        "1": "object",
        "object": "object",
        "target": "object",
        "fw_object": "object",
        "object_track": "object",
        "目标": "object",
        "目标跟踪": "object",
        "2": "track",
        "track": "track",
        "route": "track",
        "path": "track",
        "trajectory": "track",
        "fw_track": "track",
        "轨迹": "track",
        "轨迹跟踪": "track",
        "路线": "track",
    }
    return aliases.get(key)


def _finite_float(value: Any, field_name: str) -> tuple[bool, float, str]:
    try:
        v = float(value)
    except (TypeError, ValueError):
        return False, 0.0, f"Validation failed: {field_name} must be a finite number"
    if not math.isfinite(v):
        return False, 0.0, f"Validation failed: {field_name} must be a finite number"
    return True, v, ""


def _parse_task_points(points_json: str) -> tuple[bool, list[dict[str, float]], str]:
    try:
        raw = json.loads(points_json)
    except json.JSONDecodeError:
        return False, [], "Validation failed: task path points_json must be a JSON list with 1..10 points"
    if not isinstance(raw, list) or not (1 <= len(raw) <= 10):
        return False, [], "Validation failed: task path points_json must be a JSON list with 1..10 points"

    points: list[dict[str, float]] = []
    for item in raw:
        if isinstance(item, dict):
            x_raw = item.get("x")
            y_raw = item.get("y")
        elif isinstance(item, (list, tuple)) and len(item) >= 2:
            x_raw = item[0]
            y_raw = item[1]
        else:
            return False, [], "Validation failed: each task path point must contain numeric x and y"

        ok_x, x, msg_x = _finite_float(x_raw, "point.x")
        if not ok_x:
            return False, [], msg_x
        ok_y, y, msg_y = _finite_float(y_raw, "point.y")
        if not ok_y:
            return False, [], msg_y
        points.append({"x": x, "y": y})

    return True, points, ""


def _normalize_planned_mode(mode: str) -> str:
    """
    @param mode: robots.json 中的 mode 原文
    @returns: sim 或 real（部署意图，非运行态）
    """

    m = mode.strip().lower()
    if m in ("real", "physical", "hardware"):
        return "real"
    return "sim"


def derive_unit_run_mode(*, mock: bool, rpc_enabled: bool) -> str:
    """
    与主控台 HttpApiExecutor 一致：MOCK SBH 或 HTTP 未开真实 RPC 时均为 sim。

    @param mock: 绑定 SBH 是否 MOCK:
    @param rpc_enabled: 环境变量 SAU_ENABLE_REAL_RPC 是否生效
    @returns: sim 或 real
    """

    if mock or not rpc_enabled:
        return "sim"
    return "real"


def enrich_list_robots_payload(data: dict[str, Any], manager: RobotInstanceManager) -> None:
    """
    就地增强 /api/robot/list 的 data：统一 run_mode，planned_mode 仅作对照。

    @param data: list 接口返回的 data 对象
    @param manager: 机器人配置管理器
    """

    rpc_enabled = bool(data.get("rpc_enabled", False))
    units = data.get("units")
    if not isinstance(units, list):
        return

    sim_n = 0
    real_n = 0
    for u in units:
        if not isinstance(u, dict):
            continue
        uid = str(u.get("unit_id", "")).strip()
        mock = bool(u.get("mock", False))
        run_mode = derive_unit_run_mode(mock=mock, rpc_enabled=rpc_enabled)
        u["run_mode"] = run_mode
        u.pop("mode", None)

        for rid, entry in manager._robots.items():
            if entry.unit_id == uid:
                u["robot_id"] = rid
                planned = _normalize_planned_mode(entry.mode)
                u["planned_mode"] = planned
                if planned != run_mode:
                    u["mode_mismatch"] = (
                        f"planned_mode={planned} but runtime run_mode={run_mode} "
                        f"(mock={mock}, rpc_enabled={rpc_enabled})"
                    )
                break

        if run_mode == "sim":
            sim_n += 1
        else:
            real_n += 1

    data["fleet_summary"] = {
        "total": sim_n + real_n,
        "sim_count": sim_n,
        "real_count": real_n,
        "rpc_enabled": rpc_enabled,
    }
    data["runtime_hint"] = (
        "Use unit.run_mode for current sim/real state. planned_mode is robots.json intent only."
    )


@dataclass
class _RobotEntry:
    """@param robot_id: MCP 别名 @param unit_id: 主控台单元 ID @param mode: robots.json 部署意图 sim/real"""

    robot_id: str
    unit_id: str
    mode: str


class RobotInstanceManager:
    """
    管理已知机器人 ID、unit_id 与并发锁。

    @param tool_timeout_s: MCP 工具层整体超时（秒），用于 asyncio.wait_for 包裹 HTTP 调用。
    """

    def __init__(self, *, tool_timeout_s: float = DEFAULT_TOOL_TIMEOUT_S) -> None:
        self._tool_timeout_s = tool_timeout_s
        self._robots: dict[str, _RobotEntry] = {}
        self._locks: dict[str, asyncio.Lock] = {}

        for cfg in load_robot_configs():
            self._robots[cfg.robot_id] = _RobotEntry(robot_id=cfg.robot_id, unit_id=cfg.unit_id, mode=cfg.mode)

    def has_robot(self, robot_id: str) -> bool:
        """@param robot_id: 机器人标识 @returns: 是否已配置"""
        return robot_id in self._robots

    def unit_id_for(self, robot_id: str) -> str | None:
        """@param robot_id: MCP 标识 @returns: 主控台 unit_id 或 None"""
        e = self._robots.get(robot_id)
        return e.unit_id if e else None

    def canonical_robot_id(self, robot_id_or_unit: str) -> str | None:
        """
        将 MCP 入参解析为 robots.json 中的 robot_id。

        接受：配置中的 robot_id（如 robot_1），或与某条配置相同的 unit_id（如 GV1），
        便于自然语言/LLM 直接使用主控台显示的单元名。

        @param robot_id_or_unit: 工具传入的机器人键
        @returns: 规范 robot_id，无法映射时为 None
        """

        key = robot_id_or_unit.strip()
        if not key:
            return None
        if key in self._robots:
            return key
        for rid, entry in self._robots.items():
            if entry.unit_id == key:
                return rid
        return None

    def get_lock(self, robot_id: str) -> asyncio.Lock:
        """@param robot_id: 机器人标识 @returns: 该机器人互斥锁"""
        lock = self._locks.get(robot_id)
        if lock is None:
            lock = asyncio.Lock()
            self._locks[robot_id] = lock
        return lock

    def configured_robot_ids(self) -> list[str]:
        """@returns: 当前 robots.json 生效的全部 robot_id 列表"""

        return list(self._robots.keys())

    @property
    def tool_timeout_s(self) -> float:
        return self._tool_timeout_s


class RobotAdapter:
    """
    MCP 与主控台 HTTP 之间的适配器。

    扩展新能力时：在 main.py 注册新工具，并在此类中增加方法 + 主控台路由（若尚无则扩展 HttpApiExecutor）。
    """

    def __init__(self, *, tool_timeout_s: float = DEFAULT_TOOL_TIMEOUT_S) -> None:
        self._manager = RobotInstanceManager(tool_timeout_s=tool_timeout_s)
        self._logger = get_logger("RobotAdapter")
        self._fleet_lock = asyncio.Lock()
        self._cached_rpc_enabled: bool = False

    def _inject_run_mode(self, data: Any) -> None:
        """
        为 status/send_move 等返回的 data 注入 run_mode，与 list 语义一致。

        @param data: 工具返回的 data 字段（dict）
        """

        if not isinstance(data, dict):
            return
        mock = bool(data.get("mock", False))
        run_mode = derive_unit_run_mode(mock=mock, rpc_enabled=self._cached_rpc_enabled)
        data["run_mode"] = run_mode
        data.pop("mode", None)

    def _maybe_enrich_tool_data(self, raw_resp: str) -> str:
        """
        解析工具 JSON 并在 data 上补充 run_mode（若存在 data 字典）。

        @param raw_resp: 工具返回的 JSON 字符串
        @returns: 可能已增强的 JSON 字符串
        """

        try:
            resp_obj = json.loads(raw_resp)
        except json.JSONDecodeError:
            return raw_resp
        if not resp_obj.get("success"):
            return raw_resp
        data = resp_obj.get("data")
        if isinstance(data, dict):
            if "units" in data and "rpc_enabled" in data:
                self._cached_rpc_enabled = bool(data.get("rpc_enabled", False))
                enrich_list_robots_payload(data, self._manager)
            elif "items" in data:
                items = data.get("items")
                if isinstance(items, list):
                    for item in items:
                        if isinstance(item, dict) and isinstance(item.get("data"), dict):
                            self._inject_run_mode(item["data"])
            else:
                self._inject_run_mode(data)
        return json.dumps(resp_obj, ensure_ascii=False)

    def _send_move_url(self) -> str:
        """@returns: 完整 sendmove URL"""
        return qt_url(QT_SEND_MOVE_PATH)

    async def _post_qt(
        self,
        *,
        path: str,
        json_body: dict[str, Any],
        robot_id_for_lock: str | None,
        op_name: str,
    ) -> str:
        return await self._run_http(
            method="POST",
            url=qt_url(path),
            json_body=json_body,
            robot_id_for_lock=robot_id_for_lock,
            op_name=op_name,
        )

    async def _run_http(
        self,
        *,
        method: str,
        url: str,
        json_body: dict[str, Any] | None,
        robot_id_for_lock: str | None,
        op_name: str,
    ) -> str:
        """
        执行 HTTP 并在超时/错误时返回统一 JSON。

        @param method: GET 或 POST
        @param url: 完整 URL
        @param json_body: POST 体
        @param robot_id_for_lock: 若设置则仅对该车加锁；若为 None 则使用 fleet 锁（如 list/stop_all）
        @param op_name: 日志用操作名
        @returns: JSON 字符串
        """

        async def _call() -> tuple[int, dict[str, Any] | None, str]:
            return await asyncio.wait_for(
                asyncio.to_thread(http_request, method=method, url=url, json_body=json_body, timeout=QT_HTTP_TIMEOUT_S),
                timeout=self._manager.tool_timeout_s,
            )

        try:
            if robot_id_for_lock:
                lock = self._manager.get_lock(robot_id_for_lock)
                async with lock:
                    status, body, err = await _call()
            else:
                async with self._fleet_lock:
                    status, body, err = await _call()
        except asyncio.TimeoutError:
            self._logger.error("%s adapter timeout url=%s", op_name, url)
            return make_tool_response(
                success=False,
                message=f"{op_name} timed out after {self._manager.tool_timeout_s} s (adapter)",
            )

        return self._map_http_to_tool_response(status, body, err, op_name)

    def _map_http_to_tool_response(
        self,
        status: int,
        body: dict[str, Any] | None,
        err: str,
        op_name: str,
    ) -> str:
        """@brief 将 HTTP 结果映射为 MCP 工具 JSON 字符串"""

        if status < 0:
            self._logger.error("%s HTTP transport error: %s", op_name, err)
            return make_tool_response(success=False, message=err or "HTTP error")

        if status in (503, 429):
            msg = "QT server busy, please retry later"
            if body and isinstance(body.get("message"), str):
                msg = body["message"]
            self._logger.warning("%s QT busy status=%s", op_name, status)
            return make_tool_response(success=False, message=msg, data=body)

        if status >= 400:
            msg = f"QT HTTP error status={status}"
            if body and isinstance(body.get("message"), str):
                msg = body["message"]
            self._logger.error("%s bad status=%s body=%s", op_name, status, body)
            return make_tool_response(success=False, message=msg, data=body)

        if body is None:
            return make_tool_response(success=False, message="QT returned empty or non-JSON body")

        success = bool(body.get("success", False))
        message = str(body.get("message", "OK" if success else "QT reported failure"))
        data = body.get("data")

        if not success:
            self._logger.warning("%s QT logical failure: %s", op_name, message)
            return make_tool_response(success=False, message=message, data=data)

        self._logger.info("%s success", op_name)
        return make_tool_response(success=True, message=message, data=data)

    async def send_move(
        self,
        *,
        robot_id: str,
        linear_velocity: float,
        angular_velocity: float,
        duration_ms: int = 1000,
        timestamp: float | None = None,
    ) -> str:
        """
        发送速度指令到主控台 HTTP（字段与 HttpApiExecutor 一致：unit_id +速度）。

        @param robot_id: MCP 机器人标识
        @param linear_velocity: 线速度 m/s
        @param angular_velocity: 角速度 rad/s
        @param duration_ms: 持续时间（毫秒），默认 1000
        @param timestamp: 可选 Unix 时间戳；主控台当前可忽略，仅保留 MCP 侧审计
        @returns: 统一 JSON 字符串
        """
        self._logger.info(
            "send_move start: robot_id=%s linear_velocity=%s angular_velocity=%s duration_ms=%s",
            robot_id,
            linear_velocity,
            angular_velocity,
            duration_ms,
        )

        canon = self._manager.canonical_robot_id(robot_id)
        if canon is None:
            return make_tool_response(success=False, message=_message_unit_not_bound(robot_id))

        unit_id = self._manager.unit_id_for(canon)
        assert unit_id is not None

        if abs(float(linear_velocity)) > LINEAR_VELOCITY_MAX_ABS_M_S:
            return make_tool_response(success=False, message=_message_speed_linear_out_of_bounds(linear_velocity))
        if abs(float(angular_velocity)) > ANGULAR_VELOCITY_MAX_ABS_RAD_S:
            return make_tool_response(success=False, message=_message_speed_angular_out_of_bounds(angular_velocity))

        if duration_ms < 0:
            return make_tool_response(success=False, message="Validation failed: duration_ms must be >= 0")

        ts = timestamp if timestamp is not None else time.time()
        payload: dict[str, Any] = {
            "unit_id": unit_id,
            "linear_velocity": linear_velocity,
            "angular_velocity": angular_velocity,
            "duration_ms": int(duration_ms),
            "timestamp": ts,
        }

        self._logger.info("send_move alias_in=%s canonical_robot_id=%s unit_id=%s", robot_id, canon, unit_id)
        return await self._run_http(
            method="POST",
            url=self._send_move_url(),
            json_body=payload,
            robot_id_for_lock=canon,
            op_name="send_move",
        )

    async def stop_robot(self, *, robot_id: str) -> str:
        """
        停止单车（主控台 MA_Stop）。

        @param robot_id: MCP 标识
        @returns: 统一 JSON
        """
        canon = self._manager.canonical_robot_id(robot_id)
        if canon is None:
            return make_tool_response(success=False, message=_message_unit_not_bound(robot_id))
        unit_id = self._manager.unit_id_for(canon)
        assert unit_id is not None
        self._logger.info("stop_robot alias_in=%s canonical=%s unit_id=%s", robot_id, canon, unit_id)
        return await self._run_http(
            method="POST",
            url=qt_url(QT_STOP_PATH),
            json_body={"unit_id": unit_id},
            robot_id_for_lock=canon,
            op_name="stop_robot",
        )

    async def emergency_stop_all(self) -> str:
        """
        对所有已绑定单元发送停止（主控台 stop_all）。

        @returns: 统一 JSON
        """
        self._logger.info("emergency_stop_all")
        return await self._run_http(
            method="POST",
            url=qt_url(QT_STOP_ALL_PATH),
            json_body={},
            robot_id_for_lock=None,
            op_name="emergency_stop_all",
        )

    async def get_robot_status(self, *, robot_id: str) -> str:
        """
        查询单车状态（位姿、速度等，依赖主控台 /api/robot/status）。

        @param robot_id: MCP 标识
        @returns: 统一 JSON，data 中含主控台返回字段
        """
        canon = self._manager.canonical_robot_id(robot_id)
        if canon is None:
            return make_tool_response(success=False, message=_message_unit_not_bound(robot_id))
        unit_id = self._manager.unit_id_for(canon)
        assert unit_id is not None
        q = quote(unit_id, safe="")
        url = f"{qt_url(QT_STATUS_PATH)}?unit_id={q}"
        self._logger.info("get_robot_status alias_in=%s canonical=%s unit_id=%s", robot_id, canon, unit_id)
        raw = await self._run_http(
            method="GET",
            url=url,
            json_body=None,
            robot_id_for_lock=canon,
            op_name="get_robot_status",
        )
        return self._maybe_enrich_tool_data(raw)

    async def list_robots(self) -> str:
        """
        列出主控台绑定表（GET /api/robot/list）。
        运行态以主控台 mock + rpc_enabled 推导 run_mode；robots.json 仅暴露 planned_mode 对照。

        @returns: 统一 JSON
        """
        self._logger.info("list_robots")
        raw_resp = await self._run_http(
            method="GET",
            url=qt_url(QT_LIST_PATH),
            json_body=None,
            robot_id_for_lock=None,
            op_name="list_robots",
        )
        return self._maybe_enrich_tool_data(raw_resp)

    async def set_leader(self, *, robot_id: str) -> str:
        """
        设置地面编队队长。

        @param robot_id: robot_id 或 unit_id
        @returns: 统一 JSON
        """

        canon = self._manager.canonical_robot_id(robot_id)
        if canon is None:
            return make_tool_response(success=False, message=_message_unit_not_bound(robot_id))
        unit_id = self._manager.unit_id_for(canon)
        assert unit_id is not None
        return await self._post_qt(
            path=QT_SET_LEADER_PATH,
            json_body={"unit_id": unit_id},
            robot_id_for_lock=None,
            op_name="set_leader",
        )

    async def set_group_mode(self, *, mode: str) -> str:
        """
        设置地面编队主模式。

        @param mode: none/follow/imitate/mate 或常见中文别名
        @returns: 统一 JSON
        """

        normalized = _normalize_group_mode(mode)
        if normalized is None:
            return make_tool_response(
                success=False,
                message="Validation failed: mode must be one of none/follow/imitate/mate",
            )
        return await self._post_qt(
            path=QT_SET_GROUP_MODE_PATH,
            json_body={"mode": normalized},
            robot_id_for_lock=None,
            op_name="set_group_mode",
        )

    async def set_group_minor_mode(self, *, mode: str) -> str:
        """
        设置地面编队次模式。

        @param mode: none/object/track 或常见别名
        @returns: 统一 JSON
        """

        normalized = _normalize_minor_mode(mode)
        if normalized is None:
            return make_tool_response(
                success=False,
                message="Validation failed: minor mode must be one of none/object/track",
            )
        return await self._post_qt(
            path=QT_SET_GROUP_MINOR_MODE_PATH,
            json_body={"minor_mode": normalized},
            robot_id_for_lock=None,
            op_name="set_group_minor_mode",
        )

    async def set_task_point(self, *, robot_id: str, x: float, y: float) -> str:
        """
        下发单车任务点。

        @param robot_id: robot_id 或 unit_id
        @param x: 目标 x
        @param y: 目标 y
        @returns: 统一 JSON
        """

        canon = self._manager.canonical_robot_id(robot_id)
        if canon is None:
            return make_tool_response(success=False, message=_message_unit_not_bound(robot_id))
        ok_x, xv, msg_x = _finite_float(x, "x")
        if not ok_x:
            return make_tool_response(success=False, message=msg_x)
        ok_y, yv, msg_y = _finite_float(y, "y")
        if not ok_y:
            return make_tool_response(success=False, message=msg_y)

        unit_id = self._manager.unit_id_for(canon)
        assert unit_id is not None
        return await self._post_qt(
            path=QT_TASK_POINT_PATH,
            json_body={"unit_id": unit_id, "x": xv, "y": yv},
            robot_id_for_lock=canon,
            op_name="set_task_point",
        )

    async def set_task_path(self, *, robot_id: str, points_json: str) -> str:
        """
        下发单车任务路径。

        @param robot_id: robot_id 或 unit_id
        @param points_json: JSON 列表，元素包含 x/y
        @returns: 统一 JSON
        """

        canon = self._manager.canonical_robot_id(robot_id)
        if canon is None:
            return make_tool_response(success=False, message=_message_unit_not_bound(robot_id))
        ok, points, msg = _parse_task_points(points_json)
        if not ok:
            return make_tool_response(success=False, message=msg)

        unit_id = self._manager.unit_id_for(canon)
        assert unit_id is not None
        return await self._post_qt(
            path=QT_TASK_PATH_PATH,
            json_body={"unit_id": unit_id, "points": points},
            robot_id_for_lock=canon,
            op_name="set_task_path",
        )

    async def add_trap_point(self, *, x: float, y: float, radius: float) -> str:
        """
        向地面编队广播陷阱点。

        @param x: 陷阱点 x
        @param y: 陷阱点 y
        @param radius: 半径，必须大于 0
        @returns: 统一 JSON
        """

        ok_x, xv, msg_x = _finite_float(x, "x")
        if not ok_x:
            return make_tool_response(success=False, message=msg_x)
        ok_y, yv, msg_y = _finite_float(y, "y")
        if not ok_y:
            return make_tool_response(success=False, message=msg_y)
        ok_r, rv, msg_r = _finite_float(radius, "radius")
        if not ok_r:
            return make_tool_response(success=False, message=msg_r)
        if rv <= 0:
            return make_tool_response(success=False, message="Validation failed: trap radius must be > 0")

        return await self._post_qt(
            path=QT_TRAP_ADD_PATH,
            json_body={"x": xv, "y": yv, "radius": rv},
            robot_id_for_lock=None,
            op_name="add_trap_point",
        )

    async def clear_traps(self) -> str:
        """
        清空地面编队陷阱点。

        @returns: 统一 JSON
        """

        return await self._post_qt(
            path=QT_TRAP_CLEAR_PATH,
            json_body={},
            robot_id_for_lock=None,
            op_name="clear_traps",
        )

    async def reset_unit_relations(self) -> str:
        """
        重置地面单元间角色、队长和编队关系。

        @returns: 统一 JSON
        """

        return await self._post_qt(
            path=QT_RESET_RELATIONS_PATH,
            json_body={},
            robot_id_for_lock=None,
            op_name="reset_unit_relations",
        )

    async def compute_remaining_distance(
        self, *, robot_a: str, robot_b: str, target_distance_m: float = 1.0
    ) -> str:
        """
        计算两车当前欧式距离与目标间距差值（remaining = current - target）。

        @param robot_a: 机器人 A（支持 robot_id 或 unit_id）
        @param robot_b: 机器人 B（支持 robot_id 或 unit_id）
        @param target_distance_m: 目标距离（米），默认 1.0
        @returns: 统一 JSON，data 中包含 current_distance_m/remaining_distance_m
        """

        if target_distance_m < 0:
            return make_tool_response(success=False, message="Validation failed: target_distance_m must be >= 0")

        sa = await self.get_robot_status(robot_id=robot_a)
        sb = await self.get_robot_status(robot_id=robot_b)
        try:
            oa = json.loads(sa)
            ob = json.loads(sb)
        except json.JSONDecodeError:
            return make_tool_response(success=False, message="compute_remaining_distance parse status response failed")

        if not bool(oa.get("success")):
            return make_tool_response(
                success=False, message=f"robot_a status failed: {oa.get('message', 'unknown')}", data=oa.get("data")
            )
        if not bool(ob.get("success")):
            return make_tool_response(
                success=False, message=f"robot_b status failed: {ob.get('message', 'unknown')}", data=ob.get("data")
            )

        da = oa.get("data") or {}
        db = ob.get("data") or {}
        pa = (da.get("pose") or {}) if isinstance(da, dict) else {}
        pb = (db.get("pose") or {}) if isinstance(db, dict) else {}
        if not isinstance(pa.get("x"), (int, float)) or not isinstance(pa.get("y"), (int, float)):
            return make_tool_response(success=False, message=f"robot_a pose missing or invalid: {robot_a}", data=da)
        if not isinstance(pb.get("x"), (int, float)) or not isinstance(pb.get("y"), (int, float)):
            return make_tool_response(success=False, message=f"robot_b pose missing or invalid: {robot_b}", data=db)

        dx = float(pb["x"]) - float(pa["x"])
        dy = float(pb["y"]) - float(pa["y"])
        current = math.hypot(dx, dy)
        remaining = current - float(target_distance_m)
        self._logger.info(
            "compute_remaining_distance robot_a=%s robot_b=%s current=%.4f target=%.4f remaining=%.4f",
            robot_a,
            robot_b,
            current,
            target_distance_m,
            remaining,
        )
        return make_tool_response(
            success=True,
            message="ok",
            data={
                "robot_a": robot_a,
                "robot_b": robot_b,
                "target_distance_m": float(target_distance_m),
                "current_distance_m": current,
                "remaining_distance_m": remaining,
            },
        )

    async def compute_relative_pose(self, *, robot_from: str, robot_to: str) -> str:
        """
        计算两车相对位姿（含方位角与朝向误差），供转角决策。

        @param robot_from: 参考车（支持 robot_id 或 unit_id）
        @param robot_to: 目标车（支持 robot_id 或 unit_id）
        @returns: 统一 JSON，含 dx/dy/distance/bearing/yaw_error
        """

        sf = await self.get_robot_status(robot_id=robot_from)
        st = await self.get_robot_status(robot_id=robot_to)
        try:
            of = json.loads(sf)
            ot = json.loads(st)
        except json.JSONDecodeError:
            return make_tool_response(success=False, message="compute_relative_pose parse status response failed")
        if not bool(of.get("success")):
            return make_tool_response(success=False, message=f"robot_from status failed: {of.get('message', 'unknown')}")
        if not bool(ot.get("success")):
            return make_tool_response(success=False, message=f"robot_to status failed: {ot.get('message', 'unknown')}")
        df = of.get("data") or {}
        dt = ot.get("data") or {}
        pf = (df.get("pose") or {}) if isinstance(df, dict) else {}
        pt = (dt.get("pose") or {}) if isinstance(dt, dict) else {}
        if not isinstance(pf.get("x"), (int, float)) or not isinstance(pf.get("y"), (int, float)):
            return make_tool_response(success=False, message=f"robot_from pose missing: {robot_from}")
        if not isinstance(pt.get("x"), (int, float)) or not isinstance(pt.get("y"), (int, float)):
            return make_tool_response(success=False, message=f"robot_to pose missing: {robot_to}")
        x0, y0 = float(pf["x"]), float(pf["y"])
        x1, y1 = float(pt["x"]), float(pt["y"])
        yaw0 = float(pf.get("yaw", 0.0))
        dx = x1 - x0
        dy = y1 - y0
        dist = float(math.hypot(dx, dy))
        bearing = float(math.atan2(dy, dx))
        yaw_err = float((bearing - yaw0 + math.pi) % (2.0 * math.pi) - math.pi)
        return make_tool_response(
            success=True,
            message="ok",
            data={
                "robot_from": robot_from,
                "robot_to": robot_to,
                "dx_m": dx,
                "dy_m": dy,
                "distance_m": dist,
                "bearing_rad": bearing,
                "robot_from_yaw_rad": yaw0,
                "yaw_error_rad": yaw_err,
            },
        )

    async def compute_navigation_hint(
        self,
        *,
        robot_id: str,
        target_x: float,
        target_y: float,
        max_linear_m_s: float = 0.2,
        max_angular_rad_s: float = 0.6,
    ) -> str:
        """
        计算到目标点的导航提示（距离、方位误差、建议速度与时长）。

        @param robot_id: 机器人 ID
        @param target_x: 目标点 x
        @param target_y: 目标点 y
        @param max_linear_m_s: 建议最大线速度
        @param max_angular_rad_s: 建议最大角速度
        @returns: 统一 JSON，供 LLM 决策 send_move
        """

        s = await self.get_robot_status(robot_id=robot_id)
        try:
            o = json.loads(s)
        except json.JSONDecodeError:
            return make_tool_response(success=False, message="compute_navigation_hint parse status response failed")
        if not bool(o.get("success")):
            return make_tool_response(success=False, message=f"status failed: {o.get('message', 'unknown')}")
        d = o.get("data") or {}
        p = (d.get("pose") or {}) if isinstance(d, dict) else {}
        if not isinstance(p.get("x"), (int, float)) or not isinstance(p.get("y"), (int, float)):
            return make_tool_response(success=False, message=f"pose missing for {robot_id}")
        x, y, yaw = float(p["x"]), float(p["y"]), float(p.get("yaw", 0.0))
        dx = float(target_x) - x
        dy = float(target_y) - y
        dist = float(math.hypot(dx, dy))
        heading = float(math.atan2(dy, dx))
        yaw_err = float((heading - yaw + math.pi) % (2.0 * math.pi) - math.pi)
        max_lin = max(0.05, abs(float(max_linear_m_s)))
        max_ang = max(0.2, abs(float(max_angular_rad_s)))
        yaw_tol = 0.10
        # 分段控制：角误差大时先旋转；角误差小后再前进，降低漂移。
        if abs(yaw_err) > yaw_tol:
            ang_mag = min(max_ang, max(0.2, abs(yaw_err)))
            ang_v = ang_mag if yaw_err > 0 else -ang_mag
            rotate_ms = int((abs(yaw_err) / max(0.05, abs(ang_v))) * 1000.0)
            lin_v = 0.0
            move_ms = 0
        else:
            ang_v = 0.0
            # 放开单次前进步长上限，允许一次性走完所需距离，避免无谓的多次迭代
            step_dist = min(dist, 5.0)
            lin_v = min(max_lin, max(0.1, step_dist * 0.8))
            move_ms = int((step_dist / max(0.05, abs(lin_v))) * 1000.0)
            rotate_ms = 0
        return make_tool_response(
            success=True,
            message="ok",
            data={
                "robot_id": robot_id,
                "current_pose": {"x": x, "y": y, "yaw": yaw},
                "target_pose": {"x": float(target_x), "y": float(target_y)},
                "distance_m": dist,
                "heading_to_target_rad": heading,
                "yaw_error_rad": yaw_err,
                "suggested": {
                    "rotate": {"angular_velocity": ang_v, "duration_ms": rotate_ms},
                    "move": {"linear_velocity": lin_v, "duration_ms": move_ms},
                },
            },
        )

    async def plan_line_targets(
        self,
        *,
        robot_ids_csv: str = "",
        spacing_m: float = 1.0,
    ) -> str:
        """
        基于当前 fleet 位姿生成直线编队目标点（固定锚点 yaw + 最小位移分配）。

        @param robot_ids_csv: 参与机器人，空表示全部配置
        @param spacing_m: 间距（米）
        @returns: 统一 JSON，含每车目标点
        """

        if spacing_m <= 0:
            return make_tool_response(success=False, message="Validation failed: spacing_m must be > 0")
        fleet = await self.get_fleet_status(robot_ids_csv=robot_ids_csv)
        try:
            of = json.loads(fleet)
        except json.JSONDecodeError:
            return make_tool_response(success=False, message="plan_line_targets parse fleet response failed")
        if not bool(of.get("success")):
            return make_tool_response(success=False, message=f"fleet failed: {of.get('message', 'unknown')}")
        data = of.get("data") or {}
        items = data.get("items") or []
        poses: dict[str, tuple[float, float, float]] = {}
        for it in items:
            if not isinstance(it, dict) or not it.get("success"):
                continue
            inner = it.get("data") or {}
            pose = inner.get("pose") or {}
            uid = inner.get("unit_id")
            if not isinstance(uid, str):
                continue
            if not isinstance(pose.get("x"), (int, float)) or not isinstance(pose.get("y"), (int, float)):
                continue
            poses[uid] = (float(pose["x"]), float(pose["y"]), float(pose.get("yaw", 0.0)))
        if len(poses) < 2:
            return make_tool_response(success=False, message="plan_line_targets requires at least 2 robots")
        ids = list(poses.keys())
        ax, ay, ayaw = poses[ids[0]]
        ux, uy = math.cos(ayaw), math.sin(ayaw)
        n = len(ids)
        half = (n - 1) / 2.0
        targets = [(ax + (i - half) * spacing_m * ux, ay + (i - half) * spacing_m * uy) for i in range(n)]
        best_map: dict[str, tuple[float, float]] = {}
        best_cost = float("inf")
        for perm in itertools.permutations(targets, n):
            cost = 0.0
            cur: dict[str, tuple[float, float]] = {}
            for rid, tgt in zip(ids, perm):
                px, py, _ = poses[rid]
                cost += math.hypot(tgt[0] - px, tgt[1] - py)
                cur[rid] = tgt
            if cost < best_cost:
                best_cost = cost
                best_map = cur
        return make_tool_response(
            success=True,
            message="ok",
            data={
                "spacing_m": float(spacing_m),
                "axis_anchor": {"robot_id": ids[0], "yaw_rad": ayaw, "x": ax, "y": ay},
                "targets": [
                    {"robot_id": rid, "target_x": float(t[0]), "target_y": float(t[1])} for rid, t in best_map.items()
                ],
            },
        )

    async def plan_triangle_targets(
        self,
        *,
        robot_ids_csv: str = "",
        side_length_m: float = 1.0,
    ) -> str:
        """
        基于当前 fleet 位姿生成正三角形编队分配点。

        @param robot_ids_csv: 参与机器人，空表示全部
        @param side_length_m: 边长（米）
        @returns: 统一 JSON，含每车目标点
        """

        if side_length_m <= 0:
            return make_tool_response(success=False, message="Validation failed: side_length_m must be > 0")
        fleet = await self.get_fleet_status(robot_ids_csv=robot_ids_csv)
        try:
            of = json.loads(fleet)
        except json.JSONDecodeError:
            return make_tool_response(success=False, message="plan_triangle_targets parse fleet response failed")
        if not bool(of.get("success")):
            return make_tool_response(success=False, message=f"fleet failed: {of.get('message', 'unknown')}")
        data = of.get("data") or {}
        items = data.get("items") or []
        poses: dict[str, tuple[float, float, float]] = {}
        for it in items:
            if not isinstance(it, dict) or not it.get("success"):
                continue
            inner = it.get("data") or {}
            pose = inner.get("pose") or {}
            uid = inner.get("unit_id")
            if not isinstance(uid, str):
                continue
            if not isinstance(pose.get("x"), (int, float)) or not isinstance(pose.get("y"), (int, float)):
                continue
            poses[uid] = (float(pose["x"]), float(pose["y"]), float(pose.get("yaw", 0.0)))
            
        ids = list(poses.keys())[:3]
        if len(ids) < 3:
            return make_tool_response(success=False, message="plan_triangle_targets requires at least 3 robots")
        
        anchor = ids[0]
        ax, ay, ayaw = poses[anchor]
        others = ids[1:]
        nearest = min(
            others,
            key=lambda r: math.hypot(poses[r][0] - ax, poses[r][1] - ay),
        )
        dx = poses[nearest][0] - ax
        dy = poses[nearest][1] - ay
        heading = math.atan2(dy, dx) if math.hypot(dx, dy) > 1e-6 else ayaw

        def _targets(sign: float) -> list[tuple[float, float]]:
            b = (ax + side_length_m * math.cos(heading), ay + side_length_m * math.sin(heading))
            h2 = heading + sign * (math.pi / 3.0)
            c = (ax + side_length_m * math.cos(h2), ay + side_length_m * math.sin(h2))
            return [(ax, ay), b, c]

        best_map: dict[str, tuple[float, float]] = {}
        best_cost = float("inf")
        
        for sign in (1.0, -1.0):
            tgts = _targets(sign)
            for perm in itertools.permutations(tgts, 3):
                cost = 0.0
                cur: dict[str, tuple[float, float]] = {}
                for rid, tgt in zip(ids, perm):
                    px, py, _ = poses[rid]
                    cost += math.hypot(tgt[0] - px, tgt[1] - py)
                    cur[rid] = tgt
                if cost < best_cost:
                    best_cost = cost
                    best_map = cur
                    
        return make_tool_response(
            success=True,
            message="ok",
            data={
                "side_length_m": float(side_length_m),
                "targets": [
                    {"robot_id": rid, "target_x": float(t[0]), "target_y": float(t[1])} for rid, t in best_map.items()
                ],
            },
        )

    async def get_fleet_status(self, *, robot_ids_csv: str = "") -> str:
        """
        批量查询多机器人状态，便于多车编队/闭环规划。

        @param robot_ids_csv: 逗号分隔的 robot_id 或 unit_id；为空时默认查询 robots.json 全部配置
        @returns: 统一 JSON，data 包含 items 与 summary
        """

        raw_ids = [s.strip() for s in robot_ids_csv.split(",") if s.strip()] if robot_ids_csv.strip() else []
        query_ids = raw_ids if raw_ids else self._manager.configured_robot_ids()
        if not query_ids:
            return make_tool_response(success=False, message="No robots configured")

        items: list[dict[str, Any]] = []
        ok_count = 0
        for rid in query_ids:
            one = await self.get_robot_status(robot_id=rid)
            try:
                payload = json.loads(one)
            except json.JSONDecodeError:
                payload = {"success": False, "message": "invalid json from get_robot_status", "data": None}
            success = bool(payload.get("success"))
            if success:
                ok_count += 1
            items.append(
                {
                    "robot_id_input": rid,
                    "success": success,
                    "message": str(payload.get("message", "")),
                    "data": payload.get("data"),
                }
            )

        fleet_data: dict[str, Any] = {
            "items": items,
            "summary": {"total": len(items), "ok": ok_count, "failed": len(items) - ok_count},
            "rpc_enabled": self._cached_rpc_enabled,
        }
        return make_tool_response(
            success=(ok_count == len(items)),
            message="ok" if ok_count == len(items) else "partial",
            data=fleet_data,
        )
