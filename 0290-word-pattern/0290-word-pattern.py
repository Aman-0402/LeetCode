class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:

        words = s.split()

        if len(pattern) != len(words):
            return False

        map1 = {}
        map2 = {}

        for ch, word in zip(pattern, words):

            if ch in map1 and map1[ch] != word:
                return False

            if word in map2 and map2[word] != ch:
                return False

            map1[ch] = word
            map2[word] = ch

        return True