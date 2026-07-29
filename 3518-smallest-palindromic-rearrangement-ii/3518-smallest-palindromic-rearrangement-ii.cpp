class Solution {
public:
    static constexpr long long LIMIT = 1000001;

    long long binom(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIMIT)
                return LIMIT;
        }

        return ans;
    }

    long long multinomial(vector<int>& cnt) {
        int total = 0;

        for (int x : cnt)
            total += x;

        long long ans = 1;

        for (int x : cnt) {
            ans *= binom(total, x);

            if (ans >= LIMIT)
                return LIMIT;

            total -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                mid = char('a' + i);
                freq[i]--;
                break;
            }
        }

        vector<int> half(26);

        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
        }

        if (multinomial(half) < k)
            return "";

        string left;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = multinomial(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;

        return left + right;
    }
};