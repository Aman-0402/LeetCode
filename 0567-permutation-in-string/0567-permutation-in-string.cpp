class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Frequency of s1
        for (char c : s1)
            freq1[c - 'a']++;

        // First window
        for (int i = 0; i < s1.length(); i++)
            freq2[s2[i] - 'a']++;

        if (freq1 == freq2)
            return true;

        // Slide window
        for (int i = s1.length(); i < s2.length(); i++) {

            freq2[s2[i] - 'a']++;

            freq2[s2[i - s1.length()] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};