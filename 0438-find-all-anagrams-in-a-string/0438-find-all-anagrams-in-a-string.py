class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:

        ans = []

        if len(p) > len(s):
            return ans

        freqP = [0] * 26
        freqS = [0] * 26

        for ch in p:
            freqP[ord(ch) - ord('a')] += 1

        for i in range(len(p)):
            freqS[ord(s[i]) - ord('a')] += 1

        if freqP == freqS:
            ans.append(0)

        for i in range(len(p), len(s)):

            freqS[ord(s[i]) - ord('a')] += 1
            freqS[ord(s[i - len(p)]) - ord('a')] -= 1

            if freqP == freqS:
                ans.append(i - len(p) + 1)

        return ans