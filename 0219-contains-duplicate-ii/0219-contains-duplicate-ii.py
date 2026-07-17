class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        lastIndex = {}

        for i, num in enumerate(nums):

            if num in lastIndex:
                if i - lastIndex[num] <= k:
                    return True

            lastIndex[num] = i

        return False