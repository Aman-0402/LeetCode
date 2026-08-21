class Solution {

    long gcd(long a, long b) {
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    long count(long x, int[] coins) {
        int n = coins.length;
        long result = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long mult = 1;
            int bits = 0;
            boolean valid = true;

            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    bits++;

                    mult = lcm(mult, coins[i]);

                    if (mult > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid)
                continue;

            long ways = x / mult;

            if (bits % 2 == 1)
                result += ways;
            else
                result -= ways;
        }

        return result;
    }

    public long findKthSmallest(int[] coins, int k) {
        long min = coins[0];

        for (int c : coins) {
            min = Math.min(min, c);
        }

        long low = 1;
        long high = min * (long) k;

        while (low < high) {
            long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
}