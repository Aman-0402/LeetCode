class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        MOD = 10**9 + 7

        dp = [0] * (k + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            prefix = [0] * (k + 1)
            prefix[0] = dp[0]

            for j in range(1, k + 1):
                prefix[j] = (prefix[j - 1] + dp[j]) % MOD

            new_dp = [0] * (k + 1)

            for j in range(k + 1):
                new_dp[j] = prefix[j]

                if j >= i:
                    new_dp[j] = (new_dp[j] - prefix[j - i]) % MOD

            dp = new_dp

        return dp[k]