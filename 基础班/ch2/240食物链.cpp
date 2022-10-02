//https://www.acwing.com/activity/content/problem/content/887/
#include<iostream>

using namespace std;
const int N = 50010;
int p[N];

int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

//a吃b，返回true
bool eat(int a,int b,int n)
{
    a = find(a),b = find(b) ;
    if((a==n+1 && b == n+2)||(a==n+2 && b ==n+3) || ( a==n+3 && b==n+1) ) return true;
    else return false;
}

bool is_legal(int a,int b,int n)
{
    if(a>n || b > n) return false;
    else return true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    
    for(int i = 1;i<=n;i++)
    {
        p[i] = i;
    }
    
    int op,a,b,res = 0;
    while(m--)
    {
        cin >> op >> a >> b;
        
        if(!is_legal(a,b,n))
        {
            res ++;
            continue;
        }
        
        
        if(op ==1)
        {
            //先判断有没有归类
            //都归类了 
            if(find(a)>n && find(b)>n)  
            {
                if(find(a)!=find(b))
                {
                    res++;
                    continue;
                }
            }
            //a归类了，b没有
            else if(find(a)>n && find(b)<=n)
            {
                p[find(b)] = find(a);
            }
            //b归类了，a没有
            else if(find(b)>n && find(a)<=n)
            {
                p[find(a)] = find(b);
            }
            //都没归类
            else if(find(a)<=n && find(b)<=n)
            {
                p[find(a)] = n+1;
                p[find(b)] = n+1;
            }

        }
        else // op = 2
        {
            if( !eat(a,b,n) )
            {
                res++;
                continue;
            }
            
        }
        
    }
    cout << res << endl;
    return 0;
    
}