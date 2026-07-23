// https://www.geeksforgeeks.org/problems/number-of-provinces/1


// ----- DFS Solution -----
class Solution {
	public:
	void dfs(int node, vector<vector<int>> & adj, vector<bool>& visited) {
		visited[node] = true;
		for (int nbr : adj[node]) {
			if (!visited[nbr])
				dfs(nbr, adj, visited);
		}
	}
	int countConnected(int V, vector<vector<int>> & edges) {
	    vector<vector<int>> adj(V);
		for (auto& e : edges) {
			int u = e[0];
			int v = e[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited(V, false);
		int components = 0;
		for (int node = 0; node < V; node++) {
			if (!visited[node]) {
				dfs(node, adj, visited);
				components++;
			}
		}
		return components;
		
	}
};

// ----- BFS Solution -----
class Solution {
	public:
	int countConnected(int V, vector<vector<int>> & edges) {
	    vector<vector<int>> adj(V);
		for (auto& e : edges) {
			int u = e[0];
			int v = e[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited(V, false);
		int components = 0;
		
		
		for (int node = 0; node < V; node++) {
			if(!visited[node]){
			    queue<int> q;
			    visited[node] = true;
			    q.push(node);
			    components++;
			    
			    while(!q.empty()){
			        int node = q.front();
			        q.pop();
			        for(int nbr : adj[node]){
			            if(!visited[nbr]){
			                visited[nbr] = true;
			                q.push(nbr);
			            }
			        }
			    }
			}
		}
		return components;
		
	}
};