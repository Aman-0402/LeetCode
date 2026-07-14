class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;

        for (int num : nums) {
            int digits = 0;
            int temp = num;

            while (temp > 0) {
                digits++;
                temp /= 10;
            }

            if (digits % 2 == 0)
                count++;
        }

        return count;
    }
};