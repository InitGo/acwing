class Solution {
public:
    int n, m;
    bool st[310][310];
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i ++ ) 
            for (int j = 0; j < m; j ++ )
                if (grid[i][j] == '1' && !st[i][j]) {
                    ans ++ ;
                    dfs(grid, i, j);
                    //bfs(grid, i, j);
                }
        return ans;
    }

    void bfs(vector<vector<char>>& grid, int x, int y) {
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
                if (st[a][b] || grid[a][b] == '0') continue;

                st[a][b] = true;
                q.push({a, b});
            }
        }
    } 

    void dfs(vector<vector<char>>& grid, int x, int y) {
        st[x][y] = true;
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b] || grid[a][b] == '0') continue;
            dfs(grid ,a, b);
        }
    }
};