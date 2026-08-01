// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; // {effort, {i, j}}

        pq.push({0, {0, 0}});
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto [eff, pos] = pq.top();
            pq.pop();

            auto [r, c] = pos;

            if (eff > effort[r][c])
                continue;

            if (r == n - 1 && c == m - 1)
                return eff;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int currEff = abs(heights[nr][nc] - heights[r][c]);

                    int newEff = max(currEff, eff);

                    if (newEff < effort[nr][nc]) {
                        effort[nr][nc] = newEff;
                        pq.push({newEff, {nr, nc}});
                    }
                }
            }
        }
        return effort[n - 1][m - 1];
    }
};

// Dijkstra on Grid
//
// Cost to move = abs(height difference)
// Path cost = Maximum edge cost on the path
//
// Relaxation:
// newEff = max(currEff, edgeCost)
//
// if(newEff < effort[nr][nc])
//     update
//
// TC: O(N*M log(N*M))
// SC: O(N*M)