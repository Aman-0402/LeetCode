/**
 * @param {number[]} stoneValue
 * @return {number}
 */
var stoneGameV = function(stoneValue) {
    const n = stoneValue.length;

    const prefix = new Array(n + 1).fill(0);

    for (let i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    const dp = Array.from(
        { length: n },
        () => new Array(n).fill(0)
    );

    for (let len = 2; len <= n; len++) {
        for (let l = 0; l + len <= n; l++) {
            const r = l + len - 1;

            for (let k = l; k < r; k++) {
                const leftSum = prefix[k + 1] - prefix[l];
                const rightSum = prefix[r + 1] - prefix[k + 1];

                if (leftSum < rightSum) {
                    dp[l][r] = Math.max(
                        dp[l][r],
                        leftSum + dp[l][k]
                    );
                }
                else if (leftSum > rightSum) {
                    dp[l][r] = Math.max(
                        dp[l][r],
                        rightSum + dp[k + 1][r]
                    );
                }
                else {
                    dp[l][r] = Math.max(
                        dp[l][r],
                        leftSum +
                        Math.max(dp[l][k], dp[k + 1][r])
                    );
                }
            }
        }
    }

    return dp[0][n - 1];
};