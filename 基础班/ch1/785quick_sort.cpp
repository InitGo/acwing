//https://www.acwing.com/activity/content/problem/content/819/



#include<iostream>

using namespace std;
const int N = 100010;
int q[N];
void quick_sort(int q[],int l ,int r)
{
    if(l>=r) return; //确定返回的边界条件
    int x=q[(l+r)/2],i=l-1,j=r+1; //取参考值x，和左右端点
    
    while(i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
    
}
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i < n;i++ ) scanf("%d",&q[i]);
    
    quick_sort(q,0,n-1);
    
    for(int i =0;i<n;i++) printf("%d ",q[i]);
    
    return 0;
}