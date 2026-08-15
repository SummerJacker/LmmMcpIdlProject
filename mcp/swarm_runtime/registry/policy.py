from __future__ import annotations

from ..errors import DuplicateRegistrationError, RuntimeRegistrationError
from ..models import ExecutionRequest
from ..protocols import ExecutionPolicy
from ..registration import RegistrationJournal


class PolicyRegistry:
    def __init__(self, journal: RegistrationJournal) -> None:
        self._journal = journal
        self._policies: dict[str, ExecutionPolicy] = {}

    def register(self, policy: ExecutionPolicy) -> None:
        if not policy.policy_id.strip():
            raise RuntimeRegistrationError("policy_id must not be empty")
        if policy.policy_id in self._policies:
            raise DuplicateRegistrationError(
                f"policy already registered: {policy.policy_id}"
            )
        self._policies[policy.policy_id] = policy
        self._journal.record(
            f"policy:{policy.policy_id}",
            lambda key=policy.policy_id: self._policies.pop(key, None),
        )

    def matching(self, request: ExecutionRequest) -> tuple[ExecutionPolicy, ...]:
        matched = [
            policy for policy in self._policies.values() if policy.applies_to(request)
        ]
        return tuple(sorted(matched, key=lambda policy: (-policy.priority, policy.policy_id)))
