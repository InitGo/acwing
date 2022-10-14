#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;

int n, m;
int d[N][N], g[N][N];
int pos[N][N];
int path[N], cnt;


//把从i走到j的中间点存到方案path里
void get_path(int i, int j)
{
    if (pos[i][j] == 0) return;  //i与j之间没有中间点，表明i与j直接相连，不用加点，直接return

    int k = pos[i][j];  //从i走到j经过中间点k
    get_path(i, k);
    path[cnt ++ ] = k;
    get_path(k, j);
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i ++ ) g[i][i] = 0;

    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int res = INF;
    memcpy(d, g, sizeof d);
    for (int k = 1; k <= n; k ++ )
    {
        //在第一层循环的位置更新答案
        //对于最大值是k的环的集合
        //这里的循环很细节，i和j的范围都是在1~k-1里的
        for (int i = 1; i < k; i ++ )  //枚举起点i
            for (int j = i + 1; j < k; j ++ )  //枚举终点j
                if ((long long)d[i][j] + g[j][k] + g[k][i] < res)  //如果这个环的边权之和小于res，则表明可以更新res 
                {
                    res = d[i][j] + g[j][k] + g[k][i];
                    //更新完res，还要更新线路方案
                    cnt = 0;
                    path[cnt ++ ] = k;  //先把k加仅进线路
                    path[cnt ++ ] = i;  //从k走到i，i加进线路
                    get_path(i, j);  //从i走到j
                    path[cnt ++ ] = j;  //把j加进线路
                }

        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                if (d[i][j] > d[i][k] + d[k][j])  //用图论的方式更新
                {
                    d[i][j] = d[i][k] + d[k][j];  //更新距离
                    pos[i][j] = k; //更新节点 【为了存方案：表明i到j的最短路径一定是经过k这个节点来的】
                }
    }

    if (res == INF) puts("No solution.");
    else
    {
        for (int i = 0; i < cnt; i ++ ) cout << path[i] << ' ';
        cout << endl;
    }

    return 0;
}