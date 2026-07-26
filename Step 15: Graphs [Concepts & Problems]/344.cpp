// https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        grid[i][j] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto[r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }
    }
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // mark curr visited
        grid[r][c] = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1)
                dfs(nr, nc, grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Top and Bottom Row
        for (int c = 0; c < m; c++) {
            // Top: r = 0;
            if (grid[0][c] == 1)
                // dfs(0, c, grid);
                bfs(0, c, grid);

            // Bottom: r = n - 1
            if (grid[n - 1][c] == 1)
                // dfs(n - 1, c, grid);
                bfs(n - 1, c, grid);
        }
        // Left and Right Column
        for (int r = 0; r < n; r++) {
            // Left: c = 0;
            if (grid[r][0] == 1)
                // dfs(r, 0, grid);
                bfs(r, 0, grid);

            // Right: r = m - 1;
            if (grid[r][m - 1] == 1)
                // dfs(r, m - 1, grid);
                bfs(r, m - 1, grid);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};


// ----- BFS (Using Multi-source BFS) -----
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        // Top & Bottom rows
        for (int c = 0; c < m; c++) {
            if (grid[0][c] == 1) {
                q.push({0, c});
                grid[0][c] = 0;
            }

            if (grid[n - 1][c] == 1) {
                q.push({n - 1, c});
                grid[n - 1][c] = 0;
            }
        }

        // Left & Right columns
        for (int r = 0; r < n; r++) {
            if (grid[r][0] == 1) {
                q.push({r, 0});
                grid[r][0] = 0;
            }

            if (grid[r][m - 1] == 1) {
                q.push({r, m - 1});
                grid[r][m - 1] = 0;
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 0;
                    q.push({nr, nc});
                }
            }
        }

        // Count remaining land cells
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};
