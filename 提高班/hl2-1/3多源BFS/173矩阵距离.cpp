#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
char g[N][N];
PII q[M];
int dist[N][N];

void bfs()
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    memset(dist, -1, sizeof dist);
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (g[i][j] == '1')
            {
                dist[i][j] = 0;
                q[ ++ tt] = {i, j};
            }
            
    while (hh <= tt)
    {
        auto t = q[hh ++ ];
        for (int i = 0; i < 4; i ++ )
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 1 || a > n || b < 1 || b > m) continue;
            if (dist[a][b] != -1) continue;
            
            dist[a][b] = dist[t.x][t.y] + 1;
            q[ ++ tt] = {a, b};
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
    
    bfs();
    
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
            cout << dist[i][j] << ' ';
        cout << endl;
    }
    return 0;
}