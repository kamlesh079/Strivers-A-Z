// https://leetcode.com/problems/word-search/


class Solution {
public:
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int id) {
        if (id == word.size())
            return true;

        int row = board.size();
        int col = board[0].size();

        // Invalid Paths
        if (r < 0 || c < 0 || r >= row || c >= col || word[id] != board[r][c])
            return false;
        
        // if it is valid -> search all the four directions
        char temp = board[r][c];
        board[r][c] = '#'; // visited
        bool found = dfs(r - 1, c, board, word, id + 1) || // up
                     dfs(r + 1, c, board, word, id + 1) || // down
                     dfs(r, c + 1, board, word, id + 1) || // right
                     dfs(r, c - 1, board, word, id + 1);    // left
        board[r][c] = temp; // bactrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        // Search for word from each cell
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if(dfs(r, c, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};