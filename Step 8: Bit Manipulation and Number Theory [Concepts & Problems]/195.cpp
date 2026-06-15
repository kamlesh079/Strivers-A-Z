// https://chatgpt.com/c/6a2d26ea-8570-83ee-be37-b8b5be779215

// Method 1: Trial Division
// Try every possible factor from 2 to sqrt(n).
// Whenever a factor divides n, keep dividing until it no longer does.
// Time: O(sqrt(n))
class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> ans;

        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                ans.push_back(i);
                n /= i;
            }
        }

        // If n > 1, the remaining number is a prime factor.
        if (n > 1)
            ans.push_back(n);

        return ans;
    }
};

// Method 2: Optimized Trial Division
// Handle factor 2 separately, then check only odd numbers.
// All even numbers greater than 2 are composite.
// This reduces the number of divisibility checks by roughly half.
class Solution {
public:
    vector<int> primeFactors(int n) {
        vector<int> ans;

        while (n % 2 == 0) {
            ans.push_back(2);
            n /= 2;
        }

        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                ans.push_back(i);
                n /= i;
            }
        }

        // Remaining number (if any) is prime.
        if (n > 1)
            ans.push_back(n);

        return ans;
    }
};