// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    vector<int> parent, rank;

    int findUPar(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findUPar(parent[x]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int OFFSET = 10001;
        int N = OFFSET * 2;

        parent.resize(N);
        rank.resize(N, 0);

        for (int i = 0; i < N; i++)
            parent[i] = i;

        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + OFFSET;

            unionByRank(row, col);
        }
        
        unordered_set<int> components;
        for (auto &stone : stones) {
            int row = stone[0];
            int col = stone[1] + OFFSET;

            components.insert(findUPar(row));
            components.insert(findUPar(col));
        }


        return stones.size() - components.size();
    }
};