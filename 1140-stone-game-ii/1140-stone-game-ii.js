/**
 * @param {number[]} piles
 * @return {number}
 */
var stoneGameII = function(piles) {
    const n = piles.length;

    const suffix = new Array(n + 1).fill(0);

    for (let i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + piles[i];
    }

    const dp = Array.from(
        { length: n },
        () => new Array(n + 1).fill(-1)
    );

    function solve(i, M) {
        if (i >= n)
            return 0;

        if (i + 2 * M >= n)
            return suffix[i];

        if (dp[i][M] !== -1)
            return dp[i][M];

        let best = 0;

        for (let x = 1; x <= 2 * M; ++x) {
            const opponent =
                solve(i + x, Math.max(M, x));

            best = Math.max(
                best,
                suffix[i] - opponent
            );
        }

        dp[i][M] = best;

        return best;
    }

    return solve(0, 1);
};