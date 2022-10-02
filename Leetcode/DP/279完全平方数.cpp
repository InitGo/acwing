class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for (int i = 1;  i <= n; i ++ ) v.push_back(i * i);

        int f[n + 2];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;

        for (int i = 1; i <= n; i ++ )
            for (int j = v[i - 1]; j <= n; j ++ ) {
                f[j] = min(f[j], f[j - v[i - 1]] + 1);
            }
        return f[n];
    }
};