// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

class Solution {
  public:
    // # Using Recursion (Without Backtracking) -> O(n·2ⁿ) 
    void solveUsingRecursion(int n, string str, vector<string>& ans){
        if(0 == n){
            ans.push_back(str);
            return;
        }
        solveUsingRecursion(n - 1, str + '0', ans);
        solveUsingRecursion(n - 1, str + '1', ans);
    }
    
    // # Using Recursion (With Backtracking) -> O(n·2ⁿ) 
    void solveUsingRecursion(int n, string& str, vector<string>& ans){
        if(0 == n){
            ans.push_back(str);
            return;
        }
        str.push_back('0');
        solveUsingRecursion(n - 1, str, ans);
        str.pop_back();
        
        str.push_back('1');
        solveUsingRecursion(n - 1, str, ans);
        str.pop_back();
    }
    
    // # Using bit Manipulation O(n·2ⁿ)
    vector<string> solveUsingBitManipulation(int n){
        vector<string> ans;
        
        int total = 1 << n; // 2^n; 
        
        for(int mask = 0; mask < total; mask++){
            string str = "";
            // now start making the binary str
            for(int i = n - 1; i >= 0; i--){
               str += (mask & (1 << i)) ? '1' : '0';
            }
            ans.push_back(str);
        }
        return ans;
    }
    
    vector<string> binstr(int n) {
        
        // # Using Recursion 
        string str = "";
        vector<string> ans;
        solveUsingRecursion(n, str, ans);
        return ans;
        
        // # Using Bit Manipulation
        // return solveUsingBitManipulation(n);
        
    }
};

// A useful rule:

// Whenever you are generating all subsets, all binary strings, or all choices of yes/no, the complexity is almost always at least O(2ⁿ) because there are 2ⁿ outputs to produce. You can't do better than the size of the output itself.