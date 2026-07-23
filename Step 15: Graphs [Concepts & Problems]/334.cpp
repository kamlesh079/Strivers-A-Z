// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
	public:
	vector<int> bfs(vector<vector<int>> &adj) {
		int n = adj.size();
		
		vector<int> ans;
		
		queue<int> q;
		vector<int> visited(n, false);
		
		q.push(0);
		visited[0] = true;
		ans.push_back(0);
		
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			
			for (int nbr : adj[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					ans.push_back(nbr);
				}
			}
		}
		
		return ans;
		
	}
};
