

// ------ Using Adjacency List + DFS ------
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (int nbr : adj[node]) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Adjacency matrix -> adjacency list
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        // DFS
        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, adj, vis);
            }
        }

        return provinces;
    }
};

// ------ Using Adjacency Matrix + DFS ------
class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[city] = true;

        for(int next = 0; next < isConnected.size(); next++){
            if(isConnected[city][next] == 1 && !visited[next]){
                dfs(next, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        for(int city = 0; city < n; city++){
            if(!visited[city]){
                count++;
                dfs(city, isConnected,visited);
            }
        }
        return count;
    }
};