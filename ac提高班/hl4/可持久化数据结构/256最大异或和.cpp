#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 600010, M = N * 25;

int n, m;
int s[N];
int tr[M][2], max_id[M];
int root[N], idx;


//因为要维护max_id这个额外信息，所以用递归写法
void insert(int i, int k, int p, int q)  //正在处理是s[i]， 第k位， 前一个版本是p，当前最新版本是q
{
    if (k < 0)  //已经处理完s[i]的最后一位
    {
        max_id[q] = i; //q存的是叶节点
        return;
    }
    int v = s[i] >> k & 1;  //当前正在插入的数s[i]的信息
    if (p) tr[q][v ^ 1] = tr[p][v ^ 1];  //如果p存在，q是p的克隆，要把p其他的信息复制过来，当前正在插入的数s[i]的信息不用复制，都是新开
    tr[q][v] = ++ idx;  //给当前路径s[i]的第k位，v，开新的点
    insert(i, k - 1, tr[p][v], tr[q][v]);  //插入下一位：s[i]， 第k - 1位， 前一个版本的root'是tr[p][v]，当前最新版本的root'是tr[q][v]
    max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);  //更新当前点的max_id
}

int query(int root, int C, int L)  //从root版本开始查，当前value是C， 左边界限制是>=L
{
    int p = root;
    for (int i = 23; i >= 0; i -- )
    {
        int v = C >> i & 1;
        if (max_id[tr[p][v ^ 1]] >= L) p = tr[p][v ^ 1];  //如果，可以走的那边的max_id >= L (不必要验证tr[p][v ^ 1]是否大于0，因为max_id[0] = -1，但写上也没错)
        else p = tr[p][v];
    }

    return C ^ s[max_id[p]]; //s[max_id[p]]： p是最后找到的叶子节点，只有它自己，则max_id[p]表示p在前缀异或和数组中的下标，s[max_id[p]]是找到的数
}

int main()
{
    scanf("%d%d", &n, &m);

    //创建初始化版本root[0]，它的前一个版本是0
    max_id[0] = -1;  //max_id[x] = 0是合法的版本，用-1表示当节点x不存在时，也不满足>=l的要求
    root[0] = ++ idx;
    insert(0, 23, 0, root[0]);

    for (int i = 1; i <= n; i ++ )
    {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;  //计算前缀异或和
        root[i] = ++ idx;  //先创建一个全新版本
        insert(i, 23, root[i - 1], root[i]);  //再把最新的值插入tr 数据范围0~1e7，共24位，23~0
    }

    char op[2];
    int l, r, x;
    while (m -- )
    {
        scanf("%s", op);
        if (*op == 'A')  //插入一个数x
        {
            scanf("%d", &x);
            n ++ ;  //cnt++
            s[n] = s[n - 1] ^ x;  //计算前缀异或和
            root[n] = ++ idx;  //先创建一个全新版本
            insert(n, 23, root[n - 1], root[n]);  //再把最新的值插入tr 数据范围0~1e7，共24位，23~0
        }
        else  //查询
        {
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(root[r - 1], s[n] ^ x, l - 1)); 
            //p：[l, r]    p-1：[l-1, r-1]  
            //l-1作为左边的限制传入query，r-1体现在使用root[r - 1]版本
        }
    }

    return 0;
}
