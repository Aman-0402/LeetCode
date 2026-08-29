/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number[]}
 */
var lexicographicallySmallestArray = function(nums, limit) {

    const n = nums.length;

    // [value, originalIndex]
    const arr = [];

    for (let i = 0; i < n; i++) {
        arr.push([nums[i], i]);
    }

    // Sort by value
    arr.sort((a, b) => a[0] - b[0]);

    let start = 0;

    while (start < n) {

        let end = start;

        // Find group
        while (
            end + 1 < n &&
            arr[end + 1][0] - arr[end][0] <= limit
        ) {
            end++;
        }

        // Get original indices
        const indices = [];

        for (let i = start; i <= end; i++) {
            indices.push(arr[i][1]);
        }

        // Sort indices
        indices.sort((a, b) => a - b);

        // Assign smallest values to smallest indices
        for (let i = start; i <= end; i++) {
            nums[indices[i - start]] = arr[i][0];
        }

        start = end + 1;
    }

    return nums;
};