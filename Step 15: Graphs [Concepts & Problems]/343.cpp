// https://leetcode.com/problems/surrounded-regions/


// ----------------- Using DFS -----------------
class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        board[r][c] = '#'; // visited

        int n = board.size();
        int m = board[0].size();

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                board[nr][nc] == 'O') {
                dfs(nr, nc, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Top row
        for (int c = 0; c < m; c++)
            if (board[0][c] == 'O')
                dfs(0, c, board);

        // Bottom row
        for (int c = 0; c < m; c++)
            if (board[n - 1][c] == 'O')
                dfs(n - 1, c, board);

        // Left column
        for (int r = 0; r < n; r++)
            if (board[r][0] == 'O')
                dfs(r, 0, board);

        // Right column
        for (int r = 0; r < n; r++)
            if (board[r][m - 1] == 'O')
                dfs(r, m - 1, board);
        

        // Mark # -> O again as it is not surrounded and rest O wtih X
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O'; 
            }
        }
    }
};


// ----------------- Using BFS -----------------
class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        q.push({i, j});
        board[i][j] = '#';

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    board[nr][nc] == 'O') {
                    q.push({nr, nc});
                    board[nr][nc] = '#';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Top row
        for (int c = 0; c < m; c++)
            if (board[0][c] == 'O')
                bfs(0, c, board);

        // Bottom row
        for (int c = 0; c < m; c++)
            if (board[n - 1][c] == 'O')
                bfs(n - 1, c, board);

        // Left column
        for (int r = 0; r < n; r++)
            if (board[r][0] == 'O')
                bfs(r, 0, board);

        // Right column
        for (int r = 0; r < n; r++)
            if (board[r][m - 1] == 'O')
                bfs(r, m - 1, board);

        // Mark # -> O again as it is not surrounded and rest O wtih X
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};