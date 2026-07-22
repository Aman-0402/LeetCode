class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& entry : freq)
            bucket[entry.second].push_back(entry.first);

        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};