#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;

struct Node
{
    int l, r, sum, lmax, rmax, tmax;
}tr[N * 4];

int n, m;
int w[N];

void pushup(Node& u, Node& l, Node& r)
{
    u.sum = l.sum + r.sum;  //sum属性,符合区间加法
    u.lmax = max(l.lmax, l.sum + r.lmax);  //最大前缀和属性:max(左孩子的最大前缀和,左孩子的sum+右孩子的最大前缀和(跨左右孩子间))
    u.rmax = max(r.rmax, r.sum + l.rmax);  //最大后缀和属性:max(右孩子的最大后缀和,右孩子的sum+左孩子的最大后缀和(跨左右孩子间))
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);  //最大子段和属性:max(左孩子的最大子段和,右孩子的最大子段和,(左孩子的最大后缀和+右孩子的最大前缀和)(跨左右孩子间))
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[l], w[l], w[l], w[l]};  //如果是叶子节点,直接创建
    else  //不是叶子节点
    {
        tr[u] = {l, r}; //先创建好该节点的区间
        int mid = l + r >> 1;  //找到区间中点
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);  //左右递归创建左右孩子节点
        pushup(u);  //把孩子节点的修改信息同步到parent节点
    }
}

void modify(int u, int x, int v)  //修改x位置的值为v
{
    if (tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v};  //如果一定为到叶子节点,直接修改
    else  //不是叶子节点
    {
        int mid = tr[u].l + tr[u].r >> 1;  //找到区间中点
        if (x <= mid) modify(u << 1, x, v);  //如果目标点在该节点的左孩子区间,递归修改
        else modify(u << 1 | 1, x, v);  //同理
        pushup(u);  //将孩子节点的修改同步到parent节点
    }
}

//为什么不能用这种方式？因为tmax是不符合区间加法的，不能直接这样分解区间比较大小，需要重新做出res节点
// int query(int u, int l, int r)
// {
//     if (tr[u].l >= l && tr[u].r <= r) return tr[u].tmax;
    
//     int mid = tr[u].l + tr[u].r >> 1;
//     long long ans = -1e18;
//     if (l <= mid) ans = query(u << 1, l, r);
//     if (r > mid) ans = max(ans, query(u << 1 | 1, l, r));
//     return ans;
// }

Node query(int u, int l, int r) //区间查询
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    
    int mid = tr[u].l + tr[u].r >> 1;
    //Node res, left_node, right_node;
    //left_node = query(u << 1, left, right);  // 一定不能提前写，可能访问到未开辟的内存
    //right_node = query(u << 1 | 1, left, right);  // 一定不能提前写，可能访问到未开辟的内存
    
    if (r <= mid) return query(u << 1, l, r); //当前查询的区间只在左孩子区间
    else if (l > mid) return query(u << 1 | 1, l, r);  //当前查询的区间只在右孩子区间
    else  //当前查询的区间同时在左右孩子区间
    {
        Node res;
        auto left = query(u << 1, l, r); //分别计算左右孩子的部分
        auto right = query(u << 1 | 1, l, r);
        pushup(res, left, right); //再用pushup函数将左右孩子信息合并到parent节点res中
        return res;  //返回res
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n ; i ++ ) cin >> w[i];
    build(1, 1, n); //读入完数组以后一定要记得build初始化
    
    int op, x, y;
    while (m -- )
    {
        cin >> op >> x >> y;
        if (op == 1) //query
        {
            if (x > y) swap(x, y);
            cout << query(1, x, y).tmax << endl;
        }
        else modify(1, x, y);
    }
    
    return 0;
}