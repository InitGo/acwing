#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
struct Node
{
    int s[2], p, v;
    int size, flag;

    void init(int _v, int _p)
    {
        v = _v, p = _p;
        size = 1;
    }
}tr[N];
int root, idx;

void pushup(int x)
{
    tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
}

void pushdown(int x)
{
    if (tr[x].flag)  //如果当前点有标记
    {
        swap(tr[x].s[0], tr[x].s[1]);  //处理当前点的标记：交换左右子树
        tr[tr[x].s[0]].flag ^= 1;  //然后下传标记
        tr[tr[x].s[1]].flag ^= 1;
        tr[x].flag = 0;  //然后清空当前点的标记
    }
}

void rotate(int x)  //旋转，二合一写法
{
    int y = tr[x].p, z = tr[y].p;  //找到x的parent y， 找到y的parent z
    int k = tr[y].s[1] == x;  // k=0表示x是y的left child；k=1表示x是y的 right child
    //修改3条边的关系
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;  //z的child变成x，x的parent变成z
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;  //y的child变成x的child， x的child的parent变成y
    tr[x].s[k ^ 1] = y, tr[y].p = x;  //x的child变成y， y的parent变成x
    pushup(y), pushup(x);  //更新x和y的信息
}

void splay(int x, int k)  //核心函数splay，将x转到k下面
{
    while (tr[x].p != k)  //如果x的parent不是k，才需要操作，否则本来就符合
    {
        int y = tr[x].p, z = tr[y].p;  //找到y和z
        if (z != k)  //z!=k，需要转两次
            if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y)) rotate(x);  //如果是有转折的情况，转x
            else rotate(y);  //一条直线的情况，转y
        rotate(x);  //第二次都是转x
    }
    if (!k) root = x;  //如果k是0，x旋转后变成了root
}

void insert(int v)  //插入节点
{
    int u = root, p = 0;
    while (u) p = u, u = tr[u].s[v > tr[u].v];
    u = ++ idx;
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p);
    splay(u, 0);
}

int get_k(int k)  //找第k个节点:中序遍历下的第k个节点：slay只维护中序遍历，不一定是和value有关
{
    int u = root;
    while (true)
    {
        pushdown(u);
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];  //左子树的节点个数 >= k，目标点就在左子树
        else if (tr[tr[u].s[0]].size + 1 == k) return u;  //左子树的节点个数 + 1 = k，目标点就是当前点
        else k -= tr[tr[u].s[0]].size + 1, u = tr[u].s[1];  //k -= 左子树的节点个数+当前点，在右子树找 k
    }
    return -1;
}

void output(int u)  //中序遍历
{
    pushdown(u);
    if (tr[u].s[0]) output(tr[u].s[0]);
    if (tr[u].v >= 1 && tr[u].v <= n) printf("%d ", tr[u].v);
    if (tr[u].s[1]) output(tr[u].s[1]);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i ++ ) insert(i);  //将0~n+1插入，通常需要有哨兵 0, 1~n, n + 1
    while (m -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);  //因为添加了哨兵，所以区间范围是 [l+1, r+1]
        l = get_k(l), r = get_k(r + 2);  //找到前驱l 和后继r
        splay(l, 0), splay(r, l);  //l旋转到根，r旋转到l下面，则r的左子树就是需要操作的区间
        tr[tr[r].s[0]].flag ^= 1;  //r的左子树打上标记 1
    }
    output(root);  //中序遍历输出序列
    return 0;
}