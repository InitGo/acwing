#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 20010;

int n, m;
int p[N], dist[N];

unordered_map<int, int> S;
int idx;

int get(int x)
{
    if (!S.count(x)) S[x] = ++ idx;
    return S[x];
}

int find(int x)
{
    if (p[x] != x)
    {
        int u = find(p[x]);
        dist[x] += dist[p[x]];
        p[x] = u;
    }
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i < N; i ++ ) p[i] = i;
    
    int ans = m;
    for (int k = 1; k <= m; k ++ )
    {
        int a, b;
        string op;
        cin >> a >> b >> op;
        a = get(a - 1), b = get(b);
        int pa = find(a), pb = find(b);
        if (op == "even")
        {
            if (pa == pb && (dist[a] - dist[b]) % 2)
            {
                ans = k - 1;
                break;
            }
            else if (pa != pb)
            {
                dist[pa] = dist[b] - dist[a];
                p[pa] = pb;
            }
        }
        else
        {
            if (pa == pb && (dist[a] - 1 - dist[b]) % 2)
            {
                ans = k - 1;
                break;
            }
            else if (pa != pb)
            {
                dist[pa] = dist[b] - dist[a] - 1;
                p[pa] = pb;
            }
        }
    }
    cout << ans << endl;
    return 0;
}