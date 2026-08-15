from __future__ import annotations


class RuntimeRegistrationError(Exception):
    """Base error for invalid runtime registration."""


class DuplicateRegistrationError(RuntimeRegistrationError):
    """Raised when a registry key is already owned."""


class RuntimeExecutionError(Exception):
    """Base error mapped to a stable MCP execution failure."""

    def __init__(
        self,
        message: str,
        *,
        error_code: str = "INTERNAL_ERROR",
        rejected: bool = False,
    ) -> None:
        super().__init__(message)
        self.message = message
        self.error_code = error_code
        self.rejected = rejected


class RuntimeResolutionError(RuntimeExecutionError):
    """Base for failures that reject a request before provider execution."""

    def __init__(self, message: str, *, error_code: str) -> None:
        super().__init__(message, error_code=error_code, rejected=True)


class UnitNotFoundError(RuntimeResolutionError):
    def __init__(self, unit_id: str) -> None:
        super().__init__(f"unit not found: {unit_id}", error_code="UNIT_NOT_FOUND")


class ProviderNotFoundError(RuntimeResolutionError):
    def __init__(self, capability: str, version: str) -> None:
        super().__init__(
            f"no provider for {capability}@{version}",
            error_code="UNSUPPORTED_CAPABILITY",
        )


class AmbiguousProviderError(RuntimeResolutionError):
    def __init__(self, capability: str, version: str) -> None:
        super().__init__(
            f"ambiguous providers for {capability}@{version}",
            error_code="UNSUPPORTED_CAPABILITY",
        )


class PolicyRejectedError(RuntimeResolutionError):
    def __init__(self, message: str) -> None:
        super().__init__(message, error_code="SAFETY_REJECTED")


class PluginLoadError(Exception):
    """Raised when a plugin profile cannot be loaded safely."""
