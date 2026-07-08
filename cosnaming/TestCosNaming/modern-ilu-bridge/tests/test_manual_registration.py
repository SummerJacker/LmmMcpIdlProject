from modern_ilu_bridge.manual_registration import build_manual_legacy_record


def test_build_manual_record_for_java_ilu_sbh_service():
    record = build_manual_legacy_record(
        name="legacy.hello-world.java",
        language="java",
        protocol="ilu-sbh",
        interface_name="hello_world.service",
        endpoint="ilusbh:java-example",
        methods=["hello_world"],
        metadata={"owner": "lab"},
    )

    assert record.name == "legacy.hello-world.java"
    assert record.language == "java"
    assert record.protocol == "ilu-sbh"
    assert record.endpoint == "ilusbh:java-example"
    assert record.methods == ("hello_world",)
    assert record.metadata["owner"] == "lab"
    assert record.metadata["registration"] == "manual"


def test_manual_record_rejects_unknown_language():
    try:
        build_manual_legacy_record(
            name="legacy.hello-world.ruby",
            language="ruby",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:ruby-example",
            methods=["hello_world"],
        )
    except ValueError as exc:
        assert "Unsupported language" in str(exc)
    else:
        raise AssertionError("unknown language should fail")

