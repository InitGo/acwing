#include<iostream>
#include <cstring>

using namespace std;

const int N = 110;
int f[N][N], a[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    
    while (t -- )
    {
        int n, m;
        cin >> n >> m;
        
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ )
                cin >> a[i][j];
        
        for (int i = 1; i <= n; i ++ )
        {
            for (int j = 1; j <= m; j ++ )
            {
                f[i][j] = max(f[i-1][j] + a[i][j], f[i][j-1] + a[i][j]);
            }
        }
        cout << f[n][m] << endl;
    }
    
    return 0;
}