//https://www.acwing.com/activity/content/problem/content/829/

#include <iostream>
using namespace std;

const int N = 100010;
int a[N],s[N];//全局变量，初始化为0，s[0]=0
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i] = s[i-1] + a[i]; //计算前缀和
    }
    
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        cout << s[r]-s[l-1]<< endl; //计算
    }
    return 0;
}