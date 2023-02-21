#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30010;

int n;
int p[N], sz[N], dist[N];

//find的时候，同时维护集合关系、dist关系
int find(int x)  //！！！find函数的作用：找到x的root节点，并更新x到root节点的距离
{
    if (p[x] != x) //如果x不是root节点
    {
        int root = find(p[x]); //找到p[x]的root节点，并更新p[x]到root节点的距离
        dist[x] += dist[p[x]]; //在本层内具体更新x到root节点距离的具体逻辑
        //此时x的parent节点还是p[x]，并没有更新为root节点，先把dist[x]更新为dist[x] + dist[p[x]]; 更新后dist[x]为x到root的距离
        p[x] = root; //再让x的parent节点更新为root
    }
    return p[x];

    //把p[x] = find(p[x])拆成两步，在中间加入维护距离的逻辑
}

//先假定有一个find函数，它的功能就是找到x的祖宗节点，并更新x到祖宗节点的距离
//想要更新x到祖宗节点的距离，首先需要得到p[x]到祖宗节点的距离
//p[x]到祖宗节点的距离 可以使用find函数，到目前为止还很完美
//得到p[x]到祖宗节点的距离以后，要怎么更新x到祖宗节点的距离？这是实现find函数功能的核心逻辑
//首先dist[x] += dist[p[x]]
//然后使用路径优化p[x] = root; //让x的parent节点直接等于root

int main()
{
    cin >> n;
    for (int i = 1; i <= N; i ++ )
    {
        p[i] = i;
        sz[i] = 1;
    }
    
    while (n -- )
    {
        int a, b;
        string op;
        cin >> op >> a >> b;
        if (op == "M")
        {
            int pa = find(a), pb = find(b);
            if (pa != pb)  //merge的时候，需要处理集合关系、sz、dist
            {
                dist[pa] = sz[pb];  //维护dist信息
                sz[pb] += sz[pa];  //维护size信息
                p[pa] = pb;  //处理集合关系
            }
        }
        else
        {
            int pa = find(a), pb = find(b);
            if (pa != pb) cout << -1 << endl;
            else cout << max(0, abs(dist[a] - dist[b]) - 1) << endl;
        }
    }
    return 0;
}