/**
 * @param {string} num
 * @param {number} t
 * @return {string}
 */
var smallestNumber = function (num, t) {
    const [primeCount, isDivisible] = getPrimeCountNumber(t);

    if (!isDivisible)
        return "-1";

    const factorCount = getFactorCount(primeCount);

    if (sumValues(factorCount) > num.length)
        return construct(factorCount);

    let primeCountPrefix = getPrimeCountString(num);

    let firstZeroIndex = num.indexOf('0');

    if (firstZeroIndex === -1) {
        firstZeroIndex = num.length;
        if (isSubset(primeCount, primeCountPrefix))
            return num;
    }

    for (let i = num.length - 1; i >= 0; --i) {
        const d = Number(num[i]);

        primeCountPrefix = subtract(
            primeCountPrefix,
            kFactorCounts[d]
        );

        const spaceAfterThisDigit = num.length - 1 - i;

        if (i > firstZeroIndex)
            continue;

        for (let biggerDigit = d + 1; biggerDigit <= 9; ++biggerDigit) {

            const factorsAfterReplacement = getFactorCount(
                subtract(
                    subtract(primeCount, primeCountPrefix),
                    kFactorCounts[biggerDigit]
                )
            );

            if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {

                const fillOnes =
                    spaceAfterThisDigit - sumValues(factorsAfterReplacement);

                return (
                    num.substring(0, i) +
                    biggerDigit +
                    "1".repeat(fillOnes) +
                    construct(factorsAfterReplacement)
                );
            }
        }
    }

    const factorsAfterExtension = getFactorCount(primeCount);

    return (
        "1".repeat(num.length + 1 - sumValues(factorsAfterExtension)) +
        construct(factorsAfterExtension)
    );
};

const kFactorCounts = {
    0: {},
    1: {},
    2: { 2: 1 },
    3: { 3: 1 },
    4: { 2: 2 },
    5: { 5: 1 },
    6: { 2: 1, 3: 1 },
    7: { 7: 1 },
    8: { 2: 3 },
    9: { 3: 2 }
};

function getPrimeCountNumber(t) {
    const count = {
        2: 0,
        3: 0,
        5: 0,
        7: 0
    };

    for (const prime of [2, 3, 5, 7]) {
        while (t % prime === 0) {
            t = Math.floor(t / prime);
            count[prime]++;
        }
    }

    return [count, t === 1];
}

function getPrimeCountString(num) {
    const count = {
        2: 0,
        3: 0,
        5: 0,
        7: 0
    };

    for (const ch of num) {
        const factors = kFactorCounts[Number(ch)];
        for (const prime in factors)
            count[prime] += factors[prime];
    }

    return count;
}

function getFactorCount(count) {
    const count8 = Math.floor(count[2] / 3);
    const remaining2 = count[2] % 3;

    const count9 = Math.floor(count[3] / 2);
    let count3 = count[3] % 2;

    let count4 = Math.floor(remaining2 / 2);
    let count2 = remaining2 % 2;

    let count6 = 0;

    if (count2 === 1 && count3 === 1) {
        count2 = 0;
        count3 = 0;
        count6 = 1;
    }

    if (count3 === 1 && count4 === 1) {
        count2 = 1;
        count6 = 1;
        count3 = 0;
        count4 = 0;
    }

    return {
        2: count2,
        3: count3,
        4: count4,
        5: count[5],
        6: count6,
        7: count[7],
        8: count8,
        9: count9
    };
}

function construct(factors) {
    let res = "";

    for (let digit = 2; digit <= 9; digit++)
        res += String(digit).repeat(factors[digit]);

    return res;
}

function isSubset(a, b) {
    for (const key in a) {
        if (b[key] < a[key])
            return false;
    }
    return true;
}

function subtract(a, b) {
    const res = { ...a };

    for (const key in b)
        res[key] = Math.max(0, res[key] - b[key]);

    return res;
}

function sumValues(count) {
    let sum = 0;

    for (const key in count)
        sum += count[key];

    return sum;
}