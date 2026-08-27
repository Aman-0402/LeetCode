class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        int cnt[26] = {};

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Position and character of the latest possible increase.
        int bestPos = -1;
        int bestChar = -1;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            // Find the smallest available character greater than target[i].
            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bestPos = i;
                    bestChar = c;
                    break;
                }
            }

            // We must be able to match target[i] to continue.
            if (cnt[x] == 0) {
                break;
            }

            cnt[x]--;
        }

        // No possible permutation greater than target.
        if (bestPos == -1) {
            return "";
        }

        // Rebuild counts from scratch.
        fill(cnt, cnt + 26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans;

        // Keep prefix equal to target.
        for (int i = 0; i < bestPos; i++) {
            ans += target[i];
            cnt[target[i] - 'a']--;
        }

        // Make this position just slightly greater.
        ans += char('a' + bestChar);
        cnt[bestChar]--;

        // Smallest possible suffix.
        for (int c = 0; c < 26; c++) {
            ans.append(cnt[c], char('a' + c));
        }

        return ans;
    }
};