#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int n;
int q[N], temp[N];

//合并两个有序子数组
void merge(int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r) 
        if (q[i] <= q[j]) temp[k ++ ] = q[i ++ ];
        else temp[k ++ ] = q[j ++ ];
        
    while (i <= mid) temp[k ++ ] = q[i ++ ];
    while (j <= r) temp[k ++ ] = q[j ++ ];
    
    for (int i = l, j = 0; i <= r; i ++ , j ++ ) q[i] = temp[j];
}

//递归版本
void merge_sort1(int q[], int l, int r)
{
    if (l >= r) return;
    
    int mid = l + r >> 1;
    merge_sort1(q, l, mid), merge_sort1(q, mid + 1, r);
    merge(l, mid, r);
}

//迭代版本
void merge_sort2(int q[])
{
    //step表示步长，倍进枚举step
    for (int step = 1; step <= n; step *= 2)
    {
        //offset表示需要合并的区间长度是 step的两倍
        int offset = step + step;
        //index表示下标。每次合并一个区间长度是offset的子区间，一个offset里有两个step
        for (int index = 0; index < n; index += offset) //起点从0开始
        {
            //在子区间中
            int l = index; //左端点
            int mid = min(index + step - 1, n - 1); //中点
            int r = min(index + offset - 1, n - 1); //右端点
            merge(l, mid, r);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> q[i];
    
    //merge_sort1(q, 0, n - 1);
    merge_sort2(q);
    for (int i = 0; i < n; i ++ ) cout << q[i] << ' ';
    cout << endl;
     
    return 0;
    
}