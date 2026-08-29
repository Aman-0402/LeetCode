#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

int comparePairs(const void* a, const void* b) {
    Pair* p1 = (Pair*)a;
    Pair* p2 = (Pair*)b;

    return p1->value - p2->value;
}

int compareInts(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note:
 * LeetCode's C signature may use:
 * int* nums, int numsSize, int limit, int* returnSize
 */
int* lexicographicallySmallestArray(
    int* nums,
    int numsSize,
    int limit,
    int* returnSize
) {
    int n = numsSize;

    Pair* arr = malloc(n * sizeof(Pair));

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
    }

    // Sort by value
    qsort(
        arr,
        n,
        sizeof(Pair),
        comparePairs
    );

    int start = 0;

    while (start < n) {

        int end = start;

        // Find group
        while (
            end + 1 < n &&
            arr[end + 1].value - arr[end].value <= limit
        ) {
            end++;
        }

        int size = end - start + 1;

        int* indices = malloc(size * sizeof(int));

        for (int i = start; i <= end; i++) {
            indices[i - start] = arr[i].index;
        }

        // Sort original indices
        qsort(
            indices,
            size,
            sizeof(int),
            compareInts
        );

        // Assign sorted values to sorted indices
        for (int i = start; i <= end; i++) {
            nums[indices[i - start]] = arr[i].value;
        }

        free(indices);

        start = end + 1;
    }

    free(arr);

    *returnSize = n;

    return nums;
}