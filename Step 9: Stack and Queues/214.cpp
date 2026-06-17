// https://leetcode.com/problems/next-greater-element-i/


// ### Method 1: Left → Right (Resolve Previous Elements)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp;
        stack<int> st;

        for(int x : nums2){

            while(!st.empty() && x > st.top()){
                mp[st.top()] = x;
                st.pop();
            }

            st.push(x);
        }

        while(!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;

        for(int x : nums1)
            ans.push_back(mp[x]);

        return ans;
    }
};

// ### Method 2: Right → Left (Answer Current Element)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp;
        stack<int> st;

        for(int i = nums2.size()-1; i >= 0; i--){

            while(!st.empty() && st.top() <= nums2[i])
                st.pop();

            mp[nums2[i]] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        vector<int> ans;

        for(int x : nums1)
            ans.push_back(mp[x]);

        return ans;
    }
};