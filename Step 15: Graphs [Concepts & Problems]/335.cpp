// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void dfs(int node, vector<int>& ans, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        ans.push_back(node);
        
        for(int nbr : adj[node]){
            if(!visited[nbr])
                dfs(nbr, ans, adj, visited);
        }
    }   
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<int> ans;
        
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, ans, adj, visited);
            }
        }
        return ans;
    }
};