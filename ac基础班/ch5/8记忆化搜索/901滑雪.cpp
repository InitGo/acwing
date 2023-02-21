//https://www.acwing.com/activity/content/problem/content/1013/

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310;

int n, m;
int g[N][N];
int f[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; //偏移量

//从 x,y 出发， 返回最远能走多少格子 f[x][y]
int dp(int x, int y)
{
    int &v = f[x][y]; //引用符号，写v等价于写f[x][y]
    if (v != -1) return v; //如果状态已经被算过了，直接返回

    v = 1; //初始化，v最小也能走一步
    for (int i = 0; i < 4; i ++ ) 
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m && g[x][y] > g[a][b])
            v = max(v, dp(a, b) + 1); //！！！注意这里的迭代是用dp而不是f，f只是存储结果的
    }

    return v;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            scanf("%d", &g[i][j]);

    memset(f, -1, sizeof f);//f初始化为-1，表示这个状态没有被算过 【为什么不是0？因为算过的也可能是0？】

    int res = 0; //res存答案
    for (int i = 1; i <= n; i ++ ) //枚举从每个点出发，这个人可以在任意一点开始滑，所以要遍历一遍滑雪场
        for (int j = 1; j <= m; j ++ )
            res = max(res, dp(i, j)); //dp(i,j)，求出这个状态，并且返回 //res更新答案

    printf("%d\n", res);

    return 0;
}