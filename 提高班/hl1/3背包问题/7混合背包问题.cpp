#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int f[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int v, w, s;
        cin >> v >> w >> s;
        
        if (s == 0)
        {
            for (int j = v; j <= m; j ++ )
                f[j] = max(f[j], f[j - v] + w);
        }
        else
        {
            if (s == -1) s = 1;  //01背包是s=1的多重背包
            
            int k = 1;
            while (k <= s)
            {
                int v1 = k * v;
                int w1 = k * w;
                s -= k;
                k *= 2;
                
                //做好了01背包中的一个物品，得到了v1和w1，可以执行第二重循环了
                for (int j = m; j >= v1; j -- )
                    f[j] = max(f[j], f[j - v1] + w1);
            }
            if (s)
            {
                int v1 = s * v;
                int w1 = s * w;
                
                //剩下最后一个也是01背包的一个物品
                for (int j = m; j >= v1; j -- )
                    f[j] = max(f[j], f[j - v1] + w1);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}