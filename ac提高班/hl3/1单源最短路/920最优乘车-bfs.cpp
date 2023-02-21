#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 510;

int m, n;
bool g[N][N];
int dist[N];
int stop[N];
int q[N];

void bfs()
{
    int hh = 0, tt = 0;
    memset(dist, 0x3f, sizeof dist);
    q[0] = 1;
    dist[1] = 0;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = 1; i <= n; i ++ )
            if (g[t][i] && dist[i] > dist[t] + 1)
            {
                dist[i] = dist[t] + 1;
                q[ ++ tt] = i;
            }
    }
}

int main()
{
    cin >> m >> n;

    string line;
    getline(cin, line);
    while (m -- )
    {
        getline(cin, line);
        stringstream ssin(line);
        
        int cnt = 0, p;
        while (ssin >> p) stop[cnt ++ ] = p;
        
        for (int j = 0; j < cnt; j ++ )
            for (int k = j + 1; k < cnt; k ++ )
                g[stop[j]][stop[k]] = true;
    }

    bfs();

    if (dist[n] == 0x3f3f3f3f) puts("NO");
    else cout << max(dist[n] - 1, 0) << endl;

    return 0;
}