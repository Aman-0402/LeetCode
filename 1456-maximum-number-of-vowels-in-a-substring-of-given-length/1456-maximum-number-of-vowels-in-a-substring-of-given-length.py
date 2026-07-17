class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = {'a', 'e', 'i', 'o', 'u'}

        count = 0

        # First window
        for i in range(k):
            if s[i] in vowels:
                count += 1

        maxCount = count

        # Slide the window
        for i in range(k, len(s)):
            if s[i - k] in vowels:
                count -= 1

            if s[i] in vowels:
                count += 1

            maxCount = max(maxCount, count)

        return maxCount