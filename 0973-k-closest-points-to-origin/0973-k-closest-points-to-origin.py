import heapq
from typing import List

class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        heap = []

        for point in points:
            dist = point[0] * point[0] + point[1] * point[1]

            heapq.heappush(heap, (-dist, point))

            if len(heap) > k:
                heapq.heappop(heap)

        return [point for _, point in heap]