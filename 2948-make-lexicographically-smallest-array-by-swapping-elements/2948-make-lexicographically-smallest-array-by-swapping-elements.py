class Solution:
    def lexicographicallySmallestArray(self, nums, limit):

        n = len(nums)

        # (value, original index)
        arr = [(nums[i], i) for i in range(n)]

        # Sort by value
        arr.sort()

        start = 0

        while start < n:

            end = start

            # Find current group
            while (
                end + 1 < n
                and arr[end + 1][0] - arr[end][0] <= limit
            ):
                end += 1

            # Original indices
            indices = [
                arr[i][1]
                for i in range(start, end + 1)
            ]

            # Sort indices
            indices.sort()

            # Assign smallest values to smallest indices
            for i in range(start, end + 1):
                nums[indices[i - start]] = arr[i][0]

            start = end + 1

        return nums