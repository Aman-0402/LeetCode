#include <stdlib.h>

int* resultArray(
    int* nums,
    int numsSize,
    int* returnSize
) {
    int* arr1 = malloc(numsSize * sizeof(int));
    int* arr2 = malloc(numsSize * sizeof(int));
    int* result = malloc(numsSize * sizeof(int));

    int size1 = 1;
    int size2 = 1;

    arr1[0] = nums[0];
    arr2[0] = nums[1];

    for (int i = 2; i < numsSize; i++) {
        if (arr1[size1 - 1] > arr2[size2 - 1]) {
            arr1[size1++] = nums[i];
        } else {
            arr2[size2++] = nums[i];
        }
    }

    int index = 0;

    for (int i = 0; i < size1; i++) {
        result[index++] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        result[index++] = arr2[i];
    }

    free(arr1);
    free(arr2);

    *returnSize = numsSize;

    return result;
}