class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        int start = 0;

        while (start < n) {
            int end = start;

            // Find a group where consecutive values differ <= limit
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Collect original indices of this group
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            // Sort indices so smallest values go to smallest positions
            sort(indices.begin(), indices.end());

            // Assign sorted values to sorted indices
            for (int i = start; i <= end; i++) {
                nums[indices[i - start]] = arr[i].first;
            }

            start = end + 1;
        }

        return nums;
    }
};