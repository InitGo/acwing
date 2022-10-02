#include <bits/stdc++.h>

using namespace std;

const int N = 260, INF = 0x3f3f3f3f;

int n, m;
char str[N][N];
int dist[N][N];
int last[N][N];

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (last[i][j] == 0)
                q.push({i, j});
    
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int a = t.first + dx[i], b = t.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (last[a][b] != INF) continue;

            last[a][b] = last[t.first][t.second] + 1;
            q.push({a, b});
        }
    }

    int maxv = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            maxv = max(maxv, last[i][j]);
    return maxv;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n >> m;
        for (int i = 0; i < n; i ++ ) cin >> str[i];

        vector<pair<int, int>> pos;
        memset(dist, 0x3f, sizeof dist);
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < m; j ++ )
            {
                int x = str[i][j] - '0';
                if (x == 0)
                    pos.push_back({i, j});
                else dist[i][j] = 0;
            }
        
        if (pos.size() <= 1)
        {
            printf("Case #%d: %d\n", C, 0);
            continue;
        }
        else
        {
            int d = INF;
            for (auto t : pos)
            {
                int i = t.first, j = t.second;
                memcpy(last, dist, sizeof dist);
                last[i][j] = 0;
                d = min(d, bfs());
            }
            printf("Case #%d: %d\n", C, d);
        }
    }
    return 0;
}