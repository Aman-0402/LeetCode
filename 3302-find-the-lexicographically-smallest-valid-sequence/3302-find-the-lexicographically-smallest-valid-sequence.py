class Solution:
    def validSequence(self, word1: str, word2: str) -> list[int]:
        n = len(word1)
        m = len(word2)

        ans = []
        last = [-1] * m

        # Find the latest possible position
        # for every character of word2.
        i = n - 1
        j = m - 1

        while i >= 0 and j >= 0:
            if word1[i] == word2[j]:
                last[j] = i
                j -= 1
            i -= 1

        canSkip = True
        j = 0

        for i in range(n):
            if j == m:
                break

            # Exact match
            if word1[i] == word2[j]:
                ans.append(i)
                j += 1

            # Use the one allowed mismatch
            elif canSkip and (j == m - 1 or i < last[j + 1]):
                ans.append(i)
                j += 1
                canSkip = False

        if j == m:
            return ans

        return []