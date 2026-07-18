class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        for (char c : p)
            freqP[c - 'a']++;

        for (int i = 0; i < p.length(); i++)
            freqS[s[i] - 'a']++;

        if (freqP == freqS)
            ans.push_back(0);

        for (int i = p.length(); i < s.length(); i++) {

            freqS[s[i] - 'a']++;

            freqS[s[i - p.length()] - 'a']--;

            if (freqP == freqS)
                ans.push_back(i - p.length() + 1);
        }

        return ans;
    }
};