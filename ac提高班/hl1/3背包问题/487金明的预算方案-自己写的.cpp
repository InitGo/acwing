#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 66, M = 32010;

int m, n;
unordered_map<int, vector<int>> master;

int v[N], w[N];
int f[M];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int p, q;
        cin >> v[i] >> p >> q;
        w[i] = p * v[i];
        if (!q) master[i] = {};
        else master[q].push_back(i);
    }
    
    for (auto &t : master)  //枚举分组
    {
        auto& vct = t.second;
        int cnt = vct.size();
        
        for (int j = m; j >= 0; j -- )  //枚举体积
        {
            for (int k = 0; k < 1 << cnt; k ++ )  //枚举选择
            {
                int pv = v[t.first], pw = w[t.first];
                for (int u = 0; u < cnt; u ++ )
                    if (k >> u & 1)
                    {
                        int id = vct[u];
                        pv += v[id], pw += w[id];
                    }
                
                if (j >= pv) f[j] = max(f[j], f[j - pv] + pw);
            }
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}