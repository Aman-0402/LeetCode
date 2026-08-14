class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        freq = [0] * 26

        left = 0
        ans = 0

        for right in range(len(s)):
            idx = ord(s[right]) - ord('a')
            freq[idx] += 1

            while freq[idx] > 2:
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans