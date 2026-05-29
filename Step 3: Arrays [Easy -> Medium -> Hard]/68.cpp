// https://leetcode.com/problems/majority-element-ii/

// 1. Brute Force
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            // avoid duplicate checking
            bool already = false;
            for(int x : ans) {
                if(x == nums[i]) {
                    already = true;
                    break;
                }
            }
            if(already) continue;

            int count = 0;
            // count frequency
            for(int j = 0; j < n; j++) {
                if(nums[j] == nums[i]) count++;
            }

            // check majority
            if(count > n / 3) ans.push_back(nums[i]);
        }
        return ans;
    }
};

// 2. Better Approach (HashMap)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;

        // count frequencies
        for(int x : nums) {
            mp[x]++;
        }

        // check majority
        for(auto it : mp) {
            if(it.second > n / 3) ans.push_back(it.first);
        }
        return ans;
    }
};

// 3. Optimal Approach (Moore Voting Extension)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int el1 = 0, cnt1 = 0;
        int el2 = 0, cnt2 = 0;
        for(int x: nums){
            if(x == el1) cnt1++;
            else if(x == el2) cnt2++;
            else if (cnt1 == 0){
                el1 = x;
                cnt1 = 1;
            }
            else if(cnt2 == 0){
                el2 = x;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        // Verifing the candidates
        cnt1 = 0;
        cnt2 = 0;
        for(int x: nums){
            if(x == el1) cnt1++;
            else if(x == el2) cnt2++;
        }

        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(el1);
        if(cnt2 > n/3) ans.push_back(el2);

        return ans;
    }
};