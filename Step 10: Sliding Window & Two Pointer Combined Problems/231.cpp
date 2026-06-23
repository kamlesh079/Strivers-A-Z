// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int zeros = 0;
        int ans = 0;

        for(int right = 0; right < n; right++){
            if(nums[right] == 0) 
                zeros++;
            
            // shrink if count of zeros is greater than k
            while(zeros > k){
                if(nums[left] == 0) 
                    zeros--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};