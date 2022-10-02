#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 70;

int n;
int w[N];
int sum, length;
bool st[N];

//从前往后枚举每个大木u， 当前大木长度为cur， 当前从start开始枚举
bool dfs(int u, int cur, int start)
{
    if (u * length == sum) return true; //如果大木数量u*length等于总长度，找到一组合法解 return true
    if (cur == length) return dfs(u + 1, 0, 0); //当前大木的长度达标，要开新的大木

    //枚举每个小木
    for (int i = start; i < n; i ++ ) //剪枝3-1:i从start开始
    {
        if (st[i]) continue; 
        if (cur + w[i] > length) continue; //剪枝4：可行性剪枝

        st[i] = true;
        if (dfs(u, cur + w[i], i + 1)) return true;  //为什么这里是从i+1继续搜索，而不是start？
        st[i] = false;

        // 执行到这 dfs(u, cur + w[i], i + 1) 为 false: 说明当前木棍搜索失败了

        //剪枝3-3，3-4如果当前小木是大木的第一个或者最后一个，方案失败
        if (!cur || cur + w[i] == length) return false;
        
        //剪枝3-2：排好序，所有长度相同的都挨在一起，直接略过长度相同的小木
        int j = i;
        while (j < n && w[j] == w[i]) j ++ ;
        i = j - 1;
    }

    return false;
}

int main()
{
    while (cin >> n, n)
    {
        memset(st, 0, sizeof st);
        sum = 0;

        for (int i = 0; i < n; i ++ )
        {
            cin >> w[i];
            sum += w[i];
        }

        //剪枝2：优化搜索顺序
        sort(w, w + n);
        reverse(w, w + n);

        length = 1; //从小到大枚举大木的长度 【也可以从输入数据的最大值开始枚举】
        while (true)
        {
            //剪枝1：如果length能整除sum，才可能是合法方案
            if (sum % length == 0 && dfs(0, 0, 0))  
            {
                cout << length << endl;
                break;
            }
            length ++ ;
        }
    }

    return 0;
}