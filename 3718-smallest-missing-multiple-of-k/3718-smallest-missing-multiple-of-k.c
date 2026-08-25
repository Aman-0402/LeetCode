#include <stdbool.h>

int missingMultiple(int* nums, int numsSize, int k) {
    bool seen[10001] = {false};

    for (int i = 0; i < numsSize; i++) {
        seen[nums[i]] = true;
    }

    int multiple = k;

    while (multiple <= 10000 && seen[multiple]) {
        multiple += k;
    }

    return multiple;
}