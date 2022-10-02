#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define v first
#define w second

using namespace std;

typedef pair<int, int> PII;

const int N = 60, M = 32010; //N为购买物品个数， M为总钱数

int n, m;
PII master[N];
vector<PII> servent[N];
int f[M];

int main()
{
    cin >> m >> n; //体积 物品个数

    for (int i = 1; i <= n; i ++ ) //注意！！！这里0不能用：0表示主件，是有含义的，所有主件物品的下标从1开始
    {
        int v, p, q; //价格【体积】 重要度 主/附
        cin >> v >> p >> q;
        p *= v; // 优化目标：求 p*v 最大
        if (!q) master[i] = {v, p}; //体积 价值
        else servent[q].push_back({v, p}); //存进q号主件的附件
    }

    for (int i = 1; i <= n; i ++ ) //枚举物品
        for (int u = m; u >= 0; u -- ) //枚举体积
        {
            //制做分组背包问题某类里每一个可选择的单元————打包
            //for循环里的servent[i].size()筛选了只有主件会进入循环，附件不能进入
            //二进制枚举物品组内的所有打包单元的状态，共2的n次方种，用j表示每一种，j的第k位1/0表示第k个附件选/不选
            for (int j = 0; j < 1 << servent[i].size(); j ++ ) //枚举决策
            {
                //————————————————————————————————————————计算该状态的v，w
                //当前这个打包单元的体积是v， 价值是w ，下面这几行代码就是在计算v和w
                int v = master[i].v, w = master[i].w; //主件必选，加它！
                for (int k = 0; k < servent[i].size(); k ++ ) //枚举状态j的每一位
                    if (j >> k & 1) //如果j的第k位是1，说明包含第k个附件
                    {
                        v += servent[i][k].v; 
                        w += servent[i][k].w;
                    }
                //————————————————————————————————————————

                //已经计算出v和w，做分组背包问题的状态计算
                if (u >= v) f[u] = max(f[u], f[u - v] + w); 
            }
    }

    cout << f[m] << endl;

    return 0;
}