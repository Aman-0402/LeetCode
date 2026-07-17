class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int count = 0;

        // First window
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                count++;
        }

        int maxCount = count;

        // Slide the window
        for (int i = k; i < s.length(); i++) {
            if (isVowel(s[i - k]))
                count--;

            if (isVowel(s[i]))
                count++;

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};