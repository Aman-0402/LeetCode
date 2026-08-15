int longestSubsequence(int* nums, int numsSize) {

    int xor = 0;
    int hasNonZero = 0;

    for (int i = 0; i < numsSize; i++) {

        xor ^= nums[i];

        if (nums[i] != 0) {
            hasNonZero = 1;
        }
    }

    // Entire array works
    if (xor != 0) {
        return numsSize;
    }

    // All elements are zero
    if (!hasNonZero) {
        return 0;
    }

    // Remove one non-zero element
    return numsSize - 1;
}