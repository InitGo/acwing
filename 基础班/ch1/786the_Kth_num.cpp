//https://www.acwing.com/activity/content/problem/content/820/
#include<iostream>
using namespace std;
const int N = 100010;
int q[N];

void quick_sort(int q[],int l,int r)
{
    if(l>=r) return;
    
    int t=q[(l+r)>>1] ,i=l-1,j=r+1;
    
    while(i<j)
    {
        do i++;while(q[i]<t);
        do j--;while(q[j]>t);
        if(i<j) swap(q[i],q[j]);
    }
    
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    
    for(int i=0;i<n;i++) scanf("%d",&q[i]);
    
    quick_sort(q,0,n-1);
    
    printf("%d",q[k-1]);
    
    return 0;
    
}