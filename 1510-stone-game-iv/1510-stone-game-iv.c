#include <stdbool.h>
#include <stdlib.h>

bool winnerSquareGame(int n) {
    bool* dp = (bool*)calloc(n + 1, sizeof(bool));

    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j * j <= i; ++j) {
            int square = j * j;

            if (!dp[i - square]) {
                dp[i] = true;
                break;
            }
        }
    }

    bool result = dp[n];

    free(dp);

    return result;
}