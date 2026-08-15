class Solution:
    def longestSubsequence(self, nums):
        n = len(nums)

        xor = 0
        has_non_zero = False

        for x in nums:
            xor ^= x

            if x != 0:
                has_non_zero = True

        # Entire array has non-zero XOR
        if xor != 0:
            return n

        # All elements are zero
        if not has_non_zero:
            return 0

        # Remove one non-zero element
        return n - 1