class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        // Build mask for reserved seats.
        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 11) {
                rows[row] |= (1 << (col - 2));
            }
        }

        int answer = (n - rows.size()) * 2;

        for (auto& [row, mask] : rows) {
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

        return answer;
    }
};