class Solution {
public:
    int smallestNumber(int n, int t) {

        for (int i = n;; i++) {

            int product = 1;

            for (int x = i; x > 0; x /= 10)
                product *= x % 10;

            if (product % t == 0)
                return i;
        }
    }
};