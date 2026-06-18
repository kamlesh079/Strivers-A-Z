// https://leetcode.com/problems/trapping-rain-water/


// Method 1: Using two arrays to store left max and right max for each index and then calculating the water trapped at each index
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], height[i]);

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], height[i]);

        int water = 0;
        for(int i = 0; i < n; i++)
            water += min(leftMax[i], rightMax[i]) - height[i];
        
        return water;
    }
};

// Method 2: Two Pointers Approach 
class Solution {
public:
    int trap(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while(left < right) {

            if(height[left] < height[right]) {

                if(height[left] >= leftMax)
                    leftMax = height[left];
                else
                    water += leftMax - height[left];

                left++;
            }
            else {

                if(height[right] >= rightMax)
                    rightMax = height[right];
                else
                    water += rightMax - height[right];

                right--;
            }
        }

        return water;
    }
};

// Method 3: Stack method
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int water = 0;

        for (int i = 0; i < height.size(); i++) {

            while (!st.empty() && height[i] > height[st.top()]) {

                int bottom = st.top();
                st.pop();

                if (st.empty())
                    break;

                int left = st.top();
                int width = i - left + 1;

                int boundedHeight = min(height[left], height[i]) - height[bottom];

                water += width * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
};