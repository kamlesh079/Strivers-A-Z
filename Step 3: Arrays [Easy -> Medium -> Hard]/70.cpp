// https://leetcode.com/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i -1]) 
                continue;

            for(int j = i + 1; j < n; ++j){
                if(j > i + 1 && nums[j] == nums[j-1]) 
                    continue;
                
                int s = j + 1;
                int e = n - 1;
                while(s < e){
                    long long sum =(long long)nums[i] + nums[j] + nums[s] + nums[e]; // Important //
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                        while(s < e && nums[s] == nums[s + 1]) s++;
                        while(e > s && nums[e] == nums[e - 1]) e--;
                        s++;
                        e--;
                    }
                    else if (sum > target) e--;
                    else s++;
                }
            }
        }
        return ans;
    }
};