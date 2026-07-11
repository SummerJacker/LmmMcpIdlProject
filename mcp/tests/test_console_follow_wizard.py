import json

import pytest

from console_follow_wizard import (
    ConsoleFollowWizardState,
    FollowWizardPhase,
    apply_follow_tool_result,
    begin_follow_wizard,
    handle_follow_wizard_input,
)


def fleet_payload():
    return {
        "success": True,
        "data": {
            "units": [
                {"unit_id": "GV1", "robot_id": "robot_1", "online": True},
                {"unit_id": "GV2", "robot_id": "robot_2", "online": True},
            ]
        },
    }


def three_vehicle_payload():
    payload = fleet_payload()
    payload["data"]["units"].append(
        {"unit_id": "GV3", "robot_id": "robot_3", "online": True}
    )
    return payload


def test_discovery_lists_ground_units_and_asks_for_leader():
    state = ConsoleFollowWizardState()

    result = begin_follow_wizard(state, fleet_payload())

    assert state.phase is FollowWizardPhase.AWAITING_LEADER
    assert state.unit_ids == ["GV1", "GV2"]
    assert "GV1" in result.message and "GV2" in result.message


def test_discovery_accepts_missing_runtime_online_but_rejects_nontrue_values():
    payload = fleet_payload()
    payload["data"]["units"][0].pop("online")
    payload["data"]["units"].extend([
        {"unit_id": "GV3", "online": None},
        {"unit_id": "GV4", "online": 0},
    ])
    state = ConsoleFollowWizardState()

    begin_follow_wizard(state, payload)

    assert state.unit_ids == ["GV1", "GV2"]


def test_two_vehicle_leader_selection_generates_exact_set_leader_call():
    state = ConsoleFollowWizardState()
    begin_follow_wizard(state, fleet_payload())

    result = handle_follow_wizard_input(state, "GV1")

    assert result.tool_name == "set_leader"
    assert result.tool_args == {"robot_id": "GV1"}
    assert state.leader_id == "GV1"
    assert state.follower_ids == ["GV2"]


def leader_selected_state() -> ConsoleFollowWizardState:
    state = ConsoleFollowWizardState()
    begin_follow_wizard(state, fleet_payload())
    handle_follow_wizard_input(state, "GV1")
    result = apply_follow_tool_result(
        state, "set_leader", {"success": True, "message": "accepted"}
    )
    assert result.tool_name is None
    assert state.phase is FollowWizardPhase.AWAITING_SPACING
    return state


@pytest.mark.parametrize("text", ["0.5", "0.5米", "间距0.5米", "每架都设置成0.5米"])
def test_single_follower_spacing_accepts_contextual_answers(text):
    state = leader_selected_state()

    result = handle_follow_wizard_input(state, text)

    assert result.tool_name is None
    assert state.spacings_m == {"GV2": 0.5}
    assert state.phase is FollowWizardPhase.AWAITING_SEND_CONFIRMATION


def test_single_follower_bound_spacing_does_not_use_vehicle_number():
    state = leader_selected_state()

    handle_follow_wizard_input(state, "GV2 0.5米")

    assert state.spacings_m == {"GV2": 0.5}


def test_multi_follower_bare_number_is_rejected():
    state = ConsoleFollowWizardState(
        phase=FollowWizardPhase.AWAITING_SPACING,
        leader_id="GV1",
        follower_ids=["GV2", "GV3"],
    )

    result = handle_follow_wizard_input(state, "0.5")

    assert "统一" in result.message or "分别" in result.message
    assert state.phase is FollowWizardPhase.AWAITING_SPACING


def test_multi_vehicle_flow_collects_follower_order_then_uniform_spacing():
    state = ConsoleFollowWizardState()
    begin_follow_wizard(state, three_vehicle_payload())
    handle_follow_wizard_input(state, "GV1")
    apply_follow_tool_result(state, "set_leader", {"success": True})
    assert state.phase is FollowWizardPhase.AWAITING_FOLLOWER_ORDER

    order_result = handle_follow_wizard_input(state, "GV3, GV2")
    assert order_result.tool_name is None
    assert state.follower_ids == ["GV3", "GV2"]
    assert state.phase is FollowWizardPhase.AWAITING_SPACING

    handle_follow_wizard_input(state, "全部统一设置成0.5米")
    assert state.spacings_m == {"GV3": 0.5, "GV2": 0.5}
    assert state.phase is FollowWizardPhase.AWAITING_SEND_CONFIRMATION


@pytest.mark.parametrize(
    "text",
    [
        "GV2 0.5米，GV2 0.8米，GV3 0.9米",
        "GV2 0.5米，GV3 0.9米，GV4 9米",
    ],
)
def test_multi_follower_spacing_rejects_duplicate_or_unknown_bindings(text):
    state = ConsoleFollowWizardState(
        phase=FollowWizardPhase.AWAITING_SPACING,
        follower_ids=["GV2", "GV3"],
        aliases={"gv2": "GV2", "gv3": "GV3"},
    )

    result = handle_follow_wizard_input(state, text)

    assert state.phase is FollowWizardPhase.AWAITING_SPACING
    assert state.spacings_m == {}
    assert "间距无效" in result.message


def ready_to_send_state() -> ConsoleFollowWizardState:
    return ConsoleFollowWizardState(
        phase=FollowWizardPhase.AWAITING_SEND_CONFIRMATION,
        leader_id="GV1",
        follower_ids=["GV2"],
        spacings_m={"GV2": 0.5},
    )


def test_confirmation_builds_one_exact_follow_payload():
    state = ready_to_send_state()

    result = handle_follow_wizard_input(state, "发送队形")

    assert result.tool_name == "send_follow_formation"
    assert result.tool_args["leader_id"] == "GV1"
    assert json.loads(result.tool_args["followers_json"]) == [
        {"robot_id": "GV2", "distance_m": 0.5}
    ]


def test_successful_send_enters_target_phase():
    state = ready_to_send_state()

    result = apply_follow_tool_result(
        state,
        "send_follow_formation",
        {"success": True, "data": {"followers": []}},
    )

    assert state.phase is FollowWizardPhase.READY_FOR_TARGET
    assert state.formation_ready is True
    assert "目标点" in result.message


def test_successful_send_reports_requested_and_effective_spacing():
    state = ready_to_send_state()

    result = apply_follow_tool_result(
        state,
        "send_follow_formation",
        {
            "success": True,
            "data": {
                "followers": [
                    {
                        "unit_id": "GV2",
                        "requested_distance_m": 0.3,
                        "effective_distance_m": 0.5,
                    }
                ]
            },
        },
    )

    assert "GV2" in result.message
    assert "0.3" in result.message
    assert "0.5" in result.message


def test_failed_send_is_recorded_without_changing_collected_values():
    state = ready_to_send_state()

    apply_follow_tool_result(
        state,
        "send_follow_formation",
        {"success": False, "message": "GV2 RPC failed"},
    )

    assert state.formation_send_failed is True
    assert state.phase is FollowWizardPhase.AWAITING_SEND_CONFIRMATION
    assert state.spacings_m == {"GV2": 0.5}


def test_send_confirmation_allows_spacing_edit():
    state = ready_to_send_state()

    result = handle_follow_wizard_input(state, "0.8")

    assert result.tool_name is None
    assert state.spacings_m == {"GV2": 0.8}
    assert state.phase is FollowWizardPhase.AWAITING_SEND_CONFIRMATION


def test_send_confirmation_allows_cancel():
    state = ready_to_send_state()

    result = handle_follow_wizard_input(state, "取消编队")

    assert state.phase is FollowWizardPhase.IDLE
    assert state.leader_id is None
    assert state.follower_ids == []
    assert "取消" in result.message


def test_send_confirmation_allows_reselecting_leader_and_clears_downstream_state():
    state = ready_to_send_state()
    state.unit_ids = ["GV1", "GV2"]
    state.aliases = {"gv1": "GV1", "gv2": "GV2"}

    result = handle_follow_wizard_input(state, "重新选择Leader")

    assert state.phase is FollowWizardPhase.AWAITING_LEADER
    assert state.leader_id is None
    assert state.follower_ids == []
    assert state.spacings_m == {}
    assert "Leader" in result.message


@pytest.mark.parametrize("text", ["(5, 6)", "5,6", "前往目标点(5,6)"])
def test_target_input_calls_only_follow_target_tool(text):
    state = ready_to_send_state()
    state.phase = FollowWizardPhase.READY_FOR_TARGET
    state.formation_ready = True

    result = handle_follow_wizard_input(state, text)

    assert result.tool_name == "goto_follow_formation"
    assert result.tool_args == {"x": 5.0, "y": 6.0}


def test_target_rejects_multiple_coordinate_pairs():
    state = ready_to_send_state()
    state.phase = FollowWizardPhase.READY_FOR_TARGET
    state.formation_ready = True

    result = handle_follow_wizard_input(state, "先去1,2，再去3,4")

    assert result.tool_name is None
    assert state.phase is FollowWizardPhase.READY_FOR_TARGET
