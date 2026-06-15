


// Method 1: Basic Sieve

// Mark multiples of every prime number.
// For a prime i, start marking from 2*i.

// Time: O(N log log N)
// Space: O(N)

vector<int> sieve(int n) {

    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i * i <= n; i++) {

        if(isPrime[i]) {

            for(int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i])
            primes.push_back(i);
    }

    return primes;
}
// Method 2: Optimized Sieve

// For a prime i, start marking from i*i.
//
// Why?
// Multiples smaller than i*i must contain a factor
// smaller than i and have already been marked.
//
// Example:
// i = 5
//
// 10 = 2 * 5  -> marked by 2
// 15 = 3 * 5  -> marked by 3
// 20 = 4 * 5  -> marked earlier
//
// First unprocessed multiple:
// 25 = 5 * 5
//
// Time: O(N log log N)
// Space: O(N)

vector<int> sieve(int n) {

    vector<bool> isPrime(n + 1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i * i <= n; i++) {

        if(isPrime[i]) {

            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i])
            primes.push_back(i);
    }

    return primes;
}