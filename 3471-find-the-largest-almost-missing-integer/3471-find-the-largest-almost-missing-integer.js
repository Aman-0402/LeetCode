/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var largestInteger = function(nums, k) {
    const n = nums.length;

    const count = new Map();

    for (const x of nums) {
        count.set(x, (count.get(x) || 0) + 1);
    }

    // Every element forms its own subarray
    if (k === 1) {
        let ans = -1;

        for (const x of nums) {
            if (count.get(x) === 1) {
                ans = Math.max(ans, x);
            }
        }

        return ans;
    }

    // Entire array is one subarray
    if (k === n) {
        return Math.max(...nums);
    }

    // Only first and last elements can qualify
    let ans = -1;

    if (count.get(nums[0]) === 1) {
        ans = Math.max(ans, nums[0]);
    }

    if (count.get(nums[n - 1]) === 1) {
        ans = Math.max(ans, nums[n - 1]);
    }

    return ans;
};