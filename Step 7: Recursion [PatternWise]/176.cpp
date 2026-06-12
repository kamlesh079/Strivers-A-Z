// https://leetcode.com/problems/n-queens/

class Solution {
public:
    bool validPos(int row, int col, int n, vector<string>& board) {
        int r = row, c = col;

        // same column
        while (r >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
        }
        
        // upper-left diagonal
        r = row;
        c = col;
        while(r >= 0 && c >= 0){
            if(board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        // upper-right diagonal
        r = row;
        c = col;
        while(r >= 0 && c < n){
            if(board[r][c] == 'Q')
                return false;
            r--;
            c++;
        }

        return true;
    }

    void solve(int row, int n, vector<vector<string>>& ans, vector<string>& board){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(validPos(row, col, n, board)){
                board[row][col] = 'Q';
                solve(row + 1, n, ans, board);
                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0, n, ans, board);
        return ans;
    }
};