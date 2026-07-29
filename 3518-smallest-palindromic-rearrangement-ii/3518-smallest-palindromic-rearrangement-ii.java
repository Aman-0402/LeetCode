class Solution {
    private static final long MAX = 1000001;

    public String smallestPalindrome(String s, int k) {
        int[] freq = new int[26];

        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if ((freq[i] & 1) == 1) {
                mid = (char) ('a' + i);
                freq[i]--;
                break;
            }
        }

        int[] half = new int[26];
        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
        }

        if (multinomial(half) < k)
            return "";

        StringBuilder left = new StringBuilder();

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long ways = multinomial(half);

                if (ways >= k) {
                    left.append((char) ('a' + c));
                    break;
                }

                k -= (int) ways;
                half[c]++;
            }
        }

        String right = new StringBuilder(left).reverse().toString();

        if (mid == 0)
            return left.toString() + right;

        return left.toString() + mid + right;
    }

    private long multinomial(int[] cnt) {

        int total = 0;

        for (int x : cnt)
            total += x;

        long ans = 1;

        for (int i = 0; i < 26; i++) {

            ans *= binom(total, cnt[i]);

            if (ans >= MAX)
                return MAX;

            total -= cnt[i];
        }

        return ans;
    }

    private long binom(int n, int r) {

        if (r > n)
            return 0;

        r = Math.min(r, n - r);

        long ans = 1;

        for (int i = 1; i <= r; i++) {

            ans = ans * (n - i + 1) / i;

            if (ans >= MAX)
                return MAX;
        }

        return ans;
    }
}