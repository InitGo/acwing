#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3010;

int a[N], b[N];
int n, m;
int f[N][N];
int way[N][N];
int g[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j])
            {
                f[i][j] = max(f[i][j] ,f[i - 1][j - 1] + 1);
                if (f[i][j] == f[i - 1][j - 1] + 1)
                {
                    way[i][j] = 1;
                }
            }
        }
    }
    int cnt = f[n][n];
    cout << "最长公共子序列的长度：" << cnt << endl;
    
    vector<int> lcs;
    int x = cnt;
    int q[cnt + 10];
    for (int i = n; i; i -- )
        for (int j = n; j; j -- )
            if (x && way[i][j])
            {
                printf("%d %d %d %d\n", i, j, a[i], b[j]);
                //lcs.push_back(a[i]);
                q[x -- ] = a[i];
                break;
            }
                
    for (int i = 1; i <= cnt ; i ++ ) cout << q[i] << ' ';

    //reverse(lcs.begin(), lcs.end());
    //cout << res << endl;
    
    return 0;
}



// 10
// 1 5 3 6 3 2 7 3 6 2 
// 9 6 2 3 1 5 3 3 6 1