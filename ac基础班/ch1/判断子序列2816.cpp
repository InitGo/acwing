//https://www.acwing.com/activity/content/problem/content/2981/

#include<iostream>

using namespace std;
const int N =100010;
int a[N],b[N];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i =0;i<n;i++) scanf("%d",&a[i]);
    for(int i =0;i<m;i++) scanf("%d",&b[i]);

    int i=0;
    for(int j=0;j<m;j++)
    {
        if(b[j]==a[i]) i++;
    }
    if(i<n) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;

}