// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

class Solution {
  public:
    void insertAtEnd(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        
        insertAtEnd(st, x);
        
        st.push(top);
    }
    void reverseStack(stack<int> &st) {
        if(st.empty()) return;
        
        int top = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtEnd(st, top);
    }
};