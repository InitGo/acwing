//https://www.acwing.com/activity/content/problem/content/911/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];//存每个点的入度
int q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//求topsort
bool topsort()
{
    int hh = 0, tt = -1;

    //先把入度为0的点全部入队列
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;


    while (hh <= tt)
    {
        int t = q[hh ++ ];//取队头

        //枚举t的所有出边
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i]; 
            if (-- d[j] == 0) //t的出边 t-->j 删掉，如果删掉以后j的入度为0，那么j处理干净了，可以入队
                q[ ++ tt] = j;

            // int j = e[i];
            // d[j]--;
            // if(d[j]==0) q[++tt] = j;
        }
    }

    return tt == n - 1; //最后所有点都入队列，成功
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);

        d[b] ++ ;
    }

    if (!topsort()) puts("-1");
    else
    {
        for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);
        puts("");
    }

    return 0;
}