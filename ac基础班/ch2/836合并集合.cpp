//https://www.acwing.com/activity/content/problem/content/885/
#include <iostream>

using namespace std;

const int N = 100010;

int p[N];

//返回x的祖宗节点 + 路径压缩优化
int find(int x)
{
    //如果x不是根节点，就让x的母节点等于原来母节点祖宗节点，也是原来自己的祖宗节点
    //如果x是根节点了，返回p[x]
    //使用递归，可以完成优化操作
    if (p[x] != x) p[x] = find(p[x]);//只搜索一遍，让这条线上的所有点都指向根节点 即 点x的母节点p[x]是根节点
    return p[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    //初始化，让所有的元素的父节点等于自己 
    //当一个元素的父节点等于自己 ，则表示这个节点是根节点
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    while (m -- )
    {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "M") p[find(a)] = find(b); //让a的祖宗节点的父亲 = b的祖宗节点
        else
        {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}
