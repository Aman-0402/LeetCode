import java.util.*;

class Solution {
    public int missingInteger(int[] nums) {
        int sum = nums[0];

        int i = 1;

        while (i < nums.length &&
               nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            ++i;
        }

        Set<Integer> seen = new HashSet<>();

        for (int num : nums) {
            seen.add(num);
        }

        while (seen.contains(sum)) {
            ++sum;
        }

        return sum;
    }
}