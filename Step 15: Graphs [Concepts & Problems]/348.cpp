// https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool bfs(int src, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;

        q.push(src);
        color[src] = 0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            for(int nbr: graph[node]){
                // if it is not colored
                if(color[nbr] == -1){
                    color[nbr] = !color[node];
                    q.push(nbr);
                }
                // if it is already colored
                else if(color[nbr] == color[node])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // -1 = uncolored
        // 0 = first color
        // 1 = second color
        vector<int> color(n, -1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                bool ans = bfs(i, graph, color);
                if(!ans)
                    return false;
            }
        }
        return true;
    }
};