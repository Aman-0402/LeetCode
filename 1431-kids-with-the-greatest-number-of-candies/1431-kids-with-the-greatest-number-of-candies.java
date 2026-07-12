import java.util.*;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int maxCandy = 0;

        for (int candy : candies) {
            maxCandy = Math.max(maxCandy, candy);
        }

        List<Boolean> ans = new ArrayList<>();

        for (int candy : candies) {
            ans.add(candy + extraCandies >= maxCandy);
        }

        return ans;
    }
}