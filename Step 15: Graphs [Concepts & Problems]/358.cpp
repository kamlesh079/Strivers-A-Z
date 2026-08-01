// https://www.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1

class Solution {
	public:
	void topoSort(int src, stack<int>& topoOrder, vector<vector<pair<int, int>>>& adj, vector<bool>& vis) {
		vis[src] = true;
		
		for (auto nbr : adj[src]) {
			if (!vis[nbr.first])
				topoSort(nbr.first, topoOrder, adj, vis);
		}
		
		topoOrder.push(src);
	}
	vector<int> shortestPath(int V, int E, vector<vector<int>> & edges) {
		vector<vector<pair<int, int>> > adj(V);
		
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			adj[u].push_back({v, wt});
			
		}
		
		stack<int> topoOrder;
		vector<bool> vis(V, false);
		
		for (int i = 0; i < V; i++) {
			if (!vis[i])
				topoSort(i, topoOrder, adj, vis);
		}
		
		vector<int> dist(V, INT_MAX);
		
		dist[0] = 0;
		
		while (!topoOrder.empty()) {
			int node = topoOrder.top();
			topoOrder.pop();
			
			if (dist[node] == INT_MAX)
				continue;
			
			for (auto nbr : adj[node]) {
				int v = nbr.first;
				int wt = nbr.second;
				if (dist[node] + wt < dist[v]) {
					dist[v] = dist[node] + wt;
				}
			}
		}
		
		for (int i = 0; i < V; i++) {
			if (dist[i] == INT_MAX)
				dist[i] = -1;
		}
		return dist;
	}
};
