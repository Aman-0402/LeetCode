class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        windowSum = sum(nums[:k])
        maxSum = windowSum

        for i in range(k, len(nums)):
            windowSum += nums[i]
            windowSum -= nums[i - k]

            maxSum = max(maxSum, windowSum)

        return maxSum / k