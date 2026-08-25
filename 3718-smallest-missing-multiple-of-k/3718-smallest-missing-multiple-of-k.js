/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var missingMultiple = function(nums, k) {
    const seen = new Set(nums);

    let multiple = k;

    while (seen.has(multiple)) {
        multiple += k;
    }

    return multiple;
};