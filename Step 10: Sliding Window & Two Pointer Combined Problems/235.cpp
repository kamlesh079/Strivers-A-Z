// https://leetcode.com/problems/count-number-of-nice-subarrays

// 1. Using Two Pointer Approach(atMost)
class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        int left = 0;
        int odd = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right]  & 1)
                odd++;

            while (odd > k) {
                if (nums[left] & 1)
                    odd--;
                left++;
            }

            ans += right - left + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};

// 2. Using Prefix Sum and HashMap
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int ans = 0;

        for(int x : nums){
            sum += x % 2; // makes array 0, 1 and then count the subarrays
        
            ans += mp[sum - k];

            mp[sum]++;
        }
        return ans;
    }
};

// ## Version 1 ##
// if (mp.count(sum - goal))
//     ans += mp[sum - goal];

// mp[sum]++;

// ## Version 2 ##
// ans += mp[sum - goal];

// mp[sum]++;

// Both give the same answer.