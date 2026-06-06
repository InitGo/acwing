#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int st[N], ed[N];
int a[N], b[N];
vector<pair<int, int>> stars;
vector<int> ys;

void add(int l, int r)
{
    b[l] += 1;
    b[r + 1] -= 1;
}

int find(int y)
{
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        cin >> st[i];
        ys.push_back(st[i]);
    }

    for (int i = 0; i < n; i ++ )
    {
        cin >> ed[i];
        ys.push_back(ed[i]);
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    int cnt = ys.size();


    for (int i = 0; i < n; i ++ )
    {
        int l = find(st[i]), r = find(ed[i]);
        add(l, r);
    }

    for (int i = 1; i <= cnt; i ++ ) a[i] = a[i - 1] + b[i];

    int maxn = 0;
    for (int i = 1; i <= cnt; i ++ )
        maxn = max(maxn, a[i]);
    
    int ans = 0;
    vector<int> beauty;
    for (int i = 1; i <= cnt; i ++ )
        if (a[i] == maxn)
        {
            beauty.push_back(ys[i - 1]);
        }

    

    cout << maxn << ' ' << ans << endl;
    return 0;
}