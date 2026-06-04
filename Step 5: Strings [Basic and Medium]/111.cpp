// https://leetcode.com/problems/remove-outermost-parentheses/

// Using Stack O(N) Space
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;
        for (char ch : s) {
            if (ch == '(') {
                if(!st.empty()) ans += ch;
                st.push(ch);
            }
            else{
                st.pop();
                if(!st.empty()) ans += ch;
            }
        }
        return ans;
    }
};

// In O(1) -> using depth  
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;
        for(char ch : s){
            if(ch == '('){
                if(depth > 0) ans += ch;
                depth++;
            }
            else{
                depth--;
                if(depth > 0) ans += ch;
            }
        }
        return ans;
    }
};