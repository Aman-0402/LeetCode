#include <stdlib.h>
#include <string.h>

int n;
int* suffix;
int** dp;

int maxValue(int a, int b) {
    return a > b ? a : b;
}

int solve(int i, int M) {
    if (i >= n)
        return 0;

    if (i + 2 * M >= n)
        return suffix[i];

    if (dp[i][M] != -1)
        return dp[i][M];

    int best = 0;

    for (int x = 1; x <= 2 * M; ++x) {
        int nextM = maxValue(M, x);

        int opponent = solve(i + x, nextM);

        int current = suffix[i] - opponent;

        if (current > best)
            best = current;
    }

    dp[i][M] = best;

    return best;
}

int stoneGameII(int* piles, int pilesSize) {
    n = pilesSize;

    suffix = (int*)calloc(n + 1, sizeof(int));

    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + piles[i];
    }

    dp = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; ++i) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));

        for (int j = 0; j <= n; ++j)
            dp[i][j] = -1;
    }

    int result = solve(0, 1);

    for (int i = 0; i < n; ++i)
        free(dp[i]);

    free(dp);
    free(suffix);

    return result;
}