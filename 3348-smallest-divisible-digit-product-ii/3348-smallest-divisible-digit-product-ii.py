from collections import defaultdict

class Solution:
    kFactorCounts = {
        0: {},
        1: {},
        2: {2: 1},
        3: {3: 1},
        4: {2: 2},
        5: {5: 1},
        6: {2: 1, 3: 1},
        7: {7: 1},
        8: {2: 3},
        9: {3: 2},
    }

    def smallestNumber(self, num: str, t: int) -> str:
        primeCount, isDivisible = self.getPrimeCountNumber(t)

        if not isDivisible:
            return "-1"

        factorCount = self.getFactorCount(primeCount)

        if self.sumValues(factorCount) > len(num):
            return self.construct(factorCount)

        primeCountPrefix = self.getPrimeCountString(num)

        firstZeroIndex = num.find('0')
        if firstZeroIndex == -1:
            firstZeroIndex = len(num)
            if self.isSubset(primeCount, primeCountPrefix):
                return num

        for i in range(len(num) - 1, -1, -1):
            d = int(num[i])

            primeCountPrefix = self.subtract(
                primeCountPrefix,
                self.kFactorCounts[d]
            )

            spaceAfterThisDigit = len(num) - 1 - i

            if i > firstZeroIndex:
                continue

            for biggerDigit in range(d + 1, 10):
                factorsAfterReplacement = self.getFactorCount(
                    self.subtract(
                        self.subtract(primeCount, primeCountPrefix),
                        self.kFactorCounts[biggerDigit]
                    )
                )

                if self.sumValues(factorsAfterReplacement) <= spaceAfterThisDigit:
                    fillOnes = (
                        spaceAfterThisDigit
                        - self.sumValues(factorsAfterReplacement)
                    )

                    return (
                        num[:i]
                        + str(biggerDigit)
                        + "1" * fillOnes
                        + self.construct(factorsAfterReplacement)
                    )

        factorsAfterExtension = self.getFactorCount(primeCount)

        return (
            "1"
            * (len(num) + 1 - self.sumValues(factorsAfterExtension))
            + self.construct(factorsAfterExtension)
        )

    def getPrimeCountNumber(self, t: int):
        count = {2: 0, 3: 0, 5: 0, 7: 0}

        for prime in (2, 3, 5, 7):
            while t % prime == 0:
                t //= prime
                count[prime] += 1

        return count, t == 1

    def getPrimeCountString(self, num: str):
        count = {2: 0, 3: 0, 5: 0, 7: 0}

        for ch in num:
            for prime, freq in self.kFactorCounts[int(ch)].items():
                count[prime] += freq

        return count

    def getFactorCount(self, count):
        count8 = count[2] // 3
        remaining2 = count[2] % 3

        count9 = count[3] // 2
        count3 = count[3] % 2

        count4 = remaining2 // 2
        count2 = remaining2 % 2

        count6 = 0

        if count2 == 1 and count3 == 1:
            count2 = 0
            count3 = 0
            count6 = 1

        if count3 == 1 and count4 == 1:
            count2 = 1
            count6 = 1
            count3 = 0
            count4 = 0

        return {
            2: count2,
            3: count3,
            4: count4,
            5: count[5],
            6: count6,
            7: count[7],
            8: count8,
            9: count9,
        }

    def construct(self, factors):
        res = []

        for digit in range(2, 10):
            res.append(str(digit) * factors[digit])

        return "".join(res)

    def isSubset(self, a, b):
        for key, value in a.items():
            if b[key] < value:
                return False
        return True

    def subtract(self, a, b):
        res = a.copy()

        for key, value in b.items():
            res[key] = max(0, res[key] - value)

        return res

    def sumValues(self, count):
        return sum(count.values())