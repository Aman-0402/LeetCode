class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int current = 0;
        int maximum = 0;

        for (int num : nums) {
            if (num == 1) {
                current++;
                maximum = Math.max(maximum, current);
            } else {
                current = 0;
            }
        }

        return maximum;
    }
}