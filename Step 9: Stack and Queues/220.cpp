// https://leetcode.com/problems/asteroid-collision/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int ast : asteroids ){
            bool destroyed = false; // to keep track of curr ast whether it is destoryed or not so  according to that we will push it to stack
            if(ast > 0)
                st.push(ast);
            else{
                // ast is negative
                // and collision is posible only if top is positve
                if(st.empty() || st.top() < 0) 
                    st.push(ast);
                else{
                    while(!st.empty() && st.top() > 0){
                        // Case 1 : Both destroyed
                        if(abs(ast) == st.top()){
                            destroyed = true;
                            st.pop(); 
                            break;
                        }
                        // Case 2 : Top destroyed
                        else if(abs(ast) > st.top())
                            st.pop();
                        //  Case 3: Curr ast destroyed
                        else{
                            destroyed = true;
                            break;
                        }
                    }
                    if(!destroyed) 
                        st.push(ast);
                }
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};


// ####### Same But more Clean Code #######
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // stack to store the ast
        stack<int> st;

        for (int ast : asteroids) {

            bool destroyed = false;

            // Collision only if top is +ve and curr ast is -ve
            while (!st.empty() && st.top() > 0 && ast < 0) {
                
                // Case 1 : Top Ast got Destroyed
                if (st.top() < abs(ast)) 
                    st.pop();
                // Case 2 : Both Ast got Destroyed
                else if (st.top() == abs(ast)) {
                    st.pop();
                    destroyed = true;
                    break;
                } 
                // Case 3 : Curr Ast got Destroyed
                else {
                    destroyed = true;
                    break;
                }
            }

            // if st is empty or not destroyed
            if (!destroyed)
                st.push(ast);
        }

        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};