#include <stdlib.h>

typedef struct {
    int key;
    int value;
    int used;
} Entry;

#define SIZE 262144

int hash(int key) {
    unsigned int x = (unsigned int)key;
    x ^= x >> 16;
    x *= 0x45d9f3b;
    x ^= x >> 16;
    return x & (SIZE - 1);
}

int get(Entry* table, int key) {
    int index = hash(key);

    while (table[index].used) {
        if (table[index].key == key)
            return table[index].value;

        index = (index + 1) & (SIZE - 1);
    }

    return 0;
}

void update(Entry* table, int key, int value) {
    int index = hash(key);

    while (table[index].used) {
        if (table[index].key == key) {
            table[index].value = value;
            return;
        }

        index = (index + 1) & (SIZE - 1);
    }

    table[index].used = 1;
    table[index].key = key;
    table[index].value = value;
}

int maxSubarrayLength(int* nums, int numsSize, int k) {

    Entry* table = calloc(SIZE, sizeof(Entry));

    int left = 0;
    int ans = 0;

    for (int right = 0; right < numsSize; right++) {

        int current = get(table, nums[right]);
        update(table, nums[right], current + 1);

        // Shrink window
        while (get(table, nums[right]) > k) {

            int count = get(table, nums[left]);

            update(table, nums[left], count - 1);

            left++;
        }

        int length = right - left + 1;

        if (length > ans)
            ans = length;
    }

    free(table);

    return ans;
}