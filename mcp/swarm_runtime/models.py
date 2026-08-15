from __future__ import annotations

import json
from dataclasses import dataclass, field
from enum import Enum
from typing import Any, Awaitable, Callable, Mapping


@dataclass(frozen=True)
class UnitDescriptor:
    unit_id: str
    kind: str
    platform: str
    provider_plugin_id: str
    aliases: tuple[str, ...] = ()
    metadata: Mapping[str, Any] = field(default_factory=dict)


@dataclass(frozen=True)
class CapabilitySpec:
    name: str
    version: str
    description: str
    scope: str
    tool_name: str | None = None


@dataclass(frozen=True)
class ExecutionRequest:
    request_id: str
    capability: str
    version: str
    unit_ids: tuple[str, ...]
    arguments: Mapping[str, Any]
    metadata: Mapping[str, Any] = field(default_factory=dict)


@dataclass(frozen=True)
class ExecutionResult:
    success: bool
    message: str
    data: Any = None
    error_code: str = ""

    @classmethod
    def from_json(cls, raw: str) -> "ExecutionResult":
        payload = json.loads(raw)
        if not isinstance(payload, dict):
            raise ValueError("provider response must be a JSON object")
        return cls(
            success=bool(payload.get("success", False)),
            message=str(payload.get("message", "")),
            data=payload.get("data"),
            error_code=str(payload.get("error_code", "") or ""),
        )

    def to_json(self) -> str:
        payload = {
            "success": self.success,
            "message": self.message,
            "data": self.data,
        }
        if self.error_code:
            payload["error_code"] = self.error_code
        return json.dumps(payload, ensure_ascii=False)


@dataclass(frozen=True)
class ToolSpec:
    name: str
    callable: Callable[..., Awaitable[str]]


class PolicyDecision(str, Enum):
    ALLOW = "ALLOW"
    DENY = "DENY"
    ABSTAIN = "ABSTAIN"


@dataclass(frozen=True)
class PolicyOutcome:
    decision: PolicyDecision
    message: str = ""
