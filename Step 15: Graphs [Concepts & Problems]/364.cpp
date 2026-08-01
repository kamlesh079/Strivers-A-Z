// https://leetcode.com/problems/network-delay-time/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto e : times) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<int> dist(n + 1, 1e9);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue; // stale data

            for (auto nbr : adj[node]) {
                auto [nbr_node, nbr_wt] = nbr;

                if (dist[node] + nbr_wt < dist[nbr_node]) {
                    dist[nbr_node] = dist[node] + nbr_wt;
                    pq.push({dist[node] + nbr_wt, nbr_node});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};