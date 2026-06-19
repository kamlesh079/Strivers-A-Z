// https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution {
public:
    // #########  Sum of min in subarray (LeetCode - 907) #########
    vector<int> nextMin(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> v(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> preMin(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nextSmaller = nextMin(arr);
        vector<int> prevSmaller = preMin(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long left = i - prevSmaller[i];
            long long right = nextSmaller[i] - i;

            sum += (1LL * arr[i] * left * right);
        }
        return sum;
    }

    // #########  Sum of max in subarray  #########
    vector<int> nextMax(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> v(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            v[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> preMax(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            v[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return v;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> nextBig = nextMax(arr);
        vector<int> preBig = preMax(arr);

        long long sum = 0;

        for (int i = 0; i < arr.size(); i++) {

            long long left = i - preBig[i];
            long long right = nextBig[i] - i;

            sum += 1LL * arr[i] * left * right;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long mini = sumSubarrayMins(nums);
        long long maxi = sumSubarrayMax(nums);
        return maxi - mini;
    }
};