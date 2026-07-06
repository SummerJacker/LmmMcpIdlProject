"""
High-level agent service.

Wraps :class:`AgentApiClient` and :class:`AgentResolver` to provide
directory queries, single/batch status, and alias management.
Every public method returns a JSON string following the
``make_tool_response`` envelope convention.
"""

from __future__ import annotations

import json
import time

from robot_adapter import make_tool_response
from utils.logging_setup import get_logger


class AgentService:
    """High-level service for agent directory and alias operations.

    All methods return JSON strings suitable for direct use as MCP tool
    responses.  The service performs identifier resolution, calls the Qt
    HTTP API, and wraps results in the standard ``{success, message, data}``
    envelope.
    """

    def __init__(self, api_client, resolver) -> None:
        """@param api_client: :class:`AgentApiClient` instance.
        @param resolver: :class:`AgentResolver` instance.
        """
        self._api = api_client
        self._resolver = resolver
        self._logger = get_logger("AgentService")

    # ------------------------------------------------------------------
    # Directory
    # ------------------------------------------------------------------

    async def list_agents(self) -> str:
        """Return JSON string with all bound agents and summary.

        @returns: JSON envelope string.
        """
        envelope = await self._api.list_agents()
        if not envelope.get("success"):
            return make_tool_response(
                success=False,
                message=str(envelope.get("message", "Failed to list agents")),
                data=envelope.get("data"),
            )

        data = envelope.get("data") or {}
        agents = data.get("agents", [])
        summary = data.get("summary", {})

        # Annotate each agent with its robots.json robot_id for legacy
        # compatibility so callers can correlate MCP names with unit_ids.
        enriched: list[dict] = []
        for agent in agents:
            if not isinstance(agent, dict):
                enriched.append(agent)
                continue
            entry = dict(agent)
            uid = entry.get("unit_id", "")
            # Reverse-lookup: find robot_id that maps to this unit_id
            for rid in self._resolver._robot_manager.configured_robot_ids():
                if self._resolver._robot_manager.unit_id_for(rid) == uid:
                    entry["robot_id"] = rid
                    break
            enriched.append(entry)

        return make_tool_response(
            success=True,
            message="ok",
            data={
                "schema_version": data.get("schema_version", "1.0"),
                "generated_at_ms": data.get("generated_at_ms", int(time.time() * 1000)),
                "agents": enriched,
                "summary": summary,
            },
        )

    # ------------------------------------------------------------------
    # Single agent status
    # ------------------------------------------------------------------

    async def get_agent_status(self, agent: str, refresh: bool = True) -> str:
        """Get single agent status as JSON string.

        Resolves *agent* through :class:`AgentResolver` before calling Qt.

        @param agent: robot_id, unit_id, or alias.
        @param refresh: ``True`` for active probe, ``False`` for cache-only.
        @returns: JSON envelope string.
        """
        uid = await self._resolver.resolve(agent)
        if uid is None:
            return make_tool_response(
                success=False,
                message=f"agent_not_found: could not resolve '{agent}' to any known unit_id or alias",
            )

        envelope = await self._api.get_agent_status(uid, refresh=refresh)
        if not envelope.get("success"):
            return make_tool_response(
                success=False,
                message=str(envelope.get("message", "Failed to get agent status")),
                data=envelope.get("data"),
            )

        return make_tool_response(
            success=True,
            message="ok",
            data=envelope.get("data"),
        )

    # ------------------------------------------------------------------
    # Batch status (all agents)
    # ------------------------------------------------------------------

    async def get_all_agent_status(self, refresh: bool = True) -> str:
        """Batch status for every agent in the directory.

        Partial success is allowed -- each item carries its own success flag
        so callers can distinguish which agents responded.

        @param refresh: ``True`` for active probe on each agent.
        @returns: JSON envelope string with ``items`` list and ``summary``.
        """
        # Always get a fresh directory so we know who to query
        await self._resolver.invalidate_cache()
        # Force-resolve to populate the cache from the live directory
        # (we do this by calling the raw list and extracting unit_ids)
        list_env = await self._api.list_agents()
        if not list_env.get("success"):
            return make_tool_response(
                success=False,
                message=str(list_env.get("message", "Cannot list agents for batch status")),
                data=list_env.get("data"),
            )

        data = list_env.get("data") or {}
        agents = data.get("agents", [])
        if not agents:
            return make_tool_response(
                success=True,
                message="ok",
                data={"items": [], "summary": {"total": 0, "ok": 0, "failed": 0}},
            )

        items: list[dict] = []
        ok_count = 0

        for agent in agents:
            if not isinstance(agent, dict):
                continue
            uid = agent.get("unit_id", "")
            if not uid:
                continue
            envelope = await self._api.get_agent_status(uid, refresh=refresh)
            success = bool(envelope.get("success"))
            if success:
                ok_count += 1
            items.append(
                {
                    "agent_input": uid,
                    "success": success,
                    "message": str(envelope.get("message", "")),
                    "data": envelope.get("data"),
                }
            )

        total = len(items)
        return make_tool_response(
            success=(ok_count == total) if total > 0 else True,
            message="ok" if ok_count == total else "partial",
            data={
                "items": items,
                "summary": {"total": total, "ok": ok_count, "failed": total - ok_count},
            },
        )

    # ------------------------------------------------------------------
    # Alias management
    # ------------------------------------------------------------------

    async def set_agent_alias(self, agent: str, alias: str) -> str:
        """Set or rename an agent alias.

        Submits ALL ``robot_id`` values from robots.json as
        ``reserved_names`` to prevent alias conflicts with legacy names.

        @param agent: robot_id, unit_id, or current alias.
        @param alias: new alias string (empty to clear).
        @returns: JSON envelope string.
        """
        uid = await self._resolver.resolve(agent)
        if uid is None:
            return make_tool_response(
                success=False,
                message=f"agent_not_found: could not resolve '{agent}' to any known unit_id or alias",
            )

        # Collect all robot_ids from robots.json as reserved_names
        reserved = list(self._resolver._robot_manager.configured_robot_ids())

        envelope = await self._api.set_alias(uid, alias, reserved_names=reserved)
        if not envelope.get("success"):
            return make_tool_response(
                success=False,
                message=str(envelope.get("message", "Failed to set alias")),
                data=envelope.get("data"),
            )

        # Cache is now stale -- invalidate so next resolve sees the new alias
        await self._resolver.invalidate_cache()

        return make_tool_response(
            success=True,
            message="ok",
            data=envelope.get("data"),
        )

    async def clear_agent_alias(self, agent: str) -> str:
        """Clear an agent's alias.

        @param agent: robot_id, unit_id, or current alias.
        @returns: JSON envelope string.
        """
        uid = await self._resolver.resolve(agent)
        if uid is None:
            return make_tool_response(
                success=False,
                message=f"agent_not_found: could not resolve '{agent}' to any known unit_id or alias",
            )

        envelope = await self._api.clear_alias(uid)
        if not envelope.get("success"):
            return make_tool_response(
                success=False,
                message=str(envelope.get("message", "Failed to clear alias")),
                data=envelope.get("data"),
            )

        # Cache is now stale
        await self._resolver.invalidate_cache()

        return make_tool_response(
            success=True,
            message="ok",
            data=envelope.get("data"),
        )
