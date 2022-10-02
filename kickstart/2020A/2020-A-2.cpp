#include <iostream>
#include <cstring>

using namespace std;

const int N = 55, K = 35;

int plate[N][K], f[N][K*N], s[N][K]; //set the second vdiversion of f 

int main()
{
    int T;
    cin >> T;

    for (int q = 1; q <= T; q ++ )
    {
        memset(f, 0, sizeof f);
        int n, k, p;
        cin >> n >> k >> p; //n row, k col , p can be selected

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= k; j ++ )
            {
                cin >> plate[i][j];
                s[i][j] = s[i][j-1] + plate[i][j];
            }

        for (int i = 1; i <= n; i ++ )
            for (int j = 0; j <= p; j ++ )       
                for (int l = 0; l <= k ; l ++ )         
                    if (j >= l) f[i][j] = max(f[i][j], f[i-1][j-l] + s[i][l]);

        printf("Case #%d: %d\n", q, f[n][p]);
    }
    return 0;
}