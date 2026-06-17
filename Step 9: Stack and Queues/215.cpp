// https://leetcode.com/problems/next-greater-element-ii/

// ### Method 1: Left → Right (Resolve Previous Elements)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n,-1);
        stack<int> st; // stores indices

        for(int i = 0; i < 2*n; i++){

            int idx = i % n;

            while(!st.empty() &&
                  nums[idx] > nums[st.top()])
            {
                ans[st.top()] = nums[idx];
                st.pop();
            }

            if(i < n)
                st.push(idx);
        }

        return ans;
    }
};

// ### Method : Right → Left (Most Popular)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, -1);
        stack<int> st;   // stores indices

        for (int i = 2 * n - 1; i >= 0; i--) {

            int id = i % n;

            while (!st.empty() && nums[st.top()] <= nums[id]) {
                st.pop();
            }
            if (i < n)
                ans[i] = st.empty() ? -1 : nums[st.top()];
            st.push(id);
        }
        return ans;
    }
};