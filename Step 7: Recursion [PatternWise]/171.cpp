// https://www.geeksforgeeks.org/problems/subset-sum-ii/1

class Solution {
  public:
    void solve(int id, vector<int>& nums, vector<vector<int>>& ans,
               vector<int>& subset) {
        // ###### Include Exclude ######
        if(id == nums.size()){
            ans.push_back(subset);
            return;
        }

        // // include
        subset.push_back(nums[id]);
        solve(id + 1, nums, ans, subset);
        subset.pop_back();

        // // exclude
        int next = id + 1;
        while(next < nums.size() && nums[next] == nums[id]) next++;
        solve(next, nums, ans, subset);

        // ###### Recursion with for loop ######
        // ans.push_back(subset);
        // for (int i = id; i < nums.size(); i++) {
        //     if (i > id && nums[i] == nums[i - 1])
        //         continue;

        //     subset.push_back(nums[i]);
        //     solve(i + 1, nums, ans, subset);
        //     subset.pop_back();
        // }
    }
    vector<vector<int>> findSubsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> subset;
        solve(0, nums, ans, subset);
        return ans;
        
    }
};