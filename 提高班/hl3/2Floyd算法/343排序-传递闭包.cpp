#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 26;

int n, m;
bool g[N][N], d[N][N];
bool st[N];

void floyd()
{
    memcpy(d, g, sizeof d);

    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                d[i][j] |= d[i][k] && d[k][j];
}

int check()
{
    for (int i = 0; i < n; i ++ )
        if (d[i][i]) 
            return 2;
    
    for (int i = 0; i < n; i ++ )
        for (int j = i + 1; j < n; j ++ )  //只能枚举一半，如果i==j，则必然返回0
            if (!d[i][j] && !d[j][i])
                return 0;
    return 1;
}

char get_min()
{
    for (int i = 0; i < n; i ++ )
    {
        if (st[i]) continue; //验证1：不能是打印过的
        
        //验证2：必须是最小值：入度为0
        bool flag = true;  //假设i是最小值
        for (int j = 0; j < n; j ++ )
            if (!st[j] && d[j][i])  //存在j比i小
            {
                flag = false;
                break;
            }
        if (flag)
        {
            st[i] = true;
            return 'A' + i;
        }
    }   
}

void topsort()
{
    int din[N];
    memset(din, 0, sizeof din);
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            if (d[i][j])
                din[j] ++ ;
    
    int q[N], hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        if (din[i] == 0) q[ ++ tt] = i;
    }
    
    while (hh <= tt) 
    {
        int t = q[hh ++ ];
        for (int j = 0; j < n; j ++ )
            if (d[t][j])
            {
                din[j] -- ;
                if (din[j] == 0) q[ ++ tt] = j;
            }
    }
    
    for (int i = 0; i <= tt; i ++ ) cout << char('A' + q[i]) ;
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        memset(g, 0, sizeof g);
        int type = 0, t;  //t存退出时的轮数
        for (int i = 1; i <= m; i ++ )  //一条一条读入不等式关系
        {
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A'; //映射为数字下标，方便用floyd

            if (!type)  //仅当关系不确定的时候(type == 0)再继续 不能break，因为要读取所有的输入
            {
                g[a][b] = 1;  //加上这条边
                floyd();  //计算传递闭包
                type = check();  //检查
                if (type) t = i;  
            }
        }

        if (!type) puts("Sorted sequence cannot be determined.");
        else if (type == 2) printf("Inconsistency found after %d relations.\n", t); //矛盾
        else
        {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for (int i = 0; i < n; i ++ ) printf("%c", get_min());
            //topsort();
            printf(".\n");
        }
    }

    return 0;
}