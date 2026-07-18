class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        if len(s1) > len(s2):
            return False

        freq1 = [0] * 26
        freq2 = [0] * 26

        for ch in s1:
            freq1[ord(ch) - ord('a')] += 1

        for i in range(len(s1)):
            freq2[ord(s2[i]) - ord('a')] += 1

        if freq1 == freq2:
            return True

        for i in range(len(s1), len(s2)):

            freq2[ord(s2[i]) - ord('a')] += 1
            freq2[ord(s2[i - len(s1)]) - ord('a')] -= 1

            if freq1 == freq2:
                return True

        return False