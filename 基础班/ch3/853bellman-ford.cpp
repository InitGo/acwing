#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

struct Edge
{
    int a, b, c;
}edges[M];

int n, m, k;
int dist[N];
int last[N];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < k; i ++ ) //做k次relax操作：对应题目中不超过k条边
    {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; j ++ )
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
        }
    }
    return dist[n];
}


int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    
    int t = bellman_ford();
    if (t > 0x3f3f3f3f / 2) cout << "impossible" << endl;
    else cout << t << endl;
        
    return 0;
}