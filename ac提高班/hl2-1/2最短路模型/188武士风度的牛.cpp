#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 160, M = N * N;

int m, n;
char g[N][N];
int dist[N][N];
PII q[M];
PII st;
    
int bfs(int sx, int sy)
{
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    memset(dist, -1, sizeof dist);
    dist[sx][sy] = 0;
    
    while (hh <= tt)
    {
        auto t = q[hh ++ ];
        for (int i = 0; i < 8; i ++ )
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (g[a][b] == '*') continue;
            if (dist[a][b] != -1) continue;
            
            dist[a][b] = dist[t.x][t.y] + 1;
            q[ ++ tt] = {a, b};
            if (g[a][b] == 'H') return dist[a][b]; 
            //因为K和H是两个标识符，所以初始化时必不可能在一个位置
            //所以只判断跳到后的位置是否为解
        }
    }
    return -1;
}

int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            cin >> g[i][j];
            if (g[i][j] == 'K') st = {i, j};
        }
    
    cout << bfs(st.x, st.y) << endl;
    
    return 0;
}