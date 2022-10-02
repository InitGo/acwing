#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

int n, m, vol;
int p[N], v[N], w[N];
int f[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m >> vol;
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        cin >> v[i] >> w[i];
    }
    
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            p[pa] = pb;
            v[pb] += v[pa];  //注意这里是把两个集合合并 而不是把a合并到pa
            w[pb] += w[pa];
        }
    }
    
    for (int i = 1; i <= n; i ++ )
        if (find(i) == i)
        {
            for (int j = vol; j >= v[i]; j -- )
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    
    cout << f[vol] << endl;
    
    return 0;
}
