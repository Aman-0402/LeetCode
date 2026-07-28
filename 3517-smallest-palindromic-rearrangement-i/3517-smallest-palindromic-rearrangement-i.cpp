class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string left = "";
        string middle = "";
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                middle = string(1, (char)('a' + i));
            }
            left += string(freq[i] / 2, (char)('a' + i));
        }
        
        string right = left;
        reverse(right.begin(), right.end());
        
        return left + middle + right;
    }
};
