// https://www.geeksforgeeks.org/problems/power-set4302/1

class Solution {
  public:
    // Recursion -> without backtracking
    // void solve(int id, string &s, string str, vector<string>& ans){
    //     if(id >= s.size()){
    //         ans.push_back(str);
    //         return;
    //     }
    //     // case 1 - Include
    //     solve(id + 1, s, str + s[id], ans);
        
    //     // case 2 - Exclude
    //     solve(id + 1, s, str, ans);
    // }
    
    // Recursion -> with backtracking
    void solve(int id, string &s, string& str, vector<string>& ans){
        if(id >= s.size()){
            ans.push_back(str);
            return;
        }
        // case 1 - Include
        str.push_back(s[id]);
        solve(id + 1, s, str, ans);
        str.pop_back(); // Backtrack
        
        // case 2 - Exclude
        solve(id + 1, s, str, ans);
    }
    
    vector<string> powerSet(string &s) {
        string str = "";
        vector<string> ans;
        
        solve(0, s, str, ans);
        
        sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};