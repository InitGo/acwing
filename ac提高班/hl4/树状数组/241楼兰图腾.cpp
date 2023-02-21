#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int n;
int y[N], tr[N];
int Greater[N], Lower[N]; 

int lowbit(int x)
{
    return x & -x;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> y[i]; //读入每个点的y值
    
    //  从右往左，预处理统计
    //  Lower[i]表示，第i个数t=y[i]前面有Lower[i]个小于t的数字
    //  Greater[i]表示，第i个数t=y[i]前面有Greater[i]个大于t的数字
    //  树状数组-原始数组：A[i]表示值为i的数字有A[i]个，通过add来慢慢丰富
    //  对于样例: 1 5 3 2 4, A[1] = 1, A[5] = 1, A[3] = 1, A[2] = 1, A[4] = 1。
    for (int i = 1; i <= n; i ++ )
    {
        int t = y[i];  // 拿出来第i个数：t
        Lower[i] = sum(t - 1); //计算[1, t - 1]范围内的数字总个数
        Greater[i] = sum(n) - sum(t); //计算[t + 1, n]范围内的数字总个数
        
        add(t, 1); //丰富A数组：值为t的数字的个数+1
    }
    
    // 从右往左，预处理统计 + 计算答案 合并到一个for循环里了
    memset(tr, 0, sizeof tr);
    LL resA = 0, resV = 0;  //答案可能爆int，用LL存
    // 从右往左，预处理统计
    for (int i = n; i; i -- )
    {
        int t = y[i];  // 拿出来第i个数：t
        resA += Lower[i] * (LL)(sum(t - 1)); 
        resV += Greater[i] * (LL)(sum(n) - sum(t));
        
        add (t, 1);
    }
    
    cout << resV << ' ' << resA << endl;
    
    return 0;
}