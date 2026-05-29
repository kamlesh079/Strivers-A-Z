// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> ans;
        
        int maxElement = INT_MIN;
        for(int i = n - 1; i >= 0; --i){
            if(arr[i] >= maxElement){
                maxElement = arr[i];
                ans.push_back(maxElement);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};