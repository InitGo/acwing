#include <iostream>

using namespace std;

const int N = 16, M = 3010;

long long f[N];
int n, m;
int q[N];

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> q[i];
    
    f[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = q[i]; j <= m; j ++ )
        {
            f[j] += f[j - q[i]];
        }
    }
    cout << f[m] << endl;
    
    return 0;
}