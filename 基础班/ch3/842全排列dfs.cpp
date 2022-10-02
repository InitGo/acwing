//https://www.acwing.com/activity/content/problem/content/905/

#include<iostream>
using namespace std;
const int N = 100010;
int n;
int path[N];
bool st[N];//存数字的状态，true表示已被使用，不可再用
void dfs(int u)
{
    if(u==n)
    {
        for(int i = 0;i<n;i++)
        {
            cout << path[i] << ' ';
        }
        cout << endl;
        return;
    }

    for(int i =1;i<=n;i++)
    {
        if(!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u+1);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
