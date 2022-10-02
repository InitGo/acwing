#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

int n;
PII segs[N];

bool cmp(PII a, PII b)
{
    return a.second < b.second;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        cin >> l >> r;
        segs[i] = {l, r};
    }
    
    sort(segs, segs + n, cmp);
    
    int cnt = 0, p = -2e9;
    for (int i = 0; i < n; i ++ )
    {
        auto seg = segs[i];
        int l = seg.first, r = seg.second;
        if (l > p)
        {
            cnt ++ ;
            p = r;
        }
    }
    cout << cnt << endl;
    return 0;
}