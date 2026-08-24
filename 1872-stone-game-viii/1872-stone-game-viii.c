#include <stdlib.h>

int stoneGameVIII(int* stones, int stonesSize) {
    int n = stonesSize;

    int* prefix = malloc(n * sizeof(int));

    prefix[0] = stones[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + stones[i];
    }

    int dp = prefix[n - 1];

    for (int i = n - 2; i >= 1; i--) {
        int take = prefix[i] - dp;

        if (take > dp) {
            dp = take;
        }
    }

    int answer = dp;

    free(prefix);

    return answer;
}