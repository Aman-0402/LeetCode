#include <stdlib.h>

int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;

    long long* prefix =
        (long long*)malloc((n + 1) * sizeof(long long));

    for (int i = 0; i <= n; i++) {
        prefix[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    int** dp = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;

            for (int k = l; k < r; k++) {
                long long leftSum =
                    prefix[k + 1] - prefix[l];

                long long rightSum =
                    prefix[r + 1] - prefix[k + 1];

                if (leftSum < rightSum) {
                    int value =
                        (int)leftSum + dp[l][k];

                    if (value > dp[l][r])
                        dp[l][r] = value;
                }
                else if (leftSum > rightSum) {
                    int value =
                        (int)rightSum + dp[k + 1][r];

                    if (value > dp[l][r])
                        dp[l][r] = value;
                }
                else {
                    int best =
                        dp[l][k] > dp[k + 1][r]
                        ? dp[l][k]
                        : dp[k + 1][r];

                    int value =
                        (int)leftSum + best;

                    if (value > dp[l][r])
                        dp[l][r] = value;
                }
            }
        }
    }

    int answer = dp[0][n - 1];

    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }

    free(dp);
    free(prefix);

    return answer;
}