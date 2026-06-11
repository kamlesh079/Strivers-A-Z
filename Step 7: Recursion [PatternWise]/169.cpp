// https://leetcode.com/problems/combination-sum-ii/

// Include Exclude
class Solution {
public:
    void solve(int id, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& output) {
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(output);
            return;
        }
        if (id == n)
            return;

        // include
        if ( candidates[id] <= target ) {
            output.push_back(candidates[id]);
            solve(id + 1, candidates, target - candidates[id], ans, output);
            output.pop_back();
        }

        // exclude
        // skip all the duplicates (these duplicates are of same recursion level)
        int next = id + 1;
        while (next < n && candidates[next] == candidates[id])
            next++;

        solve(next, candidates, target, ans, output);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> output;
        solve(0, candidates, target, ans, output);
        return ans;
    }
};


// ############# Using "for" loop (Recursive) ###############

class Solution {
public:
    void solve(int id, vector<int>& candidates, int target,
               vector<vector<int>>& ans, vector<int>& output) {
        int n = candidates.size();
        if (target == 0) {
            ans.push_back(output);
            return;
        }

        for(int i = id; i < n; i++){
            if(i > id && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i] > target) break; // sorted so all next elements will be greater

            output.push_back(candidates[i]);
            solve(i + 1,candidates, target - candidates[i], ans, output);
            output.pop_back();
        }
    
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> output;
        solve(0, candidates, target, ans, output);
        return ans;
    }
};