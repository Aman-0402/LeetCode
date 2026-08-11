#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int longestCommonSubsequence(char* text1, char* text2) {
    int n = 0;
    int m = 0;

    while (text1[n] != '\0')
        ++n;

    while (text2[m] != '\0')
        ++m;

    int** dp = (int**)malloc((n + 1) * sizeof(int*));

    for (int i = 0; i <= n; ++i) {
        dp[i] = (int*)calloc(m + 1, sizeof(int));
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                );
            }
        }
    }

    int result = dp[n][m];

    for (int i = 0; i <= n; ++i)
        free(dp[i]);

    free(dp);

    return result;
}