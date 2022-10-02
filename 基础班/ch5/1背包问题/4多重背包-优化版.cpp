//https://www.acwing.com/activity/content/problem/content/1000/

#include <iostream>
#include <algorithm>

using namespace std;

// 0<N≤1000
// 0<V≤2000
// 0<vi,wi,si≤2000
//每件物品最多数量2000，每件物品最多拆分成log2000个堆， 共有1000种物品
//log2000 * 1000 = 11*1000
//！！！！！易错！！！注意开数组的size
const int N = 12010, M = 2010;

int n, m;
int v[N], w[N];
int f[M];

int main()
{
    cin >> n >> m;

    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
    {
        int a, b, s;
        cin >> a >> b >> s;//读入待打包的物品信息
        
        int k = 1;//1, 2, 4, 8, ..., 2^k, s
        while (k <= s)
        {
            cnt ++ ; //打包的组编号
            v[cnt] = a * k; //组的价值
            w[cnt] = b * k; //组的体积
            s -= k; //总数量减去打包完成的数量，为剩下待打包的数量
            k *= 2; //每次打包数量*2
        }
        if (s > 0) //如果还剩
        {
            cnt ++ ; //新组
            v[cnt] = a * s; //组的价值
            w[cnt] = b * s; //组的体积
        }
    }

    //做一遍01背包
    n = cnt;

    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= v[i]; j -- )
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}