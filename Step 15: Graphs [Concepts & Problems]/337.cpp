class Solution {
public:
    // DFS
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        // up
        dfs(i - 1, j, grid);
        // down
        dfs(i + 1, j, grid);
        // left
        dfs(i, j - 1, grid);
        // right
        dfs(i, j + 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    // dfs(i, j, grid);

                    // ------ BFS Logic ------
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        // up
                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            q.push({x - 1, y});
                            grid[x - 1][y] = '0';
                        }
                        // down
                        if (x + 1 < n && grid[x + 1][y] == '1') {
                            q.push({x + 1, y});
                            grid[x + 1][y] = '0';
                        }
                        // left
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            q.push({x, y - 1});
                            grid[x][y - 1] = '0';
                        }
                        // right
                        if (y + 1 < m && grid[x][y + 1] == '1') {
                            q.push({x, y + 1});
                            grid[x][y + 1] = '0';
                        }
                    }
                }
            }
        }
        return count;
    }
};