class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:

        left = 0
        windowSum = 0
        minLength = float('inf')

        for right in range(len(nums)):

            windowSum += nums[right]

            while windowSum >= target:
                minLength = min(minLength, right - left + 1)

                windowSum -= nums[left]
                left += 1

        return 0 if minLength == float('inf') else minLength