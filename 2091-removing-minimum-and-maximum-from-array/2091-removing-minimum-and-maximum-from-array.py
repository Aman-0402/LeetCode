class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:

        n = len(nums)

        min_index = 0
        max_index = 0

        for i in range(1, n):

            if nums[i] < nums[min_index]:
                min_index = i

            if nums[i] > nums[max_index]:
                max_index = i

        # Make min_index the smaller index
        if min_index > max_index:
            min_index, max_index = max_index, min_index

        # Both from left
        left = max_index + 1

        # Both from right
        right = n - min_index

        # One from each side
        mixed = (min_index + 1) + (n - max_index)

        return min(left, right, mixed)