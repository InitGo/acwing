#include <iostream>

using namespace std;

const int N = 20010, M = 6010;

int f[M];
int v[N], w[N];

int main()
{
    int n, m;
    cin >> n >> m;
    
    int cnt = 0;
    for (int i = 0; i < n; i ++ )
    {
        int a, b, s;
        cin >> a >> b >> s;
        
        int k = 1;
        while (s >= k)
        {
            cnt ++ ;
            v[cnt] = k * a;
            w[cnt] = k * b;
            s -= k;
            k *= 2;
        }
        
        if (s > 0)
        {
            cnt ++ ;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }
  
    n = cnt;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = m; j >= v[i]; j -- )
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    
    cout << f[m] << endl;
    return 0;
}