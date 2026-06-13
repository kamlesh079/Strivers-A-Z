// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution {
  public:
    
    void solve(int row, int col, vector<string>& ans, string& path, vector<vector<int>>& maze){
        int n = maze.size();
        if(row == n - 1 && col == n - 1){
            ans.push_back(path);
            return;
        }
        // mark curr visited
        maze[row][col] = 0;
        
        // Down
        if(row + 1 < n && maze[row + 1][col]){
            path.push_back('D');
            solve(row + 1, col, ans, path, maze);
            path.pop_back();
        }
        
        // left
        if(col - 1 >= 0 && maze[row][col - 1]){
            path.push_back('L');
            solve(row, col - 1, ans, path, maze);
            path.pop_back();
        }
        
        // right
        if(col + 1 < n && maze[row][col + 1]){
            path.push_back('R');
            solve(row, col + 1, ans, path, maze);
            path.pop_back();
        }
        
        // UP
        if(row - 1 >= 0 && maze[row - 1][col]){
            path.push_back('U');
            solve(row - 1, col, ans, path, maze);
            path.pop_back();
        }
        
        maze[row][col] = 1;// backtrack;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        
         if (n == 0 || maze[0][0] == 0 || maze[n-1][n-1] == 0)
            return ans;
        
        string path = "";
        
        solve(0, 0, ans, path, maze);
        
        // DLRU -> if this is followed then no sorting need else sorting will required
        // sort(ans.begin(), ans.end());
        
        return ans;
        
    }
};