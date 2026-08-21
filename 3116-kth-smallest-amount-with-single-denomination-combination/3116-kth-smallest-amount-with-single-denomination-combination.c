#include <stdlib.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = a % b;
        a = b;
        b = t;
    }

    return a;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long countValid(
    long long x,
    int* coins,
    int n
) {
    long long result = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        long long mult = 1;
        int bits = 0;
        int valid = 1;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                bits++;

                mult = lcm(mult, coins[i]);

                if (mult > x) {
                    valid = 0;
                    break;
                }
            }
        }

        if (!valid)
            continue;

        long long ways = x / mult;

        if (bits % 2 == 1)
            result += ways;
        else
            result -= ways;
    }

    return result;
}

long long findKthSmallest(
    int* coins,
    int coinsSize,
    int k
) {
    int minCoin = coins[0];

    for (int i = 1; i < coinsSize; i++) {
        if (coins[i] < minCoin)
            minCoin = coins[i];
    }

    long long low = 1;
    long long high = (long long)minCoin * k;

    while (low < high) {
        long long mid = low + (high - low) / 2;

        if (countValid(mid, coins, coinsSize) >= k)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}