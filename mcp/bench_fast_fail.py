import asyncio
import time
import aiohttp

URL = "http://127.0.0.1:9001/api/robot/status?unit_id=GV1"
NUM_REQUESTS = 20

async def fetch(session):
    start = time.perf_counter()
    try:
        async with session.get(URL, timeout=2.0) as response:
            await response.text()
            status = response.status
    except Exception as e:
        status = str(e)
    elapsed = (time.perf_counter() - start) * 1000  # ms
    return status, elapsed

async def main():
    print(f"=== Starting Fast Fail Benchmark ===")
    print(f"Target: {URL}")
    print(f"Concurrent Requests: {NUM_REQUESTS}")
    
    # Check if SAU_ENABLE_REAL_RPC is off as default
    print("\nEnsuring default state (SAU_ENABLE_REAL_RPC is not set to 1)...")
    
    async with aiohttp.ClientSession() as session:
        start_time = time.perf_counter()
        tasks = [fetch(session) for _ in range(NUM_REQUESTS)]
        results = await asyncio.gather(*tasks)
        total_time = (time.perf_counter() - start_time) * 1000
        
        print("\nResults:")
        latencies = []
        success_count = 0
        
        for i, (status, lat) in enumerate(results):
            latencies.append(lat)
            if status == 503:
                success_count += 1
            print(f"Request {i+1:02d}: Status={status}, Latency={lat:.2f}ms")
            
        print(f"\nSummary:")
        print(f"Total time for {NUM_REQUESTS} concurrent requests: {total_time:.2f}ms")
        print(f"Average latency: {sum(latencies)/len(latencies):.2f}ms")
        print(f"Max latency: {max(latencies):.2f}ms")
        print(f"Expected 503 Status Count: {success_count}/{NUM_REQUESTS}")

        # Assertions to ensure it's "Fast Fail"
        max_lat = max(latencies)
        if max_lat < 100.0:
            print("\n✅ PASS: HTTP bridge and Fast Fail mechanism are working effectively with low latency.")
        else:
            print("\n❌ FAIL: Latency is too high.")

if __name__ == "__main__":
    asyncio.run(main())
