// https://leetcode.com/problems/shortest-path-in-binary-matrix/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        queue<pair<int, pair<int, int>>> q; // {dist, {i, j}}

        int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

        q.push({1, {0, 0}});
        grid[0][0] = 1;
        

        while(!q.empty()){
            auto[dist, coordinate] = q.front();
            q.pop();

            auto [r, c] = coordinate;

            if(r == grid.size() - 1 && c == grid[0].size() -1)
                return dist;

            for(int i = 0; i < 8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 0){

                    q.push({dist + 1,{nr, nc}});
                    grid[nr][nc] = 1;
                }
            }
        }
        return -1;

    }
};