https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

class Solution {
  public:
    string preToPost(string &s) {
        string postfix = "";
        stack<string> st;
        
        for(int i = s.size() - 1; i >= 0; i--){
            
            char ch = s[i];

            if(isalnum(ch))
                st.push(string(1, ch));
            else{
                string op1 = st.top();
                st.pop();
                
                string op2 = st.top();
                st.pop();
                
                string temp = op1 + op2 + ch; // concatenate operands and operator in postfix order 
                st.push(temp);
            }
        }
        return st.top();
    }
};