#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n;
int w[N];
int f[N][3];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    
    memset(f, -0x3f, sizeof f);
    f[0][2] = 0;
    
    for (int i = 1; i <= n; i ++ )
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = max(f[i - 1][1], f[i - 1][2]);
    }
    
    cout << max(f[n][2], f[n][1]) << endl;
    return 0;
}