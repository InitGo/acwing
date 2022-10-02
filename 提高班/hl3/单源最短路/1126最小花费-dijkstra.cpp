#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n, m, S, T;
double g[N][N];
double dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0, sizeof dist);  //可不写，dist初始化即为0
    dist[S] = 1; 
    //乘法的起始值为1，非法值为0
    //加法的起始值为0，非法值为正无穷
    
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] < dist[j]))
                t = j;
        
        st[t] = true;
        
        for (int j = 1; j <= n; j ++ )
            dist[j] = max(dist[j], dist[t] * g[t][j]);
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }
    
    cin >> S >> T;
    
    dijkstra();
    
    printf("%.8lf\n", 100 / dist[T]); //dist[T]表示S的1元到T还剩多少
    
    return 0;
}