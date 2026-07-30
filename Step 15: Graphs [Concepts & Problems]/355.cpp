// https://www.geeksforgeeks.org/problems/eventual-safe-states/1
// https://leetcode.com/problems/find-eventual-safe-states


// -------- DFS -------
class Solution {
	public:
	bool dfs(int src, vector<vector<int>> &adj, vector<bool>& visited, vector<bool>& dfsTracker, vector<int>& safe) {
		visited[src] = true;
		dfsTracker[src] = true;
		
		safe[src] = 0;
		
		for (int nbr : adj[src]) {
			if (!visited[nbr]) {
				if (dfs(nbr, adj, visited, dfsTracker, safe))
					return true;
			}
			else if (dfsTracker[nbr])
				return true;
		}
		   
		safe[src] = 1;
		
		dfsTracker[src] = false; // backtracking
		return false;
	}
	vector<int> safeNodes(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		for(auto e : edges){
		    int u = e[0];
		    int v = e[1];
		    adj[u].push_back(v);
		}
		
		vector<bool> vis(V, false);
		vector<bool> pathTracker(V, false);
		vector<int> safe(V, 0);
		
		for(int i = 0; i < V; i++){
		    if(!vis[i])
		        dfs(i, adj, vis, pathTracker, safe);
		}
		
		vector<int> ans;
		for(int i = 0; i < safe.size(); i++){
		    if(safe[i])
		        ans.push_back(i);
		}
		
		return ans;
	}
};


// -------- BFS (Kahn's Algorithm) -------
class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> revAdj(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            revAdj[v].push_back(u);
        }
        
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(int nbr : revAdj[i])
                indegree[nbr]++;
        }
        
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> safe;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            safe.push_back(node);
            
            for(int nbr : revAdj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
            
        }
        
        sort(safe.begin(), safe.end());
        
        return safe;
        
    }
};