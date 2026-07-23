// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

// ---------- DFS ----------
class Solution {
	public:
	void dfs(int node, vector<int>& temp, vector<bool>& visited, vector<vector<int>> & adj) {
		visited[node] = true;
		temp.push_back(node);
		
		for (int nbr : adj[node]) {
			if (!visited[nbr])
				dfs(nbr, temp, visited, adj);
		}
	}
	
	vector<vector<int>> getComponents(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		for (auto e: edges) {
			int u = e[0];
			int v = e[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited(V, false);
		
		vector<vector<int>> ans;
		
		for (int i = 0; i<V; i++) {
			if (!visited[i]) {
				vector<int> temp;
				dfs(i, temp, visited, adj);
				
				sort(temp.begin(), temp.end());
				ans.push_back(temp);
			}
		}
		return ans;
	}
};

// ---------- BFS ----------
class Solution {
	public:
	
	vector<vector<int>> getComponents(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		for (auto e: edges) {
			int u = e[0];
			int v = e[1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited(V, false);
		
		vector<vector<int>> ans;
		
		
		for (int i = 0; i<V; i++) {
			if (!visited[i]) {
				vector<int> temp;
				queue<int> q;
				q.push(i);
				visited[i] = true;
				temp.push_back(i);
				
				while (!q.empty()) {
				    int node = q.front();
				    q.pop();
					for (int nbr : adj[node]) {
						if (!visited[nbr]) {
							q.push(nbr);
							visited[nbr] = true;
							temp.push_back(nbr);
						}
					}
				}
				
				sort(temp.begin(), temp.end());
				ans.push_back(temp);
			}
			
		}
		return ans;
	}
};
