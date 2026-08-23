#include <stdbool.h>
#include <string.h>

bool sumGame(char* num) {
    int n = strlen(num);

    int sumLeft = 0;
    int sumRight = 0;

    int qLeft = 0;
    int qRight = 0;

    for (int i = 0; i < n / 2; i++) {
        if (num[i] == '?') {
            qLeft++;
        } else {
            sumLeft += num[i] - '0';
        }
    }

    for (int i = n / 2; i < n; i++) {
        if (num[i] == '?') {
            qRight++;
        } else {
            sumRight += num[i] - '0';
        }
    }

    if (qLeft == qRight) {
        return sumLeft != sumRight;
    }

    int qDiff = qLeft - qRight;
    int sumDiff = sumLeft - sumRight;

    return sumDiff * 2 != -9 * qDiff;
}