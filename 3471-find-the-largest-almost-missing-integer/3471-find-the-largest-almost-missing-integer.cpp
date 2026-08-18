class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> count(51, 0);

        for (int x : nums) {
            count[x]++;
        }

        // Every element is its own subarray
        if (k == 1) {
            int ans = -1;

            for (int x : nums) {
                if (count[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Entire array is one subarray
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Only first and last elements can qualify
        int ans = -1;

        if (count[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (count[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};