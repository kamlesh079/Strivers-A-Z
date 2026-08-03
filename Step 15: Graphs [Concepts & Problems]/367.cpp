// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution {
	public:
	vector<int> bellmanFord(int V, vector<vector<int>> & edges, int src) {
		vector<vector<pair<int, int>> > adj(V);
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			
			adj[u].push_back({v, wt});
		}
		
		vector<int> dist(V, 1e8);
		dist[src] = 0;
		
		//  Bellman-Ford Relax(V - 1 times) But since we need to check cycle to lets do it One extar time
		for (int k = 0; k < V; k++) {
			
			for (int i = 0; i < V; i++) {
				
				if (dist[i] == 1e8)
					continue;
				
				for (auto nbr: adj[i]) {
					int v = nbr.first;
					int edW = nbr.second;
					
					if (edW + dist[i] < dist[v]) {
						if (k == V - 1)
							return {-1};
						
						dist[v] = edW + dist[i];
					}
				}
			}
		}
		
		return dist;
		
	}
};
