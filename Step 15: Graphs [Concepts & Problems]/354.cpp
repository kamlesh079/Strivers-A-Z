// https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    // Kahn's Algorithm (Topological Sort - BFS)
    vector<int> kahn(int n, vector<vector<int>>& adj) {

        // Calculate indegree of every node
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int nbr : adj[i])
                indegree[nbr]++;
        }

        // Start with all nodes having indegree 0
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            order.push_back(course);

            // Remove outgoing edges
            for (int nbr : adj[course]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // If all courses are processed, topological order exists
        if (order.size() == n)
            return order;

        return {};
    }

    // DFS Topological Sort with Cycle Detection
    bool dfs(int node, vector<bool>& vis, vector<bool>& pathVis,
             vector<vector<int>>& adj, vector<int>& order) {

        vis[node] = true;
        pathVis[node] = true;

        for (int nbr : adj[node]) {

            if (!vis[nbr]) {
                if (dfs(nbr, vis, pathVis, adj, order))
                    return true;
            }
            // Back edge found -> cycle exists
            else if (pathVis[nbr]) {
                return true;
            }
        }

        // Backtrack
        pathVis[node] = false;

        // Add node after processing all its neighbours
        order.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Build graph: prerequisite -> course
        for (auto& it : prerequisites) {
            int prerequisite = it[1];
            int course = it[0];

            adj[prerequisite].push_back(course);
        }

        // ---------- Kahn's Algorithm ----------
        // return kahn(numCourses, adj);

        // ---------- DFS Topological Sort ----------
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                // Cycle found -> no valid ordering exists
                if (dfs(i, vis, pathVis, adj, order))
                    return {};
            }
        }

        // Reverse postorder gives topological order
        reverse(order.begin(), order.end());

        return order;
    }
};