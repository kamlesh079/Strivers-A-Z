// https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0;
        int c = m - 1;
        while(r < n && c >= 0){
            int num = matrix[r][c];
            if(target == num) return true;
            else if(target > num) r++;
            else c--;
        }
        return false;
    }
};