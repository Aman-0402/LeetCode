#include <stdlib.h>
#include <string.h>

char* shortestBeautifulSubstring(char* s, int k) {
    int n = strlen(s);

    int left = 0;
    int ones = 0;

    char* ans = NULL;
    int ansLen = 0;

    for (int right = 0; right < n; right++) {

        if (s[right] == '1') {
            ones++;
        }

        while (ones > k) {
            if (s[left] == '1') {
                ones--;
            }
            left++;
        }

        if (ones == k) {

            while (left < right && s[left] == '0') {
                left++;
            }

            int currLen = right - left + 1;

            int better = 0;

            if (ans == NULL || currLen < ansLen) {
                better = 1;
            } else if (currLen == ansLen) {
                for (int i = 0; i < currLen; i++) {
                    if (s[left + i] < ans[i]) {
                        better = 1;
                        break;
                    }

                    if (s[left + i] > ans[i]) {
                        break;
                    }
                }
            }

            if (better) {
                free(ans);

                ans = malloc((currLen + 1) * sizeof(char));

                for (int i = 0; i < currLen; i++) {
                    ans[i] = s[left + i];
                }

                ans[currLen] = '\0';
                ansLen = currLen;
            }
        }
    }

    if (ans == NULL) {
        ans = malloc(1);
        ans[0] = '\0';
    }

    return ans;
}