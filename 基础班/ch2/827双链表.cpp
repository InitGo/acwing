#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int e[N], l[N], r[N], idx;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void addr(int k, int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    l[idx] = k;
    idx ++ ;
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    init();
    cin >> n;
    while (n -- )
    {
        string op;
        cin >> op;
        int k, x;
        if (op == "L")
        {
            cin >> x;
            addr(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            addr(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            addr(l[k + 1], x);
        }
        else// if (op == "IR")
        {
            cin >> k >> x;
            addr(k + 1, x);
        }
    }
    for (int i = r[0]; i!= 1; i = r[i])
    {
        cout << e[i] << ' ';
    }
    return 0;
}
