from collections import defaultdict

class Solution:
    def maxSubarrayLength(self, nums, k):
        freq = defaultdict(int)

        left = 0
        ans = 0

        for right in range(len(nums)):

            freq[nums[right]] += 1

            # Shrink window if frequency exceeds k
            while freq[nums[right]] > k:
                freq[nums[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans