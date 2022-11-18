#include <iostream>
#include <cstring>

using namespace std;

const int M1 = 32, M2 = 82, N = 1010;

int m1, m2, n;
int f[M1][M2];

int main()
{
    cin >> m1 >> m2 >> n;
    
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for (int j = m1; j >= 0; j -- )
            for (int k = m2; k >= 0; k -- )
                f[j][k] = min(f[j][k], f[max(0, j - v1)][max(0, k - v2)] + w);
    }
    cout << f[m1][m2] << endl;
    return 0;
}