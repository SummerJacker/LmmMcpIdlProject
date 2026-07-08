from modern_ilu_bridge.registry_store import RegistryStore, ServiceRecordData


def test_register_and_discover_legacy_c_service():
    store = RegistryStore(now=lambda: 100)
    record = ServiceRecordData(
        name="legacy.hello-world.c",
        language="c",
        protocol="ilu-sbh",
        interface_name="hello_world.service",
        endpoint="ilusbh:example",
        methods=("hello_world",),
        metadata={"source": "test"},
    )

    saved = store.register(record)
    found = store.discover("legacy.hello-world.c")

    assert saved.status == "HEALTHY"
    assert saved.last_seen_unix == 100
    assert found == saved
    assert found.language == "c"
    assert found.methods == ("hello_world",)


def test_list_services_can_filter_by_language():
    store = RegistryStore(now=lambda: 100)
    store.register(
        ServiceRecordData(
            name="legacy.hello-world.c",
            language="c",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:c",
            methods=("hello_world",),
        )
    )
    store.register(
        ServiceRecordData(
            name="legacy.hello-world.java",
            language="java",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:java",
            methods=("hello_world",),
        )
    )

    c_services = store.list_services(language="c")

    assert [service.name for service in c_services] == ["legacy.hello-world.c"]


def test_heartbeat_updates_existing_service_timestamp():
    times = iter([100, 250])
    store = RegistryStore(now=lambda: next(times))
    store.register(
        ServiceRecordData(
            name="legacy.hello-world.c",
            language="c",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:c",
            methods=("hello_world",),
        )
    )

    updated = store.heartbeat("legacy.hello-world.c")

    assert updated.last_seen_unix == 250
    assert updated.status == "HEALTHY"


def test_deregister_removes_service():
    store = RegistryStore(now=lambda: 100)
    store.register(
        ServiceRecordData(
            name="legacy.hello-world.c",
            language="c",
            protocol="ilu-sbh",
            interface_name="hello_world.service",
            endpoint="ilusbh:c",
            methods=("hello_world",),
        )
    )

    assert store.deregister("legacy.hello-world.c") is True
    assert store.discover("legacy.hello-world.c") is None


def test_supported_legacy_languages_are_validated():
    store = RegistryStore(now=lambda: 100)

    for language in ("c", "java", "python", "lisp", "modern"):
        store.register(
            ServiceRecordData(
                name=f"service.{language}",
                language=language,
                protocol="ilu-sbh" if language != "modern" else "grpc",
                interface_name="hello_world.service",
                endpoint=f"endpoint:{language}",
                methods=("hello_world",),
            )
        )

    invalid = ServiceRecordData(
        name="service.ruby",
        language="ruby",
        protocol="ilu-sbh",
        interface_name="hello_world.service",
        endpoint="endpoint:ruby",
        methods=("hello_world",),
    )

    try:
        store.register(invalid)
    except ValueError as exc:
        assert "Unsupported language" in str(exc)
    else:
        raise AssertionError("invalid language should fail")

