#include <bits/stdc++.h>

using namespace std;

const int N = 14, M = 1 << 12, mod = 1e8;

int n, m;
int f[2][M];
vector<int> state;
vector<int> head[M];
int g[N];
int cnt[M];

bool check(int s)
{
    return !(s & s >> 1);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            int x;
            cin >> x;
            g[i] += !x << j;
        }
    
    for (int i = 0; i < 1 << m; i ++ )
        if (check(i))
            state.push_back(i);

    for (int a : state)
        for (int b : state)
            if ((a & b) == 0)
                head[a].push_back(b);
    
    f[0][0] = 1;
    for (int i = 1; i <= n + 1; i ++ )
        for (int a : state)
        {
            f[i & 1][a] = 0; //因为是滚动数组，每次使用都需要情况上次使用情况
            if ((a & g[i]) == 0 )
                for (int b : head[a])
                    f[i & 1][a] = (f[i & 1][a] + f[(i - 1) & 1][b]) % mod;
        }
                
    cout << f[n + 1 & 1][0] << endl;
    return 0;
}