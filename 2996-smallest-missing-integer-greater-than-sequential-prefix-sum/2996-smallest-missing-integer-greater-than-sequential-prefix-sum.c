#include <stdlib.h>
#include <stdbool.h>

int missingInteger(int* nums, int numsSize) {
    int sum = nums[0];

    int i = 1;

    // Find sequential prefix sum
    while (i < numsSize &&
           nums[i] == nums[i - 1] + 1) {
        sum += nums[i];
        ++i;
    }

    /*
     * nums[i] is at most 100, and the prefix
     * sum is at most around 5050 for the given
     * constraints, so we can use a boolean array.
     */
    bool* seen = (bool*)calloc(10001, sizeof(bool));

    for (i = 0; i < numsSize; ++i) {
        if (nums[i] >= 0 && nums[i] <= 10000) {
            seen[nums[i]] = true;
        }
    }

    while (sum <= 10000 && seen[sum]) {
        ++sum;
    }

    free(seen);

    return sum;
}