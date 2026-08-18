from typing import List
from collections import Counter

class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        n = len(nums)

        count = Counter(nums)

        # Every element forms its own subarray
        if k == 1:
            ans = -1

            for x in nums:
                if count[x] == 1:
                    ans = max(ans, x)

            return ans

        # Entire array is one subarray
        if k == n:
            return max(nums)

        # Only first and last elements can qualify
        ans = -1

        if count[nums[0]] == 1:
            ans = max(ans, nums[0])

        if count[nums[-1]] == 1:
            ans = max(ans, nums[-1])

        return ans