// Bonus => Segemented Sieve Range [L, R] and L, R are very big numbers

class Solution {
public:
    vector<int> segmentedSieve(int L, int R) {

        // Step 1: Find all primes up to sqrt(R)
        int limit = sqrt(R);

        vector<bool> prime(limit + 1, true);
        prime[0] = prime[1] = false;

        for(int i = 2; i * i <= limit; i++) {
            if(prime[i]) {
                for(long long j = 1LL * i * i; j <= limit; j += i)
                    prime[j] = false;
            }
        }

        vector<int> primes;

        for(int i = 2; i <= limit; i++) {
            if(prime[i])
                primes.push_back(i);
        }

        // Step 2: Assume every number in [L, R] is prime
        vector<bool> isPrime(R - L + 1, true);

        // Step 3: Mark multiples of each prime
        for(int p : primes) {

            // First multiple of p inside [L, R]
            long long start =
                max(1LL * p * p,
                    ((L + p - 1) / p) * 1LL * p);

            for(long long j = start; j <= R; j += p) {
                isPrime[j - L] = false;
            }
        }

        // Handle cases where L is 0 or 1
        if(L == 0) {
            isPrime[0] = false;   
            if(R >= 1) isPrime[1] = false;
        }

        if(L == 1) {
            isPrime[0] = false; // Note its isPrime[0] not isPrime[1]...
        }

        // Step 4: Collect primes
        vector<int> ans;

        for(int i = L; i <= R; i++) {
            if(isPrime[i - L])
                ans.push_back(i);
        }

        return ans;
    }
};

// Practice Question
// Multiples of Prime -> https://www.geeksforgeeks.org/problems/product-of-primes5328/1 