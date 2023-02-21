#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n;
int lower[N], height[N];
int tr[N];

int lowbit(int x)
{
    return x & -x;
}

void update(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int getSum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    cin >> n;
    for (int i = 2; i <= n; i ++ )
    {
        cin >> lower[i];
    }
    
    for (int i = 1; i <= n; i ++ ) update(i, 1);
    
    for (int i = n; i; i -- )
    {
        int k = lower[i] + 1; //找第k小的数
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (getSum(mid) >= k) r = mid;
            else l = mid + 1;
        }
        update(r, -1);
        height[i] = r;
    }
    
    for (int i = 1; i <= n; i ++ )
        cout << height[i] << endl;
    return 0;
}