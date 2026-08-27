/**
 * @param {string} s
 * @param {string} target
 * @return {string}
 */
var lexGreaterPermutation = function(s, target) {
    const n = s.length;

    let cnt = new Array(26).fill(0);

    for (const c of s) {
        cnt[c.charCodeAt(0) - 97]++;
    }

    let bestPos = -1;
    let bestChar = -1;

    for (let i = 0; i < n; i++) {
        const x = target.charCodeAt(i) - 97;

        // Find smallest character greater than target[i]
        for (let c = x + 1; c < 26; c++) {
            if (cnt[c] > 0) {
                bestPos = i;
                bestChar = c;
                break;
            }
        }

        // Must be able to match target[i]
        if (cnt[x] === 0) {
            break;
        }

        cnt[x]--;
    }

    // No greater permutation exists
    if (bestPos === -1) {
        return "";
    }

    // Rebuild frequency array
    cnt = new Array(26).fill(0);

    for (const c of s) {
        cnt[c.charCodeAt(0) - 97]++;
    }

    let ans = "";

    // Match prefix
    for (let i = 0; i < bestPos; i++) {
        ans += target[i];
        cnt[target.charCodeAt(i) - 97]--;
    }

    // Make permutation greater
    ans += String.fromCharCode(97 + bestChar);
    cnt[bestChar]--;

    // Smallest possible suffix
    for (let c = 0; c < 26; c++) {
        if (cnt[c] > 0) {
            ans += String.fromCharCode(97 + c).repeat(cnt[c]);
        }
    }

    return ans;
};