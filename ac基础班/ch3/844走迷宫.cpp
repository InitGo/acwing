//https://www.acwing.com/activity/content/problem/content/907/

#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];//d记录每个点到起点的距离 
//二维数组：一个二维坐标(x,y)-->value 其中value的类型就是数组的类型

PII Prev[N][N];//记录路径
//Prev[x][y] = {t.x, .ty}


int bfs()
{
    queue<PII> q;

    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0, 0});

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        for (int i = 0; i < 4; i ++ )
        {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});

                Prev[x][y] = t;
                //t可以扩展出最多4个点，这4个点的prev都是t
                //存4个点的prev值是t，每个点的prev值是唯一的
                //得到一个终点，找他的上一个点prev，一层一层，最终得到路径
                
                
            }
        }
    }

    //输出路径
    //知道最后一个点是 x=n-1, y=m-1
    int x = n-1,y = m-1;
    while(x||y)
    {
        cout << x << ' ' << y << endl;
        auto t = Prev[x][y];
        x = t.first,y = t.second;
        
    }

    //目标点是(n,m) 在d数组中的下标是(n-1,m-1) ，返回这个值
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    cout << bfs() << endl;

    return 0;
}
