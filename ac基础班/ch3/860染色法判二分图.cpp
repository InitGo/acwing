//https://www.acwing.com/activity/content/problem/content/926/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N]; //0表示未染色， 1和2为不同的颜色

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//把u所在的连通块全部染色，u的颜色染成c
//返回是否染色成功
bool dfs(int u, int c)
{
    color[u] = c; //记录u的颜色为c 【c取1/2】

    for (int i = h[u]; i != -1; i = ne[i]) //遍历u的所有出边
    {
        int j = e[i]; //j为序号
        if (!color[j]) //如果j未染色
        {
            if (!dfs(j, 3 - c)) return false; //把j染成与u相对的颜色，并返回是否染色成功
        }
        else if (color[j] == c) return false; //出现冲突，也返回染色不成功
    }

    return true;
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = true;//记录是否出现冲突
    for (int i = 1; i <= n; i ++ ) //枚举每个点
        if (!color[i]) //如果i点还未染色
        {
            if (!dfs(i, 1)) // 把i所在的连通块全部染色，默认染1； 如果染色失败返回false
            {
                flag = false; //出现冲突
                break; 
            }
        }

    if (flag) puts("Yes"); //没有冲突，表明染色成功
    else puts("No");

    return 0;
}