"""
ActiveFormation: 活跃编队状态记录。

编队建立后，记录 leader/followers/formation_type，
使得后续移动只需控制领航者，跟随者由 Console 原有编队逻辑协同。
"""

from __future__ import annotations

import time
from dataclasses import dataclass, field
from enum import Enum


class FormationState(str, Enum):
    """编队生命周期状态"""
    IDLE = "IDLE"                       # 无活跃编队
    CHECKING_FLEET = "CHECKING_FLEET"   # 正在检查集群状态
    SELECTING_LEADER = "SELECTING_LEADER"  # 正在选择领航者
    SETTING_LEADER = "SETTING_LEADER"   # 正在设置领航者
    SETTING_FOLLOWERS = "SETTING_FOLLOWERS"  # 正在设置跟随者
    SETTING_FORMATION = "SETTING_FORMATION"  # 正在下发队形参数
    VERIFYING = "VERIFYING"             # 正在验证编队建立
    READY = "READY"                     # 编队已建立，可移动
    MOVING = "MOVING"                   # 编队移动中（控制 leader）
    FAILED = "FAILED"                   # 编队建立失败
    CANCELLED = "CANCELLED"             # 编队已取消
    DISSOLVED = "DISSOLVED"             # 编队已解散


@dataclass
class ActiveFormation:
    """
    活跃编队记录。

    保存当前编队的完整状态，包括领航者、跟随者、队形参数。
    全局最多存在一个活跃编队（由 ActiveFormationRegistry 管理）。
    """
    formation_id: str
    formation_type: str  # "line" | "triangle" | "column"
    leader_id: str       # unit_id (如 GV1)
    follower_ids: list[str] = field(default_factory=list)  # unit_id 列表
    state: FormationState = FormationState.IDLE
    spacing_m: float = 1.0
    heading_rad: float = 0.0
    anchor: dict[str, float] = field(default_factory=dict)  # {"x":0,"y":0,"yaw":0}
    task_id: str = ""            # 关联的 TaskManager task_id
    created_at: float = field(default_factory=time.time)
    updated_at: float = field(default_factory=time.time)
    error_message: str = ""
    failed_step: str = ""        # 失败发生在哪一步
    failed_unit: str = ""        # 失败的智能体

    def to_dict(self) -> dict:
        return {
            "formation_id": self.formation_id,
            "formation_type": self.formation_type,
            "state": self.state.value,
            "leader_id": self.leader_id,
            "follower_ids": self.follower_ids,
            "spacing_m": self.spacing_m,
            "heading_rad": self.heading_rad,
            "task_id": self.task_id,
            "created_at": self.created_at,
            "error_message": self.error_message,
            "all_unit_ids": [self.leader_id] + self.follower_ids,
        }

    @property
    def all_unit_ids(self) -> list[str]:
        """所有参与编队的智能体"""
        return [self.leader_id] + self.follower_ids

    @property
    def is_ready(self) -> bool:
        """编队是否已就绪（可移动）"""
        return self.state == FormationState.READY

    @property
    def is_active(self) -> bool:
        """编队是否活跃（非终态）"""
        return self.state not in (
            FormationState.IDLE,
            FormationState.FAILED,
            FormationState.CANCELLED,
            FormationState.DISSOLVED,
        )


class ActiveFormationRegistry:
    """
    活跃编队注册中心。

    单例，管理当前活跃编队。同一时间最多存在一个编队。
    新编队建立时会自动替换旧编队。
    """

    _instance: "ActiveFormationRegistry | None" = None

    def __new__(cls) -> "ActiveFormationRegistry":
        if cls._instance is None:
            cls._instance = super().__new__(cls)
            cls._instance._active: ActiveFormation | None = None
            cls._instance._history: list[ActiveFormation] = []  # 历史编队
        return cls._instance

    @property
    def active(self) -> ActiveFormation | None:
        """当前活跃编队，无则为 None"""
        return self._active

    @property
    def has_active(self) -> bool:
        """是否有活跃编队"""
        return self._active is not None and self._active.is_active

    @property
    def is_ready(self) -> bool:
        """活跃编队是否就绪"""
        return self._active is not None and self._active.is_ready

    def register(self, formation: ActiveFormation) -> None:
        """
        注册新的活跃编队。如果已有活跃编队，先存档旧编队。

        @param formation: 新编队记录
        """
        if self._active is not None and self._active.is_active:
            self._active.state = FormationState.DISSOLVED
            self._archive(self._active)
        self._active = formation

    def update_state(self, state: FormationState) -> None:
        """更新活跃编队状态"""
        if self._active:
            self._active.state = state
            self._active.updated_at = time.time()

    def set_error(self, error_message: str, failed_step: str = "", failed_unit: str = "") -> None:
        """记录错误信息"""
        if self._active:
            self._active.error_message = error_message
            self._active.failed_step = failed_step
            self._active.failed_unit = failed_unit
            self._active.state = FormationState.FAILED
            self._active.updated_at = time.time()

    def clear(self) -> None:
        """清除活跃编队（存档后设为 IDLE）"""
        if self._active:
            self._active.state = FormationState.DISSOLVED
            self._archive(self._active)
            self._active = None

    def get_status_dict(self) -> dict:
        """获取当前编队状态摘要（给 MCP 工具返回）"""
        if self._active is None:
            return {
                "has_active_formation": False,
                "state": FormationState.IDLE.value,
                "message": "No active formation",
            }
        return {
            "has_active_formation": self._active.is_active,
            **self._active.to_dict(),
        }

    def _archive(self, formation: ActiveFormation) -> None:
        """存档历史编队（保留最近 20 个）"""
        self._history.append(formation)
        if len(self._history) > 20:
            self._history = self._history[-20:]

    def get_history(self) -> list[dict]:
        """获取历史编队列表"""
        return [f.to_dict() for f in self._history]


# 全局单例
active_formation_registry = ActiveFormationRegistry()
