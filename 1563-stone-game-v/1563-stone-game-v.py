from typing import List
from functools import cache
from itertools import accumulate


class Solution:
    def stoneGameV(self, stoneValue: List[int]) -> int:

        prefix = list(accumulate(stoneValue, initial=0))

        @cache
        def dfs(left: int, right: int) -> int:
            if left == right:
                return 0

            ans = 0
            left_sum = 0

            total = prefix[right + 1] - prefix[left]

            for k in range(left, right):
                left_sum += stoneValue[k]
                right_sum = total - left_sum

                # Left part is smaller
                if left_sum < right_sum:

                    # Even the maximum possible result
                    # cannot beat our current answer.
                    if ans >= 2 * left_sum:
                        continue

                    ans = max(
                        ans,
                        left_sum + dfs(left, k)
                    )

                # Right part is smaller
                elif left_sum > right_sum:

                    # As k increases, right_sum only decreases.
                    # So no future split can improve the answer.
                    if ans >= 2 * right_sum:
                        break

                    ans = max(
                        ans,
                        right_sum + dfs(k + 1, right)
                    )

                # Equal sums
                else:
                    ans = max(
                        ans,
                        left_sum + dfs(left, k),
                        right_sum + dfs(k + 1, right)
                    )

            return ans

        return dfs(0, len(stoneValue) - 1)