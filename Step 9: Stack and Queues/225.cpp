// https://leetcode.com/problems/sliding-window-maximum/


// Priority Queue Solution O(nlogk) time complexity and O(k) space complexity
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> maxheap;

        for (int i = 0; i < k; i++) {
            maxheap.push({nums[i], i});
        }
        ans.push_back(maxheap.top().first);

        for (int i = k; i < nums.size(); ++i) {
            maxheap.push({nums[i], i});
            while (maxheap.top().second <= i - k)
                maxheap.pop();
            ans.push_back(maxheap.top().first);
        }
        return ans;
    }
};



// Optmial Solution using Deque O(n) time complexity and O(k) space complexity
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        // First Window;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        
        // Now rest of the Windows
        for(int i = k; i < nums.size(); i++){
            // is the front of dq is outdated ?
            if(!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            
            while(!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;

    }
};