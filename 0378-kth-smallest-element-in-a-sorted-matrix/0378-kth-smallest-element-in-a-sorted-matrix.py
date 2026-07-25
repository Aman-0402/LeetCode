import heapq
from typing import List

class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:

        n = len(matrix)

        heap = []

        for i in range(min(n, k)):
            heapq.heappush(heap, (matrix[i][0], i, 0))

        while k > 1:
            value, row, col = heapq.heappop(heap)

            if col + 1 < n:
                heapq.heappush(
                    heap,
                    (matrix[row][col + 1], row, col + 1)
                )

            k -= 1

        return heap[0][0]