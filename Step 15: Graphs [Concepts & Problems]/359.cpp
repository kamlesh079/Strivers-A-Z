// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// ---------- Dijkstra's Algorithm Using Priority Queue (Min Heap) ----------
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> dist(V, INT_MAX);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {

            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto nbr : adj[u]) {

                auto [v, wt] = nbr;

                // if (d + wt < dist[v]) {
                //     dist[v] = d + wt;
                //     pq.push({dist[v], v});
                // }
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

// ---------- Dijkstra's Algorithm set ----------
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);

        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> dist(V, INT_MAX);
        set<pair<int, int>> st;   // {distance, node}

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {

            auto [d, u] = *st.begin();
            st.erase(st.begin());

            for (auto [v, wt] : adj[u]) {

                if (d + wt < dist[v]) {

                    // Remove old distance if it exists
                    auto found = st.find({dist[v], v});
                    if (found != st.end())
                        st.erase(found);

                    dist[v] = d + wt;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist;
    }
};


// Time Complexity: O((V+E)logV), each edge is relaxed at most once, and for each relaxation wemay push into the priority queue, giving O(E) pushes with O(log V) heap operations.
// Space Complexity: O(V+E), additonal space is used to store adjacency list, distance array and priority queue.