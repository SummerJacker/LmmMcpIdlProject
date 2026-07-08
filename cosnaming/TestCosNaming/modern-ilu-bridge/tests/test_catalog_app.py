from modern_ilu_bridge.apps.catalog import format_summary_rows
from modern_ilu_bridge.legacy_catalog import LegacyCatalogSummary


def test_format_summary_rows_shows_ready_and_missing_state():
    rows = format_summary_rows(
        [
            LegacyCatalogSummary(
                name="legacy.hello-world.c",
                language="c",
                interface_name="hello_world.service",
                methods=("hello_world",),
                ready=True,
                reason="ready",
                service_dir="c-dir",
            ),
            LegacyCatalogSummary(
                name="legacy.hello-world.java",
                language="java",
                interface_name="hello_world.service",
                methods=("hello_world",),
                ready=False,
                reason="missing command: java",
                service_dir="java-dir",
            ),
        ]
    )

    assert "legacy.hello-world.c" in rows
    assert "READY" in rows
    assert "legacy.hello-world.java" in rows
    assert "MISSING" in rows
    assert "missing command: java" in rows

