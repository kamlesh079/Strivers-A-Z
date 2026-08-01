// https://leetcode.com/problems/cheapest-flights-within-k-stops


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto e : flights){
            int u = e[0];
            int v = e[1];
            int cost = e[2];
            adj[u].push_back({v, cost});
        }

        vector<int> dist(n, 1e9);
        
        dist[src] = 0;

        queue<pair<int, pair<int, int>>> q; // {k, {v, cost}} : k -> no of stops

        q.push({0, {src, 0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto nbr : adj[node]){
                int v = nbr.first;
                int edW = nbr.second;
                
                if(cost + edW < dist[v]){
                    dist[v] = cost + edW;
                    q.push({stops + 1, {v, cost + edW}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};