class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        current = 0
        maximum = 0

        for num in nums:
            if num == 1:
                current += 1
                maximum = max(maximum, current)
            else:
                current = 0

        return maximum