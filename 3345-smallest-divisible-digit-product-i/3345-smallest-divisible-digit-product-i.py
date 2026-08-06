class Solution(object):
    def smallestNumber(self, n, t):

        i = n

        while True:

            product = 1
            x = i

            while x:
                product *= x % 10
                x //= 10

            if product % t == 0:
                return i

            i += 1