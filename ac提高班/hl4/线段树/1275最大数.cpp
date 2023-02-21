#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

struct Node
{
    int l, r;
    int v;
}tr[4 * N];

void pushup(int u) //pushup操作,当child发生变化,用child节点的信息更新parent节点的信息
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r) //build操作:将一个区间初始化构造成线段树
{
    tr[u].l = l, tr[u].r = r; //首先构造当前u节点 tr[u] = {l, r};写法相同
    if (l == r) return;  //如果u节点已经是叶子节点,则返回
    int mid = l + r >> 1; //计算当前节点区间的中点
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r); //左右递归构建左右孩子节点
}

int query(int u, int l, int r) //query操作:区间查询:通过对线段树节点,拼凑区间,得到完整的查询区间
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].v; //如果当前节点的区间已经被包含在查询区间内,直接返回结果
    int mid = tr[u].l + tr[u].r >> 1; //否则,计算当前节点的区间中点
    int v = 0; //用v存答案
    if (l <= mid) v = query(u << 1, l, r); //如果查询区间的l在mid左侧,说明查询区间与当前节点的左孩子有交集,递归
    if (r > mid) v = max(v, query(u << 1 | 1, l, r)); //同理,如果查询区间的r在mid右侧,说明查询区间与当前区间的右孩子有交集,递归
    return v; //返回答案
}

void modify(int u, int x, int v) //modify:单点修改,将x位置的点的值修改成v
{
    if (tr[u].l == x && tr[u].r == x) tr[u].v = v; //如果已经是叶子节点,直接修改并返回
    else //不是叶子节点
    {
        int mid = tr[u].l + tr[u].r >> 1; //找当前节点所对应区间的中点
        if (x <= mid) modify(u << 1, x, v); //判断目标位置x是在当前节点的左孩子点/右孩子点
        else modify(u << 1 | 1, x, v);
        pushup(u); //将孩子的更新状态同步到parent节点
    }
}

int main()
{
    int cnt = 0, last = 0; //cnt维护当前区间的长度,last存上一次查询的结果
    int m, p;
    cin >> m >> p;
    build(1, 1, m);
    
    while (m -- )
    {
        string op;
        int x;
        cin >> op >> x;
        if (op == "Q")
        {
            last = query(1, cnt - x + 1, cnt);
            cout << last << endl;
        }
        else
        {
            modify(1, cnt + 1, ((long long)x + last) % p);
            cnt ++ ;
        }
    }
    return 0;
}