// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    vector<int> nextSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> v(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < nums[st.top()]){
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
    vector<int> preSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> v(n, -1);
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums[i] < nums[st.top()]){
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> pre = preSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxRect = INT_MIN;
        for(int i = 0; i < n; i++){
            int width = next[i] - pre[i] - 1;
            int height = heights[i];
            int currRect = width * height;

            maxRect = max(maxRect, currRect);
        }
        return maxRect;
    }
};