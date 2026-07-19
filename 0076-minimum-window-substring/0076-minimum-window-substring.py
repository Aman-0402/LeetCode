class Solution:
    def minWindow(self, s: str, t: str) -> str:

        from collections import Counter

        need = Counter(t)
        window = {}

        required = len(need)
        formed = 0

        left = 0

        minLen = float('inf')
        start = 0

        for right in range(len(s)):

            c = s[right]

            window[c] = window.get(c, 0) + 1

            if c in need and window[c] == need[c]:
                formed += 1

            while formed == required:

                if right - left + 1 < minLen:
                    minLen = right - left + 1
                    start = left

                remove = s[left]

                window[remove] -= 1

                if remove in need and window[remove] < need[remove]:
                    formed -= 1

                left += 1

        return "" if minLen == float('inf') else s[start:start + minLen]