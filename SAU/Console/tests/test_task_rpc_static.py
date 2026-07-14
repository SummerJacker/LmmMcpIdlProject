from __future__ import annotations

import hashlib
from pathlib import Path


CONSOLE = Path(__file__).resolve().parents[1]
ROOT = CONSOLE.parents[1]

PROTECTED_IDL_HASHES = {
    "air_unit.idl": "73e55f95316369e9e7eb50ca70c71af982315454f34106608fc073926b438865",
    "console.idl": "0143b264b29d6704933d2eba7d0def8e7cb474f335add8173cae1df8701e68d6",
    "general_unit.idl": "2ea533a80f320f007c9357c4485152cdb08e86492ba396f1d15d9387a51cc145",
    "ground_unit.idl": "13736312c1b2c76bf43e9fdb72bc08e418529bc26ae4cb227af853befaee770a",
    "monitor.idl": "9cc056fbdbc86cebee2bd83d2ba4a2cc9c8ede00f163e088441bad7f5db73f07",
}


def read(relative: str) -> str:
    return (CONSOLE / relative).read_text(encoding="utf-8")


def function_body(text: str, signature: str) -> str:
    start = text.index(signature)
    brace = text.index("{", start)
    depth = 0
    for index in range(brace, len(text)):
        if text[index] == "{":
            depth += 1
        elif text[index] == "}":
            depth -= 1
            if depth == 0:
                return text[brace + 1 : index]
    raise AssertionError(f"unterminated function: {signature}")


def test_protected_base_idl_hashes_are_unchanged() -> None:
    idl_dir = CONSOLE.parent / "Ilu" / "interfaces" / "i"
    for name, expected in PROTECTED_IDL_HASHES.items():
        assert hashlib.sha256((idl_dir / name).read_bytes()).hexdigest() == expected


def test_real_navigation_adapter_calls_unchanged_ground_rpc() -> None:
    adapter = read("LegacyIdlAdapter.cpp")
    point = function_body(adapter, "TaskRpcResult LegacyIdlAdapter::setTaskPoint")
    pose = function_body(adapter, "TaskPoseResult LegacyIdlAdapter::currentPose")
    path = function_body(adapter, "TaskRpcResult LegacyIdlAdapter::setTaskPath")
    assert "Ground_Unit_rpc_setTaskPoint" in point
    assert "Ground_Unit_rpc_getCurrentPose" in pose
    assert "Ground_Unit_rpc_setTaskPath" in path


def test_real_path_construction_checks_every_append_error() -> None:
    adapter = read("LegacyIdlAdapter.cpp")
    path = function_body(adapter, "TaskRpcResult LegacyIdlAdapter::setTaskPath")
    append_index = path.index("Ground_Unit_TaskPath_Append")
    error_index = path.index("ILU_ERRNOK(appendError)")
    dispatch_index = path.index("Ground_Unit_rpc_setTaskPath")
    assert append_index < error_index < dispatch_index
    assert "failed to append task path point" in path


def test_single_batch_and_static_routes_share_real_target_dispatch() -> None:
    executor = read("HttpApiExecutor.cpp")
    orchestrator = read("TaskOrchestrator.cpp")
    assert '"/api/task/navigate"' in executor
    assert "TaskOrchestrator::instance().dispatchTarget" in executor
    batch = executor[executor.index('"/api/task/goto_pose_batch"') :]
    assert "dispatchAndTrackTarget" in batch
    static = executor[executor.index('"/api/formation/execute"') :]
    assert "dispatchAndTrackTarget" in static
    dispatch = function_body(orchestrator, "TaskRpcResult TaskOrchestrator::dispatchTarget")
    polling = function_body(orchestrator, "void TaskOrchestrator::startTargetPolling")
    assert "adapter_->setTaskPoint" in dispatch
    assert "adapter_->currentPose" in polling


def test_static_formation_uses_rotation_translation_and_bounds() -> None:
    orchestrator = read("TaskOrchestrator.cpp")
    geometry = function_body(orchestrator, "QJsonArray TaskOrchestrator::staticFormationTargets")
    assert "anchorX + cosHeading * localX - sinHeading * localY" in geometry
    assert "anchorY + sinHeading * localX + cosHeading * localY" in geometry
    assert "qAbs(worldX) > 1000.0" in geometry
    assert "qAbs(worldY) > 1000.0" in geometry


def test_scoped_follow_configures_only_requested_members_and_all_steps() -> None:
    console = read("console.cpp")
    create = function_body(console, "ScopedFollowResult createScopedGroundFollow")
    assert "for (int memberIndex = 0; memberIndex < members.size(); ++memberIndex)" in create
    assert "groundFollowParentIds" in create
    assert "directParentSbh.data()" in create
    assert "setFormationWithResult(follow)" in create
    assert "configureUnitMode(member" in create
    assert "ilu_hash_BeginEnumeration" not in create


def test_scoped_follow_configures_modes_before_rear_vehicle_dispatch() -> None:
    console = read("console.cpp")
    create = function_body(console, "ScopedFollowResult createScopedGroundFollow")
    dispatch_index = create.index("setFormationWithResult(follow)")
    configure_indices = []
    start = 0
    while True:
        index = create.find("configureUnitMode(", start)
        if index < 0:
            break
        configure_indices.append(index)
        start = index + 1

    assert configure_indices
    assert max(configure_indices) < dispatch_index


def test_configure_unit_mode_rejects_false_role_and_leader_results() -> None:
    console = read("console.cpp")
    configure = function_body(console, "static bool configureUnitMode")
    assert "roleResult != ilu_TRUE" in configure
    assert "leaderResult != ilu_TRUE" in configure


def test_cancel_requests_stop_before_state_transition() -> None:
    executor = read("HttpApiExecutor.cpp")
    route = executor[executor.index('"/api/task/cancel"') :]
    stop_index = route.index("TaskOrchestrator::instance().stopUnit")
    cancel_index = route.index("TaskManager::instance().cancelTask")
    assert stop_index < cancel_index
    adapter = read("LegacyIdlAdapter.cpp")
    stop = function_body(adapter, "TaskRpcResult LegacyIdlAdapter::stopUnit")
    assert "Unit_MA_Stop" in stop


def test_uncertain_physical_control_is_quarantined_and_recoverable() -> None:
    manager_header = read("TaskManager.h")
    manager = read("TaskManager.cpp")
    assert "markUnitControlUncertain" in manager_header
    assert "clearUnitControlUncertain" in manager_header
    busy = function_body(manager, "bool TaskManager::isUnitBusyLocked")
    assert "controlUncertainUnits_" in busy

    executor = read("HttpApiExecutor.cpp")
    cancel = executor[executor.index('"/api/task/cancel"') :]
    assert "markUnitControlUncertain" in cancel
    stop = executor[executor.index('"/api/task/stop_units"') :]
    stop = stop[: stop.index('"/api/task/goto_pose_batch"')]
    assert "clearUnitControlUncertain" in stop


def test_navigation_timeout_attempts_stop_before_terminal_release() -> None:
    orchestrator = read("TaskOrchestrator.cpp")
    polling = function_body(orchestrator, "void TaskOrchestrator::startTargetPolling")
    assert "adapter_->stopUnit(unitId)" in polling
    assert "markUnitControlUncertain" in polling


def test_disband_does_not_hide_leader_stop_failure() -> None:
    executor = read("HttpApiExecutor.cpp")
    disband = executor[executor.index('"/api/task/formation/follow/disband"') :]
    disband = disband[: disband.index('"/api/task/stop_units"')]
    assert "leaderStopSafe" in disband
    assert "markUnitControlUncertain" in disband
    assert "cleared.success && leaderStopSafe" in disband


def test_task_manager_has_atomic_task_and_formation_reservations() -> None:
    manager = read("TaskManager.cpp")
    create = function_body(manager, "QString TaskManager::createTaskIfUnitsAvailable")
    reserve = function_body(manager, "bool TaskManager::reserveUnitsIfAvailable")
    busy = function_body(manager, "bool TaskManager::isUnitBusyLocked")
    assert "QMutexLocker" in create
    assert "unitReservations_.insert" in create
    assert "QMutexLocker" in reserve
    assert "isUnitBusyLocked" in reserve
    assert "unitReservations_.contains" in busy


def test_http_transport_preserves_conflict_and_rpc_disabled_statuses() -> None:
    plugin = read("HttpPlugin.cpp")
    assert 'case 409: reason = QStringLiteral("Conflict")' in plugin
    assert 'case 503: reason = QStringLiteral("Service Unavailable")' in plugin


def test_follow_owner_survives_legacy_dispatch_and_failed_cleanup_stays_reserved() -> None:
    console = read("console.cpp")
    scoped = function_body(console, "ScopedFollowResult createScopedGroundFollow")
    assert "formationOwnerId = consoleFollowFormationRecord.ownerId" in scoped
    assert "consoleFollowFormationRecord.ownerId = formationOwnerId" in scoped
    executor = read("HttpApiExecutor.cpp")
    disband = executor[executor.index('"/api/task/formation/follow/disband"') :]
    assert "const bool fullyDisbanded = cleared.success && leaderStopSafe;" in disband
    assert "if (fullyDisbanded)\n            TaskManager::instance().releaseReservations(ownerId);" in disband


def test_follow_move_terminal_state_is_event_driven() -> None:
    executor = read("HttpApiExecutor.cpp")
    constructor = function_body(executor, "HttpApiExecutor::HttpApiExecutor")
    assert "taskStateChanged" in constructor
    assert 'state == QStringLiteral("CANCELLED")' in constructor
    assert 'consoleFollowFormationRecord.state = QStringLiteral("READY")' in constructor


def test_follow_path_enforces_coordinate_and_timeout_bounds() -> None:
    executor = read("HttpApiExecutor.cpp")
    route = executor[executor.index('"/api/task/follow_path"') :]
    assert "timeoutMs > 600000" in route
    assert "qAbs(x) > 1000.0" in route
    assert "qAbs(y) > 1000.0" in route


def test_follow_routes_apply_authoritative_numeric_safety_checks() -> None:
    executor = read("HttpApiExecutor.cpp")
    create = executor[executor.index('"/api/task/formation/follow/create"') :]
    create = create[: create.index('"/api/task/formation/follow/move"')]
    move = executor[executor.index('"/api/task/formation/follow/move"') :]
    move = move[: move.index('"/api/task/formation/follow/status"')]
    assert "SafetyValidator::isFollowDistanceAllowed" in create
    assert "SafetyValidator::isTaskTargetInBounds" in move


def test_ground_formation_requires_vehicle_acceptance() -> None:
    console = read("console.cpp")
    dispatch = function_body(console, "static GroupResult _setGroundFormation")
    assert "CORBA_boolean formationAccepted" in dispatch
    assert "formationAccepted != ilu_TRUE" in dispatch


def test_follow_cleanup_checks_role_reset_acceptance() -> None:
    console = read("console.cpp")
    cleanup = function_body(console, "ScopedFollowResult clearScopedGroundFollow")
    assert "roleResult" in cleanup
    assert "roleResult != ilu_TRUE" in cleanup


def test_task_capabilities_only_report_executable_ground_units() -> None:
    header = read("TaskOrchestrator.h")
    orchestrator = read("TaskOrchestrator.cpp")
    executor = read("HttpApiExecutor.cpp")
    assert "struct TaskCapabilityPolicy" in header
    assert "TaskOrchestrator::capabilityPolicy" in orchestrator
    capability_route = executor[executor.index('"/api/task/capabilities"') :]
    capability_route = capability_route[: capability_route.index('"/api/task/navigate"')]
    assert "TaskOrchestrator::capabilityPolicy" in capability_route
    assert "mockCount + (realRpcEnabled ? realCount : 0)" in orchestrator


def test_follow_creation_resolves_logical_unit_aliases_to_canonical_ids() -> None:
    adapter_header = read("LegacyIdlAdapter.h")
    executor = read("HttpApiExecutor.cpp")
    assert "canonicalUnitId" in adapter_header
    route = executor[executor.index('"/api/task/formation/follow/create"') :]
    route = route[: route.index('"/api/task/formation/follow/move"')]
    assert "canonicalUnitId" in route
    assert "sbhForUid" not in route


def test_real_fleet_online_state_is_not_claimed_without_a_probe() -> None:
    executor = read("HttpApiExecutor.cpp")
    route = executor[executor.index('"/api/task/fleet_snapshot"') :]
    route = route[: route.index('"/api/task/capabilities"')]
    assert "TaskPoseResult probe" in route
    assert "LegacyIdlAdapter::instance().currentPose(unitId)" in route
    assert "online = probe.success" in route
    assert "onlineVerified = true" in route
    assert 'unit.insert(QStringLiteral("online"), online)' in route
    assert 'unit.insert(QStringLiteral("online_verified"), onlineVerified)' in route
    assert 'unit.insert(QStringLiteral("probe_error"), probeError)' in route


def test_follow_preflight_rejects_mock_before_reserving_units() -> None:
    executor = read("HttpApiExecutor.cpp")
    route = executor[executor.index('"/api/task/formation/follow/create"') :]
    route = route[: route.index('"/api/task/formation/follow/move"')]
    assert "TaskOrchestrator::followSetupPolicy" in route
    assert route.index("TaskOrchestrator::followSetupPolicy") < route.index(
        "reserveUnitsIfAvailable"
    )
    assert "UnsupportedMock" in route
    assert "Mock follow control-plane formation READY" not in route


def test_follow_physical_cleanup_state_is_retained_for_retry() -> None:
    record = read("console.h")
    assert "physicalSetupAttempted" in record
    assert "physicalMembers" in record
    assert "errorCode" in record
    executor = read("HttpApiExecutor.cpp")
    disband = executor[executor.index('"/api/task/formation/follow/disband"') :]
    disband = disband[: disband.index('"/api/task/stop_units"')]
    assert "consoleFollowFormationRecord.physicalSetupAttempted" in disband
    assert "consoleFollowFormationRecord.physicalMembers" in disband
    assert "clearScopedGroundFollow(members)" not in disband


def test_follow_setup_reports_internal_rollback_outcome() -> None:
    console_header = read("console.h")
    console = read("console.cpp")
    assert "rollbackSucceeded" in console_header
    create = function_body(console, "ScopedFollowResult createScopedGroundFollow")
    assert "result.physicalSetupAttempted = true" in create
    assert "result.rollbackSucceeded" in create


def test_mock_follow_path_uses_ordered_waypoint_polling() -> None:
    header = read("TaskOrchestrator.h")
    orchestrator = read("TaskOrchestrator.cpp")
    assert "class MockPathProgress" in header
    dispatch = function_body(orchestrator, "TaskRpcResult TaskOrchestrator::dispatchPath")
    assert "if (result.mock)" in dispatch
    assert "startMockPathPolling" in dispatch
    polling = function_body(orchestrator, "void TaskOrchestrator::startMockPathPolling")
    assert "currentTarget" in polling
    assert "advance" in polling


def test_goto_pose_legacy_alias_shares_the_navigate_implementation() -> None:
    executor = read("HttpApiExecutor.cpp")
    route = executor[executor.index('"/api/task/navigate"') :]
    route = route[: route.index('"/api/task/follow_path"')]
    assert '"/api/task/goto_pose"' in route
    assert "taskTypeForNavigateRoute(path)" in route
    assert "TaskOrchestrator::instance().dispatchTarget" in route
    assert "return processRequest" not in route
    assert "Ground_Unit_rpc_setTaskPoint" not in route


def test_task_routes_build_complete_immediate_failure_results() -> None:
    executor = read("HttpApiExecutor.cpp")
    assert "static QJsonObject immediateTaskResult" in executor
    for start_marker, end_marker in (
        ('"/api/task/navigate"', '"/api/task/formation/static"'),
        ('"/api/task/follow_path"', '"/api/task/formation/follow/create"'),
        ('"/api/task/formation/follow/move"', '"/api/task/formation/follow/status"'),
        ('"/api/task/status"', '"/api/task/cancel"'),
    ):
        route = executor[executor.index(start_marker) :]
        route = route[: route.index(end_marker)]
        assert "immediateTaskResult" in route


def test_follow_creation_failures_keep_full_formation_status_shape() -> None:
    executor = read("HttpApiExecutor.cpp")
    assert "currentFollowFormationSnapshot" in executor
    route = executor[executor.index('"/api/task/formation/follow/create"') :]
    route = route[: route.index('"/api/task/formation/follow/move"')]
    assert "currentFollowFormationSnapshot" in route
    assert "QJsonValue::Null" not in route


def test_static_formation_and_stop_validation_return_task_results() -> None:
    executor = read("HttpApiExecutor.cpp")
    static_route = executor[executor.rindex('"/api/formation/execute"') :]
    static_route = static_route[: static_route.index('"/api/task/status"')]
    assert "immediateTaskResult" in static_route
    stop_route = executor[executor.index('"/api/task/stop_units"') :]
    stop_route = stop_route[: stop_route.index('"/api/task/goto_pose_batch"')]
    assert "immediateTaskResult" in stop_route
