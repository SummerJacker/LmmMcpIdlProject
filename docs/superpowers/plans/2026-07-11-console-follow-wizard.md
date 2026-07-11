# Deterministic Console Follow Formation Wizard Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace LLM-driven Console-follow parameter planning with a deterministic wizard that discovers vehicles, sets the Leader, collects spacing, sends one formation, and then accepts Leader target points.

**Architecture:** Add a pure `console_follow_wizard.py` state machine that produces typed prompts or MCP tool calls and consumes normalized tool results. `deepseek_mcp_client.py` remains responsible for terminal I/O and `run_mcp_call`, but routes active Console-follow turns through the wizard before entering the LLM agent loop. Geometric formation and existing motion guardrails remain unchanged.

**Tech Stack:** Python 3.10, dataclasses, Enum, regex/JSON parsing, pytest, FastMCP CLI.

**Repository note:** `E:\MCP-IDL` is not a Git repository, so the commit steps normally required by this workflow are replaced with explicit test checkpoints.

---

### Task 1: Pure Wizard State and Vehicle Discovery

**Files:**
- Create: `mcp/console_follow_wizard.py`
- Create: `mcp/tests/test_console_follow_wizard.py`

- [ ] **Step 1: Write failing discovery and two-vehicle tests**

```python
from console_follow_wizard import (
    ConsoleFollowWizardState,
    FollowWizardPhase,
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


def test_discovery_lists_ground_units_and_asks_for_leader():
    state = ConsoleFollowWizardState()
    result = begin_follow_wizard(state, fleet_payload())
    assert state.phase is FollowWizardPhase.AWAITING_LEADER
    assert state.unit_ids == ["GV1", "GV2"]
    assert "GV1" in result.message and "GV2" in result.message


def test_two_vehicle_leader_selection_generates_exact_set_leader_call():
    state = ConsoleFollowWizardState()
    begin_follow_wizard(state, fleet_payload())
    result = handle_follow_wizard_input(state, "GV1")
    assert result.tool_name == "set_leader"
    assert result.tool_args == {"robot_id": "GV1"}
    assert state.leader_id == "GV1"
    assert state.follower_ids == ["GV2"]
```

- [ ] **Step 2: Run tests and verify RED**

Run:

```powershell
cd E:\MCP-IDL\mcp
python -m pytest tests\test_console_follow_wizard.py -q
```

Expected: collection fails because `console_follow_wizard` does not exist.

- [ ] **Step 3: Implement state, result types, discovery, and Leader resolution**

Create these public types and functions:

```python
class FollowWizardPhase(str, Enum):
    IDLE = "idle"
    DISCOVERING_UNITS = "discovering_units"
    AWAITING_LEADER = "awaiting_leader"
    AWAITING_FOLLOWER_ORDER = "awaiting_follower_order"
    AWAITING_SPACING = "awaiting_spacing"
    AWAITING_SEND_CONFIRMATION = "awaiting_send_confirmation"
    READY_FOR_TARGET = "ready_for_target"


@dataclass
class ConsoleFollowWizardState:
    phase: FollowWizardPhase = FollowWizardPhase.IDLE
    unit_ids: list[str] = field(default_factory=list)
    aliases: dict[str, str] = field(default_factory=dict)
    leader_id: str | None = None
    follower_ids: list[str] = field(default_factory=list)
    spacings_m: dict[str, float] = field(default_factory=dict)
    formation_ready: bool = False


@dataclass(frozen=True)
class WizardTurnResult:
    handled: bool = True
    message: str = ""
    tool_name: str | None = None
    tool_args: dict[str, Any] = field(default_factory=dict)
```

`begin_follow_wizard()` must unwrap only successful payloads, retain online `GV*` units, build case-insensitive mappings for both `unit_id` and `robot_id`, reject fewer than two vehicles, and enter `AWAITING_LEADER`.

`handle_follow_wizard_input()` in `AWAITING_LEADER` must resolve only a discovered ID. For two vehicles it assigns the remaining unit as the sole Follower; for more vehicles it leaves Follower ordering for the next phase. It returns only `set_leader(robot_id=<unit_id>)`.

- [ ] **Step 4: Run tests and verify GREEN**

Run the command from Step 2. Expected: both tests pass.

### Task 2: Tool Results, Follower Ordering, and Contextual Spacing

**Files:**
- Modify: `mcp/console_follow_wizard.py`
- Modify: `mcp/tests/test_console_follow_wizard.py`

- [ ] **Step 1: Write failing tests for successful Leader transition and reported spacing forms**

```python
from console_follow_wizard import apply_follow_tool_result


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


def test_multi_follower_bare_number_is_rejected():
    state = ConsoleFollowWizardState(
        phase=FollowWizardPhase.AWAITING_SPACING,
        leader_id="GV1",
        follower_ids=["GV2", "GV3"],
    )
    result = handle_follow_wizard_input(state, "0.5")
    assert "统一" in result.message or "分别" in result.message
    assert state.phase is FollowWizardPhase.AWAITING_SPACING
```

- [ ] **Step 2: Run the new tests and verify RED**

Run:

```powershell
python -m pytest tests\test_console_follow_wizard.py -q
```

Expected: failures because tool-result transitions and contextual spacing are not implemented.

- [ ] **Step 3: Implement the transitions and parsers**

Add `apply_follow_tool_result(state, tool_name, payload) -> WizardTurnResult`. Its first branch must be:

```python
def apply_follow_tool_result(
    state: ConsoleFollowWizardState,
    tool_name: str,
    payload: dict[str, Any],
) -> WizardTurnResult:
    success = payload.get("success") is True
    message = str(payload.get("message", ""))
    if tool_name == "set_leader" and not success:
        state.phase = FollowWizardPhase.AWAITING_LEADER
        return WizardTurnResult(message=f"Leader 设置失败：{message}")
    if tool_name == "set_leader":
        state.phase = (
            FollowWizardPhase.AWAITING_SPACING
            if len(state.follower_ids) == 1
            else FollowWizardPhase.AWAITING_FOLLOWER_ORDER
        )
        return WizardTurnResult(message="Leader 设置成功，请继续设置 Followers 和间距。")
    raise ValueError(f"unsupported wizard tool result: {tool_name}")
```

For `set_leader`, enter `AWAITING_SPACING` when there is one Follower and `AWAITING_FOLLOWER_ORDER` when there are multiple remaining units. On failure, preserve `AWAITING_LEADER` and return the payload message.

Follower-order parsing must accept comma-, Chinese-comma-, or whitespace-separated discovered IDs; reject duplicates, the Leader, unknown IDs, and incomplete lists.

Spacing parsing must:

```python
BARE_DISTANCE_RE = re.compile(r"^\s*(\d+(?:\.\d+)?)\s*(?:米|m)?\s*$", re.I)
UNIFORM_DISTANCE_RE = re.compile(
    r"(?:都|全部|每(?:辆|架)|统一).*?(\d+(?:\.\d+)?)\s*(?:米|m)?", re.I
)
BOUND_DISTANCE_RE = re.compile(
    r"((?:GV|AV)\d+|robot_\d+)\D{0,12}?(\d+(?:\.\d+)?)\s*(?:米|m)", re.I
)
```

Accept a bare value only for one Follower. For multiple Followers, accept one explicit uniform value or require one bound value per Follower. Reject nonfinite or nonpositive values. Successful parsing enters `AWAITING_SEND_CONFIRMATION` and returns a summary prompt without calling a tool.

- [ ] **Step 4: Run the wizard tests and verify GREEN**

Expected: all Task 1 and Task 2 tests pass.

### Task 3: Confirmed Formation Dispatch and Target Movement

**Files:**
- Modify: `mcp/console_follow_wizard.py`
- Modify: `mcp/tests/test_console_follow_wizard.py`

- [ ] **Step 1: Write failing send-confirmation and target tests**

```python
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


@pytest.mark.parametrize("text", ["(5, 6)", "5,6", "前往目标点(5,6)"])
def test_target_input_calls_only_follow_target_tool(text):
    state = ready_to_send_state()
    state.phase = FollowWizardPhase.READY_FOR_TARGET
    state.formation_ready = True
    result = handle_follow_wizard_input(state, text)
    assert result.tool_name == "goto_follow_formation"
    assert result.tool_args == {"x": 5.0, "y": 6.0}
```

- [ ] **Step 2: Run tests and verify RED**

Expected: confirmation and target tests fail because the phases have no handlers.

- [ ] **Step 3: Implement confirmation, payload construction, and target parsing**

Confirmation accepts `发送`, `发送队形`, `确认`, `是`, and `yes`. It first builds `followers_payload = [{"robot_id": follower_id, "distance_m": state.spacings_m[follower_id]} for follower_id in state.follower_ids]`, then serializes it with `json.dumps(followers_payload, ensure_ascii=False, separators=(",", ":"))` and returns exactly one `send_follow_formation` call.

`apply_follow_tool_result()` enters `READY_FOR_TARGET` only when the unwrapped result has `success=true`. It keeps `AWAITING_SEND_CONFIRMATION` and collected values on failure. Include requested/effective spacing from the Console response in the success message when present.

Target parsing extracts exactly two signed finite numbers separated by an English or Chinese comma and returns only `goto_follow_formation(x, y)`. Invalid input remains in `READY_FOR_TARGET`. A failed target tool result also preserves `READY_FOR_TARGET`.

- [ ] **Step 4: Run tests and verify GREEN**

Expected: all wizard tests pass.

### Task 4: Integrate the Wizard Before the LLM Agent Loop

**Files:**
- Modify: `mcp/deepseek_mcp_client.py:110-200`
- Modify: `mcp/deepseek_mcp_client.py:750-885`
- Modify: `mcp/tests/test_deepseek_mcp_client.py`

- [ ] **Step 1: Write a failing transcript regression test**

Use a fake `run_mcp_call` that records calls and returns MCP envelopes for `list_robots`, `set_leader`, and `send_follow_formation`. Feed inputs:

```python
inputs = iter([
    "进行编队",
    "1",
    "GV1",
    "每架都设置成0.5米",
    "发送队形",
    "exit",
])
```

Assert `call_llm` is never called and recorded tool calls equal:

```python
[
    ("list_robots", {}),
    ("set_leader", {"robot_id": "GV1"}),
    (
        "send_follow_formation",
        {
            "leader_id": "GV1",
            "followers_json": '[{"robot_id":"GV2","distance_m":0.5}]',
        },
    ),
]
```

- [ ] **Step 2: Run the transcript test and verify RED**

Expected: the current client calls the LLM after `GV1` or spacing input.

- [ ] **Step 3: Add deterministic wizard routing**

Import the wizard state/functions. When mode `1` is selected:

1. call `list_robots` immediately;
2. unwrap the tool response;
3. call `begin_follow_wizard` and print its prompt;
4. on later turns, if the wizard phase is not `IDLE`, call `handle_follow_wizard_input` before appending to the LLM conversation;
5. if a tool action is returned, execute it once, unwrap it, call `apply_follow_tool_result`, and print the result;
6. continue the terminal input loop without entering `call_llm`.

Keep explicit recovery commands routed through the existing recovery guard only after a formation tool failure. Starting a new ambiguous `进行编队` resets the wizard.

Remove the old `record_explicit_follow_spacings()` path from active Console-follow wizard turns; retain its helper only if existing compatibility tests still exercise non-wizard LLM calls.

- [ ] **Step 4: Run transcript and existing client tests**

Run:

```powershell
python -m pytest tests\test_console_follow_wizard.py tests\test_deepseek_mcp_client.py -q
```

Expected: all pass and the transcript invokes no LLM.

### Task 5: Prose Compatibility and Defensive Tool-Argument Normalization

**Files:**
- Modify: `mcp/deepseek_mcp_client.py:681-747`
- Modify: `mcp/tests/test_deepseek_mcp_client.py`

- [ ] **Step 1: Write failing tests for prose and `set_leader` alias handling**

```python
def test_call_llm_wraps_nonempty_prose_as_done(monkeypatch):
    response = MockResponse(
        json.dumps({"choices": [{"message": {"content": "请指定 Leader。"}}]})
    )
    monkeypatch.setattr("requests.Session.post", Mock(return_value=response))
    assert call_llm([], "key", "model") == {
        "done": True,
        "message": "请指定 Leader。",
    }


def test_normalize_set_leader_unit_id_alias():
    assert normalize_tool_call_args("set_leader", {"unit_id": "GV1"}) == {
        "robot_id": "GV1"
    }


def test_conflicting_set_leader_alias_is_rejected():
    with pytest.raises(ValueError):
        normalize_tool_call_args(
            "set_leader", {"robot_id": "GV1", "unit_id": "GV2"}
        )
```

- [ ] **Step 2: Run tests and verify RED**

Expected: prose raises `RuntimeError`, and the normalization helper is missing.

- [ ] **Step 3: Implement the minimal compatibility behavior**

In `call_llm()`, retain the original unmodified content before JSON cleanup. If JSON parsing fails and the original content is nonempty, return `{"done": True, "message": original_content}`. Empty content still raises `RuntimeError`.

Add:

```python
def normalize_tool_call_args(tool_name: str, args: dict[str, Any]) -> dict[str, Any]:
    normalized = dict(args)
    if tool_name != "set_leader" or "unit_id" not in normalized:
        return normalized
    unit_id = str(normalized.pop("unit_id"))
    if "robot_id" in normalized and str(normalized["robot_id"]) != unit_id:
        raise ValueError("conflicting robot_id and unit_id")
    normalized["robot_id"] = unit_id
    return normalized
```

Call this helper before generic tool guardrails and execution. Convert `ValueError` into a rejected tool observation; do not call FastMCP.

- [ ] **Step 4: Run focused tests and verify GREEN**

Run:

```powershell
python -m pytest tests\test_deepseek_mcp_client.py -q
```

Expected: all client tests pass.

### Task 6: Regression and Runtime-Shape Verification

**Files:**
- Modify if needed: `mcp/README.md`
- Verify: `mcp/deepseek_mcp_client.py`
- Verify: `mcp/console_follow_wizard.py`

- [ ] **Step 1: Document the deterministic Console flow**

Update the README example to show:

```text
进行编队 -> 1 -> GV1 -> 0.5 -> 发送队形 -> (5,6)
```

State that Console-follow mode does not call the LLM for slot collection and that Console may raise a requested spacing below `0.5m` to its effective minimum.

- [ ] **Step 2: Run syntax and relevant regression tests**

```powershell
cd E:\MCP-IDL\mcp
python -m py_compile deepseek_mcp_client.py console_follow_wizard.py main.py robot_adapter.py config.py
python -m pytest tests\test_agent_system.py tests\test_formation_orchestrator.py tests\test_robot_adapter.py tests\test_main_formation_tools.py tests\test_console_follow_wizard.py tests\test_deepseek_mcp_client.py -q
```

Expected: syntax succeeds and all selected tests pass.

- [ ] **Step 3: Run the transcript with a fake tool runner**

Run the transcript regression test with `-s` and verify the prompt sequence is:

```text
请选择编队类型
发现 GV1, GV2；请选择 Leader
GV1 已设为 Leader；请输入 GV2 间距
已记录 GV2=0.5m；请输入“发送队形”确认
队形发送成功；请输入目标点
```

- [ ] **Step 4: Record external integration limits**

Do not claim live vehicle success unless the running Console executable includes the new HTTP endpoints and returns successful real RPC results. If live Console is unavailable, report unit/integration-mock results separately from real vehicle execution.
