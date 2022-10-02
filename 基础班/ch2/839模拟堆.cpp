//https://www.acwing.com/activity/content/problem/content/889/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 100010;

//因为要存 堆中的点和和h[k]是第几个插入的点 第几个插入的点在堆中的下标 h[k] 
//ph[k] 第k个插入的点在堆中的下标
//hp[k] 堆中下标为k的点是第几个插入的点
int h[N], ph[N], hp[N], cnt;

//堆交换 ，交换映射关系和值
//传入两个 堆中的下标a,b 交换他们的值和映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    while (n -- )
    {
        char op[5];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I"))
        {
            scanf("%d", &x);
            cnt ++ ; //插入一个数，cnt++
            m ++ ; //m表示第m个插入的点
            ph[m] = cnt, hp[cnt] = m;
            //第m个插入的点在堆中下标是cnt ； 堆中下标是cnt的点是第m个插入的点
            //这两对映射与x在h中的位置cnt有关，与x的值h[x]无关
            h[cnt] = x;
            up(cnt);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM"))
        {
            heap_swap(1, cnt);
            cnt -- ;
            down(1);
        }
        else if (!strcmp(op, "D"))
        {
            scanf("%d", &k);
            k = ph[k];
            heap_swap(k, cnt);
            cnt -- ;
            up(k);
            down(k);
        }
        else
        {
            scanf("%d%d", &k, &x);
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }

    return 0;
}
