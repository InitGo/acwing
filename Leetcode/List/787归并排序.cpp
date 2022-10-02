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
    //i表示迭代层数,第i层,所有长度为i的小区间已经排好序
    //需要把成对的长度为i的小区间合并成长度为2i的区间, 这层做完以后下一层的i为2i了
    //当i=n,表示长度为n的区间已经排好序,所以i的取值范围为[1, n), i*= 2
    for (int i = 1; i < n; i *= 2 ) //层数从1到n-1
        //现在横向处理这一层的所有子区间
        //每次处理两个区间,左区间的起点为j号点, 右区间的起点为j+i号点
        //每次处理完两个区间后, j += i * 2
        for (int j = 0; j < n; j += 2 * i) //起点从0开始
        {
            int l = j; //左区间的起点
            int mid = min(j + i, n - 1); //右区间的起点
            int r = min(j + 2 * i - 1, n - 1); //右区间的终点
            merge(l, mid, r);
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