#include <stdlib.h>
#include <string.h>

int* validSequence(char* word1, char* word2, int* returnSize) {
    int n = strlen(word1);
    int m = strlen(word2);

    int* ans = (int*)malloc(sizeof(int) * m);
    int* last = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < m; ++i) {
        last[i] = -1;
    }

    /*
     * Find the latest possible matching position
     * for every character of word2.
     */
    int i = n - 1;
    int j = m - 1;

    while (i >= 0 && j >= 0) {
        if (word1[i] == word2[j]) {
            last[j] = i;
            --j;
        }

        --i;
    }

    int canSkip = 1;
    j = 0;

    for (i = 0; i < n; ++i) {
        if (j == m)
            break;

        /*
         * Exact match
         */
        if (word1[i] == word2[j]) {
            ans[j] = i;
            ++j;
        }

        /*
         * Use the one allowed mismatch
         */
        else if (
            canSkip &&
            (j == m - 1 || i < last[j + 1])
        ) {
            ans[j] = i;
            ++j;
            canSkip = 0;
        }
    }

    free(last);

    if (j == m) {
        *returnSize = m;
        return ans;
    }

    free(ans);

    *returnSize = 0;
    return NULL;
}