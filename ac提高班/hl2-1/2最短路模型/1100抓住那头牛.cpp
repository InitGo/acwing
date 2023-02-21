#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int st, ed;
int dist[N];
int q[N];

int bfs(int st)
{
    int hh = 0, tt = 0;
    q[0] = st;
    
    memset(dist, -1, sizeof dist);
    dist[st] = 0;
    
    while (hh <= tt)
    {
        int t = q[hh ++ ];
        if (t == ed) return dist[t]; //先判断是否找到，再做扩展
        
        int dt[] = {t - 1, t + 1, t * 2};
        for (int i = 0; i < 3; i ++ )
        {
            int ne = dt[i];
            if (ne < 0 || ne > 1e5) continue;
            if (dist[ne] != -1) continue;
            
            dist[ne] = dist[t] + 1;
            q[ ++ tt] = ne;
        }
    }
    return -1;
}

int main()
{
    cin >> st >> ed;
    cout << bfs(st) << endl;
    return 0;
}