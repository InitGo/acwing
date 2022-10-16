#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int n;
int g[N][N], f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> g[i][j];
    
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            if (i == 1 && j == 1) f[i][j] = g[i][j];
            else f[i][j] = min(f[i][j - 1], f[i - 1][j]) + g[i][j];
        }
            
    cout << f[n][n] << endl;
    return 0;
}