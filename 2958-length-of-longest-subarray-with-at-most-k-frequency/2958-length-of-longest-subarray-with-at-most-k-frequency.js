var maxSubarrayLength = function(nums, k) {
    const freq = new Map();

    let left = 0;
    let ans = 0;

    for (let right = 0; right < nums.length; right++) {

        freq.set(
            nums[right],
            (freq.get(nums[right]) || 0) + 1
        );

        // Shrink window if frequency exceeds k
        while (freq.get(nums[right]) > k) {
            freq.set(
                nums[left],
                freq.get(nums[left]) - 1
            );

            left++;
        }

        ans = Math.max(ans, right - left + 1);
    }

    return ans;
};