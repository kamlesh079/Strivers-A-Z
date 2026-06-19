// https://leetcode.com/problems/sum-of-subarray-minimums
class Solution {
public:
    // ## Function to find the next smaller element(Methos:- Resolving stack
    // elements)
    vector<int> nextMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
    // ## Function to find the pre smaller element (Methos:- Resolving stack
    // elements)
    vector<int> preMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nextSmaller = nextMin(arr);
        vector<int> prevSmaller = preMin(arr);

        const long long MOD = 1e9 + 7;
        long long count = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;

            count = (count + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
        }
        return count;
    }
};




// Each element owns all subarrays where it is the unique minimum.

// Duplicates create ownership conflicts.

// To avoid two equal elements claiming the same subarray,
// use one strict comparison and one non-strict comparison.

// Tie goes to one king only.