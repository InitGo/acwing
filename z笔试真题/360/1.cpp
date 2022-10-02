#include <bits/stdc++.h>

using namespace std;

const int N = 8;

int n = 5;
int path[N];
int g[N];

//对第i个数做+1/-1 【做一次/恢复现场】
void change(int x, int op)
{
    g[x] = (g[x] + op) % n;
}


//检查是否五个数字相同
bool check()
{
    int x = g[0];
    for (int i = 1; i < n; i ++ )
        if (g[i] != x) return false;
    return true;
}


//当前做了u次，最大做max_depth次
bool dfs(int u, int max_depth)
{
    if (u > max_depth) return false;
    if (check()) return true;
    
    for (int i = 0; i < n; i ++ )
        for (int j = i; j < n; j ++ )
        { 
            change(i, 1);
            if (i != j) change(j, 1);
            if (dfs(u + 1, max_depth)) return true;
            change(i, -1);
            if (i != j) change(j, -1);
        }
    return false;
}


int main()
{
    //1 1 1 1 1
    //2 2 1 2 2
    //2 1 1 2 1
    for (int i = 0; i < n; i ++ ) cin >> g[i];

    int max_depth = 0;
    while (!dfs(0, max_depth)) max_depth ++ ;
    cout << max_depth << endl;

    return 0;
}