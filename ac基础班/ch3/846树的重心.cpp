//https://www.acwing.com/activity/content/problem/content/909/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 100010, M = N * 2;//无向边
int n;
int h[N], e[M], ne[M], idx;
int ans = N; //遍历每个点，删除当前点以后找到所有子树中点数最大值sum ，遍历完成之后找到min(sum)
bool st[N]; //深度遍历，存每个点的状态，true表示被搜索过了

//插入一条a-->b的边 无向图则插入 a-->b，b-->a
//在a链表的头节点插入b 表示a可以到达b a链表中的元素表示a可以到达的所有点
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//返回以u为根节点的子树的点的个数,包括根节点，用sum变量
//dfs遍历树图
int dfs(int u)
{
    st[u] = true;//u点打标记，已经遍历过了
    //为什么要打标记？？？所有的dfs都打了标记？？
    //因为只搜索每个点为根节点时它的子树的情况，不能向上搜索，所以搜索过的点要打标记

    int size = 0, sum = 0; 
    //size标记删除当前点以后，剩余各连通块的点数最大值
    //sum标记当前点的所有子树的点的和

    //处理u的所有可以到达的子节点
    for (int i = h[u]; i != -1; i = ne[i])//遍历u可以到达的点
    {
        int j = e[i];
        if (st[j]) continue; //如果已经标记过了，则continue

        //如果没有标记，则搜索这个点，并返回 删除这个点后，剩余连通块中点数最大值 存进s
        int s = dfs(j);
        size = max(size, s);//size=以u为根节点的所有子树中最大点数
        sum += s;//sum=以u为根节点的所有子树的size之和 ，为了求它上面那棵树做准备 n-sum-1
    }

    size = max(size, n - sum - 1); //不是以u为根节点的那一个连通块的点数是n-sum-1
    ans = min(ans, size);

    return sum + 1;//根节点加上
}

int main()
{
    scanf("%d", &n);

    memset(h, -1, sizeof h);

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs(1);

    printf("%d\n", ans);

    return 0;
}

