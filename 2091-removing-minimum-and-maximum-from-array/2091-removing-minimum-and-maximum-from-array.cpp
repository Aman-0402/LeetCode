class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Make minIndex the smaller index
        if (minIndex > maxIndex)
            swap(minIndex, maxIndex);

        // Option 1:
        // Remove both from the left
        int left = maxIndex + 1;

        // Option 2:
        // Remove both from the right
        int right = n - minIndex;

        // Option 3:
        // Remove min from left and max from right
        int mixed = (minIndex + 1) + (n - maxIndex);

        return min({left, right, mixed});
    }
};