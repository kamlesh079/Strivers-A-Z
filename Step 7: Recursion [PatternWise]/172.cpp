

class Solution {
public:
    // ###### for loop ######
    void solve(int count, int target, vector<int>& v, vector<vector<int>>& ans,
               int start) {
        if (count == 0) {
            if (target == 0)
                ans.push_back(v);
            return;
        }

        // if(count < 0 || target < 0)
        //     return;

        for (int num = start; num <= 9; num++) {
            v.push_back(num);
            solve(count - 1, target - num, v, ans, num + 1);
            v.pop_back();
        }
    }

    // include exclude version
    void solve(int count, int target, vector<int>& v, vector<vector<int>>& ans,
               int id) {
        if (count == 0) {
            if (target == 0)
                ans.push_back(v);
            return;
        }
        if(id > 9 || target < 0) // target < 0 -> for early returns
            return;

        //include
        v.push_back(id);
        solve(count - 1, target - id, v, ans, id + 1);
        v.pop_back();

        // exclude
        solve(count, target, v, ans, id + 1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(k, n, v, ans, 1);
        return ans;
    }
};