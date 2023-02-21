//https://www.acwing.com/activity/content/problem/content/1094/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
char a[N], b[N]; //存字符串
int f[N][N];

int main()
{
    scanf("%d%s", &n, a + 1); //下标会用到i-1，所以从1开始存，避免越界
    scanf("%d%s", &m, b + 1);

    //分别初始化边界
    //当a是0个，b是i个，只能通过i次增加操作，使得a与b匹配
    for (int i = 0; i <= m; i ++ ) f[0][i] = i; 
    //当a是i个，b是0个，只能通过i次删除操作，使得a与b匹配
    for (int i = 0; i <= n; i ++ ) f[i][0] = i;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            //前两种情况直接写  ！！！什么时候直接写min，什么时候要跟原来的f[i][j]再比？
            //如果集合划分只有少数【1，2，3】种情况，就直接对划分的子集合求属性
            //如果集合划分有多种情况，需要用到循环，则先设置f[i][j]的初始值，再用f[i][j]来维护属性值
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1); 

            //第三种情况，先判断a[i]与b[j]是否相等
            if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }

    printf("%d\n", f[n][m]);

    return 0;
}
