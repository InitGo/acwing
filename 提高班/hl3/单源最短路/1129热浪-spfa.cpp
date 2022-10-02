#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 2510, M = 6200 * 2 + 10;

int n, m, S, T;
int h[N], e[M], w[M], ne[M], idx;
bool st[N];
int dist[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    
    queue<int> q;
    q.push(S);
    st[S] = true;
    
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
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return dist[T];
}

int main()
{
    cin >> n >> m >> S >> T;
    
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    cout << spfa() << endl;
    
    return 0;
}