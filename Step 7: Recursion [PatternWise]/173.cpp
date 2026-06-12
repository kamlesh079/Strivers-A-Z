https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void solve(int id, string digits, vector<string>& ans, string& output, vector<string>& map){
        if(id == digits.size()){
            ans.push_back(output);
            return;
        }
        int index = digits[id] - '0';
        string str = map[index];
        for(int i = 0; i < str.size(); i++){
            output.push_back(str[i]);
            solve(id + 1, digits, ans, output, map);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> map = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int id = 0;
        string output = "";
        solve(id, digits, ans, output, map);
        return ans;
    }
};