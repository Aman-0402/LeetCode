class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandy = *max_element(candies.begin(), candies.end());

        vector<bool> ans;

        for (int candy : candies) {
            ans.push_back(candy + extraCandies >= maxCandy);
        }

        return ans;
    }
};