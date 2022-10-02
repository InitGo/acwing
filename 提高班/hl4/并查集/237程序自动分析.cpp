#include <bits/stdc++.h>

using namespace std;

const int N = 200010; //最多1e5个方程，最多2e5个数字

int cnt;
int p[N];
unordered_map<int, int> S;

struct Query
{
    int x, y, e;
}query[N];

int get(int x)
{
    if (S.count(x) == 0) S[x] = ++ cnt;
    return S[x];
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        S.clear();
        cnt = 0;
        
        int n; //n是方程个数 cnt是离散化后的数字个数
        cin >> n;
        for (int i = 0; i < n; i ++ )
        {
            int x, y, e;
            cin >> x >> y >> e;
            query[i] = {get(x), get(y), e};  //在读入，每个方程的时候就应该完成离散化
        }
        
        for (int i = 1; i <= cnt; i ++ ) p[i] = i;
        
        // 合并所有相等约束条件
        for (int i = 0; i < n; i ++ )
        {
            auto t = query[i];
            if (t.e == 1)
            {
                int pa = find(t.x), pb = find(t.y);
                p[pa] = pb;
            }
        }
        
        
        // 检查所有不等条件
        bool has_conflict = false;
        for (int i = 0; i < n; i ++ )
        {
            auto t = query[i];
            if (t.e == 0)
            {
                int pa = find(t.x), pb = find(t.y);
                if (pa == pb)
                {
                    has_conflict = true;
                    break;
                }
            }
        }
        
        if (has_conflict) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}