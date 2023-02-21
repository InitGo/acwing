#include <iostream>

using namespace std;

const int N = 110, M = 12;

int n, m;
int f[N][M];

int main()
{
    while (cin >> n >> m)
    {
        //就不考虑第0层的情况，直接初始化第1层，然后从第2层开始递推
        //如果有i层，1次机会
        for (int i = 1; i <= n; i ++ ) f[i][1] = i;
        //如果有1层，j次机会
        for (int j = 1; j <= m; j ++ ) f[1][j] = 1;
        
        for (int i = 2; i <= n; i ++ )
            for (int j = 2; j <= m; j ++ )
            {
                f[i][j] = f[i][j - 1];
                for (int k = 1; k <= i; k ++ )
                    f[i][j] = min(f[i][j], max(f[k - 1][j - 1], f[i - k][j]) + 1);
            }
        cout << f[n][m] << endl;
    }
    
    return 0;
}