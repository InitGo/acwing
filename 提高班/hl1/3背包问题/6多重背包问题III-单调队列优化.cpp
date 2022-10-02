#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;

int n, m;
int f[N], g[N], q[N]; //f和g做滚动数组

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ )
    {
        int v, w, s;
        cin >> v >> w >> s;
        memcpy(g, f, sizeof f); //做的时候先把上一次f的结果存到g
        for (int r = 0; r < v; r ++ ) //r表示余数，余数从0 ~ v-1
        {
            int hh = 0, tt = -1; //定义单调队列
            for (int k = r; k <= m; k += v) //余数r固定的时候，一串序列的起止位置为从r到m，每次+=v
            {
                //如果队头已经滑出滑动窗口， 队头出列
                if (hh <= tt && q[hh] < k - s * v) hh  ++ ; 

                //q[tt] 和 k作比较，k在后面，还要减一个偏移量
                //while (hh <= tt && g[q[tt]] - (q[tt] - r) / v * w <= g[k] - (k - r) / v * w) tt -- ;
                while (hh <= tt && g[q[tt]] <= g[k] - (k - q[tt]) / v * w) tt -- ; 
                
                q[ ++ tt] = k;

                //新的f用上一层的g来算出
                //k比q[hh] 靠后，q[hh]要加上一个偏移量
                f[k] = g[q[hh]] + (k - q[hh]) / v * w; 
            }
        }
    }

    cout << f[m] << endl;

    return 0;
}