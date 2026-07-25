// https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// https://leetcode.com/problems/01-matrix/

// Same but with Diff Language: https://leetcode.com/problems/map-of-highest-peak

class Solution {
public:
    // Multi src BFS problems
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    dist[nr][nc] == -1) {
                    dist[nr][nc] = 1 + dist[r][c];
                    q.push({nr, nc});
                }
            }
        }
        return dist;
    }
};