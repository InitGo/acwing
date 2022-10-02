#include<bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, k;
int a[N];
double ans = 1e9;

void check(double res, double x, double y)
{
    double lower = min(res, x);
    double greater = max(res, y);
    ans = min(ans, greater - lower);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    sort(a, a + n);

    if (k <= 1) printf("%.6lf\n", (double)(a[n - 1] - a[0]));
    else if (k == n) printf("%.6lf\n", (double)(0));
    else
    {
        double avrg = 0;
        int half = k / 2;
        int l = half - 1, r = n - half;
        for (int i = 0; i < n && i <= l; i ++ )
            avrg += a[i];

        for (int i = n - 1; i >= 0 && i >= r; i -- )
            avrg += a[i];

        if (k % 2 == 0)
        {
            double res = avrg / k;
            check(res, a[l + 1], a[r - 1]);
        }
        else
        {
            double res1 = avrg / (k - 1);
            check(res1, a[l + 1], a[r - 1]);

            double res2 = (avrg + a[l + 1]) / k;
            check(res2, a[l + 2], a[r - 1]);

            double res3 = (avrg + a[r - 1]) / k;
            check(res3, a[l + 1], a[r - 2]);
        }
        printf("%.6lf\n", ans);
    
    }
    return 0;
}