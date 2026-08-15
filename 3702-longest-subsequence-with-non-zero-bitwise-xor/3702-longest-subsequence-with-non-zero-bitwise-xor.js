var longestSubsequence = function(nums) {

    const n = nums.length;

    let xor = 0;
    let hasNonZero = false;

    for (const x of nums) {
        xor ^= x;

        if (x !== 0) {
            hasNonZero = true;
        }
    }

    // Entire array has non-zero XOR
    if (xor !== 0) {
        return n;
    }

    // All elements are zero
    if (!hasNonZero) {
        return 0;
    }

    // Remove one non-zero element
    return n - 1;
};