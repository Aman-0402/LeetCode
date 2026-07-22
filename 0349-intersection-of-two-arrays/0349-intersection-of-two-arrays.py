class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        seen = set(nums1)
        ans = []

        for num in nums2:
            if num in seen:
                ans.append(num)
                seen.remove(num)

        return ans