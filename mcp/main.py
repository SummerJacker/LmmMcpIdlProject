"""
FastMCP 服务主入口。

职责：通过 stdio 暴露 MCP 工具；HTTP 转发至 SAU 主控台 HttpPlugin（默认 127.0.0.1:9001）。
"""

from __future__ import annotations

from fastmcp import FastMCP

from config import DEFAULT_TOOL_TIMEOUT_S, LOG_FILE, QT_HTTP_BASE
from robot_adapter import RobotAdapter
from utils.logging_setup import setup_logging
from agents import AgentApiClient, AgentResolver, AgentService, register_agent_tools


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

    return mcp


app = create_app()


if __name__ == "__main__":
    setup_logging(log_file=LOG_FILE, level="INFO")
    app.run()
