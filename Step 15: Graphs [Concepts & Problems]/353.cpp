// https://leetcode.com/problems/course-schedule

class Solution {
public:
    // Kahn's Algorithm (BFS)
    bool kahn(int n, vector<vector<int>>& adj) {

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

        int count = 0; // Number of processed courses

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;

            // Remove outgoing edges
            for (int nbr : adj[course]) {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        // If all courses are processed, no cycle exists
        return count == n;
    }

    // DFS Cycle Detection
    bool dfs(int node, vector<bool>& vis, vector<bool>& pathVis,
             vector<vector<int>>& adj) {

        vis[node] = true;
        pathVis[node] = true;

        for (int nbr : adj[node]) {

            if (!vis[nbr]) {
                if (dfs(nbr, vis, pathVis, adj))
                    return true;
            }
            // Back edge found -> cycle exists
            else if (pathVis[nbr]) {
                return true;
            }
        }

        // Backtrack
        pathVis[node] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // Build graph: prerequisite -> course
        for (auto &it : prerequisites) {
            int prerequisite = it[1];
            int course = it[0];

            adj[prerequisite].push_back(course);
        }

        // ---------- Kahn's Algorithm ----------
        // return kahn(numCourses, adj);

        // ---------- DFS Cycle Detection ----------
        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                // Cycle found -> cannot finish all courses
                if (dfs(i, vis, pathVis, adj))
                    return false;
            }
        }

        return true;
    }
};