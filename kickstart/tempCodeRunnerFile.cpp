#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

struct Ant
{
    int id;
    int pos;
    int dir;
    int state;
    int time;
}ants[N];

int n, l;

bool cmp(Ant a, Ant b)
{
    if (a.time != b.time) return a.time < b.time;
    return a.id < b.id;
}

int main()
{
    int T;
    cin >> T;
    
    for (int C = 1; C <= T; C ++ )
    {
        cin >> n >> l;
        int on_stick = 0;

        for (int i = 1; i <= n; i ++ )
        {
            int a, b;
            cin >> a >> b;
            if (b == 0) b = -1; //-1:left 1:right
            
            bool st = false; //没掉false 掉了true
            if (a == 0 || a == l) st = true;
            on_stick += (!st);
            ants[i] = {i, a, b, st, 0};
        }
        
        map<PII, vector<int> > mp;
        while (on_stick)
        {
            mp.clear();
            for (int i = 1; i <= n; i ++ )
            {   
                Ant& t = ants[i];
                if (t.state) continue; //已经掉了就不再处理；
                
                t.pos += t.dir; //位置
                t.time ++ ; //时间
                if (t.pos == 0 || t.pos == l)
                {//判断掉了吗
                    t.state = true;
                    on_stick -- ;
                }

                // PII seg;
                // if (t.dir == -1) seg = {t.pos, t.pos + 1};
                // else seg = {t.pos - 1, t.pos};
                PII seg = {t.pos - t.dir, t.pos};

                mp[seg].push_back(t.id);
            }
            for (auto x : mp)
                {
                    auto vec = x.second;
                    if (vec.size() <= 1) continue;

                    if (mp[{x.first.first, x.first.second}].size() >= 1 && mp[{x.first.second, x.first.first}].size() >= 1)
                    {
                        for (int id : mp[{x.first.first, x.first.second}])
                        {
                            ants[id].pos -= ants[id].dir;
                            ants[id].dir = 0 - ants[id].dir;
                        }
                        for (int id : mp[{x.first.second, x.first.first}])
                        {
                            ants[id].pos -= ants[id].dir;
                            ants[id].dir = 0 - ants[id].dir;
                        }
                    }
                }
        }
        
        sort(ants + 1, ants + n + 1, cmp);

        cout << "Case #" << C << ": ";
        for (int i = 1; i <= n; i ++ )
        {
            cout << ants[i].id << ' ';
        }
        cout << endl;
        //cout << "Case #" << C << ": " << "POSSIBLE" << endl;
    }
    return 0;
}