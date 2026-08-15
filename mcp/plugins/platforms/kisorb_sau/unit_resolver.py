from __future__ import annotations

import json

from robot_adapter import RobotAdapter
from swarm_runtime.models import UnitDescriptor


class KisorbLiveUnitResolver:
    resolver_id = "kisorb.live"
    priority = 100

    def __init__(self, adapter: RobotAdapter) -> None:
        self._adapter = adapter

    async def resolve(self, unit_id: str) -> UnitDescriptor | None:
        requested_unit_id = unit_id.strip()
        if not requested_unit_id:
            return None

        raw_directory = await self._adapter.list_robots()
        try:
            payload = json.loads(raw_directory)
        except (TypeError, json.JSONDecodeError):
            return None

        if not isinstance(payload, dict) or payload.get("success") is not True:
            return None
        data = payload.get("data")
        if not isinstance(data, dict):
            return None
        units = data.get("units")
        if not isinstance(units, list):
            return None

        requested_key = requested_unit_id.casefold()
        for item in units:
            if not isinstance(item, dict):
                continue
            raw_unit_id = item.get("unit_id")
            if not isinstance(raw_unit_id, str):
                continue
            canonical_unit_id = raw_unit_id.strip()
            if not canonical_unit_id:
                continue
            if canonical_unit_id.casefold() == requested_key:
                return UnitDescriptor(
                    unit_id=canonical_unit_id,
                    kind="ugv",
                    platform="kisorb-sau",
                    provider_plugin_id="platform.kisorb-sau",
                    metadata={"source": "console-live"},
                )
        return None
