// https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    bool isPalindrome(string& str, int left, int right){
        while(left < right){
            if(str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(int start, vector<vector<string>>& ans, vector<string>& output, string& s){
        if(start == s.size()){
            ans.push_back(output);
            return;
        }

        for(int end = start; end < s.size(); end++){
            if(isPalindrome(s, start, end)){
               string str = s.substr(start, end - start + 1);
               output.push_back(str);
                solve(end + 1, ans, output, s);
               output.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        int id = 0;
        solve(id, ans, output, s);
        return ans;
    }
};