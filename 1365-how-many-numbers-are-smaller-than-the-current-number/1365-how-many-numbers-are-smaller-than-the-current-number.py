class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        sorted_nums = sorted(nums)

        first_index = {}

        for i, num in enumerate(sorted_nums):
            if num not in first_index:
                first_index[num] = i

        ans = []

        for num in nums:
            ans.append(first_index[num])

        return ans