// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1


// ----------------- Using DFS  -----------------
class Solution {
	public:
	void dfs(int r, int c, vector<vector<char>> &grid, vector<vector<int>> &vis,
	vector<pair<int, int>>& shape, int baseR, int baseC) {
		
		int n = grid.size();
		int m = grid[0].size();
		
		// mark visited 
		vis[r][c] = 1;
		shape.push_back({r - baseR, c - baseC});
		
		int dr[] = {-1, 1, 0, 0};
		int dc[] = {0, 0, -1, 1};
		
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (nr >= 0 && nr < n && 
			    nc >= 0 && nc < m && 
			    !vis[nr][nc] && 
			    grid[nr][nc] == 'L'){
			    dfs(nr, nc, grid, vis, shape, baseR, baseC);
			}
		}
	}
	
	int countDistinctIslands(vector<vector<char>> & grid) {
		int n = grid.size();
		int m = grid[0].size();
		
		int count = 0;
		
		vector<vector<int>> vis(n, vector<int>(m, 0));
		
		set<vector<pair<int, int>> > st;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 'L' && !vis[i][j]) {
					vector<pair<int, int>> shape;
					
					dfs(i, j, grid, vis, shape, i, j);
					
					st.insert(shape);
				}
			}
		}
		return st.size();
	}
};



// ----------------- Using BFS  -----------------
class Solution {
public:
    void bfs(int row, int col,
             vector<vector<char>> &grid,
             vector<vector<int>> &vis,
             vector<pair<int, int>> &shape)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int baseR = row;
        int baseC = col;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            // Store relative coordinate
            shape.push_back({r - baseR, c - baseC});

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    !vis[nr][nc] &&
                    grid[nr][nc] == 'L')
                {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int countDistinctIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'L' && !vis[i][j])
                {
                    vector<pair<int, int>> shape;

                    bfs(i, j, grid, vis, shape);

                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};