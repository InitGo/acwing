//一开始用dist数组存直接相连的边
//然后在dist上做floyd，让dist数组表示两点之间的最短距离同时维护点与点之间的连通性
//利用连通性枚举可以连边的点，得到答案
//太妙了

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 160, INF = 1e20;
int n;
double dist[N][N];  //距离矩阵
string g[N];  //存邻接表
PII pos[N];  //牧场的坐标
double maxd[N];

double get_dis(int i, int j)
{
    int dx = pos[i].x - pos[j].x;
    int dy = pos[i].y - pos[j].y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }
    
    for (int i = 0; i < n; i ++ ) cin >> g[i];
    
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (i != j)
            {
                if (g[i][j] == '1') dist[i][j] = get_dis(i, j);
                else dist[i][j] = INF;
            }
    
    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (dist[i][j] < INF / 2) maxd[i] = max(maxd[i], dist[i][j]);
        
    
    double res1 = 0;
    for (int i = 0; i < n; i ++ ) res1 = max(res1, maxd[i]);
    
    double res2 = INF;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (dist[i][j] > INF / 2)
                res2 = min(res2, maxd[i] + maxd[j] + get_dis(i, j));
    
    printf("%.6lf\n", max(res1, res2));
    
    return 0;
}