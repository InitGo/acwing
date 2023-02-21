#include <bits/stdc++.h>

using namespace std;

const int N = 30, M = 120;

int n;
int h[N], e[M], ne[M], w[M], idx;
int r[N], num[N];
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void build(int c)
{
    memset(h, -1, sizeof h);
    idx = 0;
    for (int i = 1; i <= 24; i ++ ) 
    {
        add(i - 1, i, 0);
        add(i, i - 1, -num[i]);
    }
    
    for (int i = 8; i <= 24; i ++ ) add(i - 8, i, r[i]);
    for (int i = 1; i <= 7; i ++ ) add(i + 16, i, -c + r[i]);
    add(0, 24, c), add(24, 0, -c);
}

bool check(int c)
{
    build(c);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    
    queue<int> q;
    q.push(0);
    st[0] = true;
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= 25) return false;
                
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        memset(r, 0, sizeof r);
        memset(num, 0, sizeof num);
        for (int i = 1; i <= 24; i ++ ) cin >> r[i];
        cin >> n;
        
        for (int i = 1; i <= n; i ++ )
        {
            int t;
            cin >> t;
            num[t + 1] ++ ;
        }
        
        int l = 0, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        
        if (check(r)) cout << r << endl;
        else cout << "No Solution" << endl;
    }
    return 0;
}