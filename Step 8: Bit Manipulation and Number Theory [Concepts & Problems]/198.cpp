// https://www.geeksforgeeks.org/problems/prime-factorization-using-sieve/1

class Solution {
	public:
	void sieve() {
	}
	
	vector<int> findPrimeFactors(int N) {
		
		vector<int> sieve(N + 1);
		for (int i = 0 ; i <= N; i++)
			sieve[i] = i;
		
		for (int i = 2; i * i <= N; i++) {
			if (sieve[i] == i) { // i is prime
				for (int j = i * i; j <= N; j += i) {
					if (sieve[j] == j) {
						sieve[j] = i;
					}
				}
			}
		}
		
		vector<int> ans;
		while (N > 1) {
			ans.push_back(sieve[N]);
			N /= sieve[N];
		}
		return ans;
	}
};
