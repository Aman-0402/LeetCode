/**
 * @param {number[]} coins
 * @param {number} k
 * @return {number}
 */
var findKthSmallest = function(coins, k) {

    const n = coins.length;

    function gcd(a, b) {
        while (b !== 0) {
            let t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    function lcm(a, b) {
        return a / gcd(a, b) * b;
    }

    function count(x) {
        let result = 0;

        for (let mask = 1; mask < (1 << n); mask++) {
            let mult = 1;
            let bits = 0;
            let valid = true;

            for (let i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    mult = lcm(mult, coins[i]);

                    if (mult > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) continue;

            const ways = Math.floor(x / mult);

            if (bits % 2 === 1)
                result += ways;
            else
                result -= ways;
        }

        return result;
    }

    let low = 1;
    let high = Math.min(...coins) * k;

    while (low < high) {
        const mid = Math.floor((low + high) / 2);

        if (count(mid) >= k)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
};