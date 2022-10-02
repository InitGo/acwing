#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m;
int dist[N][N];

void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    cin >> n >> m;

    memset(dist, 0x3f, sizeof dist); 
    //可以不把对角线初始化成0，即认为自己到不了自己
    //for (int i = 1; i <= n; i ++ ) dist[i][i] = 0;

    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }
    
    floyd();
    
    int ans = 0;
    for (int i = 2; i <= n; i ++ ) //如果不初始化对角线，这里i需要从2开始枚举，不能枚举1，dist[1][1] = INF
        ans = max(ans, dist[1][i]);
    
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}
