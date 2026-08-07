import java.util.*;

class Solution {

    private static final Map<Integer, Map<Integer, Integer>> kFactorCounts = new HashMap<>();

    static {
        kFactorCounts.put(0, new HashMap<>());
        kFactorCounts.put(1, new HashMap<>());

        Map<Integer, Integer> m;

        m = new HashMap<>();
        m.put(2, 1);
        kFactorCounts.put(2, m);

        m = new HashMap<>();
        m.put(3, 1);
        kFactorCounts.put(3, m);

        m = new HashMap<>();
        m.put(2, 2);
        kFactorCounts.put(4, m);

        m = new HashMap<>();
        m.put(5, 1);
        kFactorCounts.put(5, m);

        m = new HashMap<>();
        m.put(2, 1);
        m.put(3, 1);
        kFactorCounts.put(6, m);

        m = new HashMap<>();
        m.put(7, 1);
        kFactorCounts.put(7, m);

        m = new HashMap<>();
        m.put(2, 3);
        kFactorCounts.put(8, m);

        m = new HashMap<>();
        m.put(3, 2);
        kFactorCounts.put(9, m);
    }

    public String smallestNumber(String num, long t) {
        Pair primeResult = getPrimeCount(t);

        if (!primeResult.isDivisible)
            return "-1";

        Map<Integer, Integer> factorCount = getFactorCount(primeResult.count);

        if (sumValues(factorCount) > num.length())
            return construct(factorCount);

        Map<Integer, Integer> primeCountPrefix = getPrimeCount(num);

        int firstZeroIndex = num.indexOf('0');

        if (firstZeroIndex == -1) {
            firstZeroIndex = num.length();
            if (isSubset(primeResult.count, primeCountPrefix))
                return num;
        }

        for (int i = num.length() - 1; i >= 0; --i) {
            int d = num.charAt(i) - '0';

            primeCountPrefix =
                    subtract(primeCountPrefix, kFactorCounts.get(d));

            int spaceAfterThisDigit = num.length() - 1 - i;

            if (i > firstZeroIndex)
                continue;

            for (int biggerDigit = d + 1; biggerDigit <= 9; ++biggerDigit) {

                Map<Integer, Integer> factorsAfterReplacement =
                        getFactorCount(
                                subtract(
                                        subtract(primeResult.count, primeCountPrefix),
                                        kFactorCounts.get(biggerDigit)));

                if (sumValues(factorsAfterReplacement) <= spaceAfterThisDigit) {

                    int fillOnes =
                            spaceAfterThisDigit - sumValues(factorsAfterReplacement);

                    return num.substring(0, i)
                            + biggerDigit
                            + "1".repeat(fillOnes)
                            + construct(factorsAfterReplacement);
                }
            }
        }

        Map<Integer, Integer> factorsAfterExtension =
                getFactorCount(primeResult.count);

        return "1".repeat(num.length() + 1 - sumValues(factorsAfterExtension))
                + construct(factorsAfterExtension);
    }

    private static class Pair {
        Map<Integer, Integer> count;
        boolean isDivisible;

        Pair(Map<Integer, Integer> count, boolean isDivisible) {
            this.count = count;
            this.isDivisible = isDivisible;
        }
    }

    private Pair getPrimeCount(long t) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(2, 0);
        count.put(3, 0);
        count.put(5, 0);
        count.put(7, 0);

        int[] primes = {2, 3, 5, 7};

        for (int prime : primes) {
            while (t % prime == 0) {
                t /= prime;
                count.put(prime, count.get(prime) + 1);
            }
        }

        return new Pair(count, t == 1);
    }

    private Map<Integer, Integer> getPrimeCount(String num) {
        Map<Integer, Integer> count = new HashMap<>();
        count.put(2, 0);
        count.put(3, 0);
        count.put(5, 0);
        count.put(7, 0);

        for (char c : num.toCharArray()) {
            for (Map.Entry<Integer, Integer> e :
                    kFactorCounts.get(c - '0').entrySet()) {
                count.put(e.getKey(), count.get(e.getKey()) + e.getValue());
            }
        }

        return count;
    }

    private Map<Integer, Integer> getFactorCount(Map<Integer, Integer> count) {

        int count8 = count.get(2) / 3;
        int remaining2 = count.get(2) % 3;

        int count9 = count.get(3) / 2;
        int count3 = count.get(3) % 2;

        int count4 = remaining2 / 2;
        int count2 = remaining2 % 2;

        int count6 = 0;

        if (count2 == 1 && count3 == 1) {
            count2 = 0;
            count3 = 0;
            count6 = 1;
        }

        if (count3 == 1 && count4 == 1) {
            count2 = 1;
            count6 = 1;
            count3 = 0;
            count4 = 0;
        }

        Map<Integer, Integer> res = new HashMap<>();
        res.put(2, count2);
        res.put(3, count3);
        res.put(4, count4);
        res.put(5, count.get(5));
        res.put(6, count6);
        res.put(7, count.get(7));
        res.put(8, count8);
        res.put(9, count9);

        return res;
    }

    private String construct(Map<Integer, Integer> factors) {
        StringBuilder sb = new StringBuilder();

        for (int digit = 2; digit <= 9; digit++) {
            int cnt = factors.get(digit);
            while (cnt-- > 0)
                sb.append(digit);
        }

        return sb.toString();
    }

    private boolean isSubset(Map<Integer, Integer> a,
                             Map<Integer, Integer> b) {

        for (Map.Entry<Integer, Integer> e : a.entrySet()) {
            if (b.get(e.getKey()) < e.getValue())
                return false;
        }

        return true;
    }

    private Map<Integer, Integer> subtract(Map<Integer, Integer> a,
                                           Map<Integer, Integer> b) {

        Map<Integer, Integer> res = new HashMap<>(a);

        for (Map.Entry<Integer, Integer> e : b.entrySet()) {
            res.put(e.getKey(),
                    Math.max(0, res.get(e.getKey()) - e.getValue()));
        }

        return res;
    }

    private int sumValues(Map<Integer, Integer> map) {
        int sum = 0;

        for (int val : map.values())
            sum += val;

        return sum;
    }
}