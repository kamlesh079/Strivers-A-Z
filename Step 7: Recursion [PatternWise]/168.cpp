// https://leetcode.com/problems/combination-sum/

// # Include and Exclude case
class Solution {
public:
    void solve(int id, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& output) {
        int n = candidates.size();
        if(target == 0){
            ans.push_back(output);
            return;
        }
        if(id == n) return;

        // take it (include)
        if(candidates[id] <= target){
            output.push_back(candidates[id]);
            solve(id, candidates, target - candidates[id], ans, output);
            output.pop_back();
        }
        // not take it (exclude)
        solve(id + 1, candidates, target, ans, output);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, candidates, target, ans, output);
        return ans;
    }
};

// ##### Using for loop and recursion ###########

class Solution {
public:
    void solve(int start, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& output) {
        if (target == 0) {
            ans.push_back(output);
            return;
        }

        // for loop helps in "exclude" case
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                continue;

            output.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], ans, output);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, candidates, target, ans, output);
        return ans;
    }
};