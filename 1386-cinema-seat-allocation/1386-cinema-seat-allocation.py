from typing import List

class Solution:
    def maxNumberOfFamilies(
        self,
        n: int,
        reservedSeats: List[List[int]]
    ) -> int:

        rows = {}

        for row, col in reservedSeats:
            if 2 <= col <= 11:
                rows[row] = rows.get(row, 0) | (1 << (col - 2))

        # Every completely empty row can fit 2 families.
        answer = (n - len(rows)) * 2

        for mask in rows.values():

            left = (mask & 0b00001111) == 0
            middle = (mask & 0b00111100) == 0
            right = (mask & 0b11110000) == 0

            if left and right:
                answer += 2
            elif left or middle or right:
                answer += 1

        return answer