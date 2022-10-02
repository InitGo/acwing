#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = 2e6 + 10;

int n, m;
int hl[N], hr[N], e[M], ne[M], idx;
int price[N];  //存每个点的水晶球的价格
int dmin[N], dmax[N];
bool st[N];

void add(int a, int b, int h[])
{
    e[idx]= b, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa(int h[], int dist[], int type)
{
    memset(st, 0, sizeof st);
    queue<int> q;
    if (type == 0)
    {
        memset(dist, 0x3f, sizeof dmin);  //！！！这里sizeof的时候一定要注意是原数组的size
        dist[1] = price[1]; 
        q.push(1);
        st[1] = true;
    }
    else 
    {
        memset(dist, -0x3f, sizeof dmax);
        dist[n] = price[n];
        q.push(n);
        st[n] = true;
    }
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            
            if (type == 0 && dist[j] > min(dist[t],  price[j]) || type == 1 && dist[j] < max(dist[t], price[j]))
            {
                if (type == 0) dist[j] = min(dist[t], price[j]);
                if (type == 1) dist[j] = max(dist[t], price[j]);
                
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++ ) cin >> price[i];
    
    memset(hl, -1, sizeof hl);
    memset(hr, -1, sizeof hr);
    while (m -- ) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, hl), add(b, a, hr);
        if (c == 2)
        {
            add(b, a, hl); 
            add(a, b, hr); 
        }
    }
    
    spfa(hl, dmin, 0);
    spfa(hr, dmax, 1);
    
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
        ans = max(ans, dmax[i] - dmin[i]);
    
    cout << ans << endl;
    return 0;
}