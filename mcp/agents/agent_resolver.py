"""
Agent identifier resolver.

Resolves any user-facing name (robot_id, unit_id, alias) to the canonical
Qt unit_id by consulting the live agent directory, respecting a short-lived
cache to avoid excessive HTTP round-trips.
"""

from __future__ import annotations

import asyncio
import time

from utils.logging_setup import get_logger


class AgentResolver:
    """Resolves agent identifiers to canonical unit_id.

    Resolution order (first match wins):
      1. Exact match against a Qt unit_id in the current directory.
      2. Match against a Qt persistent alias.
      3. Match robots.json ``robot_id`` -> ``unit_id``.
      4. Not found -> return ``None``.

    The directory listing is cached for *cache_ttl* seconds (default 2.0 s).
    On a cache miss the resolver forces a single refresh.  Callers can also
    explicitly invalidate the cache (e.g. after an alias change).
    """

    def __init__(self, api_client, robot_manager) -> None:
        """@param api_client: :class:`AgentApiClient` instance.
        @param robot_manager: :class:`RobotInstanceManager` instance (for robots.json fallback).
        """
        self._api = api_client
        self._robot_manager = robot_manager
        self._cache: dict | None = None
        self._cache_at: float = 0.0
        self._cache_ttl: float = 2.0  # 2000 ms
        self._lock = asyncio.Lock()
        self._logger = get_logger("AgentResolver")

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    async def resolve(self, name: str) -> str | None:
        """Resolve *name* to a canonical Qt ``unit_id``.

        @param name: robot_id, unit_id, or alias.
        @returns: unit_id string, or ``None`` if unresolvable.
        """
        key = name.strip()
        if not key:
            return None

        # 1. Try cache first
        directory = await self._ensure_cache(force=False)
        uid = self._resolve_from_directory(key, directory)
        if uid is not None:
            return uid

        # 2. Cache miss -- force one refresh and retry
        directory = await self._ensure_cache(force=True)
        uid = self._resolve_from_directory(key, directory)
        if uid is not None:
            return uid

        # 3. Fallback: robots.json robot_id -> unit_id
        uid = self._robot_manager.unit_id_for(key)
        if uid is not None:
            self._logger.debug("Resolved '%s' via robots.json -> '%s'", key, uid)
            return uid

        # 4. Check if key is itself a known unit_id in robots.json
        #    (inverted lookup: canonical_robot_id style)
        for rid in self._robot_manager.configured_robot_ids():
            if self._robot_manager.unit_id_for(rid) == key:
                self._logger.debug("Resolved '%s' as direct unit_id from robots.json", key)
                return key

        self._logger.debug("Unable to resolve agent identifier '%s'", key)
        return None

    async def invalidate_cache(self) -> None:
        """Force the next :meth:`resolve` call to refresh the directory."""
        async with self._lock:
            self._cache = None
            self._cache_at = 0.0
            self._logger.debug("Agent directory cache invalidated")

    # ------------------------------------------------------------------
    # Internal
    # ------------------------------------------------------------------

    async def _ensure_cache(self, force: bool = False) -> dict:
        """Return cached directory data, refreshing if stale or forced.

        The returned dict has the shape of the /api/agent/list ``data``
        envelope, i.e. ``{"agents": [...], "summary": {...}}``.

        @param force: If ``True``, skip TTL check and always refresh.
        @returns: directory data dict (may be empty on failure).
        """
        now = time.monotonic()

        # Fast-path: cache is fresh enough
        if not force and self._cache is not None and (now - self._cache_at) < self._cache_ttl:
            return self._cache

        async with self._lock:
            # Double-check inside lock
            if not force and self._cache is not None and (now - self._cache_at) < self._cache_ttl:
                return self._cache

            self._logger.info("Refreshing agent directory cache (force=%s)", force)
            envelope = await self._api.list_agents()

            if envelope.get("success") and isinstance(envelope.get("data"), dict):
                self._cache = envelope["data"]
                self._cache_at = time.monotonic()
                self._logger.debug(
                    "Directory cache populated: %s agents",
                    len(self._cache.get("agents", [])),
                )
                return self._cache

            # On failure, keep stale cache if available; otherwise return empty
            self._logger.warning(
                "Directory refresh failed: %s -- %s",
                envelope.get("message"),
                "keeping stale cache" if self._cache is not None else "no fallback",
            )
            if self._cache is not None:
                return self._cache
            return {"agents": [], "summary": {"total": 0}}

    @staticmethod
    def _resolve_from_directory(key: str, directory: dict) -> str | None:
        """Try to match *key* against the cached directory.

        Resolution order within directory:
          1. Exact unit_id match.
          2. Alias match (case-insensitive, since Qt normalises).

        @param key: candidate identifier.
        @param directory: cache dict with ``agents`` list.
        @returns: unit_id or ``None``.
        """
        agents = directory.get("agents")
        if not isinstance(agents, list):
            return None

        # Pass 1: exact unit_id
        for agent in agents:
            if not isinstance(agent, dict):
                continue
            uid = agent.get("unit_id")
            if isinstance(uid, str) and uid == key:
                return uid

        # Pass 2: alias match (folded for robustness; Qt already normalises)
        key_lower = key.lower()
        for agent in agents:
            if not isinstance(agent, dict):
                continue
            alias = agent.get("alias")
            if isinstance(alias, str) and alias.lower() == key_lower:
                return agent.get("unit_id")

        return None
