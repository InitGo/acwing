#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n, m;
int a[N];
LL tr1[N], tr2[N];
//tr1[]数组是原始数组的差分数组d[i]的树状数组
//tr2[]数组是原始数组的差分数组乘以i即i*d[i]的树状数组

int lowbit(int x)
{
    return x & -x;
}

void add(LL tr[], int x, LL c)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(LL tr[], int x)
{
    LL res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

LL prefix_sum(int x)
{
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    
    for (int i = 1; i <= n; i ++ )
    {
        int b = a[i] - a[i - 1];
        add(tr1, i, b);
        add(tr2, i, i * (LL)b);
    }
    
    while (m -- )
    {
        string op;
        int l, r;
        cin >> op >> l >> r;
        if (op == "C")
        {
            int d;
            cin >> d;
            add(tr1, l, d), add(tr1, r + 1, -d);
            add(tr2, l, l * d), add(tr2, r + 1, (r + 1) * -d);
        }
        else
        {
            cout << prefix_sum(r) - prefix_sum(l - 1) << endl;
        }
    }
    
    return 0;
}