// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long, int>,
               vector<pair<long long, int>>,
               greater<pair<long long, int>>> pq;

        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (wt > dist[node])
                continue;
            for (auto nbr : adj[node]) {
                int v = nbr.first;
                int edW = nbr.second;

                if (dist[node] + edW < dist[v]) {
                    dist[v] = dist[node] + edW;
                    pq.push({dist[v], v});

                    ways[v] = ways[node];
                } else if (dist[node] + edW == dist[v]) {
                    ways[v] = (ways[v] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};