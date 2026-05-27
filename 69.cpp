// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int s = i + 1;
            int e = n - 1;

            while (s < e) {
                int sum = nums[i] + nums[s] + nums[e];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    while (s < e && nums[s] == nums[s + 1])
                        s++;
                    while (e > s && nums[e] == nums[e - 1])
                        e--;
                    s++;
                    e--;
                } 
                // diplication removal in these case in unnessary as these will result in same sum 
                // same sum means again we will skip it so no need to add extra skipping like in
                // we did in case of sum == 0
                else if (sum < 0) s++;
                else e--; 
            }
        }
        return ans;
    }
};