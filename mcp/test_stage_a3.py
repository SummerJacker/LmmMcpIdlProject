import asyncio
import json
from robot_adapter import RobotAdapter

async def main():
    adapter = RobotAdapter()
    
    print("\n--- TC: list_robots ---")
    res = await adapter.list_robots()
    print(res)

    print("\n--- TC-04: 断连降级触发 (503 Fast Fail) ---")
    # robot_1 in robots.json has mode: real, which maps to unit_id: GV1
    res = await adapter.get_robot_status(robot_id="robot_1")
    print(res)

    print("\n--- TC-06: 越界参数拦截 ---")
    res = await adapter.send_move(robot_id="robot_2", linear_velocity=100.0, angular_velocity=0.0)
    print(res)

if __name__ == "__main__":
    asyncio.run(main())
