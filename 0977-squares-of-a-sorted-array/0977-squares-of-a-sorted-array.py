class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)

        ans = [0] * n

        left = 0
        right = n - 1
        index = n - 1

        while left <= right:

            if abs(nums[left]) > abs(nums[right]):
                ans[index] = nums[left] * nums[left]
                left += 1
            else:
                ans[index] = nums[right] * nums[right]
                right -= 1

            index -= 1

        return ans