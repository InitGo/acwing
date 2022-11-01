#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

int n, m, mod;
int a[N];

struct Node
{
    int l, r;
    queue<PII> op;
    LL sum;
}tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    auto& q = root.op;
    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int op = t.first, x = t.second;
        if (op == 1)  //mul
        {
            left.sum *= x;
            left.op.push({1, x});
            right.sum *= x;
            right.op.push({1, x});
        }
        else  //op == 2 add
        {
            left.sum += (left.r - left.l + 1) * x;
            left.op.push({2, x});
            right.sum += (right.r - right.l + 1) * x;
            right.op.push({2, x});
        }
    }
}


void build(int u, int l, int r)
{
    if (l == r) tr[u] = {l, r, {}, a[r]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int op, int v)
{
    if (tr[u].l >= l && tr[u].r <= r) 
    {
        if (op == 1) tr[u].sum *= v;
        else if (op == 2) tr[u].sum += (tr[u].r - tr[u].l + 1) * v;
        tr[u].op.push({op, v});
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, op, v);
        if (r > mid) modify(u << 1 | 1, l, r, op, v);
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
    cin >> n >> mod;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    cin >> m;

    build(1, 1, n);

    while (m -- )
    {
        int op, l, r;
        LL d;
        cin >> op >> l >> r;
        if (op == 1 || op == 2)
        {
            cin >> d;
            modify(1, l, r, op, d);
        }
        else cout << query(1, l, r) % mod << endl;
    }
    return 0;
}
