#include <bits/stdc++.h>

using namespace std;

int n;
string start, stop;

int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db)
{
    int d = da[q.front()];
    while (q.size() && da[q.front()] == d)
    {
        auto t = q.front();
        q.pop();
        
        for (int i = 0; i < t.size(); i ++ )
            for (int len = t.size() - i + 1; len; len -- )
            {
                string r1 = t.substr(0, i) + t.substr(len + i);
                string r2 = t.substr(i, len);
                for (int k = i; k < r1.size(); k ++ )
                {
                    string r = r1.substr(0, k + 1) + r2 + r1.substr(k + 1);
                    if (db.count(r)) return da[t] + 1 + db[r];
                    if (da.count(r)) continue;
                    
                    da[r] = da[t] + 1;
                    q.push(r);
                }
            }
    }
    return 5;
}

int bfs()
{
    queue<string> qa, qb;
    unordered_map<string, int> da, db;
    qa.push(start), qb.push(stop);
    da[start] = 0, db[stop] = 0;
    
    int step = 0;
    while (qa.size() && qb.size())
    {
        int t;
        if (qa.size() <= qb.size()) t = extend(qa, da, db);
        else t = extend(qb, db, da);
        
        if (t <= 4) return t;
        if ( ++ step >= 5) return 5;
    }
    return 5;
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        start = "", stop = "";
        cin >> n;
        for (int i = 0; i < n; i ++ )
        {
            int x;
            cin >> x;
            start += (x + '0');
            stop += (i + 1 + '0');
        }
        if (start == stop) cout << 0 << endl;
        else
        {
            int t = bfs();
            if (t < 5) cout << t << endl;
            else cout << "5 or more" << endl;
        }
    }
    
    return 0;
}

/*这组数据TLE了
3
13
10 5 12 6 9 13 3 4 8 2 7 1 11
13
11 6 5 3 12 2 7 4 8 13 10 9 1
13
1 2 3 4 6 7 8 9 10 12 13 11 5
*/