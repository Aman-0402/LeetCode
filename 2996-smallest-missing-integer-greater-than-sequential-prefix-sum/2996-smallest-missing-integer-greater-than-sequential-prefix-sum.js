/**
 * @param {number[]} nums
 * @return {number}
 */
var missingInteger = function(nums) {
    let sum = nums[0];

    let i = 1;

    while (
        i < nums.length &&
        nums[i] === nums[i - 1] + 1
    ) {
        sum += nums[i];
        ++i;
    }

    const seen = new Set(nums);

    while (seen.has(sum)) {
        ++sum;
    }

    return sum;
};