class Solution {
    public String lexGreaterPermutation(String s, String target) {
        int n = s.length();

        int[] cnt = new int[26];

        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        int bestPos = -1;
        int bestChar = -1;

        for (int i = 0; i < n; i++) {
            int x = target.charAt(i) - 'a';

            // Find smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bestPos = i;
                    bestChar = c;
                    break;
                }
            }

            // Must be able to match target[i]
            if (cnt[x] == 0) {
                break;
            }

            cnt[x]--;
        }

        // No greater permutation exists
        if (bestPos == -1) {
            return "";
        }

        // Rebuild frequency array
        cnt = new int[26];

        for (char c : s.toCharArray()) {
            cnt[c - 'a']++;
        }

        StringBuilder ans = new StringBuilder();

        // Match prefix
        for (int i = 0; i < bestPos; i++) {
            ans.append(target.charAt(i));
            cnt[target.charAt(i) - 'a']--;
        }

        // Make permutation greater
        ans.append((char) ('a' + bestChar));
        cnt[bestChar]--;

        // Smallest possible suffix
        for (int c = 0; c < 26; c++) {
            while (cnt[c] > 0) {
                ans.append((char) ('a' + c));
                cnt[c]--;
            }
        }

        return ans.toString();
    }
}