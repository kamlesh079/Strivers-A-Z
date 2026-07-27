// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& ans){
        vis[node] = true;
        
        for(int nbr : adj[node]){
            if(!vis[nbr])
                dfs(nbr, adj, vis, ans);
        }
        
        // while return store nodes to ans
        ans.push_back(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false); // or store in stack and then push back to vector
        vector<int> ans;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, ans);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};