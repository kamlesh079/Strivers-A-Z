// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
	public:
	bool kahn(int n, vector<vector<int>> & adj) {
		// vector<int> ans;
		
		vector<int> indegree(n, 0);
		for (int i = 0; i < n; i++) {
			for (int nbr : adj[i]) {
				indegree[nbr]++;
			}
		}
		
		queue<int> q;
		// push all the nodes that have indgree of 0;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}
		
		int count = 0;
		
		while (!q.empty()) {
			auto node = q.front();
			q.pop();
			
			// ans.push_back(node);
			count++;
			
			for (int nbr : adj[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0)
					q.push(nbr);
			}
		}
		// return ans;
		return count != n; // if count != n then there is a cycle
	}
	bool isCyclic(int V, vector<vector<int>> &edges) {
		vector<vector<int>> adj(V);
		for (auto e : edges) {
			int u = e[0];
			int v = e[1];
			adj[u].push_back(v);
		}

        // Core Logic: If there is cycle in the graph then topological will have less nodes than the total number of nodes in the graph. So we can use Kahn's algorithm to check if there is a cycle in the graph or not.

		return kahn(V, adj);
		
	}
};

