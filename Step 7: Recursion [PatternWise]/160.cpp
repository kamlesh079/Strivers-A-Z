// https://www.geeksforgeeks.org/problems/sort-a-stack/1


// space complexity O(1) as we didn't use any other data structure
// O(n) due to recursion stack
class Solution {
  public:
    void sortedInsert(stack<int> &st, int x){
        if(st.empty() || st.top() <= x ){
            st.push(x);
            return;
        }
        
        int top = st.top();
        st.pop();
        
        sortedInsert(st, x);
        
        st.push(top);
    }
    
    void sortStack(stack<int> &st) {
        if (st.empty())
            return;
        
        int top = st.top();
        st.pop();
        
        sortStack(st);
        
        sortedInsert(st, top);
    }
};
