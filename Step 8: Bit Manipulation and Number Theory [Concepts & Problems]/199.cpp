


// Method 1: Naive
long long power(long long n, long long x) {

    long long ans = 1;

    for(int i = 0; i < x; i++)
        ans *= n;

    return ans;
}

// Method 2: Binary Exponentiation (Fast Power)
long long power(long long n, long long x) {

    long long ans = 1;

    while(x) {

        if(x & 1)
            ans *= n;

        n *= n;
        x >>= 1;
    }

    return ans;
}