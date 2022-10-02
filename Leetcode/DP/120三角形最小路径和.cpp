#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        const int INF = 0x3f3f3f3f;
        int f[n + 2][n + 2];
        memset(f, 0x3f, sizeof f);

        f[1][1] = triangle[0][0];
        for (int i = 2; i <= n; i ++ ) 
            for (int j = 1; j <= triangle[i - 1].size(); j ++ ) 
                f[i][j] = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i - 1][j - 1];
        
        int ans = INF;
        for (int j = 1; j <= triangle[n - 1].size(); j ++ )
            ans = min(ans, f[n][j]);
        return ans;
    }
};

int main()
{
    vector<vector<int>> triangle{{2},{3,4},{6,5,7},{4,1,8,3}};

    auto s = Solution();
    int ans = s.minimumTotal(triangle);

    cout << ans << endl;
    return 0;
}