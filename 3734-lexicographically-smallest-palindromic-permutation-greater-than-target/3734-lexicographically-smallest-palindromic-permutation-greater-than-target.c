#include <stdlib.h>
#include <string.h>

char* buildPalindrome(char* left, int len, char mid) {

    int n = 2 * len + (mid != '#');

    char* res = (char*)malloc(n + 1);

    int idx = 0;

    for (int i = 0; i < len; i++)
        res[idx++] = left[i];

    if (mid != '#')
        res[idx++] = mid;

    for (int i = len - 1; i >= 0; i--)
        res[idx++] = left[i];

    res[idx] = '\0';

    return res;
}

char* lexPalindromicPermutation(char* s, char* target) {

    int n = strlen(s);

    int cnt[26] = {0};

    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    int odd = 0;
    char mid = '#';

    for (int i = 0; i < 26; i++) {

        if (cnt[i] % 2) {
            odd++;
            mid = 'a' + i;
        }
    }

    if (odd > 1)
        return strdup("");

    int half[26];

    for (int i = 0; i < 26; i++)
        half[i] = cnt[i] / 2;

    int halfLen = n / 2;

    char left[305];
    int leftLen = 0;

    for (int pos = 0; pos < halfLen; pos++) {

        int found = 0;

        for (int c = 0; c < 26; c++) {

            if (half[c] == 0)
                continue;

            half[c]--;
            left[leftLen++] = 'a' + c;
            left[leftLen] = '\0';

            /*
             * Construct largest possible left half.
             */
            char maxLeft[305];

            memcpy(maxLeft, left, leftLen);

            int maxLen = leftLen;

            for (int x = 25; x >= 0; x--) {

                for (int k = 0; k < half[x]; k++) {
                    maxLeft[maxLen++] = 'a' + x;
                }
            }

            maxLeft[maxLen] = '\0';

            char* candidate =
                buildPalindrome(maxLeft, maxLen, mid);

            if (strcmp(candidate, target) > 0) {

                found = 1;
                free(candidate);
                break;
            }

            free(candidate);

            half[c]++;
            leftLen--;
            left[leftLen] = '\0';
        }

        if (!found)
            return strdup("");
    }

    char* ans =
        buildPalindrome(left, leftLen, mid);

    if (strcmp(ans, target) > 0)
        return ans;

    free(ans);

    return strdup("");
}