"""
FastMCP 服务主入口。

职责：通过 stdio 暴露 MCP 工具；HTTP 转发至 SAU 主控台 HttpPlugin（默认 127.0.0.1:9001）。
"""

from __future__ import annotations

import asyncio as _asyncio
import json as _json

from fastmcp import FastMCP

from config import DEFAULT_TOOL_TIMEOUT_S, LOG_FILE, QT_HTTP_BASE
from robot_adapter import RobotAdapter
from utils.logging_setup import setup_logging
from agents import AgentApiClient, AgentResolver, AgentService, register_agent_tools

# 任务级编排器
from orchestrator.formation_mission import (
    FormationMissionOrchestrator,
    FormationMissionResult,
)

# 任务级编队编排器（全局单例，在 create_app 中初始化）
_formation_orchestrator: FormationMissionOrchestrator | None = None
from orchestrator.active_formation import (
    FormationState,
    active_formation_registry,
)
from orchestrator.task_manager import task_manager
from safety.validator import (
    validate_formation_mission,
    validate_move_formation,
    ERR_FORMATION_NOT_READY,
    ERR_FORMATION_CONFLICT,
)


def create_app() -> FastMCP:
    """
    创建并配置 FastMCP 应用实例。

    @returns: FastMCP 对象
    """

    mcp = FastMCP(name="firstmcp-robot-server")
    adapter = RobotAdapter(tool_timeout_s=DEFAULT_TOOL_TIMEOUT_S)

    # --- 智能体目录、状态与别名系统（Phase 2）---
    agent_api_client = AgentApiClient(base_url=QT_HTTP_BASE)
    agent_resolver = AgentResolver(agent_api_client, adapter._manager)
    agent_service = AgentService(agent_api_client, agent_resolver)
    register_agent_tools(mcp, agent_service)
    # 注入 AgentResolver 到 RobotAdapter，使所有旧工具支持别名解析
    adapter.set_agent_resolver(agent_resolver)

    # --- 初始化任务级编排器（MCP-Console 融合核心）---
    global _formation_orchestrator
    _formation_orchestrator = FormationMissionOrchestrator(adapter.orchestrator_dispatch)

    @mcp.tool
    async def send_move(
        robot_id: str,
        linear_velocity: float,
        angular_velocity: float,
        duration_ms: int = 1000,
        timestamp: float | None = None,
    ) -> str:
        """
        向主控台发送运动指令（线速度 m/s + 角速度 rad/s）。robot_id 在 robots.json 映射为 unit_id（如 GV1）。

        @param robot_id: MCP 机器人标识，如 robot_1
        @param linear_velocity: 线速度，单位 m/s
        @param angular_velocity: 角速度，单位 rad/s
        @param duration_ms: 持续时间（毫秒），默认 1000
        @param timestamp: 可选 Unix 时间戳（秒），供审计；主控台可忽略
        @returns: 统一 JSON 字符串 success/message/data
        """

        return await adapter.send_move(
            robot_id=robot_id,
            linear_velocity=linear_velocity,
            angular_velocity=angular_velocity,
            duration_ms=duration_ms,
            timestamp=timestamp,
        )

    @mcp.tool
    async def stop_robot(robot_id: str) -> str:
        """
        停止指定机器人（主控台 Unit MA_Stop）。

        @param robot_id: MCP 标识
        @returns: 统一 JSON 字符串
        """

        return await adapter.stop_robot(robot_id=robot_id)

    @mcp.tool
    async def emergency_stop_all() -> str:
        """
        对所有已绑定单元发送停止指令（简单全停，非硬件急停）。

        @returns: 统一 JSON 字符串
        """

        return await adapter.emergency_stop_all()

    @mcp.tool
    async def get_robot_status(robot_id: str) -> str:
        """
        查询机器人位姿与速度等（地面 GV* / 空中 AV* 由主控台返回字段决定）。

        @param robot_id: MCP 标识
        @returns: 统一 JSON 字符串，data 来自主控台
        """

        return await adapter.get_robot_status(robot_id=robot_id)

    @mcp.tool
    async def list_robots() -> str:
        """
        列出主控台绑定单元；data.units[].run_mode 为当前 sim/real（依据 mock 与 rpc_enabled）。
        planned_mode 仅来自 robots.json，不可当作运行态。

        @returns: 统一 JSON 字符串
        """

        return await adapter.list_robots()

    @mcp.tool
    async def set_leader(robot_id: str) -> str:
        """
        设置地面无人车编队队长。

        @param robot_id: MCP robot_id 或 Qt unit_id（如 robot_1/GV1）
        @returns: 统一 JSON 字符串
        """

        return await adapter.set_leader(robot_id=robot_id)

    @mcp.tool
    async def set_group_mode(mode: str) -> str:
        """
        设置地面无人车编队主模式：none/follow/imitate/mate。

        @param mode: 模式名称或常见别名（如 跟随）
        @returns: 统一 JSON 字符串
        """

        return await adapter.set_group_mode(mode=mode)

    @mcp.tool
    async def set_group_minor_mode(mode: str) -> str:
        """
        设置地面无人车编队次模式：none/object/track。

        @param mode: 次模式名称或常见别名（如 route/轨迹）
        @returns: 统一 JSON 字符串
        """

        return await adapter.set_group_minor_mode(mode=mode)

    @mcp.tool
    async def set_task_point(robot_id: str, x: float, y: float) -> str:
        """
        为指定地面无人车下发任务点。

        @param robot_id: MCP robot_id 或 Qt unit_id
        @param x: 目标点 x
        @param y: 目标点 y
        @returns: 统一 JSON 字符串
        """

        return await adapter.set_task_point(robot_id=robot_id, x=x, y=y)

    @mcp.tool
    async def set_task_path(robot_id: str, points_json: str) -> str:
        """
        为指定地面无人车下发任务路径。

        @param robot_id: MCP robot_id 或 Qt unit_id
        @param points_json: JSON 列表，元素为 {"x": number, "y": number}，最多 10 个点
        @returns: 统一 JSON 字符串
        """

        return await adapter.set_task_path(robot_id=robot_id, points_json=points_json)

    @mcp.tool
    async def add_trap_point(x: float, y: float, radius: float) -> str:
        """
        向地面无人车编队广播陷阱点。

        @param x: 陷阱点 x
        @param y: 陷阱点 y
        @param radius: 陷阱半径，必须大于 0
        @returns: 统一 JSON 字符串
        """

        return await adapter.add_trap_point(x=x, y=y, radius=radius)

    @mcp.tool
    async def clear_traps() -> str:
        """
        清空地面无人车陷阱点。

        @returns: 统一 JSON 字符串
        """

        return await adapter.clear_traps()

    @mcp.tool
    async def reset_unit_relations() -> str:
        """
        重置地面单元间队长、角色和编队关系。

        @returns: 统一 JSON 字符串
        """

        return await adapter.reset_unit_relations()

    @mcp.tool
    async def compute_remaining_distance(robot_a: str, robot_b: str, target_distance_m: float = 1.0) -> str:
        """
        计算两车当前距离与目标距离差值（remaining = current - target）。

        @param robot_a: 机器人 A（robot_id 或 unit_id）
        @param robot_b: 机器人 B（robot_id 或 unit_id）
        @param target_distance_m: 目标间距（米），默认 1.0
        @returns: 统一 JSON（含 current_distance_m / remaining_distance_m）
        """

        return await adapter.compute_remaining_distance(
            robot_a=robot_a, robot_b=robot_b, target_distance_m=target_distance_m
        )

    @mcp.tool
    async def get_fleet_status(robot_ids_csv: str = "") -> str:
        """
        批量查询机器人状态；为空时查询 robots.json 中全部配置。

        @param robot_ids_csv: 逗号分隔 robot_id 或 unit_id，例如 "GV1,GV2,robot_3"
        @returns: 统一 JSON，含 items 列表与 summary 统计
        """

        return await adapter.get_fleet_status(robot_ids_csv=robot_ids_csv)

    @mcp.tool
    async def compute_relative_pose(robot_from: str, robot_to: str) -> str:
        """
        计算两车相对位姿（dx/dy/distance/bearing/yaw_error）。

        @param robot_from: 参考车（robot_id 或 unit_id）
        @param robot_to: 目标车（robot_id 或 unit_id）
        @returns: 统一 JSON
        """

        return await adapter.compute_relative_pose(robot_from=robot_from, robot_to=robot_to)

    @mcp.tool
    async def compute_navigation_hint(
        robot_id: str,
        target_x: float,
        target_y: float,
        max_linear_m_s: float = 0.2,
        max_angular_rad_s: float = 0.6,
    ) -> str:
        """
        计算到目标点导航提示（距离、航向误差、建议旋转/直行参数）。

        @param robot_id: 机器人 ID
        @param target_x: 目标 x
        @param target_y: 目标 y
        @param max_linear_m_s: 建议最大线速度
        @param max_angular_rad_s: 建议最大角速度
        @returns: 统一 JSON
        """

        return await adapter.compute_navigation_hint(
            robot_id=robot_id,
            target_x=target_x,
            target_y=target_y,
            max_linear_m_s=max_linear_m_s,
            max_angular_rad_s=max_angular_rad_s,
        )

    @mcp.tool
    async def plan_line_targets(robot_ids_csv: str = "", spacing_m: float = 1.0) -> str:
        """
        按当前位姿规划直线位点目标（固定锚点 yaw + 最小位移分配）。

        @param robot_ids_csv: 参与机器人，空表示全部
        @param spacing_m: 目标间距
        @returns: 统一 JSON
        """

        return await adapter.plan_line_targets(robot_ids_csv=robot_ids_csv, spacing_m=spacing_m)

    @mcp.tool
    async def plan_triangle_targets(robot_ids_csv: str = "", side_length_m: float = 1.0) -> str:
        """
        用于基于当前位姿生成正三角形编队的分配点。

        @param robot_ids_csv: 参与机器人，需3台
        @param side_length_m: 边长（米）
        @returns: 统一 JSON
        """

        return await adapter.plan_triangle_targets(robot_ids_csv=robot_ids_csv, side_length_m=side_length_m)

    # =====================================================================
    # MCP-IDL Task-Level Tools (mcp_swarm_task.idl SwarmTaskControl)
    # =====================================================================

    @mcp.tool
    async def goto_pose(
        robot_id: str,
        x: float,
        y: float,
        yaw: float = 0.0,
        linear_speed_m_s: float = 0.3,
        angular_speed_rad_s: float = 0.6,
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        """
        令指定智能体自主导航到目标点位 (x, y)。

        系统内部调用 setTaskPoint 指令，智能体自主导航至目标点。
        返回 task_id，使用 get_task_status 轮询进度直到到达。

        @param robot_id: 智能体标识，如 GV1、robot_1、或别名
        @param x: 目标 x 坐标（米）
        @param y: 目标 y 坐标（米）
        @param yaw: 目标朝向（弧度，0=不关心）
        @param linear_speed_m_s: 最大线速度（默认 0.3 m/s）
        @param angular_speed_rad_s: 最大角速度（默认 0.6 rad/s）
        @param tolerance_m: 到达容差（默认 0.15m）
        @param timeout_ms: 超时（默认 30s）
        @returns: JSON，data.task_id 用于查询进度
        """
        return await adapter.goto_pose(
            robot_id=robot_id, x=x, y=y, yaw=yaw,
            linear_speed_m_s=linear_speed_m_s,
            angular_speed_rad_s=angular_speed_rad_s,
            tolerance_m=tolerance_m, timeout_ms=timeout_ms,
        )

    @mcp.tool
    async def goto_pose_batch(
        targets_json: str,
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        """
        多智能体并发导航到各自目标点。

        @param targets_json: JSON 数组，每项 {"robot_id":"GV1","x":3,"y":5}
        @param tolerance_m: 到达容差
        @param timeout_ms: 超时
        @returns: JSON，data.task_id 用于查询 batch 进度
        """
        return await adapter.goto_pose_batch(
            targets_json=targets_json,
            tolerance_m=tolerance_m, timeout_ms=timeout_ms,
        )

    @mcp.tool
    async def execute_formation(
        formation_type: str,
        unit_ids_csv: str = "",
        spacing_m: float = 1.0,
        anchor_json: str = "",
        heading_rad: float = 0.0,
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        """
        执行编队任务（语义化参数，大模型友好）。

        编队类型支持:
        - "line": 直线编队（>=2台）
        - "triangle": 正三角形编队（>=3台）
        - "column": 纵队（>=2台）

        内部自动完成: 规划目标点 → 并发导航 → 到达确认。

        @param formation_type: "line" | "triangle" | "column"
        @param unit_ids_csv: 逗号分隔的 unit_id，如 "GV1,GV2,GV3"
        @param spacing_m: 间距（米），默认 1.0
        @param anchor_json: 锚点 {"x":0,"y":0,"yaw":0}，空=自动计算
        @param heading_rad: 编队朝向，默认 0.0
        @param tolerance_m: 到达容差
        @param timeout_ms: 超时
        @returns: JSON，data.task_id 用于查询进度
        """
        return await adapter.execute_formation(
            formation_type=formation_type,
            unit_ids_csv=unit_ids_csv,
            spacing_m=spacing_m,
            anchor_json=anchor_json,
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )

    @mcp.tool
    async def get_task_status(task_id: str) -> str:
        """
        查询异步任务（goto_pose / goto_pose_batch / execute_formation）的执行进度。

        返回完整的 TaskResult：
        - state: PENDING | RUNNING | COMPLETED | FAILED | PARTIAL_COMPLETED | TIMEOUT | CANCELLED | REJECTED
        - progress_pct: 0-100
        - unit_results: 每个 unit 的子状态
        - error_code: MCP-IDL 统一错误码（空=无错误）

        大模型应轮询此接口直到 state 为终态。

        @param task_id: goto_pose 等返回的 task_id
        @returns: JSON
        """
        return await adapter.get_task_status(task_id=task_id)

    @mcp.tool
    async def cancel_task(task_id: str) -> str:
        """
        取消运行中的任务。所有相关智能体会立即停止。

        已完成/已取消的任务不可重复取消。

        @param task_id: 要取消的任务 ID
        @returns: JSON
        """
        return await adapter.cancel_task(task_id=task_id)

    # =====================================================================
    # MCP-Console 任务级编排工具 (FormationMissionOrchestrator)
    #
    # 大模型不应直接调用 set_leader / set_follower / set_formation，
    # 而应调用以下任务级工具，由编排器自动完成完整工作流。
    # =====================================================================

    @mcp.tool
    async def execute_formation_mission(
        formation_type: str,
        unit_ids_csv: str = "",
        leader_id: str = "",
        spacing_m: float = 1.0,
        heading_rad: float = 0.0,
        tolerance_m: float = 0.15,
        timeout_ms: int = 30000,
    ) -> str:
        """
        【任务级工具】执行完整编队任务流程。

        用户只需输入自然语言（如"对集群进行三角形编队"），LLM 调用此工具，
        系统自动完成: 状态确认 → 领航者选择 → 跟随关系设置 → 队形下发 → 验证。

        编队类型:
        - "line": 直线编队 (>=2台)
        - "triangle": 正三角形编队 (>=3台)
        - "column": 纵队 (>=2台)

        内部流程:
        1. 查询集群状态 (get_fleet_status)
        2. 自动选择最适合的领航者 (或使用 leader_id 指定)
        3. 设置领航者 (set_leader)
        4. 设置跟随者关系 (set_group_mode + set_leader per follower)
        5. 下发队形参数 (execute_formation)
        6. 验证编队建立成功

        成功后，后续移动请使用 move_active_formation（仅控制领航者，
        跟随者由 Console 原有编队逻辑自动协同）。

        @param formation_type: "line" | "triangle" | "column"
        @param unit_ids_csv: 参与智能体，逗号分隔（如 "GV1,GV2,GV3"）；空=自动获取全部在线
        @param leader_id: 指定领航者 unit_id；空=自动选择最合适的
        @param spacing_m: 间距（米），默认 1.0
        @param heading_rad: 编队朝向（弧度），默认 0.0
        @param tolerance_m: 到达容差（米），默认 0.15
        @param timeout_ms: 超时（毫秒），默认 30000
        @returns: JSON，含 leader_id/follower_ids/formation_type/state
        """
        # 解析 unit_ids
        raw_ids = [s.strip() for s in unit_ids_csv.split(",") if s.strip()] if unit_ids_csv.strip() else []
        unit_ids: list[str] = []
        for rid in raw_ids:
            uid = await adapter._resolve_to_unit_id(rid)
            if uid is None:
                return _json.dumps({
                    "success": False,
                    "message": f'unit_not_bound: "{rid}" 无法解析为已知智能体',
                    "error_code": "UNIT_NOT_FOUND",
                }, ensure_ascii=False)
            unit_ids.append(uid)

        # 如果未指定 unit_ids，自动获取全部在线
        if not unit_ids:
            resp = await adapter.get_fleet_status()
            try:
                data = _json.loads(resp)
            except _json.JSONDecodeError:
                return _json.dumps({
                    "success": False,
                    "message": "获取集群状态失败，无法自动选择智能体",
                    "error_code": "FLEET_STATUS_FAILED",
                }, ensure_ascii=False)
            if data.get("success") and data.get("data"):
                for item in data["data"].get("items", []):
                    if item.get("success"):
                        inner = item.get("data") or {}
                        uid = inner.get("unit_id", "")
                        if uid:
                            unit_ids.append(uid)
            if not unit_ids:
                return _json.dumps({
                    "success": False,
                    "message": "没有可用的在线智能体",
                    "error_code": "NO_UNITS_AVAILABLE",
                }, ensure_ascii=False)

        # 解析 leader_id
        resolved_leader: str | None = None
        if leader_id.strip():
            resolved_leader = await adapter._resolve_to_unit_id(leader_id.strip())
            if resolved_leader is None:
                return _json.dumps({
                    "success": False,
                    "message": f'leader_id "{leader_id}" 无法解析',
                    "error_code": "LEADER_NOT_FOUND",
                }, ensure_ascii=False)

        # 安全检查（客户端侧预检）
        has_active = active_formation_registry.has_active
        passed, err_code, msg = validate_formation_mission(
            formation_type=formation_type.strip().lower(),
            unit_ids=unit_ids,
            leader_id=resolved_leader,
            spacing_m=spacing_m,
            existing_formation=has_active,
        )
        if not passed:
            return _json.dumps({
                "success": False,
                "message": msg,
                "error_code": err_code,
            }, ensure_ascii=False)

        # 执行编排
        if _formation_orchestrator is None:
            return _json.dumps({
                "success": False,
                "message": "编队编排器未初始化",
                "error_code": "ORCHESTRATOR_NOT_READY",
            }, ensure_ascii=False)

        result: FormationMissionResult = await _formation_orchestrator.execute(
            formation_type=formation_type.strip().lower(),
            unit_ids=unit_ids,
            leader_id=resolved_leader,
            spacing_m=spacing_m,
            heading_rad=heading_rad,
            tolerance_m=tolerance_m,
            timeout_ms=timeout_ms,
        )
        return result.to_json()

    @mcp.tool
    async def move_active_formation(
        linear_velocity: float,
        angular_velocity: float = 0.0,
        duration_ms: int = 1000,
    ) -> str:
        """
        【任务级工具】移动当前活跃编队（仅控制领航者）。

        编队建立后，使用此工具控制编队移动。系统内部只对领航者 (leader)
        下发移动指令，跟随者 (followers) 由 Console 原有编队控制逻辑自动协同。

        使用前必须先调用 execute_formation_mission 建立编队。

        @param linear_velocity: 线速度（m/s），正=前进，负=后退
        @param angular_velocity: 角速度（rad/s），正=左转，负=右转
        @param duration_ms: 持续时间（毫秒），默认 1000
        @returns: JSON，含 leader_id / controlled_unit
        """
        # 安全检查：是否有活跃且就绪的编队
        passed, err_code, msg = validate_move_formation(
            has_active_formation=active_formation_registry.has_active,
            is_ready=active_formation_registry.is_ready,
        )
        if not passed:
            return _json.dumps({
                "success": False, "message": msg, "error_code": err_code,
            }, ensure_ascii=False)

        formation = active_formation_registry.active
        if formation is None:
            return _json.dumps({
                "success": False,
                "message": "没有活跃编队",
                "error_code": ERR_FORMATION_NOT_READY,
            }, ensure_ascii=False)

        leader_id = formation.leader_id
        all_units = [leader_id] + formation.follower_ids

        # 向编队中所有智能体下发相同的移动指令
        # （Console 当前无编队自动跟随逻辑，需要 MCP 侧显式控制每个单元）
        results: dict[str, bool] = {}
        async def _move_one(uid: str) -> None:
            resp = await adapter.send_move(
                robot_id=uid,
                linear_velocity=linear_velocity,
                angular_velocity=angular_velocity,
                duration_ms=duration_ms,
            )
            try:
                d = _json.loads(resp)
                results[uid] = d.get("success", False)
            except _json.JSONDecodeError:
                results[uid] = False

        await _asyncio.gather(*[_move_one(uid) for uid in all_units])

        # 更新编队状态为 MOVING
        active_formation_registry.update_state(FormationState.MOVING)
        all_ok = all(results.values())

        # 构建响应
        return _json.dumps({
            "success": all_ok,
            "message": f"编队移动: {'全部成功' if all_ok else '部分失败'} ({sum(1 for v in results.values() if v)}/{len(results)})",
            "data": {
                "formation_type": formation.formation_type,
                "leader_id": leader_id,
                "follower_ids": formation.follower_ids,
                "controlled_units": list(results.keys()),
                "unit_results": results,
                "move_params": {
                    "linear_velocity": linear_velocity,
                    "angular_velocity": angular_velocity,
                    "duration_ms": duration_ms,
                },
            },
        }, ensure_ascii=False)

    @mcp.tool
    async def stop_active_formation() -> str:
        """
        【任务级工具】停止当前活跃编队的所有智能体。

        向编队中所有成员（领航者+跟随者）并发下发停止指令。

        @returns: JSON
        """
        formation = active_formation_registry.active
        if formation is not None and formation.is_ready:
            all_units = [formation.leader_id] + formation.follower_ids
            await _asyncio.gather(*[
                adapter.stop_robot(robot_id=uid) for uid in all_units
            ])
            active_formation_registry.update_state(FormationState.IDLE)
            return _json.dumps({
                "success": True,
                "message": f"编队已停止: {all_units}",
                "data": {"stopped_units": all_units},
            }, ensure_ascii=False)

        # 无活跃编队时，全停保险
        result = await adapter.emergency_stop_all()
        return result

    @mcp.tool
    async def get_formation_status() -> str:
        """
        【任务级工具】查询当前编队状态。

        返回活跃编队的完整信息：leader、followers、formation_type、
        编队状态 (IDLE/READY/MOVING/FAILED 等)。

        @returns: JSON，含 formation 状态摘要
        """
        status = active_formation_registry.get_status_dict()

        # 如果有活跃编队，附加各智能体的实时状态
        formation = active_formation_registry.active
        if formation is not None and formation.is_active:
            unit_states: list[dict] = []
            for uid in formation.all_unit_ids:
                resp = await adapter.get_robot_status(robot_id=uid)
                try:
                    sdata = _json.loads(resp)
                    unit_states.append({
                        "unit_id": uid,
                        "role": "leader" if uid == formation.leader_id else "follower",
                        "online": sdata.get("success", False),
                        "data": sdata.get("data") if sdata.get("success") else None,
                    })
                except _json.JSONDecodeError:
                    unit_states.append({
                        "unit_id": uid,
                        "role": "leader" if uid == formation.leader_id else "follower",
                        "online": False,
                    })
            status["unit_states"] = unit_states

        return _json.dumps({
            "success": True,
            "message": "ok",
            "data": status,
        }, ensure_ascii=False)

    @mcp.tool
    async def cancel_formation_mission(task_id: str = "") -> str:
        """
        【任务级工具】取消编队任务并回滚配置。

        取消正在执行的编队任务，自动回滚已设置的 leader/follower/formation 配置。
        如果 task_id 为空，则取消当前活跃编队。

        回滚步骤:
        1. 重置所有编队关系 (reset_unit_relations)
        2. 恢复默认编队模式 (set_group_mode=none)

        @param task_id: 要取消的任务 ID；空=取消当前活跃编队
        @returns: JSON
        """
        tid = task_id.strip()

        if tid:
            # 取消指定任务
            rec = task_manager.get_task(tid)
            if rec is None:
                return _json.dumps({
                    "success": False,
                    "message": f"任务 {tid} 不存在",
                    "error_code": "TASK_NOT_FOUND",
                }, ensure_ascii=False)

            if _formation_orchestrator is not None:
                _formation_orchestrator.request_cancel()
            await adapter.cancel_task(task_id=tid)
            task_manager.cancel_task(tid, "用户取消编队任务")

            return _json.dumps({
                "success": True,
                "message": f"编队任务 {tid} 已取消",
                "data": {"task_id": tid, "state": "CANCELLED"},
            }, ensure_ascii=False)

        # 取消当前活跃编队
        formation = active_formation_registry.active
        if formation is None or not formation.is_active:
            return _json.dumps({
                "success": True,
                "message": "没有活跃编队需要取消",
                "data": {"has_active_formation": False},
            }, ensure_ascii=False)

        ftask_id = formation.task_id

        if _formation_orchestrator is not None:
            result = await _formation_orchestrator.rollback_current(
                ftask_id, "用户取消编队任务"
            )
            return result.to_json()

        # 兜底：直接重置
        await adapter.reset_unit_relations()
        await adapter.set_group_mode(mode="none")
        active_formation_registry.clear()

        return _json.dumps({
            "success": True,
            "message": "编队已取消，集群关系已重置",
            "data": {"state": "CANCELLED"},
        }, ensure_ascii=False)

    return mcp


app = create_app()


if __name__ == "__main__":
    setup_logging(log_file=LOG_FILE, level="INFO")
    app.run()
