#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* stoneGameIII(int* stoneValue, int stoneValueSize) {

    int *dp = (int *)malloc((stoneValueSize + 1) * sizeof(int));

    for (int i = 0; i <= stoneValueSize; i++)
        dp[i] = INT_MIN;

    dp[stoneValueSize] = 0;

    for (int i = stoneValueSize - 1; i >= 0; i--) {

        int take = 0;

        for (int k = 0; k < 3 && i + k < stoneValueSize; k++) {

            take += stoneValue[i + k];

            int diff = take - dp[i + k + 1];

            if (diff > dp[i])
                dp[i] = diff;
        }
    }

    int ans = dp[0];   // Save before freeing

    free(dp);

    if (ans > 0)
        return "Alice";
    else if (ans < 0)
        return "Bob";
    else
        return "Tie";
}