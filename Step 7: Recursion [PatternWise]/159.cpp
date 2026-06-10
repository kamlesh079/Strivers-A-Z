// https://leetcode.com/problems/count-good-numbers/

class Solution {
public:
    long long mod = 1e9 + 7;
    long long fastExpo(long long b, long long p){
        if(p == 0) return 1;
        
        long long half = fastExpo(b, p / 2);
        
        if(p & 1)
            return (b *( half * half) % mod) % mod;
        return 
            (half * half) % mod;

    }
    long long countGoodNumbers(long long n) {
        // even pos -> 0, 2, 4, 6, 8 -> 5 digits
        // oddd pos -> 2, 3, 4, 7 -> 4 digits

        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        // Using Combinator 
        long long evenWays = fastExpo(5, evenPos);
        long long oddWays = fastExpo(4, oddPos);

        return (evenWays * oddWays) % mod;
    }
};