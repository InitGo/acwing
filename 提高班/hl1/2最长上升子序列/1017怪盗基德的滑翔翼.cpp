#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
int h[N], f[N], g[N];

int main()
{
    int K;
    cin >> K;
    while (K -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> h[i];
        
        int res = 0;
        for (int i = 1; i <= n; i ++ )
        {
            f[i] = 1;
            for (int k = 1; k < i; k ++ ) 
                if (h[k] < h[i]) f[i] = max(f[i], f[k] + 1);
            res = max(res, f[i]);
        }
        for (int i = n; i; i -- )
        {
            g[i] = 1;
            for (int k = n; k > i; k -- )
                if (h[k] < h[i]) g[i] = max(g[i], g[k] + 1);
            res = max(res, g[i]);
        }
        
        cout << res << endl;
    }
    return 0;
}