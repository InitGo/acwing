/*
1. 有个测试点给的图，是不连通的，但是也保证了所有牛所在的牧场连通，
就是说有个测试点有一个牧场里面没有牛并且这个牧场没连边
2. 计算花销一定要注意，并不是 如果某个牧场不能到达，花销就是INF
在计算花销的时候，如果某个点不连通，需要再判断一下该点是否有牛，如果没有牛，就不需要管
3. 毕竟花销的主体是牛，所以也可以遍历牛的编号，每次加它所在牧场的距离，来计算花销
*/

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

int dijkstra(int s) {
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
                heap.push({dist[j],j});
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (dist[i] == INF) {
            if (cnt[i])
                return INF;
        }
        else res += dist[i] * cnt[i];
    }
    return res;
}

int spfa(int s) {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
    queue<int> q;
    q.push(s);
    st[s] = true;
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (dist[i] == INF) {
            if (cnt[i])
                return INF;
        }
        else res += dist[i] * cnt[i];
    }
    return res;
}

int main() {
    cin >> k >> n >> m;
    
    for (int i = 0; i < k; i ++ ) {
        int id;
        cin >> id;
        cnt[id] ++ ;
    }
    
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    for (int i = 1; i <= n; i ++ ) {
        ans = min(ans, spfa(i));
        //ans = min(ans, dijkstra(i));
    }
    
    cout << ans << endl;
    
    return 0;
}

