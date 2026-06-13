// https://leetcode.com/problems/power-of-two

// 1st Method (Bit Manipulation)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 &&( n & (n - 1)) == 0;
    }
};

// 2nd Method (Divide By 2)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        while (n % 2 == 0) {
            n /= 2;
        }

        return n == 1;
    }
};

// 3rd Method (log2) -> if power of 2 then log2 -> returns an integer
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        double x = log2(n);
        
        return floor(x) == ceil(x);
    }
};
