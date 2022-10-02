#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& a, int S) {
        // 由于题目里说数组里总和最多只有1000，所以只能做[-1000,+1000]，如果S不在这个范围就直接返回
        if (S < -1000 || S > 1000) return 0;
        int n = a.size(), Offset = 1000; // 因为有负数，所以这里用一个偏移量，所有的j放到f里都要加上这个偏移量
        vector<vector<int>> f(n + 1, vector<int>(2 * Offset + 1)); //2001：数据范围差是2001
        f[0][0 + Offset] = 1; // 选0个数，总和也是0的情况（因为在f数组里所以加上了一个偏移量Offset）
        for (int i = 1; i <= n; i ++ ) {
            for (int j = -1000; j <= 1000; j ++ ) {
                // 注意，因为a的下标是从0开始的，所以这里要用a[i - 1]
                // a[i]取正数
                if (j - a[i - 1] + Offset >= 0) //f的第二维的取值范围是0 ~2000
                    f[i][j + Offset] += f[i - 1][j - a[i - 1] + Offset];
                // a[i]取负数
                if (j + a[i - 1] + Offset <= 2000)
                    f[i][j + Offset] += f[i - 1][j + a[i - 1] + Offset];
            }
        }
        return f[n][S + Offset]; // 在前n个数里选，总和是S的方案数
    }
};