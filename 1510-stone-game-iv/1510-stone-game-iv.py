class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dp = [False] * (n + 1)

        for i in range(1, n + 1):

            j = 1

            while j * j <= i:
                square = j * j

                if not dp[i - square]:
                    dp[i] = True
                    break

                j += 1

        return dp[n]