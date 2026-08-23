class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sumLeft = 0;
        int sumRight = 0;

        int qLeft = 0;
        int qRight = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                sumLeft += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                sumRight += num[i] - '0';
        }

        // If the number of ? on both sides is equal
        if (qLeft == qRight) {
            return sumLeft != sumRight;
        }

        // Difference in number of ? must be even for Bob
        // to potentially balance the sums.
        int qDiff = qLeft - qRight;
        int sumDiff = sumLeft - sumRight;

        return sumDiff * 2 != -9 * qDiff;
    }
};