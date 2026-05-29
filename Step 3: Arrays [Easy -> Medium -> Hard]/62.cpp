// https://leetcode.com/problems/longest-consecutive-sequence/

// # Longest Consecutive Sequence in an Array
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int x : nums)
            st.insert(x);
            
        int ans = 0;
        for (int x : st) {
            // start only if x is beginning of sequence
            if (!st.count(x - 1)) {
                int count = 1;
                int curr = x;
                // extend sequence
                while (st.count(curr + 1)) {
                    count++;
                    curr++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};