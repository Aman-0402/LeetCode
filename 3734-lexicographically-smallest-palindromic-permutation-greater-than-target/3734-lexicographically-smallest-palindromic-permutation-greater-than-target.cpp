class Solution {
public:
    string build(string &left, char mid) {
        string res = left;

        if (mid != '#')
            res += mid;

        for (int i = (int)left.size() - 1; i >= 0; i--)
            res += left[i];

        return res;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check if a palindrome can be formed
        int odd = 0;
        char mid = '#';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for the left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int halfLen = n / 2;

        string left;

        /*
         * Build the answer from left to right.
         */
        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Try character c
                half[c]--;
                left.push_back(char('a' + c));

                /*
                 * Put all remaining characters in descending order.
                 * This creates the largest palindrome having this prefix.
                 */
                string maxLeft = left;

                for (int x = 25; x >= 0; x--) {
                    maxLeft.append(
                        half[x],
                        char('a' + x)
                    );
                }

                string candidate = build(maxLeft, mid);

                /*
                 * If even the largest possible palindrome
                 * is not greater than target, this character
                 * cannot be used here.
                 */
                if (candidate > target) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        string ans = build(left, mid);

        if (ans > target)
            return ans;

        return "";
    }
};