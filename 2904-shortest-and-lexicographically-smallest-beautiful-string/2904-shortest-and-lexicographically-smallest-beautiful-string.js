/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var shortestBeautifulSubstring = function(s, k) {
    let left = 0;
    let ones = 0;
    let ans = "";

    for (let right = 0; right < s.length; right++) {

        if (s[right] === '1') {
            ones++;
        }

        while (ones > k) {
            if (s[left] === '1') {
                ones--;
            }
            left++;
        }

        if (ones === k) {

            while (left < right && s[left] === '0') {
                left++;
            }

            const curr = s.substring(left, right + 1);

            if (
                ans === "" ||
                curr.length < ans.length ||
                (curr.length === ans.length && curr < ans)
            ) {
                ans = curr;
            }
        }
    }

    return ans;
};