//https://www.acwing.com/activity/content/problem/content/832/

#include <iostream>
using namespace std;
const int N=1010;
int a[N][N],b[N][N];

void insert(int x1,int y1,int x2 ,int y2 ,int c)
{
    b[x1][y1] += c;
    b[x2+1][y1] -=c;
    b[x1][y2+1] -=c;
    b[x2+1][y2+1] +=c;
}


int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            insert(i,j,i,j,a[i][j]);
           
        }
    }
        
    
    while(q--)
    {
        int x1,x2,y1,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1,y1,x2,y2,c);
        
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=a[i][j-1] + a[i-1][j] - a[i-1][j-1] + b[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
            
      return 0 ;     
    
}