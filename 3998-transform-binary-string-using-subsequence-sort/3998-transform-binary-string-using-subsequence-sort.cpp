class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();

        vector<int> pref(n);
        int totalOnes = 0;

        // Prefix count of 1's in s
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') totalOnes++;
            pref[i] = totalOnes;
        }

        vector<bool> ans;

        for (string t : strs) {
            int fixedOnes = 0, q = 0;

            for (char c : t) {
                if (c == '1')
                    fixedOnes++;
                else if (c == '?')
                    q++;
            }

            int need = totalOnes - fixedOnes;

            if (need < 0 || need > q) {
                ans.push_back(false);
                continue;
            }

            // Place required 1's in the rightmost '?' positions
            for (int i = n - 1; i >= 0 && need > 0; i--) {
                if (t[i] == '?') {
                    t[i] = '1';
                    need--;
                }
            }

            // Remaining '?' become '0'
            for (char &c : t)
                if (c == '?')
                    c = '0';

            bool ok = true;
            int cur = 0;

            for (int i = 0; i < n; i++) {
                if (t[i] == '1')
                    cur++;

                if (cur > pref[i]) {
                    ok = false;
                    break;
                }
            }

            ans.push_back(ok);
        }

        return ans;
    }
};