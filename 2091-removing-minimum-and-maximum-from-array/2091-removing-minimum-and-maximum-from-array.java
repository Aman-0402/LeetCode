class Solution {
    public int minimumDeletions(int[] nums) {
        int n = nums.length;

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // Make minIndex the smaller index
        if (minIndex > maxIndex) {
            int temp = minIndex;
            minIndex = maxIndex;
            maxIndex = temp;
        }

        // Both from left
        int left = maxIndex + 1;

        // Both from right
        int right = n - minIndex;

        // One from each side
        int mixed = (minIndex + 1) + (n - maxIndex);

        return Math.min(left, Math.min(right, mixed));
    }
}