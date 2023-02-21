#include <iostream>

using namespace std;

const int N = 100010, M = 3000010;

int n;
int a[N];
int tr[M][2], idx;

void insert(int x)
{
    int p = 0;  //先放好根节点
    for (int i = 30; ~i; i -- )
    {
        int s = x >> i & 1;  //tr[p][s]是下一个需要加入的节点
        if (!tr[p][s]) tr[p][s] = ++ idx;  //如果tr[p][s]不存在，开一个新的空间给s
        p = tr[p][s];  //p一路往下走
    }
}

int query(int x)
{
    int res = 0, p = 0;
    for (int i = 30; ~i; i -- )
    {
        int s = x >> i & 1;  //s是x的第i位的元素
        if (tr[p][!s])  
        {
            res += 1 << i;
            p = tr[p][!s];
        }
        else p = tr[p][s];
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) 
    {
        cin >> a[i];
        insert(a[i]);
    }
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        res = max(res, query(a[i]));
    }
    
    cout << res << endl;
    
    return 0;
}