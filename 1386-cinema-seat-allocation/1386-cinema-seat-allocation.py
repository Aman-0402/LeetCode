class Solution:
    def maxNumberOfFamilies(self, n, reservedSeats):
        rows = {}

        for r, c in reservedSeats:
            if 2 <= c <= 11:
                rows[r] = rows.get(r, 0) | (1 << (c - 2))

        ans = (n - len(rows)) * 2

        for mask in rows.values():
            left = not (mask & 15)
            middle = not (mask & 60)
            right = not (mask & 240)

            if left and right:
                ans += 2
            elif left or middle or right:
                ans += 1

        return ans