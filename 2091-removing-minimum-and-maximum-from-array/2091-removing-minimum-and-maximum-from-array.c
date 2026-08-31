#include <stdlib.h>

int minimumDeletions(int* nums, int numsSize) {

    int n = numsSize;

    int minIndex = 0;
    int maxIndex = 0;

    // Find minimum and maximum indices
    for (int i = 1; i < n; i++) {

        if (nums[i] < nums[minIndex])
            minIndex = i;

        if (nums[i] > nums[maxIndex])
            maxIndex = i;
    }

    // Make minIndex the smaller index
    if (minIndex > maxIndex) {
        int temp = minIndex;
        minIndex = maxIndex;
        maxIndex = temp;
    }

    // Both from left
    int left = maxIndex + 1;

    // Both from right
    int right = n - minIndex;

    // One from each side
    int mixed =
        (minIndex + 1) + (n - maxIndex);

    int ans = left;

    if (right < ans)
        ans = right;

    if (mixed < ans)
        ans = mixed;

    return ans;
}