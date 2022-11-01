#include <bits/stdc++.h>

using namespace std;

const int N = 50010, M = N * 3 + 10;

int n;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b; w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa()
{
    memset(st, 0, sizeof st);
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    st[0] = true;

    queue<int> q;
    q.push(0);
    
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
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ ) 
    {
        int a, b, c;
        cin >> a >> b >> c;
        a ++ , b ++ ;
        add(a - 1, b, c);
    }
    
    for (int i = 1; i <= 50001; i ++ )
    {
        add(i - 1, i, 0);
        add(i, i - 1, -1);
    }
    
    spfa();
    
    cout << dist[50001] << endl;
    return 0;
}

