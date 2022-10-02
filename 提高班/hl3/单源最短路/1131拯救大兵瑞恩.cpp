#include <cstring>
#include <iostream>
#include <algorithm>
#include <deque>
#include <set>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 11, M = 360, P = 1 << 10;

int n, m, k, p;
int h[N * N], e[M], w[M], ne[M], idx;
int g[N][N], key[N * N];  //g存二维点到一维点的映射， key存二维点上的钥匙情况
int dist[N * N][P];  //dist存[一维点上，钥匙状态]的点的距离
bool st[N * N][P];  //st双端队列判重

set<PII> edges;  
//存下来已经做好的边：题目中只给了门和墙的边，没给可以走的边
//读取完输入后，要自己存下门和墙的边（已经做好了的边），再枚举所有边，把没做好的边做出来

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}


//比较长的代码用模块化函数分解：做边
void build()
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            for (int u = 0; u < 4; u ++ )  //枚举每个点的上下左右四个方向
            {
                int x = i + dx[u], y = j + dy[u];  //x, y 是四个方向的点
                if (!x || x > n || !y || y > m) continue;  //判断出界
                int a = g[i][j], b = g[x][y];  //得到(i,j) 和 (x,y) 的一维坐标
                if (!edges.count({a, b})) add(a, b, 0);  //如果这条边没做好，那么做出来，边权是0
            }
}

int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;  //起点，1号点上钥匙状态是0，距离是0

    deque<PII> q;
    q.push_back({1, 0});

    while (q.size())
    {
        PII t = q.front();
        q.pop_front();

        if (st[t.x][t.y]) continue;
        st[t.x][t.y] = true;

        //dijkstra是按照距离从小到大扩展的，所以终点第一次出队时，是答案，
        if (t.x == n * m) return dist[t.x][t.y];

        //如果这个点有钥匙，多一个扩展方向：拿起钥匙
        if (key[t.x])
        {
            int state = t.y | key[t.x];
            if (dist[t.x][state] > dist[t.x][t.y])
            {
                dist[t.x][state] = dist[t.x][t.y];
                q.push_front({t.x, state});
            }
        }


        //扩展上下左右四个方向
        for (int i = h[t.x]; ~i; i = ne[i])
        {
            int j = e[i];
            if (w[i] && !(t.y >> (w[i] - 1) & 1)) continue;   // 有门并且没有钥匙
            if (dist[j][t.y] > dist[t.x][t.y] + 1)
            {
                dist[j][t.y] = dist[t.x][t.y] + 1;
                q.push_back({j, t.y});
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m >> p >> k;

    //先预处理二维坐标映射到一维坐标，从1开始
    for (int i = 1, t = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            g[i][j] = t ++ ;

    memset(h, -1, sizeof h);
    while (k -- )
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = g[x1][y1], b = g[x2][y2];

        edges.insert({a, b}), edges.insert({b, a});
        //如果c==0，是墙，不连通，不能做边，否则，做边，边权是第c种门
        if (c) add(a, b, c), add(b, a, c);
    }

    build();  //做好其他边

    //读入钥匙情况
    int s;
    cin >> s;
    while (s -- )
    {
        int x, y, c;
        cin >> x >> y >> c;
        key[g[x][y]] |= 1 << c - 1;  //为了方便二进制表示，让钥匙种类从0开始，即0钥匙开1门，1钥匙开2门
    }

    cout << bfs() << endl;

    return 0;
}