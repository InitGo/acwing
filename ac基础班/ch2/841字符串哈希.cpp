//https://www.acwing.com/activity/content/problem/content/891/
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL; //用ULL存哈希值，省去mod这一步

const int N = 100010, P = 131;//P进制经验值取131

int n, m; //字符串长度为n ， m个询问
char str[N]; //存字符串
ULL h[N], p[N]; 
//h[i]存 str的前i个字符组成的字串 的哈希值，
//p[i] 存P的i次方 方便直接读取，避免多次计算

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    scanf("%d%d", &n, &m);
    scanf("%s", str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        h[i] = h[i - 1] * P + str[i]; //计算字符串前缀哈希
        p[i] = p[i - 1] * P; //计算P次方算子
    }

    while (m -- )
    {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }

    return 0;
}



// #include<iostream>

// using namespace std;

// typedef unsigned long long   ull;
// const int N = 100010,P = 131;

// int n,m;
// char str[N];
// ull h[N],p[N];

// ull get(int l,int r)
// {
//     return (h[r]-h[l-1]*p[r-l+1]);
// }

// int main()
// {
//     cin >> n >> m;
//     cin >> str+1;
    
//     p[0] = 1;
//     for(int i=1;i<=n;i++)
//     {
//         h[i] = h[i-1]*P + str[i];
//         p[i] = p[i-1] *P;
//     }
//     while(m--)
//     {
//         int l1,r1,l2,r2;
//         cin >> l1 >> r1 >> l2 >> r2;
//         if(get(l1,r1)==get(l2,r2)) cout << "Yes" << endl;
//         else cout << "No" << endl;
//     }
//     return 0;
    
    
// }