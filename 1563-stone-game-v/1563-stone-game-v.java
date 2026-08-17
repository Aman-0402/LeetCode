class Solution {
    public int stoneGameV(int[] stoneValue) {
        int n = stoneValue.length;

        long[] prefix = new long[n + 1];

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        int[][] dp = new int[n][n];

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;

                for (int k = l; k < r; k++) {
                    long leftSum = prefix[k + 1] - prefix[l];
                    long rightSum = prefix[r + 1] - prefix[k + 1];

                    if (leftSum < rightSum) {
                        dp[l][r] = Math.max(
                            dp[l][r],
                            (int) leftSum + dp[l][k]
                        );
                    } 
                    else if (leftSum > rightSum) {
                        dp[l][r] = Math.max(
                            dp[l][r],
                            (int) rightSum + dp[k + 1][r]
                        );
                    } 
                    else {
                        dp[l][r] = Math.max(
                            dp[l][r],
                            (int) leftSum +
                            Math.max(dp[l][k], dp[k + 1][r])
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
}