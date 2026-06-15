// https://leetcode.com/problems/sudoku-solver/

class Solution {
public:
    bool validPlace(int row, int col, char num, vector<vector<char>>& board) {
        // check row
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;
        }
        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }
        // 3 x 3 Matrix
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int r = startRow; r < startRow + 3; r++){
            for(int c = startCol; c < startCol + 3; c++){
                if (board[r][c] == num)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] != '.') 
                    continue;
                // else
                for(char num = '1'; num <= '9'; num++){
                    if(validPlace(r, c, num, board)){
                        board[r][c] = num;
                        if(solve(board)) 
                            return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};