"""
MCP tool registration for the agent capability module (Member 3).

Call :func:`register_agent_tools` with the FastMCP instance and a
configured :class:`AgentService` to wire up the five agent tools.
"""

from __future__ import annotations


def register_agent_tools(mcp, agent_service) -> None:
    """Register the 5 agent MCP tools on the given FastMCP instance.

    @param mcp: FastMCP application instance.
    @param agent_service: Configured :class:`AgentService` instance.
    """

    # ------------------------------------------------------------------
    # 1. list_agents
    # ------------------------------------------------------------------
    @mcp.tool
    async def list_agents() -> str:
        """
        List all bound agents registered in the Qt console binding table.

        Each agent includes unit_id, alias, connection state, status freshness,
        run_mode, role, pose, speed, capabilities, and a per-agent robot_id
        annotation from robots.json when available.  A fleet-level summary
        (total, online, offline, unknown, mock, real) is also included.

        @returns: JSON envelope string with ``agents`` list and ``summary``.
        """
        return await agent_service.list_agents()

    # ------------------------------------------------------------------
    # 2. get_agent_status
    # ------------------------------------------------------------------
    @mcp.tool
    async def get_agent_status(agent: str, refresh: bool = True) -> str:
        """
        Query a single agent by robot_id, unit_id, or alias.

        When ``refresh=True`` an active probe is sent (subject to Qt's real-RPC
        gate); when ``False`` only cached state is returned.

        @param agent: robot_id (e.g. robot_1), unit_id (e.g. GV1), or alias (e.g. 先锋车).
        @param refresh: True for active probe, False for cache-only.
        @returns: JSON envelope with agent status fields (pose, speed, connection_state, etc.).
        """
        return await agent_service.get_agent_status(agent=agent, refresh=refresh)

    # ------------------------------------------------------------------
    # 3. get_all_agent_status
    # ------------------------------------------------------------------
    @mcp.tool
    async def get_all_agent_status(refresh: bool = True) -> str:
        """
        Batch-query every agent in the current Qt directory.

        Partial success is allowed: the response ``items`` array has a
        per-agent ``success`` flag so callers can identify which agents
        responded and which did not.

        @param refresh: True for active probe on each agent.
        @returns: JSON envelope with ``items`` list and ``summary`` (total/ok/failed).
        """
        return await agent_service.get_all_agent_status(refresh=refresh)

    # ------------------------------------------------------------------
    # 4. set_agent_alias
    # ------------------------------------------------------------------
    @mcp.tool
    async def set_agent_alias(agent: str, alias: str) -> str:
        """
        Set or rename a human-readable alias for an agent.

        The alias must pass Qt validation rules (no empty names, no control
        characters, max 32 normalised chars, no conflict with existing
        unit_ids, aliases, or robots.json robot_ids).

        Submitting an empty alias string is equivalent to clearing the alias.

        @param agent: robot_id, unit_id, or current alias to target.
        @param alias: new alias string (pass empty to clear).
        @returns: JSON envelope with updated unit_id and alias.
        """
        return await agent_service.set_agent_alias(agent=agent, alias=alias)

    # ------------------------------------------------------------------
    # 5. clear_agent_alias
    # ------------------------------------------------------------------
    @mcp.tool
    async def clear_agent_alias(agent: str) -> str:
        """
        Clear (remove) the alias for an agent.

        After clearing the agent is identified only by its unit_id.

        @param agent: robot_id, unit_id, or current alias to target.
        @returns: JSON envelope confirming the cleared alias.
        """
        return await agent_service.clear_agent_alias(agent=agent)
