// https://leetcode.com/problems/making-a-large-island/

class Solution {
public:
    vector<int> size;
    vector<int> parent;

    int findParent(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = findParent(parent[x]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        size.resize(n * n, 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Step 1: Create and merge all existing islands
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0)
                    continue;

                int u = r * n + c;

                for (int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int v = nr * n + nc;

                        if (findParent(u) != findParent(v))
                            unionBySize(u, v);
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: Try converting every 0 into 1
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                // Existing island
                if (grid[r][c] == 1) {
                    ans = max(ans, size[findParent(r * n + c)]);
                    continue;
                }

                unordered_set<int> st;

                // Find unique neighbouring islands
                for (int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        int node = nr * n + nc;

                        st.insert(findParent(node));
                    }
                }

                int sum = 1;  // Convert current 0 -> 1

                for (int parent : st)
                    sum += size[parent];

                ans = max(ans, sum);
            }
        }

        return ans;
    }
};