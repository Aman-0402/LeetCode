class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> ans(m);
        vector<int> last(m, -1);

        // last[j] = latest index in word1
        // that can match word2[j]
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }
            --i;
        }

        bool canSkip = true;
        j = 0;

        for (i = 0; i < n; ++i) {
            if (j == m)
                break;

            // Exact match
            if (word1[i] == word2[j]) {
                ans[j] = i;
                ++j;
            }

            // Use our one allowed mismatch
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {
                ans[j] = i;
                ++j;
                canSkip = false;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};