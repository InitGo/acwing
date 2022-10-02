class Solution {
public:
    string countAndSay(int n) {
        string f[32];
        f[1] = "1";

        for (int k = 2; k <= n; k ++ ) {
            for (int i = 0; i < f[k - 1].size(); i ++ ) {
                int cnt = 1;
                while (i + 1 < f[k - 1].size() && f[k - 1][i] == f[k - 1][i + 1]) cnt ++ , i ++ ;            
                f[k] += cnt + '0';
                f[k] += f[k - 1][i];
            }
        }
        return f[n];
    }
};