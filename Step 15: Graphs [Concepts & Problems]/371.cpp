// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// ------------ DFS Cycle Detection in Undirected Graph ------------
class Solution {
	public:
	bool dfs(int node, int parent, vector<bool>& visited, vector<vector<int>> & adj) {
		visited[node] = true;
		
		for (int nbr : adj[node]) {
			if (!visited[nbr]) {
				bool ans = dfs(nbr, node, visited, adj);
				if (ans)
					return true;
			}
			else if (nbr != parent)
				return true;
		}
		return false;
		
	}
	bool isCycle(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		for (auto e : edges) {
			int u = e[0];
			int v = e[1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<bool> visited(V, false);
		for (int src = 0; src < V; src++) {
			if (!visited[src]) {
				bool ans = dfs(src, -1, visited, adj);
				if (ans)
					return true;
			}
		}
		return false;
		
	}
};
