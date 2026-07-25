// https://leetcode.com/problems/critical-connections-in-a-network/

class Solution {
public:
    void dfs(int node, int &time, int parent,
             vector<int>& tin, vector<int>& low,
             vector<bool>& vis,
             vector<vector<int>>& adj,
             vector<vector<int>>& bridges){

        // Mark current node as visited
        vis[node] = true;

        // Assign discovery time (tin)
        // Initially, the lowest tin reachable is itself
        tin[node] = low[node] = time++;

        // Explore all neighbours
        for(int nbr : adj[node]){

            // Ignore the edge through which we came here
            // We are interested in finding another way back
            if(nbr == parent) continue;

            // ---------------- TREE EDGE ----------------
            // Neighbour not visited -> DFS further
            if(!vis[nbr]){

                dfs(nbr, time, node, tin, low, vis, adj, bridges);

                // Child explored its entire subtree.
                // If child (or anyone below it) found an earlier ancestor,
                // then current node can also reach that ancestor.
                low[node] = min(low[node], low[nbr]);

                // Bridge Condition:
                //
                // If child's subtree CANNOT reach current node
                // or any ancestor of current node using a back edge,
                // then removing (node,nbr) disconnects the graph.
                //
                //        node ----- nbr
                //
                // low[nbr] > tin[node]
                //
                // means the only connection is this edge.
                if(low[nbr] > tin[node]){
                    bridges.push_back({node, nbr});
                }
            }

            // ---------------- BACK EDGE ----------------
            else{

                // Already visited neighbour (not parent)
                // Means we found a back edge to an ancestor.
                //
                // Update low with ancestor's discovery time.
                //
                // IMPORTANT:
                // Use tin[nbr], NOT low[nbr]. thought both works but We use tin[nbr] because it directly represents the ancestor reached by the back edge. At the moment this back edge is processed, low[nbr] is typically the same value anyway, which is why using low[nbr] also works for this problem.
                // Because back edges always point directly to an ancestor.
                low[node] = min(low[node], tin[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // Build adjacency list
        vector<vector<int>> adj(n);

        for(auto &edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, false);

        // tin[i] = discovery time of node i
        vector<int> tin(n);

        // low[i] = smallest tin reachable from i
        //          (including itself and its DFS subtree)
        //          without using the parent edge
        vector<int> low(n);

        int time = 0;

        vector<vector<int>> bridges;

        // Graph may be disconnected,
        // so start DFS from every unvisited node.
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, time, -1, tin, low, vis, adj, bridges);
            }
        }

        return bridges;
    }
};