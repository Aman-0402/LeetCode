#include <stdlib.h>
#include <stdbool.h>

int* findMissingElements(int* nums, int numsSize, int* returnSize) {

    bool present[101] = {false};

    int mn = 101;
    int mx = 0;

    for (int i = 0; i < numsSize; i++) {
        present[nums[i]] = true;

        if (nums[i] < mn)
            mn = nums[i];

        if (nums[i] > mx)
            mx = nums[i];
    }

    int* ans = (int*)malloc(sizeof(int) * (mx - mn + 1));

    int idx = 0;

    for (int x = mn + 1; x < mx; x++) {
        if (!present[x])
            ans[idx++] = x;
    }

    *returnSize = idx;

    return ans;
}