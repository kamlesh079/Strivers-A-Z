// https://leetcode.com/problems/split-array-largest-sum/description/

class Solution {
public:
    bool isValid(int mid, vector<int>& nums, int k){
        int sum = 0;
        int count = 1; // subArray Count
        for(int x : nums){
            if(sum + x > mid){
                count++;
                sum = 0;
            }
            sum += x;
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int ans = -1;
        
        int s = *max_element(nums.begin(), nums.end());
        int e = accumulate(nums.begin(), nums.end(), 0);
        while(s <= e){
            int mid = s + (e - s)/2;
            if(isValid(mid, nums, k)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};