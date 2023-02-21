#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int h[N];
int f[N], g[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);

    //从1到n方向的最长上升子序列
    for (int i = 1; i <= n; i ++ )
    {
        f[i] = 1;
        for (int j = 1; j < i; j ++ )
            if (h[i] > h[j])
                f[i] = max(f[i], f[j] + 1);
    }

    //从n到1方向的最长上升子序列    
    for (int i = n; i >= 1; i -- )
    {
        g[i] = 1;
        for (int j = n; j > i; j -- )
            if (h[i] > h[j])
                g[i] = max(g[i], g[j] + 1);
    }

    int res = 0;
    //枚举每个点作为顶点时的值，求max
    for (int i = 1; i <= n; i ++ ) res = max(res, f[i] + g[i] - 1);

    printf("%d\n", res);

    return 0;
}
















//自己写的 ， 绕一点

#include <iostream>

using namespace std;

const int N = 1010;

int a[N], b[N];
int up[N], down[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int t;
        cin >> t;
        a[i] = t;
        b[n + 1- i] = t;
    }

    for (int i = 1; i <= n; i ++ )
    {
        up[i] = 1;
        down[i] = 1;
        for (int j = 1; j < i; j ++ )
        {
            if (a[j] < a[i]) up[i] = max(up[i], up[j] + 1);
            if (b[j] < b[i]) down[i] = max(down[i], down[j] + 1);
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        res = max(res, up[i] + down[n - i + 1] - 1);
    }
    
    cout << res << endl;
    
    return 0;
}