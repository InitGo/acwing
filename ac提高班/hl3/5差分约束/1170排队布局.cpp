#include <bits/stdc++.h>

using namespace std;

const int N = 1010, M = 21010, INF = 0x3f3f3f3f;

int n, m1, m2;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa(int op)
{
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0x3f, sizeof dist);
    
    queue<int> q;
    for (int i = 1; i <= op; i ++ )
    {
        dist[i] = 0;
        q.push(i);
        st[i] = true;
    }
    
    while(q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }

    }
    return false;
}

int main()
{
    cin >> n >> m1 >> m2;
    memset(h, -1, sizeof h);
    
    while (m1 -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b < a) swap(a, b);
        add(a, b, c);
    }
    while(m2 -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b < a) swap(a, b);
        add(b, a, -c);
    }
    
    for (int i = 1; i < n; i ++ ) add(i + 1, i, 0);
    
    if (spfa(n)) cout << -1 << endl;
    else
    {
        spfa(1);
        if (dist[n] == INF) cout << -2 << endl;
        else cout << dist[n] << endl;
    }
    return 0;
}