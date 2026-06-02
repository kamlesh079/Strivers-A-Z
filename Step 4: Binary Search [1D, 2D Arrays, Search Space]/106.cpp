// https://www.geeksforgeeks.org/problems/row-with-max-1s0023/1

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int j = m - 1;
         int ans = -1;
        for(int i = 0; i < n; i++){
            
            while(j >= 0 && arr[i][j] == 1){
                ans = i;
                j--;
            } 
            
        }
        return ans;
    }
};