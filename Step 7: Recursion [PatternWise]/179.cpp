// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

class Solution {
  public:
    bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& adj){
        for(int nbr : adj[node]){
            if(color[nbr] == col)
                return false;
        }
        return true;
    }
  
    bool solve(int node, int m, int n, vector<int>& color, vector<vector<int>>& adj){
        if(node == n) 
            return true;
        
        for(int col = 1; col <= m; col++){
            if(isSafe(node, col, color, adj)){
                color[node] = col;
                if(solve(node + 1, m, n, color, adj))
                    return true;
                color[node] = 0; // backtrack
            }
        }
        return false;
    }
    
    bool graphColoring(int n, vector<vector<int>> &edges, int m) {
       vector<vector<int>> adj(n);
       for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(n, 0);
        
        return solve(0, m, n, color, adj);
        
    }
};