#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int minimumPushes(char* word) {
    int freq[26] = {0};

    for (int i = 0; word[i] != '\0'; i++) {
        freq[word[i] - 'a']++;
    }

    qsort(freq, 26, sizeof(int), compare);

    int ans = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0)
            break;

        ans += freq[i] * (i / 8 + 1);
    }

    return ans;
}