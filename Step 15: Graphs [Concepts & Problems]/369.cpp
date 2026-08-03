// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

// ----------- Floyd Warshall Algorithm (n^3) -----------
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Distance to itself
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Insert edges
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == INT_MAX || dist[via][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int minCnt = INT_MAX;
        int city = -1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    cnt++;
            }
            // Tie -> larger index
            if (cnt <= minCnt) {
                minCnt = cnt;
                city = i;
            }
        }
        return city;
    }
};

// ----------- Dijkstra Algorithm (n * (n + m) log n) -----------

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        int minCnt = INT_MAX;
        int city = -1;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);

            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>> pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {

                auto [d, node] = pq.top();
                pq.pop();

                if (d > dist[node])
                    continue;

                for (auto [nbr, wt] : adj[node]) {

                    if (dist[node] + wt < dist[nbr]) {

                        dist[nbr] = dist[node] + wt;
                        pq.push({dist[nbr], nbr});
                    }
                }
            }

            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (i != src && dist[i] <= distanceThreshold)
                    cnt++;
            }

            if (cnt <= minCnt) {
                minCnt = cnt;
                city = src;
            }
        }

        return city;
    }
};