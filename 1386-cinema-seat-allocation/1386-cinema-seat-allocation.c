#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int row;
    int mask;
} Row;

int maxNumberOfFamilies(
    int n,
    int** reservedSeats,
    int reservedSeatsSize,
    int* reservedSeatsColSize
) {
    Row* rows = malloc(reservedSeatsSize * sizeof(Row));
    int rowCount = 0;

    for (int i = 0; i < reservedSeatsSize; i++) {
        int row = reservedSeats[i][0];
        int col = reservedSeats[i][1];

        if (col < 2 || col > 11)
            continue;

        int found = -1;

        for (int j = 0; j < rowCount; j++) {
            if (rows[j].row == row) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            rows[rowCount].row = row;
            rows[rowCount].mask = 1 << (col - 2);
            rowCount++;
        } else {
            rows[found].mask |= 1 << (col - 2);
        }
    }

    int answer = (n - rowCount) * 2;

    for (int i = 0; i < rowCount; i++) {
        int mask = rows[i].mask;

        bool left = (mask & 0b00001111) == 0;
        bool middle = (mask & 0b00111100) == 0;
        bool right = (mask & 0b11110000) == 0;

        if (left && right) {
            answer += 2;
        }
        else if (left || middle || right) {
            answer += 1;
        }
    }

    free(rows);

    return answer;
}