/**
 * @param {string} word1
 * @param {string} word2
 * @return {number[]}
 */
var validSequence = function(word1, word2) {
    const n = word1.length;
    const m = word2.length;

    const ans = [];
    const last = new Array(m).fill(-1);

    // Find the latest possible matching
    // position for every character of word2.
    let i = n - 1;
    let j = m - 1;

    while (i >= 0 && j >= 0) {
        if (word1[i] === word2[j]) {
            last[j] = i;
            --j;
        }
        --i;
    }

    let canSkip = true;
    j = 0;

    for (i = 0; i < n; ++i) {
        if (j === m)
            break;

        // Exact match
        if (word1[i] === word2[j]) {
            ans.push(i);
            ++j;
        }

        // Use the one allowed mismatch
        else if (
            canSkip &&
            (j === m - 1 || i < last[j + 1])
        ) {
            ans.push(i);
            ++j;
            canSkip = false;
        }
    }

    return j === m ? ans : [];
};