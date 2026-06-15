// https://leetcode.com/problems/expression-add-operators/

class Solution {
public:
    void solve(string& num, int& target, int start, string exp,
               long long currVal, long long prvOprand, vector<string>& ans) {
        if (start == num.size()) {
            if (currVal == target)
                ans.push_back(exp);
            return;
        }

        // lets now try each combinatios -> eg => 123  -> 1, 12, 123, 23, ....
        for (int end = start; end < num.size(); end++) {

            if (end > start && num[start] == '0')
                break; // to avoid anu no with lead zero, eg - 05 000123, etc

            string currStr = num.substr(start, end - start + 1);
            long long currNum = stoll(currStr);
            // First number
            if (start == 0)
                solve(num, target, end + 1, exp + currStr, currNum, currNum,
                      ans);
            else {
                // +
                solve(num, target, end + 1, exp + '+' + currStr,
                      currVal + currNum, currNum, ans);
                // -
                solve(num, target, end + 1, exp + '-' + currStr,
                      currVal - currNum, -currNum, ans);
                // *
                solve(num, target, end + 1, exp + '*' + currStr,
                      currVal - prvOprand + prvOprand * currNum,
                      prvOprand * currNum, ans);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(num, target, 0, "", 0, 0, ans);
        return ans;
    }
};