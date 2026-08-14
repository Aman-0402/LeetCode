class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {};
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            int idx = s[right] - 'a';
            freq[idx]++;

            while (freq[idx] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};