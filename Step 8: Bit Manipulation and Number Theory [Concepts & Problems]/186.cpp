// https://www.geeksforgeeks.org/problems/set-bits0143/1

// 1. bit by bit count (Brute Force)
int countSetBits(int n) {
    int count = 0;

    while (n) {
        count += (n & 1);
        n >>= 1;
    }

    return count;
}
// ##### Complexity #####
// Time: O(number of bits)
//       O(32) for int
//       O(64) for long long
// Space: O(1)

// 2. Brian Kernighan's Algorithm
// n = n & (n - 1); -> the rightmost set bit gets removed.

int countSetBits(int n) {
    int count = 0;

    while (n) {
        n = n & (n - 1);
        count++;
    }

    return count;
}
// ##### Complexity #####
// Time: O(number of set bits)
// Space: O(1)


int countSetBits(int n) {
    return  __buildin_popcount(n);
}
// Usually O(1) because modern CPUs often have a POPCOUNT instruction.

// 4. Recursive Method
int countSetBits(int n) {
    if (n == 0)
        return 0;

    return (n & 1) + countSetBits(n >> 1);
}
// ##### Complexity #####
// Time: O(bits)
// Space: O(bits) due to recursion stack
