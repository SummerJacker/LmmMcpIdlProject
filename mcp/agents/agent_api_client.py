"""
HTTP client for Qt /api/agent/* endpoints.

Uses asyncio.to_thread(http_request, ...) to bridge the synchronous
qt_http_client into async context, following the same pattern as RobotAdapter._run_http.
"""

from __future__ import annotations

import asyncio
from urllib.parse import quote

from qt_http_client import http_request
from utils.logging_setup import get_logger


class AgentApiClient:
    """HTTP client for the Qt agent management API.

    Each method returns the parsed JSON envelope dict from Qt.
    On transport failure or HTTP error the returned dict has
    ``{"success": False, "message": "..."}``.
    """

    def __init__(self, base_url: str = "http://127.0.0.1:9001", timeout: float = 5.0) -> None:
        self._base_url = base_url.rstrip("/")
        self._timeout = timeout
        self._logger = get_logger("AgentApiClient")

    # ------------------------------------------------------------------
    # Public API
    # ------------------------------------------------------------------

    async def list_agents(self) -> dict:
        """GET /api/agent/list -> parsed JSON envelope.

        @returns: dict with ``success``, ``message``, ``data`` keys.
        """
        url = f"{self._base_url}/api/agent/list"
        return await self._get(url)

    async def get_agent_status(self, agent: str, refresh: bool = True) -> dict:
        """GET /api/agent/status?agent=X&refresh=0|1.

        @param agent: unit_id or Qt alias.
        @param refresh: True -> ``refresh=1`` (active probe); False -> ``refresh=0`` (cache only).
        @returns: envelope dict.
        """
        refresh_val = "1" if refresh else "0"
        url = f"{self._base_url}/api/agent/status?agent={quote(agent, safe='')}&refresh={refresh_val}"
        return await self._get(url)

    async def set_alias(self, agent: str, alias: str, reserved_names: list[str] | None = None) -> dict:
        """POST /api/agent/alias/set.

        @param agent: unit_id or current alias.
        @param alias: new alias (empty string means clear).
        @param reserved_names: extra names to reserve against conflicts.
        @returns: envelope dict.
        """
        url = f"{self._base_url}/api/agent/alias/set"
        body: dict = {"agent": agent, "alias": alias}
        if reserved_names is not None:
            body["reserved_names"] = reserved_names
        return await self._post(url, body)

    async def clear_alias(self, agent: str) -> dict:
        """POST /api/agent/alias/clear.

        @param agent: unit_id or current alias.
        @returns: envelope dict.
        """
        url = f"{self._base_url}/api/agent/alias/clear"
        return await self._post(url, {"agent": agent})

    # ------------------------------------------------------------------
    # Internal helpers
    # ------------------------------------------------------------------

    async def _get(self, url: str) -> dict:
        return await self._run_http("GET", url, None)

    async def _post(self, url: str, body: dict) -> dict:
        return await self._run_http("POST", url, body)

    async def _run_http(self, method: str, url: str, json_body: dict | None) -> dict:
        """Execute an HTTP call via thread pool and return the parsed envelope.

        On any transport or parsing failure the returned dict is a synthetic
        ``{"success": False, "message": "..."}`` envelope so callers always
        receive a dict they can safely dereference.

        @param method: ``"GET"`` or ``"POST"``.
        @param url: full URL (query params already encoded).
        @param json_body: JSON body for POST; ``None`` for GET.
        @returns: envelope dict.
        """
        try:
            status, resp_body, err = await asyncio.to_thread(
                http_request,
                method=method,
                url=url,
                json_body=json_body,
                timeout=self._timeout,
            )
        except Exception as exc:
            self._logger.error("AgentApiClient transport exception url=%s: %s", url, exc)
            return {"success": False, "message": f"HTTP transport error: {exc}"}

        # Transport-level failure (status < 0)
        if status < 0:
            self._logger.error("AgentApiClient transport error url=%s: %s", url, err)
            return {"success": False, "message": err or "HTTP transport error"}

        # Non-JSON or empty body
        if resp_body is None:
            self._logger.error("AgentApiClient empty/non-JSON body url=%s status=%s", url, status)
            return {"success": False, "message": f"Empty or invalid JSON response (HTTP {status})"}

        # HTTP-level error (4xx / 5xx) -- Qt already returns envelope format,
        # but if it doesn't we synthesize one.
        if status >= 400:
            self._logger.warning("AgentApiClient HTTP %s url=%s body=%s", status, url, resp_body)
            # Trust Qt's envelope if present; otherwise wrap.
            if isinstance(resp_body, dict):
                return resp_body
            return {"success": False, "message": f"HTTP {status}", "data": resp_body}

        # Validate envelope shape
        if not isinstance(resp_body, dict):
            return {"success": False, "message": "Unexpected response format"}

        # Ensure "data" is a dict when present (per contract)
        if "data" in resp_body and resp_body["data"] is not None and not isinstance(resp_body["data"], dict):
            self._logger.warning(
                "AgentApiClient non-dict data field url=%s type=%s", url, type(resp_body["data"]).__name__
            )

        return resp_body
