#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25010;

int n;
int a[N];
bool f[N];

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        sort(a, a + n);

        //只需统计所有物品的体积是否能被其他的线性表出
        //因此背包的体积只需设置为最大的物品体积即可
        int m = a[n - 1];
        memset(f, 0, sizeof f); //多组测试，要初始化
        f[0] = true; //前0选，体积恰好0，有方案，true

        int cnt = 0;
        for (int i = 0; i < n; i ++ )
        {
            if (!f[a[i]]) cnt ++ ; //如果a[i]不能被前面的数表示，cnt ++
            //从小到大，先查看当前数有没有被筛掉，
            //1)如果没有就把它加入到最大无关向量组中，并把他以及他和此前的硬币的线性组合都筛掉
            //2)如果有就不理会
            for (int j = a[i]; j <= m; j ++ ) //做一遍完全背包
                f[j] += f[j - a[i]];
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