// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// ------------ BFS Cycle Detection in Undirected Graph ------------
class Solution {
	public:
	bool hasCycle(int src, int V, vector<vector<int>>& adj, vector<bool>& visited){
	    queue<int> q;
		vector<int> parent(V, -1);
		
		q.push(src);
		visited[src] = true;
		parent[src] = -1;
		
		while(!q.empty()){
		    int node = q.front();
		    q.pop();
		    
		    for(int nbr : adj[node]){
		        if(!visited[nbr]){
		            visited[nbr] = true;
		            parent[nbr] = node;
		            q.push(nbr);
		        }
		        else if(parent[node] != nbr)
		            return true;
		    }
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
		
        // ****** Important (If graph is disconnected ) ****** 	
		vector<bool> visited(V, false);
		for(int i = 0; i < V; i++){
		    if(!visited[i]){
		        bool ans = hasCycle(i, V, adj, visited);
		        if(ans)
		            return true;
		    }
		}
		return false;
	}
};
