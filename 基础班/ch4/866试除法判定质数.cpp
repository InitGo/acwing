//https://www.acwing.com/activity/content/problem/content/935/

#include<iostream>

using namespace std;

bool prime(int x)
{
    if(x<2) return false; 
    for(int i=2;i<=x/i;i++) //注意这里是小于等于 
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        if(prime(x)) cout << "Yes" << endl;
        else cout  << "No" << endl;
    }
    return 0;
}