// https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1
// https://leetcode.com/problems/spiral-matrix/description/

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> ans; // for storing ans
        
        int count = 0;
        int total = row * col;
        
        int left = 0;
        int right = col - 1;
        int top = 0;
        int bottom = row - 1;
        
        while(count < total){
            // top (left -> right)
            for(int i = left; i <= right && count < total; i++){
               int num = mat[top][i];
               ans.push_back(num);
               count++;
            }
            top++;
            
            //down (top -> down)
            for(int i = top; i <= bottom && count < total; i++){
                int num = mat[i][right];
                ans.push_back(num);
                count++;
            }
            right--;
           
            //bottom (righ -> left)
            for(int i = right; i >= left && count < total; i--){
                int num = mat[bottom][i];
                ans.push_back(num);
                count++;
            }
            bottom--;
            
            //up (bottom -> top)
            for(int i = bottom; i >= top && count < total; i--){
                int num = mat[i][left];
                ans.push_back(num);
                count++;
            }
            left++;
        }
        return ans;
    }
};