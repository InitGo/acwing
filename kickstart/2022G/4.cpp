#include <bits/stdc++.h>

using namespace std;

const int N = 510;

typedef long long LL;

int n, E;
int g[N][N];
int direction;
bool st[N][N];

int dx[] = {0, -1, 1}, dy[] = {1, 0, 0};

LL dfs(int x, int y)
{
    LL sum = 0;
    sum += g[x][y];
    st[x][y] = true;
    LL s = -1e18;
    for (int i = 0; i < 3; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > 501 || b < 1 || b > 501) continue;
        if (st[a][b]) continue;

        if (i == 0) s = max(s, dfs(a, b));
        if (i == 1)
        {
            if (direction == 1) s = max(s, dfs(a, b));
            else 
            {
                s = max(s, dfs(a, b) - E);
                direction = !direction;
            }
        }
        if (i == 2)
        {
            if (direction == 0) s = max(s, dfs(a, b));
            else 
            {
                s = max(s, dfs(a, b) - E);
                direction = !direction;
            }
        }
    }
    return sum + s;
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        memset(g, 0, sizeof g);
        cin >> n >> E;
        for (int i = 0; i < n; i ++ )
        {
            int a, b, c;
            cin >> a >> b >> c;
            a ++ , b ++ ;
            g[a][b] = c;
        }

        direction = 1;
        memset(st, 0, sizeof st);
        printf("Case #%d: %lld\n", C, dfs(1, 1));
    }
    return 0;
}