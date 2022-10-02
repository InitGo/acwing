//https://www.acwing.com/activity/content/problem/content/937/

#include <iostream>
#include <algorithm>

using namespace std;

const int N= 1000010;

int primes[N], cnt;
bool st[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}