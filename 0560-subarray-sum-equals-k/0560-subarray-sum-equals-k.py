class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        prefix_count = {0: 1}

        prefix = 0
        ans = 0

        for num in nums:
            prefix += num

            if prefix - k in prefix_count:
                ans += prefix_count[prefix - k]

            prefix_count[prefix] = prefix_count.get(prefix, 0) + 1

        return ans