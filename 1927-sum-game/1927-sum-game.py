class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)

        sum_left = 0
        sum_right = 0

        q_left = 0
        q_right = 0

        for i in range(n // 2):
            if num[i] == '?':
                q_left += 1
            else:
                sum_left += int(num[i])

        for i in range(n // 2, n):
            if num[i] == '?':
                q_right += 1
            else:
                sum_right += int(num[i])

        if q_left == q_right:
            return sum_left != sum_right

        q_diff = q_left - q_right
        sum_diff = sum_left - sum_right

        return sum_diff * 2 != -9 * q_diff