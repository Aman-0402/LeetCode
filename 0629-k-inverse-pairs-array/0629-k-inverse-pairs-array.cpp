class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007;

        vector<int> dp(k + 1, 0), newDp(k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            vector<int> prefix(k + 1, 0);
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
            fill(newDp.begin(), newDp.end(), 0);
        }

        return dp[k];
    }
};