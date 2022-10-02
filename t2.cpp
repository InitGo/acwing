#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 810, M = 1450 * 2 + 10, INF = 0x3f3f3f3f;

int k, n, m;
int cnt[N];
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int ans = INF;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra(int s) {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        
        if (st[ver]) continue;
        st[ver] = true;
        
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({j, dist[j]});
            }
        }
    }
    
    // int res = 0;
    // for (int i = 1; i <= n; i ++ ) 
    //     if (dist[i] == INF) {
    //         res = INF;
    //         break;
    //     }
    //     else res += dist[i] * cnt[i];
    // ans = min(ans, res);
    
    int res = 0;
    for (int i = 0; i < k; i ++ ) {
        int j = cnt[i];
        if (dist[j] == INF) {
            res = INF;
            break;
        }
        else {
            res += dist[j];
        }
    }
    for (int i = 1; i <= n; i ++ ) cout << dist[i] << ' ';
    cout << endl;
    cout << s << ": " << res << endl;
    cout << endl;
    ans = min(ans, res);
}

int main() {
    
    cin >> k >> n >> m;
    
    for (int i = 0; i < k; i ++ ) {
        int t;
        cin >> t;
        cnt[k] = t;
    }
    
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    for (int i = 1; i <= n; i ++ )
        dijkstra(i);
    
    cout << ans << endl;
    
    return 0;
}