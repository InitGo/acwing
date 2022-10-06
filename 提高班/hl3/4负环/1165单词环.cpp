#include <bits/stdc++.h>

using namespace std;

const int N = 700, M = 100010;

int n;
double dist[N];
int cnt[N];
bool st[N];
int h[N], e[M], w[M], ne[M], idx;
unordered_map<string, int> S;
int point_cnt;

void init()
{
    idx = 0;
    memset(h, -1, sizeof h);
    
    point_cnt = 0;
    S.clear();
}

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int get(string s)
{
    if (!S.count(s)) S[s] = point_cnt ++ ;
    return S[s];
}

bool check(double mid)
{
    memset(cnt, 0, sizeof cnt);
    memset(st, 1, sizeof st);
    
    queue<int> q;
    for (int i = 0; i < point_cnt; i ++ ) q.push(i);
    
    int count = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i] - mid)
            {
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                
                if ( ++ count > 10000) return true;
                if (cnt[j] >= point_cnt) return true;
                
                if (!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}

int main()
{
    while (cin >> n, n)
    {
        init();
        
        string word;
        for (int i = 0; i < n; i ++ )
        {
            cin >> word;
            int len = word.size();
            if (len >= 2)
            {
                int a = get(word.substr(0, 2));
                int b = get(word.substr(len - 2));
                add(a, b, len);
            }
        }
        
        if (!check(0)) cout << "No solution" << endl;
        else
        {
            double l = 0, r = 1000;
            while (r - l > 1e-4)
            {
                double mid = (l + r) / 2;
                if (check(mid)) l = mid;
                else r = mid;
            }
            cout << r << endl;
        }
    }
    return 0;
}