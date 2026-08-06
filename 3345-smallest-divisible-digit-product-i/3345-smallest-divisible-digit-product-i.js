/**
 * @param {number} n
 * @param {number} t
 * @return {number}
 */
var smallestNumber = function(n, t) {

    for (let i = n;; i++) {

        let product = 1;

        for (let x = i; x > 0; x = Math.floor(x / 10))
            product *= x % 10;

        if (product % t === 0)
            return i;
    }
};