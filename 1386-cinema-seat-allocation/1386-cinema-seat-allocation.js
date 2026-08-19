/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function(n, reservedSeats) {
    const rows = new Map();

    for (const [row, col] of reservedSeats) {
        if (col >= 2 && col <= 11) {
            const mask = rows.get(row) || 0;
            rows.set(row, mask | (1 << (col - 2)));
        }
    }

    let answer = (n - rows.size) * 2;

    for (const mask of rows.values()) {
        const left = (mask & 0b00001111) === 0;
        const middle = (mask & 0b00111100) === 0;
        const right = (mask & 0b11110000) === 0;

        if (left && right) {
            answer += 2;
        }
        else if (left || middle || right) {
            answer += 1;
        }
    }

    return answer;
};