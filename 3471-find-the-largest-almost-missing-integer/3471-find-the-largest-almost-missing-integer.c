#include <stdlib.h>

int largestInteger(int* nums, int numsSize, int k) {
    int count[51] = {0};

    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    // Every element forms its own subarray
    if (k == 1) {
        int ans = -1;

        for (int i = 0; i < numsSize; i++) {
            if (count[nums[i]] == 1) {
                if (nums[i] > ans) {
                    ans = nums[i];
                }
            }
        }

        return ans;
    }

    // Entire array is one subarray
    if (k == numsSize) {
        int ans = nums[0];

        for (int i = 1; i < numsSize; i++) {
            if (nums[i] > ans) {
                ans = nums[i];
            }
        }

        return ans;
    }

    // Only first and last elements can qualify
    int ans = -1;

    if (count[nums[0]] == 1) {
        ans = nums[0];
    }

    if (count[nums[numsSize - 1]] == 1 &&
        nums[numsSize - 1] > ans) {
        ans = nums[numsSize - 1];
    }

    return ans;
}