class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        freq = [0] * 26

        left = 0
        maxFreq = 0
        ans = 0

        for right in range(len(s)):

            index = ord(s[right]) - ord('A')

            freq[index] += 1

            maxFreq = max(maxFreq, freq[index])

            while (right - left + 1) - maxFreq > k:

                freq[ord(s[left]) - ord('A')] -= 1

                left += 1

            ans = max(ans, right - left + 1)

        return ans