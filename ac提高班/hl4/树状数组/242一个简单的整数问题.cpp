#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;

int n, m;
LL tr[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(int x)
{
    LL res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        add(i, x), add(i + 1, -x); //在原数组a[]的[i,i]区间内+x ==> 在差分数组b[]的 b[i] += x, b[i+1] -=x;
        //add(i, a[i] - a[i - 1]);
    }
    //注：对差分数组b[]建树状数组tr[]
    
    while (m -- )
    {
        string op;
        int l;
        cin >> op >> l;
        if (op == "C") //在原数组a[]的[l,r]区间内+x ==> 在差分数组b[]的 b[l] += x, b[r+1] -=x;
        {
            int r, d;
            cin >> r >> d;
            add(l, d), add(r + 1, -d); 
        }
        else
        {
            cout << sum(l) << endl; //求原数组a[]的单点值a[l] ==> 求差分数组的前缀和 b[1] + b[2] + ... + b[l]
        }
    }
    
    return 0;
}