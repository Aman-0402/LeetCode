import java.util.*;

class Solution {
    public int[] validSequence(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        int[] ans = new int[m];
        int[] last = new int[m];

        Arrays.fill(last, -1);

        // Find the latest possible matching
        // position for every character of word2.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1.charAt(i) == word2.charAt(j)) {
                last[j] = i;
                --j;
            }
            --i;
        }

        boolean canSkip = true;
        j = 0;

        for (i = 0; i < n; ++i) {
            if (j == m)
                break;

            // Exact match
            if (word1.charAt(i) == word2.charAt(j)) {
                ans[j] = i;
                ++j;
            }

            // Use the one allowed mismatch
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {
                ans[j] = i;
                ++j;
                canSkip = false;
            }
        }

        if (j == m)
            return ans;

        return new int[0];
    }
}