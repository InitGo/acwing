//https://www.acwing.com/activity/content/problem/content/1004/

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int a[N]; //存读入的数组
int q[N];   //q[i]存长度为i的所有最长上升子序列的结尾的最小值 

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]); //读入a[i]

    int len = 0; //存结果
    for (int i = 0; i < n; i ++ ) //遍历a[i]
    {
        int l = 0, r = len; //找最大的小于a[i]的结尾
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1); //更新最长上升子序列的长度
        q[r + 1] = a[i]; //把a[i]接到符合条件的结尾q[r]后面，更新q[r+1]
    }

    printf("%d\n", len);

    return 0;
}