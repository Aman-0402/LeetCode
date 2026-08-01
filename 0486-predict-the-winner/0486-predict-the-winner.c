#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b) {
    return a > b ? a : b;
}

bool predictTheWinner(int* nums, int numsSize) {

    int **dp = (int **)malloc(numsSize * sizeof(int *));

    for (int i = 0; i < numsSize; i++) {
        dp[i] = (int *)calloc(numsSize, sizeof(int));
        dp[i][i] = nums[i];
    }

    for (int len = 2; len <= numsSize; len++) {

        for (int i = 0; i + len - 1 < numsSize; i++) {

            int j = i + len - 1;

            dp[i][j] = max(
                nums[i] - dp[i + 1][j],
                nums[j] - dp[i][j - 1]
            );
        }
    }

    bool ans = dp[0][numsSize - 1] >= 0;

    for (int i = 0; i < numsSize; i++)
        free(dp[i]);

    free(dp);

    return ans;
}