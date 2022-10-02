//https://www.acwing.com/activity/content/problem/content/831/

#include<iostream>

using namespace std;

const int N=100010;

int a[N],b[N];

void insert(int l,int r,int c)
{
    b[l] += c;
    b[r+1] -= c;
}

int main()
{
    int n,m,t;
    cin >> n >> m;
    for(int i =1;i<=n;i++) 
    {
        cin >> t;
        insert(i,i,t);
    }
    int l,r,c;
    while(m--)
    {
        cin >> l >> r >> c;
        insert(l,r,c);
    }
    
    for(int i = 1;i<=n ;i++) 
    {
        a[i] = a[i-1] + b[i];
        cout << a[i] << ' ';
    }
    return 0;    
}