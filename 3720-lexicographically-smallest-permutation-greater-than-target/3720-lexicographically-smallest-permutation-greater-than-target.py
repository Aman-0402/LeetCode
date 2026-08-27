class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)

        cnt = [0] * 26

        for c in s:
            cnt[ord(c) - ord('a')] += 1

        best_pos = -1
        best_char = -1

        for i in range(n):
            x = ord(target[i]) - ord('a')

            # Find smallest character greater than target[i]
            for c in range(x + 1, 26):
                if cnt[c] > 0:
                    best_pos = i
                    best_char = c
                    break

            # Must match target[i] to continue
            if cnt[x] == 0:
                break

            cnt[x] -= 1

        # No greater permutation exists
        if best_pos == -1:
            return ""

        # Rebuild counts
        cnt = [0] * 26

        for c in s:
            cnt[ord(c) - ord('a')] += 1

        ans = []

        # Match prefix
        for i in range(best_pos):
            ans.append(target[i])
            cnt[ord(target[i]) - ord('a')] -= 1

        # Make it greater
        ans.append(chr(ord('a') + best_char))
        cnt[best_char] -= 1

        # Smallest suffix
        for c in range(26):
            if cnt[c] > 0:
                ans.append(chr(ord('a') + c) * cnt[c])

        return ''.join(ans)