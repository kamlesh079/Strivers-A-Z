https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution {
	public:
	int spanningTree(int V, vector<vector<int>> & edges) {
		vector<vector<pair<int, int>> > adj(V);
		for (auto e : edges) {
			int u = e[0];
			int v = e[1];
			int wt = e[2];
			
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		
		priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>
		>q;
		
		vector<int> vis(V, 0);
		
		int sum = 0;
		
		q.push({0, 0}); // {wt, node}
		
		while (!q.empty()) {
			auto [wt, node] = q.top();
			q.pop();
			
			if (vis[node])
				continue;
			
			vis[node] = 1;
			sum += wt;
			
			for (auto nbr : adj[node]) {
				auto[v, edW] = nbr;
				if (!vis[v])
					q.push({edW, v});
			}
			
		}
		return sum;
	}
};
