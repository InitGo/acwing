class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        int f[n + 2][m + 2];
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i <= n; i ++ ) f[i][0] = i;
        for (int i = 0; i <= m; i ++ ) f[0][i] = i;

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1];
                else {
                    f[i][j] = min(f[i][j], f[i][j - 1] + 1);
                    f[i][j] = min(f[i][j], f[i - 1][j] + 1);
                    f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
            }
        return f[n][m];
    }
};