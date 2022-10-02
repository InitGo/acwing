//https://www.acwing.com/activity/content/problem/content/836/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 300010;

int a[N],s[N] ;//计算前缀和要用

vector<PII> add, query; //存读进来的数对
vector<int> alls; //所有要用到的大数字都存在alls

int find(int x)//输入大数，返回其下标，从1开始
{
    int l = 0,r=alls.size()-1;
    while(l<r)
    {
        int mid = (l+r)/2;
        if(alls[mid]>=x ) r=mid;
        else l = mid+1;
    }
    return l+1;
}


int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        alls.push_back(x);


    }
    for(int i=0;i<m;i++)
    {
        int l ,r;
        cin >> l >> r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    
    //alls排序 去重 ，为二分索引下标做准备
    sort(alls.begin(), alls.end()); 
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for(auto item : add)
    {
        int id = find(item.first);
        a[id]+= item.second;
    }

    //为什么计算前缀和是用 alls.size() 而不是 add.size() ??
    //alls 中存的是 x,l,r , 是用到的所有大数字，所以a[i] 中的下标i也对应了所有 大数字-->(离散化)-->下标 
    //这里的 alls a s都是配套长度的 
    for(int i = 1;i <= alls.size(); i ++ ) s[i] = s[i - 1] + a[i];

    for(auto item : query)
    {
        int l ,r;
        l= find(item.first);
        r= find(item.second);

        cout << s[r] - s[l - 1] << endl;
        
    }

    return 0;
}