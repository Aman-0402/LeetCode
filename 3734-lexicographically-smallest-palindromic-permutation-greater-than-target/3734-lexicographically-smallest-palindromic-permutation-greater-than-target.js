/**
 * @param {string} s
 * @param {string} target
 * @return {string}
 */
var lexPalindromicPermutation = function(s, target) {

    const n = s.length;

    const cnt = new Array(26).fill(0);

    for (const ch of s) {
        cnt[ch.charCodeAt(0) - 97]++;
    }

    let odd = 0;
    let mid = '#';

    for (let i = 0; i < 26; i++) {
        if (cnt[i] % 2 === 1) {
            odd++;
            mid = String.fromCharCode(97 + i);
        }
    }

    if (odd > 1)
        return "";

    const half = cnt.map(x => Math.floor(x / 2));

    const halfLen = Math.floor(n / 2);

    let left = "";

    function build(leftPart) {

        let res = leftPart;

        if (mid !== '#')
            res += mid;

        for (let i = leftPart.length - 1; i >= 0; i--) {
            res += leftPart[i];
        }

        return res;
    }

    for (let pos = 0; pos < halfLen; pos++) {

        let found = false;

        for (let c = 0; c < 26; c++) {

            if (half[c] === 0)
                continue;

            half[c]--;
            left += String.fromCharCode(97 + c);

            // Largest possible completion
            let maxLeft = left;

            for (let x = 25; x >= 0; x--) {
                maxLeft += String.fromCharCode(97 + x)
                    .repeat(half[x]);
            }

            const candidate = build(maxLeft);

            if (candidate > target) {
                found = true;
                break;
            }

            half[c]++;
            left = left.slice(0, -1);
        }

        if (!found)
            return "";
    }

    const ans = build(left);

    return ans > target ? ans : "";
};