class Solution:
    def stoneGameII(self, piles):
        n = len(piles)

        suffix = [0] * (n + 1)

        for i in range(n - 1, -1, -1):
            suffix[i] = suffix[i + 1] + piles[i]

        dp = [[-1] * (n + 1) for _ in range(n)]

        def solve(i, M):
            if i >= n:
                return 0

            if i + 2 * M >= n:
                return suffix[i]

            if dp[i][M] != -1:
                return dp[i][M]

            best = 0

            for x in range(1, 2 * M + 1):
                opponent = solve(i + x, max(M, x))

                best = max(
                    best,
                    suffix[i] - opponent
                )

            dp[i][M] = best
            return best

        return solve(0, 1)