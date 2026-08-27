#include <stdlib.h>
#include <string.h>

char* lexGreaterPermutation(char* s, char* target) {
    int n = strlen(s);

    int cnt[26] = {0};

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    int bestPos = -1;
    int bestChar = -1;

    // Find the rightmost position where we can make
    // the permutation greater.
    for (int i = 0; i < n; i++) {
        int x = target[i] - 'a';

        // Find smallest character greater than target[i]
        for (int c = x + 1; c < 26; c++) {
            if (cnt[c] > 0) {
                bestPos = i;
                bestChar = c;
                break;
            }
        }

        // Must match target[i]
        if (cnt[x] == 0) {
            break;
        }

        cnt[x]--;
    }

    // No greater permutation exists
    if (bestPos == -1) {
        char* result = malloc(1);
        result[0] = '\0';
        return result;
    }

    // Rebuild counts
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    char* ans = malloc((n + 1) * sizeof(char));
    int index = 0;

    // Match prefix
    for (int i = 0; i < bestPos; i++) {
        ans[index++] = target[i];
        cnt[target[i] - 'a']--;
    }

    // Make it greater
    ans[index++] = 'a' + bestChar;
    cnt[bestChar]--;

    // Smallest possible suffix
    for (int c = 0; c < 26; c++) {
        while (cnt[c] > 0) {
            ans[index++] = 'a' + c;
            cnt[c]--;
        }
    }

    ans[index] = '\0';

    return ans;
}