// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
    vector<string> ans;

    void solve(int row, int col, vector<vector<int>>& maze, int n, string path, vector<vector<int>>& vis) {

        if (row == n - 1 && col == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[row][col] = 1;

        // Down
        if (row + 1 < n && maze[row + 1][col] == 1 && !vis[row + 1][col]) {
            solve(row + 1, col, maze, n, path + 'D', vis);
        }

        // Left
        if (col - 1 >= 0 && maze[row][col - 1] == 1 && !vis[row][col - 1]) {
            solve(row, col - 1, maze, n, path + 'L', vis);
        }

        // Right
        if (col + 1 < n && maze[row][col + 1] == 1 && !vis[row][col + 1]) {
            solve(row, col + 1, maze, n, path + 'R', vis);
        }

        // Up
        if (row - 1 >= 0 && maze[row - 1][col] == 1 && !vis[row - 1][col]) {
            solve(row - 1, col, maze, n, path + 'U', vis);
        }

        vis[row][col] = 0; // backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
         int n = maze.size();

        if (maze[0][0] == 0)
            return {};

        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(0, 0, maze, n, "", vis);

        return ans;
        
    }
};