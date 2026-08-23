/**
 * @param {string} num
 * @return {boolean}
 */
var sumGame = function(num) {
    const n = num.length;

    let sumLeft = 0;
    let sumRight = 0;

    let qLeft = 0;
    let qRight = 0;

    for (let i = 0; i < n / 2; i++) {
        if (num[i] === '?') {
            qLeft++;
        } else {
            sumLeft += Number(num[i]);
        }
    }

    for (let i = n / 2; i < n; i++) {
        if (num[i] === '?') {
            qRight++;
        } else {
            sumRight += Number(num[i]);
        }
    }

    if (qLeft === qRight) {
        return sumLeft !== sumRight;
    }

    const qDiff = qLeft - qRight;
    const sumDiff = sumLeft - sumRight;

    return sumDiff * 2 !== -9 * qDiff;
};