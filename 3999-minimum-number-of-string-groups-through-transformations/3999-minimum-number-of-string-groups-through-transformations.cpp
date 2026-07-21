class Solution {
public:
    string minRotation(const string &s) {
        int n = s.size();
        if (n <= 1) return s;

        string t = s + s;
        int i = 0, j = 1, k = 0;

        while (i < n && j < n && k < n) {
            if (t[i + k] == t[j + k]) {
                k++;
            } else if (t[i + k] > t[j + k]) {
                i += k + 1;
                if (i <= j) i = j + 1;
                k = 0;
            } else {
                j += k + 1;
                if (j <= i) j = i + 1;
                k = 0;
            }
        }

        int start = min(i, j);
        return t.substr(start, n);
    }

    int minimumGroups(vector<string>& words) {
        unordered_set<string> st;

        for (string &word : words) {
            string even = "", odd = "";

            for (int i = 0; i < word.size(); i++) {
                if (i % 2 == 0)
                    even += word[i];
                else
                    odd += word[i];
            }

            string key = minRotation(even) + "#" + minRotation(odd);
            st.insert(key);
        }

        return st.size();
    }
};