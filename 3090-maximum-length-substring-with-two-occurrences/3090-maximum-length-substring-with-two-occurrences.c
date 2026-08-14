#include <string.h>

int maximumLengthSubstring(char* s) {
    int freq[26] = {0};

    int left = 0;
    int ans = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {

        int idx = s[right] - 'a';
        freq[idx]++;

        while (freq[idx] > 2) {
            freq[s[left] - 'a']--;
            left++;
        }

        int len = right - left + 1;

        if (len > ans)
            ans = len;
    }

    return ans;
}