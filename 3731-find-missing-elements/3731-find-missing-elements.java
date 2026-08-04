import java.util.*;

class Solution {
    public List<Integer> findMissingElements(int[] nums) {

        int mn = Integer.MAX_VALUE;
        int mx = Integer.MIN_VALUE;

        Set<Integer> set = new HashSet<>();

        for (int x : nums) {
            mn = Math.min(mn, x);
            mx = Math.max(mx, x);
            set.add(x);
        }

        List<Integer> ans = new ArrayList<>();

        for (int x = mn + 1; x < mx; x++) {
            if (!set.contains(x))
                ans.add(x);
        }

        return ans;
    }
}