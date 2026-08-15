from __future__ import annotations

import logging
from typing import TYPE_CHECKING

from .errors import (
    PolicyRejectedError,
    ProviderNotFoundError,
    RuntimeExecutionError,
)
from .models import ExecutionRequest, ExecutionResult, PolicyDecision

if TYPE_CHECKING:
    from .context import SwarmContext


class CapabilityExecutor:
    def __init__(self, ctx: "SwarmContext") -> None:
        self._ctx = ctx
        self._logger = logging.getLogger("swarm_runtime.executor")

    async def execute(self, request: ExecutionRequest) -> ExecutionResult:
        try:
            self._ctx.capabilities.get(request.capability, request.version)
        except KeyError as exc:
            raise ProviderNotFoundError(request.capability, request.version) from exc

        units = tuple(self._ctx.units.resolve(unit_id) for unit_id in request.unit_ids)
        provider = self._ctx.providers.resolve(
            request.capability, request.version, units
        )

        for policy in self._ctx.policies.matching(request):
            try:
                outcome = await policy.evaluate(request, units, provider)
            except Exception as exc:
                raise PolicyRejectedError(
                    f"policy {policy.policy_id} failed closed"
                ) from exc
            if outcome.decision is PolicyDecision.DENY:
                raise PolicyRejectedError(
                    outcome.message or f"policy {policy.policy_id} denied request"
                )

        try:
            return await provider.execute(request, units)
        except RuntimeExecutionError:
            raise
        except Exception as exc:
            self._logger.exception(
                "provider execution failed",
                extra={"request_id": request.request_id},
            )
            raise RuntimeExecutionError("capability execution failed") from exc
