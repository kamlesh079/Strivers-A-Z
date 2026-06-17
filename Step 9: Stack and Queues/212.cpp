// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

class Solution {
  public:
    string postToInfix(string &exp) {
        stack<string> st;
        
        for(char ch : exp){
            if(isalnum(ch))
                st.push(string(1, ch));
            else{
                string op2 = st.top();
                st.pop();
                
                string op1 = st.top();
                st.pop();
                
                string temp =  "(" + op1 + ch + op2 + ")";
                st.push(temp);
            }
        }
        return st.top();
        
    }
};