#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 20010;

int n, m, K;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool check(int x)
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    deque<int> q;
    q.push_back(1);
    while (q.size())
    {
        auto t = q.front();
        q.pop_front();
        
        if (st[t]) continue;
        st[t] = true;
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            int weight = w[i] > x ? 1 : 0;
            if (dist[j] > dist[t] + weight)
            {
                dist[j] = dist[t] + weight;
                if (weight) q.push_back(j);
                else q.push_front(j);
            }
        }
    }
    return dist[n] <= K;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> K;
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    int l = 0, r = 1e6 + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    if (l == 1e6 + 1) cout << -1 << endl;
    else cout << l << endl;
    
    return 0;
}