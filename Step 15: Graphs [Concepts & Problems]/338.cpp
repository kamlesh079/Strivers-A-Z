// https://leetcode.com/problems/rotting-oranges/
// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh_oranges = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh_oranges++;
            }
        }

        // if no fresh Oranges -> no rottening
        if(fresh_oranges == 0) 
            return 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = { 0, 0, -1, 1};

        int minutes = 0;
        while(!q.empty()){
            int size = q.size();
            bool rotton = false;

            while(size--){
                auto[r, c] = q.front();
                q.pop();
                

                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh_oranges--;
                        q.push({nr, nc});
                        rotton = true;
                    }
                }

            }
            if(rotton)
                minutes++;
        }
        return (fresh_oranges == 0) ? minutes : -1;

    }
};