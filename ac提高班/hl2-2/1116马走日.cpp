#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

int n, m;
bool st[N][N];
int ans;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int cnt)
{
    if (cnt == n * m) //一共n*m个格子，起点占了一个格子，所以还需要搜索n*m - 1个格子，所以当cnt == n * m 搜索完成
    {
        ans ++ ; //搜索完成，搜索方案++
        return;
    }
    
    //如果搜索未完成
    st[x][y] = true; //处理这个位置

    for (int i = 0; i < 8; i ++ ) //8个方向可以走
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) continue;
        if (st[a][b]) continue;
        dfs(a, b, cnt + 1);
    }

    st[x][y] = false; //恢复现场
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        int x, y;
        scanf("%d%d%d%d", &n, &m, &x, &y);

        memset(st, 0, sizeof st); //可以初始化，也可以不初始化，回溯会恢复初始状态
        ans = 0;
        dfs(x, y, 1); //正在搜索第一个格子

        printf("%d\n", ans);
    }

    return 0;
}