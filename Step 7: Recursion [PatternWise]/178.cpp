// This is a DP problem so either do DP first or just do the recursion part only

// Link -> https://leetcode.com/problems/word-break

// ######## Recursive Solution ########

class Solution {
public:
    bool solve(int start, string& s, unordered_set<string>& st ){
        if(start == s.size()) return true;
        
        for(int end = start; end < s.size(); end++){
            string word = s.substr(start, end - start + 1);
            if(st.count(word)){
                if(solve(end + 1, s, st))
                    return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(0, s, st);
    }
};


// ######## DP Solution ########
class Solution {
public:
    // # Top Down
    bool solve(int start, string& s, unordered_set<string>& st, vector<int>&
    dp){
        if(start == s.size())
            return true;

        if(dp[start] != -1) return dp[start];

        bool ans = false;
        for(int end = start; end < s.size(); end++){
            string word = s.substr(start, end - start + 1);
            if(st.count(word)){
                if(solve(end + 1, s, st, dp))
                    ans = true;
            }
        }
        dp[start] = ans;
        return dp[start];
    }

    // Bottom up
    bool solve(int start, string& s, unordered_set<string>& st) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        // Analyse base case
        dp[n] = true;

        // top down => 0 -> n => in bottom up => n -> 0
        for (int start = n - 1; start >= 0; start--) {
            for (int end = start; end < s.size(); end++) {
                string word = s.substr(start, end - start + 1);
                if (st.count(word) && dp[end + 1]) {
                    dp[start] = true;
                    break;
                }
            }
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() + 1, -1);
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        // # Top Down
        // return solve(0, s, st, dp);

        // # Bottom Up
        return solve(0, s, st);
    }
};