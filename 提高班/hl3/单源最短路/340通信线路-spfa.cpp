#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1010, M = 20010;

int n, m, k;
int dist[N];
bool st[N];
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

bool check(int x) {
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            int distance = w[i] > x ? 1 : 0;
            if (dist[j] > dist[t] + distance) {
                dist[j] = dist[t] + distance;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return dist[n] <= k;
}

int main() {
    cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a , c);
    }
    
    int l = 0, r = 1e6 + 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    if (l == 1e6 + 1) l = -1;
    cout << l << endl;
    return 0;
}