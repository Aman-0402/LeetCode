from typing import List

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        cnt = [0, 0, 0]

        for x in stones:
            cnt[x % 3] += 1

        if min(cnt[1], cnt[2]) == 0:
            return max(cnt[1], cnt[2]) > 2 and cnt[0] % 2 == 1

        return abs(cnt[1] - cnt[2]) > 2 or cnt[0] % 2 == 0