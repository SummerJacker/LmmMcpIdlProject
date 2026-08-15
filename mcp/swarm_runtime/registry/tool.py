from __future__ import annotations

from ..errors import DuplicateRegistrationError, RuntimeRegistrationError
from ..models import ToolSpec
from ..registration import RegistrationJournal


class ToolRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._tools: dict[str, ToolSpec] = {}

    def register(self, tool: ToolSpec) -> None:
        if not tool.name.strip():
            raise RuntimeRegistrationError("tool name must not be empty")
        if tool.name in self._tools:
            raise DuplicateRegistrationError(f"tool already registered: {tool.name}")
        self._tools[tool.name] = tool
        self._journal.record(
            f"tool:{tool.name}",
            lambda key=tool.name: self._tools.pop(key, None),
        )

    def get(self, name: str) -> ToolSpec:
        return self._tools[name]

    def list(self) -> tuple[ToolSpec, ...]:
        return tuple(self._tools[key] for key in sorted(self._tools))
