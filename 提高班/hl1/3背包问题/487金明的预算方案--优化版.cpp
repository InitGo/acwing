#include <stdio.h>
#include <cstring>
#include<stack>
#include<deque>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>
#include <iostream>
#include <queue>
#include<set>
#include <map>
#define For(i, x, y) for(int i=x;i<=y;i++)
#define _For(i, x, y) for(int i=x;i>=y;i--)
#define Mem(f,x) memset(f,x,sizeof(f))
#define Sca(x) scanf("%d", &x)
#define Sca2(x,y) scanf("%d%d",&x,&y)
#define Sca3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%lld",&x)
#define Pri(x) printf("%d\n",4 x)
#define Prl(x) printf("%lld\n",x)
#define LL long long
#define ULL unsigned long long
using namespace std;
const int INF = 0x3f3f3f3f;
template<typename T> void read(T &x)
{
    x = 0;char ch = getchar();LL f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n,m;
int dp[70][42009];

struct node
{
    int v;
    int w;
};

node x[70];
node y[70][70];
int sz[70];
int a,b,c;

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        b=a*b;
        if(c==0)
        {
            x[i].v=a;
            x[i].w=b;

        }
        else
        {
            y[c][++sz[c]].v=a;
            y[c][sz[c]].w=b;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(x[i].v==0)//如果为0则代表这个编号是附件，在别的组里直接跳过，
        {
            for(int j=0;j<=m;j++)
                dp[i][j]=dp[i-1][j];
            continue;
        }
        for(int j=m;j>=0;j--)//优先处理只选择了主键的，然后dp[i][j]里但凡数据不是0的，都是选择了主件的；
        {
            if(j==x[i].v)
            {
                dp[i][j]=max(dp[i][j],x[i].w);
            }
            if(j>x[i].v&&dp[i-1][j-x[i].v]>0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-x[i].v]+x[i].w);
            }
        }
        for(int k=1;k<=sz[i];k++)//枚举所有附件，对DP[i][j-y[i][k].v](代表选择了主件)中不为0的数据进行处理
        {
            for(int j=m;j>=0;j--)
            {
                if(j-y[i][k].v>=0&&dp[i][j-y[i][k].v]>0)
                    dp[i][j]=max(dp[i][j],dp[i][j-y[i][k].v]+y[i][k].w);
            }
        }
        for(int j=0;j<=m;j++)//最后把不选主件的数据处理出来，顺序不可换，保证能识别有没有选择主键
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
    }
    int res=0;

        for(int j=0;j<=m;j++)
        {
            res=max(dp[n][j],res);
        }

    cout<<res<<endl;
    return 0;
}