//https://www.acwing.com/activity/content/problem/content/824/
#include<iostream>
#include<math.h>

using namespace std;

double sqrt3(double x)
{
    double l,r;
    int flag=1;
    if(x<0){
        x=abs(x);
        flag = -1;
    }
    
    if(x<=1){
        l=0,r=1;
    }else{
       l=0,r=x;
    }
    
    while((r-l)>1e-8)
    {
        double mid = (l + r)/2;
        if(mid*mid*mid >= x) r=mid;
        else l=mid;
    }
    l= flag*l ;
    return l;
    
}

int main()
{
    double x,y;
    cin >> x;
    y = sqrt3(x);
    printf("%.6lf\n",y);

    
    return 0;
}