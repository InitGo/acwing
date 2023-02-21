#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 25010;

int n;
int a[N], f[M];

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        sort(a + 1, a + 1 + n);  //一定要先排序，让小的数先被处理

        //只需统计所有物品的体积是否能被其他的线性表出
        //因此背包的体积只需设置为最大的物品体积即可
        memset(f, 0, sizeof f); //多组测试，要初始化
        f[0] = 1; //前0选，体积恰好0，有方案，true

        int cnt = n;
        for (int i = 1; i <= n; i ++ )
        {
            if (f[a[i]]) cnt -- ; //如果a[i]能被前面的数表示，cnt --
            else  //否则，用当前数更新：表示的数的方案
            {
                for (int j = a[i]; j <= 25000; j ++ ) //做一遍完全背包
                    f[j] += f[j - a[i]];
            }
            
        }

        cout << cnt << endl;
    }

    return 0;
}

//为什么要先判断，再更新？
//更新？ 更新f的值？ 
//求x能否用x前的数表出 / 求x能否用全体数字表出？
//x一定能用全体数字表出！！x就是数字中的一个
//所以必须先判断再更新！