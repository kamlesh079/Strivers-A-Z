// https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        // vector<int> row(r, -1);
        // vector<int> col(c, -1);

        int col0 = 1; // due to overlapping we use a sep variable for col0
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0; // row
                    if(j == 0) col0 = 0;
                    else matrix[0][j] = 0; // col 
                }
            }
        }
        // we will process 0th row and col later as it may result in wrong ans
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                if(!matrix[i][0] || !matrix[0][j]) 
                    matrix[i][j] = 0;
            }
        }
        // Handle first row
        if(matrix[0][0] == 0) {
            for(int j = 0; j < c; j++) {
                matrix[0][j] = 0;
            }
        }

        // Handle first column
        if(col0 == 0) {
            for(int i = 0; i < r; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};