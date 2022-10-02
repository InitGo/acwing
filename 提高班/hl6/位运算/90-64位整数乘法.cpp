#include <iostream>

using namespace std;

typedef long long ll;

ll qadd(ll a, ll b, ll p)
{
    ll res = 0;
    while (b)
    {
        if (b & 1) res = (res + a) % p;
        b >>= 1;
        a = a * 2 % p;
    }
    return res;
}

int main()
{
    ll a, b, p;
    cin >> a >> b >> p;
    cout << qadd(a, b, p) << endl;
    return 0;
}