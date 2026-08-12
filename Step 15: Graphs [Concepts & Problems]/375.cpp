// https://leetcode.com/problems/number-of-operations-to-make-network-connected/


// Using Union-Find (Disjoint Set Union) data structure to find the number of operations to make the network connected
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
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    int makeConnected(int V, vector<vector<int>>& connections) {
        if (connections.size() < V - 1)
            return -1;

        rank.resize(V, 0);
        parent.resize(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int extra = 0;

        for (auto e : connections) {

            int u = e[0];
            int v = e[1];

            if (findUPar(u) == findUPar(v)) {
                extra++;
            } else {
                unionByRank(u, v);
            }
        }

        int components = 0;
        for (int i = 0; i < V; i++) {
            if (findUPar(i) == i)
                components++;
        }
        
        int required = components - 1;

        if (extra >= required)
            return required;

        return -1;
    }
};


