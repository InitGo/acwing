//https://www.acwing.com/activity/content/problem/content/866/

#include <iostream>

using namespace std;

const int N = 100010;

int m;
int q[N], hh,tt=-1;

int main()
{
    cin >> m;
    while (m -- )
    {
        string op;
        int x;

        cin >> op;
        if (op == "push")
        {
            cin >> x;
            q[ ++ tt] = x;
        }
        else if (op == "pop") 
        {
            hh++;
        }
        else if (op == "empty") 
        {
            if(hh>tt) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else //query
        {
            cout << q[hh]<<endl;
        }
    }

    return 0;
}
