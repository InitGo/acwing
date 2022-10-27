#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int a[N];

struct Node
{
    int l, r, add;
    LL sum;
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.sum += (left.r - left.l + 1) * root.add;
        left.add += root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        right.add += root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, 0, a[r]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int v)
{
    if (tr[u].l >= l && tr[u].r <= r) 
    {
        tr[u].sum += (tr[u].r - tr[u].l + 1) * v;
        tr[u].add += v;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}

LL query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    LL ans = 0;
    if (l <= mid) ans = query(u << 1, l, r);
    if (r > mid) ans += query(u << 1 | 1, l, r);
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    build(1, 1, n);

    while (m -- )
    {
        int op, l, r;
        LL d;
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> d;
            modify(1, l, r, d);
        }
        else cout << query(1, l, r) << endl;
    }
    return 0;
}
