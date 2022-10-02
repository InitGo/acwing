#include <iostream>

using namespace std;

const int N = 100010, mod = 1e9 + 7;

int n1, n2, m;
int f[N];

int main()
{
    cin >> n1 >> n2 >> m;
    
    f[0] = 1;
    for (int i = 1; i <= n1; i ++ )
    {
        int p;
        cin >> p;
        for (int j = p; j <= m; j ++ ) 
            f[j] = (f[j] + f[j - p]) % mod;
    }
    
    for (int i = 1; i <= n2; i ++ )
    {
        int p;
        cin >> p;
        for (int j = m; j >= p; j -- )
            f[j] = (f[j] + f[j - p]) % mod;
    }
    
    cout << f[m] << endl;
    return 0;
}