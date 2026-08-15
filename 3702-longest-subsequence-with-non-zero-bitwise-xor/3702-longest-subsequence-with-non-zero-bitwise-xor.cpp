class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xr = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            xr ^= x;

            if (x != 0)
                hasNonZero = true;
        }

        // Entire array has non-zero XOR
        if (xr != 0)
            return n;

        // All elements are zero
        if (!hasNonZero)
            return 0;

        // Remove one non-zero element
        return n - 1;
    }
};