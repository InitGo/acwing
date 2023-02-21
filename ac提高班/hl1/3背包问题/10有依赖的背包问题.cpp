#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N];
int h[N], e[N], ne[N], idx;
int f[N][N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

//递归处理到第u个点
//考虑以u位根节点的子树时，考虑不同的体积下，在子树中选择，最大价值是多少
void dfs(int u)
{
    for (int i = h[u]; ~i; i = ne[i])   // 把每一棵子树看成一个物品组，循环物品组
    {
        int son = e[i];
        dfs(son);

        // 分组背包
        for (int j = m - v[u]; j >= 0; j -- )  // 考虑不同的体积下，循环体积 [金明是循环状态]
            for (int k = 0; k <= j; k ++ )  // 循环决策：枚举当前给son分配的体积k
                f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
                //所有子树总共有体积m-v[u]，给该子树分配的体积为k，
                //f[u][j - k] + f[son][k]
                //从u为根的子树中选，体积不超过j - k
                //从son为根的子树中选，体积不超过k的价值
    }

    // 将物品u加进去 逆序使用，更新f的值
    //逆序：要用小的来更新大的，不能用已经更新的去更新别的
    for (int i = m; i >= v[u]; i -- ) f[u][i] = f[u][i - v[u]] + w[u]; // f[u][i - v[u]]上面已经算好了
    //因为我们是从叶子结点开始往上做，所以如果背包容积不如当前物品的体积大，那就不能选择当前结点及其子节点，因此赋值为零 
    for (int i = 0; i < v[u]; i ++ ) f[u][i] = 0;
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);
    int root; //找树根
    for (int i = 1; i <= n; i ++ ) 
    {
        int p;
        cin >> v[i] >> w[i] >> p; 
        if (p == -1) root = i; //找到树根
        else add(p, i);
    }

    dfs(root); //从根节点开始递归操作

    cout << f[root][m] << endl; //考虑整棵树，总集体不超过m的最大价值是多少

    return 0;
}