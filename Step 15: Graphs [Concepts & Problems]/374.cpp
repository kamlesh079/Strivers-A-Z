// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1


// ------ Kruskals Algorithm to find Minimum Spanning Tree (MST) ------
class Solution {
	public:
	vector<int> rank;
	vector<int> parent;
	
	int findUPar(int num) {
		if (parent[num] == num)
			return num;
		
		return parent[num] = findUPar(parent[num]);
	}
	
	void unionByRank(int u, int v) {
		int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);
		
		if (ulp_u == ulp_v)
			return;
		
		if (rank[ulp_u] < rank[ulp_v])
			parent[ulp_u] = ulp_v;
		else if (rank[ulp_v] < rank[ulp_u]) {
			parent[ulp_v] = ulp_u;
		}
		else {
			parent[ulp_v] = ulp_u;
			rank[ulp_u]++;
		}
	}
	
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		rank.resize(V, 0);
		parent.resize(V, 0);
		for (int i = 0; i < V; i++) {
			parent[i] = i;
		}
		
		int sum = 0;
		
		sort(edges.begin(), edges.end(), [](auto& e1, auto& e2) {
			return e1[2] < e2[2];
		});
		
		
		for(auto e : edges){
		    int u = e[0];
		    int v = e[1];
		    int wt = e[2];
		    
		    if(findUPar(u) != findUPar(v)){
		        sum += wt;
		        
		        unionByRank(u, v);
		    }
		}
		return sum;
	}
};
