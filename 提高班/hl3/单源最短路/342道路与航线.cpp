#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 25010, M = 150010, INF = 0x3f3f3f3f;

int n, mr, mp, S;
int id[N];
vector<int> block[N];
int block_cnt;

int h[N], e[M], w[M], ne[M], idx;
int dist[N]; 
bool st[N];

queue<int> q;  //全局的topsort
int din[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int bid) {
    id[u] = bid;
    block[bid].push_back(u);
    
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!id[j]) 
            dfs(j, bid);
    }
}

void dijkstra(int bid) {
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    
    //对bid这个块内的点做最短路
    //普通的dijkstra是先把起点入堆，再慢慢扩展，这里不知道起点是谁，就把所有点全部入堆，最上面的自然是起点
    //事实上普通的dijkstra只有起点是0，其他点都是INF，如果非要全部入堆，也都只会在堆底部，所以就只入起点
    //本题的块内的所有点的距离并不都是INF，所以一起入堆
    for (int x : block[bid]) heap.push({dist[x], x});
    
    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            
            //1先检查j是否与ver在同一个连通块
            if (id[j] != id[ver]) { //不在同一个连通块，说明找到了bid的出边，因为bid已经出队列，所有被bid指向的块 都应该减去bid对其入度的影响
                din[id[j]] -- ; //j所在连通块的入度--
                if (!din[id[j]]) q.push(id[j]); //如果j所在连通块的入度减为0，则入拓扑排序队列
            }

            //2再看点j的距离能否被更新：不管是否在同一连通块，都都应该更新
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                if (id[ver] == id[j]) heap.push({dist[j], j}); //能更新且在同一连通块，则入heap
            }
        }
    }
}

void topsort() {
    memset(dist, 0x3f, sizeof dist);  //dijkstra的初始化放在这里，表示统计全局的最短路
    dist[S] = 0;
    
    for (int i = 1; i <= block_cnt; i ++ ) {
        if (!din[i]) q.push(i);
    }
    
    while (q.size()) {  
        int t = q.front();
        q.pop();  //当前块虽然pop了，但是当前块里的若干点与其他块的若干点存在有向边连接，这个入度的更改只能放在dijkstra里处理
        
        dijkstra(t);  //t这个块已出队列
    }
}

int main() {
    cin >> n >> mr >> mp >> S;
    
    memset(h, -1, sizeof h);
    while (mr -- ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    
    for (int i = 1; i <= n; i ++ ) {
        if (!id[i]) {  //如果第i个点还没有被标记属于哪个连通块（没被遍历到），就 把连通块数量++， dfs这个点，搜完这个连通块
            block_cnt ++ ;
            dfs(i, block_cnt);
        }
    }
    
    while (mp -- ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        din[id[b]] ++ ;
    }
    
    topsort();
    
    for (int i = 1; i <= n; i ++ ) {
        if (dist[i] > INF / 2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    }
    
    return 0;
}