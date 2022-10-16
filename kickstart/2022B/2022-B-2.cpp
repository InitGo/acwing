#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

bool is_p(LL x)
{
    if (x/10 == 0) return true;
    vector<int> res;
    while (x)
    {
        res.push_back(x % 10);
        x /= 10;
    }

    int i = 0, j = res.size() - 1;
    while (i < j)
    {
        if (res[i ++ ] != res[j --]) 
            return false; 
    }
    return true;
}

int get_divisors(LL x)
{
    int res = 0;
    for (LL i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            if (is_p(i)) res ++ ;

            if (i != x / i)
            {
                LL s = x / i;
                
                if (is_p(s)) res ++ ;
            }
        }

    return res;
}


int main()
{
    int t;
    cin >> t;
    for (int e = 1; e <= t; e ++ )
    {
        LL  x;
        cin >> x;

        auto res = get_divisors(x);
        
        printf("Case #%d: %d\n", e, res);
    }
    return 0;
}