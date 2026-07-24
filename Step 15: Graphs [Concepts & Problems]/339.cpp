// Link - https://leetcode.com/problems/flood-fill/


// --------- DFS Solution ---------
class Solution {
public:
    void dfs(int org, int sr, int sc, vector<vector<int>>& image, int color) {
        int n = image.size();
        int m = image[0].size();

        if (sr < 0 || sc < 0 || sr >= n || sc >= m || image[sr][sc] != org)
            return;

        image[sr][sc] = color;
        dfs(org, sr + 1, sc, image, color);
        dfs(org, sr - 1, sc, image, color);
        dfs(org, sr, sc - 1, image, color);
        dfs(org, sr, sc + 1, image, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int org = image[sr][sc];

        if (org == color)
            return image;

        dfs(org, sr, sc, image, color);

        return image;
    }
};

// --------- BFS Solution ---------
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        if (image[sr][sc] == color)
            return image;

        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int old_color = image[sr][sc];
        image[sr][sc] = color;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    image[nr][nc] ==  old_color) {
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};