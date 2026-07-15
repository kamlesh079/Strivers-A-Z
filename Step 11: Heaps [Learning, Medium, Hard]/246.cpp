// https://www.geeksforgeeks.org/problems/k-largest-elements4206/1
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/


// GFG
class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        
        for(int i = 0; i < k; i++){
            heap.push(arr[i]);
        }
        
        for(int i = k; i < arr.size(); i++){
            if(heap.top() < arr[i]){
                heap.pop();
                heap.push(arr[i]);
            }
        }
        
        vector<int> ans(heap.size());
        int i = heap.size() - 1;
        while(!heap.empty()){
            ans[i] = heap.top();
            heap.pop();
            i--;
        }
        return ans;
    }
};

// LeetCode
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        for(int i = k ; i < nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};