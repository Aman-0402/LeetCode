class Solution {

    private String build(String left, char mid) {
        StringBuilder res = new StringBuilder(left);

        if (mid != '#')
            res.append(mid);

        for (int i = left.length() - 1; i >= 0; i--)
            res.append(left.charAt(i));

        return res.toString();
    }

    public String lexPalindromicPermutation(String s, String target) {

        int n = s.length();

        int[] cnt = new int[26];

        for (char c : s.toCharArray())
            cnt[c - 'a']++;

        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = (char) ('a' + i);
            }
        }

        if (odd > 1)
            return "";

        int[] half = new int[26];

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int halfLen = n / 2;

        StringBuilder left = new StringBuilder();

        for (int pos = 0; pos < halfLen; pos++) {

            boolean found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;
                left.append((char) ('a' + c));

                // Largest possible completion
                StringBuilder maxLeft =
                    new StringBuilder(left);

                for (int x = 25; x >= 0; x--) {
                    for (int k = 0; k < half[x]; k++) {
                        maxLeft.append((char) ('a' + x));
                    }
                }

                String candidate =
                    build(maxLeft.toString(), mid);

                if (candidate.compareTo(target) > 0) {
                    found = true;
                    break;
                }

                half[c]++;
                left.deleteCharAt(left.length() - 1);
            }

            if (!found)
                return "";
        }

        String ans = build(left.toString(), mid);

        return ans.compareTo(target) > 0 ? ans : "";
    }
}