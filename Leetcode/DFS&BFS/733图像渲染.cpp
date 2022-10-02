class Solution {
public:
    int n, m;
    bool st[55][55];
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();
        memset(st, 0, sizeof st);
        dfs(image, sr, sc);
        //bfs(image, sr, sc);
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
                if (st[i][j])
                    image[i][j] = color;
        return image;
        
    }

    void bfs(vector<vector<int>>& image, int x, int y) {
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        queue<pair<int, int>> q;
        q.push({x, y});
        st[x][y] = true;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i ++ ) {
                int a = t.first + dx[i], b = t.second + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m) continue;
                if (st[a][b]) continue;
                if (image[t.first][t.second] != image[a][b]) continue;

                st[a][b] = true;
                q.push({a, b});
            }
        }
    }

    void dfs(vector<vector<int>>& image, int x, int y) {
        st[x][y] = true;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b]) continue;
            if (image[x][y] != image[a][b]) continue;
            
            dfs(image, a, b);
        }
    }
};