from typing import List
from math import lcm

class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:

        n = len(coins)

        def count(x):
            result = 0

            for mask in range(1, 1 << n):
                value = 1
                bits = 0

                for i in range(n):
                    if mask & (1 << i):
                        bits += 1
                        value = lcm(value, coins[i])

                        if value > x:
                            break
                else:
                    if bits % 2:
                        result += x // value
                    else:
                        result -= x // value

            return result

        low = 1
        high = min(coins) * k

        while low < high:
            mid = (low + high) // 2

            if count(mid) >= k:
                high = mid
            else:
                low = mid + 1

        return low