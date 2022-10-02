#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 30010;

int n, m;
int h1[N], h2[N], e[M], ne[M], idx;
bool st[N];
int level[N];

void add(int h[], int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//处理以u为根的子树
void dfs(int u)
{
    st[u] = true;
    for (int i = h1[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (st[j]) continue;
        add(h2, u, j);
        dfs(j);
    }
}

int bfs(int m)
{
    //int dist[N];
    //memset(dist, -1, sizeof dist);
    
    int index = 0;
    queue<int> q;
    q.push(1);
    //dist[1] = 0;
    while (q.size())
    {
        int len = q.size();
        level[index ++ ] = len;
        //int cnt = 0;
        while (len -- )
        {
            auto t = q.front();
            q.pop();
            //cnt ++ ;

            for (int i = h2[t]; ~i; i = ne[i])
            {
                int j = e[i];
                //dist[j] = dist[t] + 1;
                q.push(j);
            }
        }
        //level[index ++ ] = cnt;
    }

    int ans = 0;
    for (int i = 0; i < index; i ++ )
    {
        if (level[i] <= m)
        {
            ans += level[i];
            m -= level[i];
        }
        else break;
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C ++ )
    {
        idx = 0;
        memset(h1, -1, sizeof h1);
        memset(h2, -1, sizeof h2);
        memset(st, 0, sizeof st);
        memset(level, 0, sizeof level);

        cin >> n >> m;
        for (int i = 0; i < n - 1; i ++ )
        {
            int a, b;
            cin >> a >> b;
            add(h1, a, b), add(h1, b, a);
        }
        
        int x;
        for (int i = 0; i < m; i ++ ) cin >> x;
  
        dfs(1);
        int t = bfs(m);
        printf("Case #%d: %d\n", C, t);
    }
    return 0;
}