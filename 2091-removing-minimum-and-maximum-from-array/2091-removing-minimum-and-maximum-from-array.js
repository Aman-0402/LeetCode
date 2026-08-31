/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDeletions = function(nums) {

    const n = nums.length;

    let minIndex = 0;
    let maxIndex = 0;

    for (let i = 1; i < n; i++) {

        if (nums[i] < nums[minIndex]) {
            minIndex = i;
        }

        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }

    // Make minIndex the smaller index
    if (minIndex > maxIndex) {
        [minIndex, maxIndex] = [maxIndex, minIndex];
    }

    // Both from left
    const left = maxIndex + 1;

    // Both from right
    const right = n - minIndex;

    // One from each side
    const mixed =
        (minIndex + 1) + (n - maxIndex);

    return Math.min(left, right, mixed);
};