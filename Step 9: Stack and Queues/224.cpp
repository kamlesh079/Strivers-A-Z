// https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    // ### ReUsed Code LeetCode-84 ###
    vector<int> nextSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                v[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
    vector<int> preSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
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
        for (int i = 0; i < n; i++) {
            int width = next[i] - pre[i] - 1;
            int height = heights[i];
            int currRect = width * height;

            maxRect = max(maxRect, currRect);
        }
        return maxRect;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        // for each row we find largest rectangle
        vector<int> heights(matrix[0].size(), 0);

        int n = matrix.size();
        int m = matrix[0].size();

        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            area = max(area, largestRectangleArea(heights));
        }
        return area;
    }
};