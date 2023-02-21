#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 5500;

int n, m, ms;
int h[N], e[M], w[M], ne[M], idx;
bool st[N];
int dist[N], cnt[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool spfa()
{
    memset(dist, 0, sizeof dist);
    memset(st, 1, sizeof st);
    memset(cnt, 0, sizeof cnt);
    
    queue<int> q;
    for (int i = 1; i <= n; i ++ ) 
        q.push(i);
    
    while (q.size())
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
    int T;
    cin >> T;
    while (T -- )
    {
        idx = 0;
        cin >> n >> m >> ms;
        memset(h, -1, sizeof h);
        int a, b, c;
        for (int i = 0; i < m; i ++ )
        {
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }
        for (int i = 0; i < ms; i ++ )
        {
            cin >> a >> b >> c;
            add(a, b, -c);
        }
        
        if (spfa()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}