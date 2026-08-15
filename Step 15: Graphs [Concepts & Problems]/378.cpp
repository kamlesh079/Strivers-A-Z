// https://www.naukri.com/code360/problems/number-of-islands-ii_1266048

vector<int> parent;
vector<int> ranlDSU;

int findParent(int x){
	if(parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionByRank(int u, int v){
	int ulp_u = findParent(u);
	int ulp_v = findParent(v);

	if(ulp_u == ulp_v) 
		return;

	if(ranlDSU[ulp_u] < ranlDSU[ulp_v])
		parent[ulp_u] = ulp_v;
	else if(ranlDSU[ulp_u] > ranlDSU[ulp_v])
		parent[ulp_v] = ulp_u;
	else{
		parent[ulp_v] = ulp_u;
		ranlDSU[ulp_u]++;
	}
}


vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &queries){
	parent.resize(n * m);
	ranlDSU.resize(n * m, 0);

	for(int i = 0; i < n * m; i++)
		parent[i] = i;


	vector<vector<int>> grid(n, vector<int>(m, 0));

	vector<int> ans;
	int count = 0;

	int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

	for(auto& q : queries){
		int r = q[0];
		int c = q[1];

		// Already land
		if(grid[r][c] == 1){
			ans.push_back(count);
			continue;
		}

		// Make current cell land
		grid[r][c] = 1;
		count++;

		int node = r + n * c;

		// Check 4 neighbours
		for(int i = 0; i < 4; i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 0){
				int adjNode = nr + n * nc;
				
				if(findParent(node) != findParent(adjNode)){
					unionByRank(node, adjNode);
					count--;
				}
			}
		}

		ans.push_back(count);
	}

	return ans;

}