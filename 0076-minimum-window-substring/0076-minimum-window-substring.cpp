class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c : t)
            need[c]++;

        int required = need.size();
        int formed = 0;

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                formed++;

            while (formed == required) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char remove = s[left];

                window[remove]--;

                if (need.count(remove) &&
                    window[remove] < need[remove])
                    formed--;

                left++;
            }
        }

        return minLen == INT_MAX
               ? ""
               : s.substr(start, minLen);
    }
};