#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n;
int w[N];
int f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i];
        w[i + n] = w[i];
    }

    //长度为2时,表示只有一个矩阵,len从3开始
    //枚举长度要到n+1
    for (int len = 3; len <= n + 1; len ++ ) 
        for (int i = 1; i + len - 1 <= 2 * n; i ++ )
        {
            int l = i, r = i + len - 1;
            for (int k = l + 1; k < r; k ++ ) //k的范围是[l + 1, r - 1]
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[r] * w[k]);
        }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = max(res, f[i][i + n]);
    
    cout << res << endl;
    return 0;
}