// https://www.acwing.com/activity/content/problem/content/1006/

//做n次最短编辑距离
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 15, M = 1010;

int n, m;
int f[N][N];
char str[M][N]; //存n个字符串

//返回需要操作的次数
int edit_distance(char a[], char b[])
{
    int la = strlen(a + 1), lb = strlen(b + 1); //获取字符串的长度

    //初始化
    for (int i = 0; i <= lb; i ++ ) f[0][i] = i;
    for (int i = 0; i <= la; i ++ ) f[i][0] = i;

    for (int i = 1; i <= la; i ++ )
        for (int j = 1; j <= lb; j ++ )
        {
            //三种情况取最小值
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }

    return f[la][lb]; //返回操作次数
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%s", str[i] + 1); //读入n个等待操作的a字符串

    while (m -- )
    {
        char s[N]; //读入目标字符串b
        int limit; //读入要求的次数限制
        scanf("%s%d", s + 1, &limit);

        int res = 0; //存n中有几个符合条件
        for (int i = 0; i < n; i ++ )
            if (edit_distance(str[i], s) <= limit)
                res ++ ;

        printf("%d\n", res);
    }

    return 0;
}