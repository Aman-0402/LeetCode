class Solution {
    public int kInversePairs(int n, int k) {
        int MOD = 1000000007;

        int[] dp = new int[k + 1];
        int[] newDp = new int[k + 1];

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int[] prefix = new int[k + 1];
            prefix[0] = dp[0];

            for (int j = 1; j <= k; j++) {
                prefix[j] = (prefix[j - 1] + dp[j]) % MOD;
            }

            for (int j = 0; j <= k; j++) {
                newDp[j] = prefix[j];

                if (j >= i) {
                    newDp[j] = (newDp[j] - prefix[j - i] + MOD) % MOD;
                }
            }

            dp = newDp;
            newDp = new int[k + 1];
        }

        return dp[k];
    }
}