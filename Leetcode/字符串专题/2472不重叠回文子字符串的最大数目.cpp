class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> g(n + 1, vector<bool>(n + 1));
        for (int len = 1; len <= n; len ++ ) {
            for (int i = 1; i + len - 1 <= n; i ++ ) {
                int j = i + len - 1;
                if (s[i - 1] == s[j - 1] && (len <= 2 || g[i + 1][j - 1]))
                    g[i][j] = true;
            }
        }

        vector<int> f(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            f[i] = f[i - 1];
            for (int j = i - k + 1; j >= 1; j -- ) {  //枚举最后一个回文串的起始位置,从i-k+1开始， i-(i-k+1)+1=k
                if (g[j][i]) {
                    f[i] = max(f[i], f[j - 1] + 1);
                }
            }
        }

        return f[n];
    }
};