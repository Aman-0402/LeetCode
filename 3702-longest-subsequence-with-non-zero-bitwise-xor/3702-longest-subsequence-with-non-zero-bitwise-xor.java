class Solution {
    public int longestSubsequence(int[] nums) {

        int n = nums.length;

        int xor = 0;
        boolean hasNonZero = false;

        for (int x : nums) {
            xor ^= x;

            if (x != 0)
                hasNonZero = true;
        }

        // Entire array works
        if (xor != 0)
            return n;

        // Every element is zero
        if (!hasNonZero)
            return 0;

        // Remove one non-zero element
        return n - 1;
    }
}