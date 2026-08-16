/**
 * @param {number[]} stones
 * @return {boolean}
 */
var stoneGameIX = function(stones) {
    const cnt = [0, 0, 0];

    for (const x of stones) {
        cnt[x % 3]++;
    }

    if (Math.min(cnt[1], cnt[2]) === 0) {
        return Math.max(cnt[1], cnt[2]) > 2 && cnt[0] % 2 === 1;
    }

    return Math.abs(cnt[1] - cnt[2]) > 2 || cnt[0] % 2 === 0;
};