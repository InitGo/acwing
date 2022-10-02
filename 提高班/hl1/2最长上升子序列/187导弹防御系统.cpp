#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;

int n;
int h[N];
int up[N], down[N];
// up数组表示所有严格上升子序列的结尾，它本身随下标是非严格单调下降的；
// down数组表示所有严格下降子序列的结尾，它本身随下标是非严格单调上升的；
int ans; //全局变量

//当前枚举到了第几个数 当前上升子序列的个数 当前下降子序列的个数
void dfs(int u, int su, int sd)
{
    if (su + sd >= ans) return; //当前子序列的个数超过ans了，不可能把答案再变小了，return
    if (u == n) //已经找到了一个方案
    {
        ans = min(ans, su + sd);
        //ans = su + sd; 也可以直接更新，能下来说明 su + sd 是严格小于ans的
        return;
    }

    //情况1 将当前数放到上升子序列中
    int k = 0;
    while (k < su && up[k] >= h[u]) k ++ ;
    if (k < su) //没有增加新的上升子序列
    {
        int t = up[k]; //备份现场
        up[k] = h[u]; //做更改
        dfs(u + 1, su, sd); //深搜
        up[k] = t; //回溯
    }
    else //增加了新的上升子序列
    {
        up[k] = h[u];
        dfs(u + 1, su + 1, sd);
    }

    //情况2 将当前数放到下降子序列中
    k = 0;
    while (k < sd && down[k] <= h[u]) k ++ ;
    if (k < sd)
    {
        int t = down[k];
        down[k] = h[u];
        dfs(u + 1, su, sd);
        down[k] = t;
    }
    else
    {
        down[k] = h[u];
        dfs(u + 1, su, sd + 1);
    }
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i ++ ) cin >> h[i];

        ans = n;
        dfs(0, 0, 0);

        cout << ans << endl;
    }

    return 0;
}
