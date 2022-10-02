class Solution {
public:
    int ans;
    bool col[12], dg[20], udg[20];
    int totalNQueens(int n) {
        dfs(0, n);
        return ans;
    }

    void dfs(int u, int n) {
        if (u == n) {
            ans ++ ;
            return;
        }

        for (int i = 0; i < n; i ++ ) {
            if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
                col[i] = dg[u + i] = udg[n - u + i] = true;
                dfs(u + 1, n);
                col[i] = dg[u + i] = udg[n - u + i] = false;
            }
        }
    }
};