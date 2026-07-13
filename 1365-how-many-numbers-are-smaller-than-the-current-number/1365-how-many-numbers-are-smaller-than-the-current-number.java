import java.util.*;

class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] count = new int[102]; // 0..100, extra slot avoids bounds issues

        for (int i = 0; i < n; i++) {
            count[nums[i] + 1]++;
        }

        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = count[nums[i]];
        }

        return ans;
    }
}