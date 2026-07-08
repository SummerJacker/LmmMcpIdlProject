"""
TaskManager: 任务状态追踪与子步骤管理。

支持:
- 任务生命周期状态机 (PENDING → RUNNING → COMPLETED / FAILED / CANCELLED)
- 子步骤 (SubStep) 追踪，精确到每一步
- 回滚操作记录
- 任务取消与清理
"""

from __future__ import annotations

import time
import uuid
from dataclasses import dataclass, field
from enum import Enum
from typing import Any, Callable


class TaskState(str, Enum):
    """任务主状态（MCP 层可见）"""
    PENDING = "PENDING"
    RUNNING = "RUNNING"
    COMPLETED = "COMPLETED"
    FAILED = "FAILED"
    PARTIAL_COMPLETED = "PARTIAL_COMPLETED"
    TIMEOUT = "TIMEOUT"
    CANCELLED = "CANCELLED"
    REJECTED = "REJECTED"


class SubStepState(str, Enum):
    """子步骤状态"""
    PENDING = "PENDING"
    IN_PROGRESS = "IN_PROGRESS"
    COMPLETED = "COMPLETED"
    FAILED = "FAILED"
    SKIPPED = "SKIPPED"
    ROLLED_BACK = "ROLLED_BACK"


@dataclass
class SubStep:
    """任务子步骤记录"""
    name: str
    description: str
    state: SubStepState = SubStepState.PENDING
    started_at: float | None = None
    completed_at: float | None = None
    error_message: str = ""
    rollback_action: str = ""  # 回滚操作描述
    rollback_completed: bool = False


@dataclass
class TaskRecord:
    """任务完整记录"""
    task_id: str
    task_type: str  # "formation_mission", "navigation", "patrol"
    state: TaskState = TaskState.PENDING
    sub_steps: list[SubStep] = field(default_factory=list)
    created_at: float = field(default_factory=time.time)
    updated_at: float = field(default_factory=time.time)
    progress_pct: float = 0.0
    message: str = ""
    error_code: str = ""
    result_data: dict[str, Any] = field(default_factory=dict)
    rollback_stack: list[str] = field(default_factory=list)  # 回滚操作栈（后进先执行）

    def to_dict(self) -> dict[str, Any]:
        return {
            "task_id": self.task_id,
            "task_type": self.task_type,
            "state": self.state.value,
            "progress_pct": self.progress_pct,
            "message": self.message,
            "error_code": self.error_code,
            "created_at": self.created_at,
            "updated_at": self.updated_at,
            "sub_steps": [
                {
                    "name": s.name,
                    "description": s.description,
                    "state": s.state.value,
                    "error_message": s.error_message,
                }
                for s in self.sub_steps
            ],
            "data": self.result_data,
        }


class TaskManager:
    """
    任务管理器：创建、追踪、取消、清理任务。

    单例模式，管理所有活跃任务的生命周期。
    """

    _instance: TaskManager | None = None

    def __new__(cls) -> TaskManager:
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance._tasks: dict[str, TaskRecord] = {}
            cls._instance._max_history = 100  # 保留最近 N 个已完成任务
        return cls._instance

    # ------------------------------------------------------------------
    # 任务创建与查询
    # ------------------------------------------------------------------

    def create_task(self, task_type: str, sub_step_names: list[tuple[str, str]] | None = None) -> TaskRecord:
        """
        创建新任务。

        @param task_type: 任务类型标识
        @param sub_step_names: 子步骤列表 [(name, description), ...]
        @returns: TaskRecord
        """
        task_id = f"task_{uuid.uuid4().hex[:12]}"
        sub_steps = []
        if sub_step_names:
            for name, desc in sub_step_names:
                sub_steps.append(SubStep(name=name, description=desc))

        record = TaskRecord(
            task_id=task_id,
            task_type=task_type,
            sub_steps=sub_steps,
        )
        self._tasks[task_id] = record
        self._cleanup_old_tasks()
        return record

    def get_task(self, task_id: str) -> TaskRecord | None:
        """查询任务记录"""
        return self._tasks.get(task_id)

    # ------------------------------------------------------------------
    # 状态转换
    # ------------------------------------------------------------------

    def transition_to(self, task_id: str, state: TaskState, message: str = "") -> TaskRecord:
        """
        转换任务主状态。

        @param task_id: 任务 ID
        @param state: 目标状态
        @param message: 状态说明
        @returns: 更新后的 TaskRecord
        @raises ValueError: 任务不存在
        """
        record = self._tasks.get(task_id)
        if record is None:
            raise ValueError(f"Task {task_id} not found")
        record.state = state
        record.updated_at = time.time()
        record.message = message
        return record

    def start_task(self, task_id: str) -> TaskRecord:
        """标记任务开始执行"""
        return self.transition_to(task_id, TaskState.RUNNING, "Task started")

    def complete_task(self, task_id: str, message: str = "Task completed") -> TaskRecord:
        """标记任务完成"""
        record = self.transition_to(task_id, TaskState.COMPLETED, message)
        record.progress_pct = 100.0
        return record

    def fail_task(self, task_id: str, error_code: str, message: str) -> TaskRecord:
        """标记任务失败"""
        record = self.transition_to(task_id, TaskState.FAILED, message)
        record.error_code = error_code
        return record

    def cancel_task(self, task_id: str, message: str = "Task cancelled") -> TaskRecord:
        """标记任务取消"""
        return self.transition_to(task_id, TaskState.CANCELLED, message)

    # ------------------------------------------------------------------
    # 子步骤管理
    # ------------------------------------------------------------------

    def start_sub_step(self, task_id: str, step_name: str) -> SubStep | None:
        """标记子步骤开始"""
        record = self._tasks.get(task_id)
        if record is None:
            return None
        for s in record.sub_steps:
            if s.name == step_name:
                s.state = SubStepState.IN_PROGRESS
                s.started_at = time.time()
                record.updated_at = time.time()
                return s
        return None

    def complete_sub_step(self, task_id: str, step_name: str) -> SubStep | None:
        """标记子步骤完成"""
        record = self._tasks.get(task_id)
        if record is None:
            return None
        for s in record.sub_steps:
            if s.name == step_name:
                s.state = SubStepState.COMPLETED
                s.completed_at = time.time()
                record.updated_at = time.time()
                self._recalc_progress(record)
                return s
        return None

    def fail_sub_step(self, task_id: str, step_name: str, error: str) -> SubStep | None:
        """标记子步骤失败"""
        record = self._tasks.get(task_id)
        if record is None:
            return None
        for s in record.sub_steps:
            if s.name == step_name:
                s.state = SubStepState.FAILED
                s.error_message = error
                s.completed_at = time.time()
                record.updated_at = time.time()
                return s
        return None

    def skip_sub_step(self, task_id: str, step_name: str, reason: str = "") -> SubStep | None:
        """跳过子步骤（例如已满足条件）"""
        record = self._tasks.get(task_id)
        if record is None:
            return None
        for s in record.sub_steps:
            if s.name == step_name:
                s.state = SubStepState.SKIPPED
                s.error_message = reason
                record.updated_at = time.time()
                return s
        return None

    # ------------------------------------------------------------------
    # 回滚
    # ------------------------------------------------------------------

    def push_rollback(self, task_id: str, action_description: str) -> None:
        """
        压入一个回滚操作。回滚时按 LIFO（后进先出）顺序执行。

        @param task_id: 任务 ID
        @param action_description: 回滚操作描述（如 "clear_leader_for_GV1"）
        """
        record = self._tasks.get(task_id)
        if record:
            record.rollback_stack.append(action_description)

    def get_rollback_actions(self, task_id: str) -> list[str]:
        """获取回滚操作栈（倒序：最后压入的最先执行）"""
        record = self._tasks.get(task_id)
        if record is None:
            return []
        return list(reversed(record.rollback_stack))

    # ------------------------------------------------------------------
    # 内部
    # ------------------------------------------------------------------

    def _recalc_progress(self, record: TaskRecord) -> None:
        """根据已完成的子步骤计算进度百分比"""
        if not record.sub_steps:
            record.progress_pct = 0.0
            return
        completed = sum(
            1 for s in record.sub_steps
            if s.state in (SubStepState.COMPLETED, SubStepState.SKIPPED)
        )
        record.progress_pct = round(completed / len(record.sub_steps) * 100.0, 1)

    def _cleanup_old_tasks(self) -> None:
        """清理超出历史限制的已完成任务"""
        terminal = {TaskState.COMPLETED, TaskState.FAILED, TaskState.CANCELLED, TaskState.REJECTED}
        terminal_tasks = [
            (tid, r) for tid, r in self._tasks.items()
            if r.state in terminal
        ]
        if len(terminal_tasks) > self._max_history:
            terminal_tasks.sort(key=lambda x: x[1].updated_at)
            to_remove = terminal_tasks[:len(terminal_tasks) - self._max_history]
            for tid, _ in to_remove:
                del self._tasks[tid]

    def list_active_tasks(self) -> list[TaskRecord]:
        """列出所有非终态任务"""
        terminal = {TaskState.COMPLETED, TaskState.FAILED, TaskState.CANCELLED, TaskState.REJECTED}
        return [r for r in self._tasks.values() if r.state not in terminal]

    def set_result_data(self, task_id: str, data: dict[str, Any]) -> None:
        """设置任务的返回数据"""
        record = self._tasks.get(task_id)
        if record:
            record.result_data.update(data)
            record.updated_at = time.time()


# 全局单例
task_manager = TaskManager()
