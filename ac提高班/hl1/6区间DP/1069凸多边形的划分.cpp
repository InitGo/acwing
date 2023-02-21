#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int N = 55;

int n;
int w[N];
VI f[N][N];

//initialize VI
VI pakage(VI a)
{
    if (a.size() == 0)
        a.push_back(0);
    return a;
}

//print VI
void print(VI a)
{
    for (int i = a.size() - 1; i >= 0; i -- )
        cout << a[i];
    cout << endl;
}

//convert type-LL to type-VI
VI LL2vec(LL a)
{
    VI c;
    while (a)
    {
        c.push_back(a % 10);
        a /= 10;
    }
    return c;
}

VI add(VI a, VI b)
{
    VI c;
    LL t = 0;
    for (int i = 0; i < a.size() || i < b.size() || t; i ++ )
    {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

VI mul(VI a, LL b)
{
    VI c;
    LL t = 0;
    for (int i = 0; i < a.size() || t; i ++ )
    {
        if (i < a.size()) t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

//compare: if a > b, return true
bool cmp(VI a, VI b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i -- )
        if (a[i] != b[i]) 
            return a[i] > b[i];
    return false;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    
    for (int len = 3; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n; l ++ )
        {
            int r = l + len - 1;

            //initialization: INF
            for (int q = 0; q < N; q ++ )
                f[l][r].push_back(0);
            f[l][r].push_back(1);
            
            //f[l][r] = min(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
            for (int k = l + 1; k < r; k ++ )
            {
                VI x = pakage(f[l][r]);
                
                VI add1 = add(pakage(f[l][k]), pakage(f[k][r]));
                VI add2 = mul(mul(LL2vec(w[l]), w[k]), w[r]);
                VI y = add(add1, add2);

                if (cmp(x, y)) f[l][r] = y;
            } 
        }
    print(f[1][n]);
    return 0;
}