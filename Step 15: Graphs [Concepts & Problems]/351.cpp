// https://www.geeksforgeeks.org/problems/topological-sort/1


// --------------- Kahn's Algorithm -----------------
class Solution {
	public:
	vector<int> kahn(int n, vector<vector<int>> & adj) {
	    vector<int> ans;
	    
	    vector<int> indegree(n, 0);
	    
	    for(int i = 0; i < n; i++){
	        for(int nbr : adj[i]){
	            indegree[nbr]++;
	        }
	    }
	    
	    queue<int> q; 
	    
	    // push all the nodes that have indgree of 0;
	    for(int i = 0; i < n; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    
	    while(!q.empty()){
	        auto node = q.front(); 
	        q.pop();
	        
	        ans.push_back(node);
	        
	        for(int nbr : adj[node]){
	            indegree[nbr]--;
	            if(indegree[nbr] == 0)
	                q.push(nbr);
	        }
	    }
	    return ans;
	}
	
	vector<int> topoSort(int V, vector<vector<int>> & edges) {
		vector<vector<int>> adj(V);
		for (auto e : edges) {
			int u = e[0];
			int v = e[1];
			adj[u].push_back(v);
		}
		
		return kahn(V, adj);
		
	}
};
