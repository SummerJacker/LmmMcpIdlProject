#!/bin/bash
B="http://127.0.0.1:9001"
PASS=0; FAIL=0
check() { if [ "$1" = "ok" ]; then PASS=$((PASS+1)); echo "  PASS: $2"; else FAIL=$((FAIL+1)); echo "  FAIL: $2 ($3)"; fi; }

echo "=== EXCEPTION TESTS ==="
R=$(curl -s -X POST $B/api/task/goto_pose -H "Content-Type: application/json" -d '{"unit_id":"GV999","x":3,"y":5,"tolerance_m":0.15,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "GV999 rejected" || check fail "GV999 rejected" "$R"
echo "$R" | grep -q 'UNIT_NOT_FOUND' && check ok "  error_code=UNIT_NOT_FOUND" || check fail "  error_code=UNIT_NOT_FOUND" "$R"

R=$(curl -s -X POST $B/api/task/goto_pose -H "Content-Type: application/json" -d '{"unit_id":"GV1"}')
echo "$R" | grep -q '"success":false' && check ok "missing x/y rejected" || check fail "missing x/y rejected" "$R"

R=$(curl -s -X POST $B/api/task/goto_pose -H "Content-Type: application/json" -d '{"unit_id":"GV1","x":3,"y":5,"tolerance_m":-1,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "negative tolerance rejected" || check fail "negative tolerance rejected" "$R"

R=$(curl -s -X POST $B/api/task/goto_pose -H "Content-Type: application/json" -d '{"unit_id":"GV1","x":9999,"y":9999,"tolerance_m":0.15,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "out-of-bounds rejected" || check fail "out-of-bounds rejected" "$R"

R=$(curl -s -X POST $B/api/task/goto_pose_batch -H "Content-Type: application/json" -d '{"targets":[],"tolerance_m":0.15,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "empty batch rejected" || check fail "empty batch rejected" "$R"

R=$(curl -s -X POST $B/api/task/goto_pose_batch -H "Content-Type: application/json" -d '{"targets":[{"unit_id":"GV999","x":1,"y":0}],"tolerance_m":0.15,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "batch bad unit rejected" || check fail "batch bad unit rejected" "$R"

R=$(curl -s -X POST $B/api/formation/execute -H "Content-Type: application/json" -d '{"formation_type":"line","unit_ids":["GV1"],"spacing_m":1,"tolerance_m":0.15,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "formation line 1u rejected" || check fail "formation line 1u rejected" "$R"

R=$(curl -s -X POST $B/api/formation/execute -H "Content-Type: application/json" -d '{"formation_type":"triangle","unit_ids":["GV1","GV2"],"spacing_m":1,"tolerance_m":0.15,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "formation triangle 2u rejected" || check fail "formation triangle 2u rejected" "$R"

R=$(curl -s -X POST $B/api/formation/execute -H "Content-Type: application/json" -d '{"formation_type":"circle","unit_ids":["GV1","GV2","GV3"],"spacing_m":1,"tolerance_m":0.15,"timeout_ms":30000}')
echo "$R" | grep -q '"success":false' && check ok "formation circle rejected" || check fail "formation circle rejected" "$R"

R=$(curl -s $B/api/task/status?task_id=nonexistent)
echo "$R" | grep -q '"success":false' && check ok "status nonexistent rejected" || check fail "status nonexistent rejected" "$R"

R=$(curl -s -X POST $B/api/task/cancel -H "Content-Type: application/json" -d '{"task_id":"nonexistent"}')
echo "$R" | grep -q '"success":false' && check ok "cancel nonexistent rejected" || check fail "cancel nonexistent rejected" "$R"

echo ""
echo "=== HAPPY PATH ==="
R=$(curl -s -X POST $B/api/task/goto_pose -H "Content-Type: application/json" -d '{"unit_id":"GV1","x":50,"y":50,"tolerance_m":0.15,"timeout_ms":2000}')
echo "$R" | grep -q '"success":true' && check ok "goto_pose GV1 accepted" || check fail "goto_pose GV1 accepted" "$R"
TID=$(echo "$R" | python -c "import sys,json; print(json.load(sys.stdin)['data']['task_id'])" 2>/dev/null)
echo "    task_id=$TID"
echo "$R" | grep -q '"state":"RUNNING"' && check ok "  state=RUNNING on create" || check fail "  state=RUNNING on create" "$R"

if [ -n "$TID" ]; then
    sleep 1
    S=$(curl -s "$B/api/task/status?task_id=$TID")
    echo "$S" | grep -q '"task_type":"goto_pose"' && check ok "status has task_type" || check fail "status has task_type" "$S"
    echo "$S" | grep -q '"unit_results"' && check ok "status has unit_results" || check fail "status has unit_results" "$S"
    echo "$S" | grep -q '"audit_log"' && check ok "status has audit_log" || check fail "status has audit_log" "$S"

    # 等超时
    sleep 3
    S2=$(curl -s "$B/api/task/status?task_id=$TID")
    ST=$(echo "$S2" | python -c "import sys,json; print(json.load(sys.stdin)['data']['state'])" 2>/dev/null)
    check "timeout complete (state=$ST)" "[ \"$ST\" = \"TIMEOUT\" ] || [ \"$ST\" = \"COMPLETED\" ]" "$S2"
fi

sleep 3
echo ""
echo "=== BATCH ==="
R=$(curl -s -X POST $B/api/task/goto_pose_batch -H "Content-Type: application/json" -d '{"targets":[{"unit_id":"GV1","x":1,"y":0},{"unit_id":"GV2","x":2,"y":0},{"unit_id":"GV3","x":3,"y":0}],"tolerance_m":0.15,"timeout_ms":5000}')
echo "$R" | grep -q '"success":true' && check ok "batch 3u accepted" || check fail "batch 3u accepted" "$R"
BTID=$(echo "$R" | python -c "import sys,json; print(json.load(sys.stdin)['data']['task_id'])" 2>/dev/null)
echo "    task_id=$BTID"
URC=$(echo "$R" | python -c "import sys,json; print(len(json.load(sys.stdin)['data']['unit_results']))" 2>/dev/null)
check "  3 subtasks" "[ \"$URC\" = \"3\" ]" "$R"

if [ -n "$BTID" ]; then
    # cancel it
    C=$(curl -s -X POST $B/api/task/cancel -H "Content-Type: application/json" -d "{\"task_id\":\"$BTID\"}")
    echo "$C" | grep -q '"state":"CANCELLED"' && check ok "batch cancel -> CANCELLED" || check fail "batch cancel -> CANCELLED" "$C"
fi

sleep 3
echo ""
echo "=== FORMATION ==="
for FT in line column triangle; do
    case $FT in
        line) IDS='["GV1","GV2","GV3"]' ;;
        column) IDS='["GV1","GV2"]' ;;
        triangle) IDS='["GV1","GV2","GV3"]' ;;
    esac
    R=$(curl -s -X POST $B/api/formation/execute -H "Content-Type: application/json" -d "{\"formation_type\":\"$FT\",\"unit_ids\":$IDS,\"spacing_m\":1,\"tolerance_m\":0.15,\"timeout_ms\":5000}")
    echo "$R" | grep -q '"success":true' && check ok "$FT accepted" || check fail "$FT accepted" "$R"
    FTID=$(echo "$R" | python -c "import sys,json; d=json.load(sys.stdin); print(d['data']['task_id'] if d['success'] else '')" 2>/dev/null)
    if [ -n "$FTID" ]; then
        curl -s -X POST $B/api/task/cancel -H "Content-Type: application/json" -d "{\"task_id\":\"$FTID\"}" > /dev/null
    fi
    sleep 2
done

sleep 2
echo ""
echo "=== DOUBLE-BOOK PREVENTION ==="
R1=$(curl -s -X POST $B/api/task/goto_pose -H "Content-Type: application/json" -d '{"unit_id":"GV1","x":10,"y":10,"tolerance_m":0.15,"timeout_ms":10000}')
DTID=$(echo "$R1" | python -c "import sys,json; d=json.load(sys.stdin); print(d['data']['task_id'] if d['success'] else '')" 2>/dev/null)
check "create task on GV1" "[ -n \"$DTID\" ]" "$R1"

R2=$(curl -s -X POST $B/api/task/goto_pose -H "Content-Type: application/json" -d '{"unit_id":"GV1","x":5,"y":5,"tolerance_m":0.15,"timeout_ms":5000}')
echo "$R2" | grep -q '"UNIT_BUSY"' && check ok "double-book GV1 -> UNIT_BUSY" || check fail "double-book GV1 -> UNIT_BUSY" "$R2"
[ -n "$DTID" ] && curl -s -X POST $B/api/task/cancel -H "Content-Type: application/json" -d "{\"task_id\":\"$DTID\"}" > /dev/null

echo ""
echo "RESULTS: $PASS passed, $FAIL failed"
