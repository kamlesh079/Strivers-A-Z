// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
    bool dfs(int src, vector<vector<int>> &adj, vector<bool>& visited, vector<bool>& dfsTracker){
        visited[src] = true;
        dfsTracker[src] = true;
        
        for(int nbr : adj[src]){
            if(!visited[nbr]){
                if(dfs(nbr, adj, visited, dfsTracker))
                    return true;
            }
            else if(dfsTracker[nbr]) 
                return true;
        }
        dfsTracker[src] = false; // backtracking
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // make adj list
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> dfsTracker(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, dfsTracker))
                    return true;
            }
               
        }
        return false;
    }
};