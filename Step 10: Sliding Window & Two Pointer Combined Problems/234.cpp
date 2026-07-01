// https://leetcode.com/problems/binary-subarrays-with-sum

// 1. Using Prefix Sum and HashMap
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int count = 0;
        int prefix = 0;

        for(int x : nums){
            prefix += x;
            int req = prefix - goal;

            if(mp.find(req) != mp.end())
                count += mp[req];

            mp[prefix]++;
        }
        return count;
    }
};

// 2. Using Sliding Window (using atMost function)
class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;

        int left = 0;
        int sum = 0;
        int ans = 0;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            
            ans += right - left + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};