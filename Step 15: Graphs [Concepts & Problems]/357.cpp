
// # BFS (Breadth First Search) Approach Using distance array to find the shortest path in an unweighted graph  
class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<int>> adj(V);
        
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        vector<int> dist(V, -1);
        
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nbr : adj[node]){
                if(dist[nbr] == -1){
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }
        return dist[dest];
    }
};



// BFS (Breadth First Search) Approach Using parent array to find the shortest path in an unweighted graph
// This is helpfull when u need to find the path from source to destination as well as the distance
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);
        queue<int> q;
        
        q.push(src);
        vis[src] = true;
        // parent[src] = -1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nbr : adj[node]){
                if(!vis[nbr]){
                    vis[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }

        vector<int> ans(V, -1);

        ans[src] = 0;

        for(int dest = 0; dest < V; dest++){

            if(dest == src) continue;

            if(!vis[dest]) continue;

            int node = dest;
            int cost = 0;

            while(parent[node] != -1){
                cost++;
                node = parent[node];
            }

            ans[dest] = cost;
        }

        return ans[dest];
    }
};


// Important Note:
// BFS Shortest Path (Unweighted Graph)

// -> Single Source Shortest Path (SSSP)
// -> Works for both Directed & Undirected graphs
// -> Valid only when all edge weights are equal (usually 1)
// -> BFS explores level by level
// -> First time a node is visited = Shortest path to that node
// -> dist[] stores shortest distance from source
// -> dist[node] == -1 means node is unvisited/unreachable

// Time Complexity: O(V + E)
// Space Complexity: O(V + E)