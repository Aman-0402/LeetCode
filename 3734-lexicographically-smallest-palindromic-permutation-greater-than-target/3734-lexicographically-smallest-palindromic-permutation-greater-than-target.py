class Solution:

    def build(self, left, mid):
        res = left

        if mid != '#':
            res += mid

        res += left[::-1]

        return res

    def lexPalindromicPermutation(self, s: str, target: str) -> str:

        n = len(s)

        cnt = [0] * 26

        for ch in s:
            cnt[ord(ch) - ord('a')] += 1

        odd = 0
        mid = '#'

        for i in range(26):
            if cnt[i] % 2:
                odd += 1
                mid = chr(ord('a') + i)

        if odd > 1:
            return ""

        half = [x // 2 for x in cnt]

        half_len = n // 2

        left = []

        for pos in range(half_len):

            found = False

            for c in range(26):

                if half[c] == 0:
                    continue

                half[c] -= 1
                left.append(chr(ord('a') + c))

                # Largest possible completion
                max_left = left.copy()

                for x in range(25, -1, -1):
                    max_left.extend(
                        [chr(ord('a') + x)] * half[x]
                    )

                candidate = self.build(
                    ''.join(max_left),
                    mid
                )

                if candidate > target:
                    found = True
                    break

                half[c] += 1
                left.pop()

            if not found:
                return ""

        ans = self.build(''.join(left), mid)

        return ans if ans > target else ""