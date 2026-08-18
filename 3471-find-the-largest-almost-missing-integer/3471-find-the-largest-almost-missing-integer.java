class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;

        int[] count = new int[51];

        for (int x : nums) {
            count[x]++;
        }

        // Every element is its own subarray
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (count[x] == 1) {
                    ans = Math.max(ans, x);
                }
            }

            return ans;
        }

        // Entire array is one subarray
        if (k == n) {
            int ans = 0;

            for (int x : nums) {
                ans = Math.max(ans, x);
            }

            return ans;
        }

        // Only first and last elements can qualify
        int ans = -1;

        if (count[nums[0]] == 1) {
            ans = Math.max(ans, nums[0]);
        }

        if (count[nums[n - 1]] == 1) {
            ans = Math.max(ans, nums[n - 1]);
        }

        return ans;
    }
}