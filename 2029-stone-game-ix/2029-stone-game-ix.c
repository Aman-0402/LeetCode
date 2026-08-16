#include <stdbool.h>
#include <stdlib.h>

bool stoneGameIX(int* stones, int stonesSize) {
    int cnt[3] = {0, 0, 0};

    for (int i = 0; i < stonesSize; i++) {
        cnt[stones[i] % 3]++;
    }

    int min12 = cnt[1] < cnt[2] ? cnt[1] : cnt[2];
    int max12 = cnt[1] > cnt[2] ? cnt[1] : cnt[2];

    if (min12 == 0) {
        return max12 > 2 && cnt[0] % 2 == 1;
    }

    return abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 == 0;
}