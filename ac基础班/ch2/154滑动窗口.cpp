//https://www.acwing.com/activity/content/problem/content/868/

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], q[N];//q存下标

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

    int hh = 0, tt = -1;//初始化队列
    for (int i = 0; i < n; i ++ )
    {
        //如果 队列非空 && 队头中存的下标 已经出了滑动窗口 则把队头元素弹出 
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

        //从队尾开始，只要 队尾存的下标对应的数字>=要加进来的数字 把队尾弹出  
        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ; //!!!注意，这里是用队尾元素q[tt]比较
        //要加进来的数字加入队尾，新加进来的一定是滑动窗口中最小的数字
        q[ ++ tt] = i;

        //当滑动窗口中k个数字满了的时候再行输出 输出队头存的下标对应的那个数字【永远最小】
        //i-k+1 >= 0 输出
        if (i-k+1 >= 0) printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
        q[ ++ tt] = i;

        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }

    puts("");

    return 0;
}
