// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

// ### Method 1: Left → Right (Resolve Previous Elements)
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        vector<int> ans(n, -1);

        for(int i = 0; i < arr.size(); i++){

            while(!st.empty() && arr[i] < arr[st.top()]){
                ans[st.top()] = arr[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};

// ### Method 2: Right → Left  (Answer Current Element)
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n);
        
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : arr[st.top()];
            
            st.push(i);
        }
        return ans;
    }
};