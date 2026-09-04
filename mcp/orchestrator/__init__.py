"""
MCP-Console Task Orchestration Layer.

任务级编排模块：将 Console 中多个底层操作封装为完整的任务工作流。
大模型只调用任务级工具，内部自动完成多步 Console 操作。

包含:
- FormationMissionOrchestrator: 编队任务编排器（状态机驱动）
- TaskManager: 任务状态追踪与子步骤管理
- ActiveFormation: 活跃编队状态记录
"""

from orchestrator.task_manager import TaskManager, TaskState, SubStep, task_manager
from orchestrator.active_formation import ActiveFormation, FormationState, active_formation_registry
from orchestrator.formation_mission import (
    FormationMissionOrchestrator,
    FormationMissionState,
    FormationMissionResult,
    formation_mission_orchestrator,
)

__all__ = [
    "TaskManager",
    "TaskState",
    "SubStep",
    "task_manager",
    "ActiveFormation",
    "FormationState",
    "active_formation_registry",
    "FormationMissionOrchestrator",
    "FormationMissionState",
    "FormationMissionResult",
    "formation_mission_orchestrator",
]
