// https://leetcode.com/problems/powx-n

class Solution {
public:
    // --------------------------------------------------
    // Normal Exponentiation (O(n))
    // --------------------------------------------------
    double normalExpo(double x, long long n) {
        if (n == 0)
            return 1.0;

        return x * normalExpo(x, n - 1);
    }

    // --------------------------------------------------
    // Fast Exponentiation (O(log n))
    // --------------------------------------------------
    double fastExpo(double x, long long n) {
        if (n == 0)
            return 1.0;

        double half = fastExpo(x, n / 2);

        if (n & 1)                // odd exponent
            return x * half * half;

        return half * half;       // even exponent
    }

    double myPow(double x, int n) {
        long long N = n;

        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }
        
        // # Normal exponentiation
        // return normalExpo(x, N);

        // # Fast exponentiation
        return fastExpo(x, N);

    }
};