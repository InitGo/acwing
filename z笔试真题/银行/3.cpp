#include<bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, T;

struct Range
{
    int l, r;
    
    bool operator< (const Range &W) const
    {
        return l < W.l;
    }
}range[N];


int main()
{
    cin >> n >> T;
    int st = 1, ed = T + 1;
    
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        range[i] = {a, b + 1};
    }
    
    sort(range, range + n);
    
    bool success = false;
    int res = 0;
    
    for(int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        while(j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j++;
        }
        
        if(r < st) break;
        
        st = r;
        res++;
        if(r >= ed)
        {
            success = true;
            break;
        }
        
        i = j - 1;
    }
    
    if(!success) res = -1;
    cout << res << endl;
    
    return 0;
