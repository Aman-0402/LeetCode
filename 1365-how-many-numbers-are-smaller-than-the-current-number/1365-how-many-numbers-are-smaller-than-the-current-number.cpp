class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> map;

        for (int i = 0; i < sorted.size(); i++) {
            if (map.find(sorted[i]) == map.end()) {
                map[sorted[i]] = i;
            }
        }

        vector<int> ans;

        for (int num : nums) {
            ans.push_back(map[num]);
        }

        return ans;
    }
};