import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:

        # Python has only Min Heap
        stones = [-stone for stone in stones]
        heapq.heapify(stones)

        while len(stones) > 1:

            y = -heapq.heappop(stones)
            x = -heapq.heappop(stones)

            if y != x:
                heapq.heappush(stones, -(y - x))

        return -stones[0] if stones else 0