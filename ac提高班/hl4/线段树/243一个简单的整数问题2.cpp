#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m;
int w[N];

struct Node
{
    int l, r;
    ll sum, add;
}tr[N * 4];

//pushup操作：用子节点的信息更新父节点 只处理常规属性 
void pushup(int u)  //pushup只更新非懒标记的属性 理解：懒标记表示当前区间更新过了，还没传到子区间，pushup操作不涉及从上到下，所以不需要管懒标记
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

//pushdown操作：用父节点的信息更新子节点 同时处理懒标记和常规属性
void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) //仅当 当前节点区间有懒标记的时候才需要下传
    {
        left.sum += (left.r - left.l + 1) * root.add;
        left.add += root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        right.add += root.add;
        root.add = 0;  //一旦完成下传懒标记，就要把当前节点区间的懒标记清除
        //懒标记的定义：当前区间修改过了，但是还没有下传
    }
}

//只修改子节点，只pushup
void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, w[l], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

//又是往下递归：要pushdown下传懒标记 ， 又是修改子节点：要pushup更新父节点
void modify(int u, int l, int r, int v)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (ll)(tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
    }
    else
    {
        pushdown(u);  //操作孩子区间之前，先下传懒标记
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);  //操作完孩子区间，需要pushup上传
    }
}


//只涉及向下递归：只要pushdown
ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll ans = 0;
    if (l <= mid) ans = query(u << 1, l, r);  //这里区间常出错
    if (r > mid) ans += query(u << 1 | 1, l, r);
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    build(1, 1, n);
    
    string op;
    int l, r, v;
    while (m -- )
    {
        cin >> op >> l >> r;
        if (op == "C")
        {
            cin >> v;
            modify(1, l, r, v);
        }
        else
        {
            cout << query(1, l, r) << endl;
        }
    }
    
    return 0;
}