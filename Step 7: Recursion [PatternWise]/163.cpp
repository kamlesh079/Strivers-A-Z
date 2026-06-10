https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    // # Without Backtracking
    void solve(int n, vector<string>& ans, string str, int open, int close){
        if(open == n && open == close){
            ans.push_back(str);
            return;
        }
        if(open < n)
            solve(n, ans, str + '(', open + 1, close);
        if(close < open)
            solve(n, ans, str + ')', open, close + 1);
    }
    // # With Backtracking (when -> pass by ref, why? to avoid duplication of str)        
    void solve(int n, vector<string>& ans, string& str, int open, int close) {
        if (open == n && close == n) {
            ans.push_back(str);
            return;
        }

        if (open < n) {
            str.push_back('(');
            solve(n, ans, str, open + 1, close);
            str.pop_back();          // backtrack
        }
        if (close < open) {
            str.push_back(')');
            solve(n, ans, str, open, close + 1);
            str.pop_back();          // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> ans;
        solve(n, ans, str, 0, 0);
        return ans;
    }
};