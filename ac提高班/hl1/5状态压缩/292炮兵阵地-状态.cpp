#include <bits/stdc++.h>

using namespace std;

const int N = 10, M = 1 << 10;

int n, m;
int g[110];
vector<int> state;
int f[2][M][M];
int cnt[M];

bool check(int state)
{
    for (int i = 0; i < m; i ++ )
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
            return false;
    return true;
    //return !(s & s >> 1 || s & s >> 2);
}

int count(int state)
{
    int res = 0;
    for (int i = 0; i < m; i ++ ) res += state >> i & 1;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            char c;
            cin >> c;
            g[i] += (c == 'H') << j;
        }
    
    for (int i = 0; i < 1 << m; i ++ )
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    
    for (int i = 1; i <= n + 2; i ++ )
        for (int j : state)
            for (int k : state)
                for (int u : state)
                {
                    if ((j & k) | (j & u) | (k & u)) continue;
                    if (g[i - 1] & j | g[i] & k | g[i - 2] & u) continue;
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[k]);
                }
                
    cout << f[n + 2 & 1][0][0] << endl;
    return 0;
}