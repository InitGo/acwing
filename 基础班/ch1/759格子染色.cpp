#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<pair<int,int>,pair<int,int> > PII;
typedef pair<int,pair<int,int> > PI;

vector< PII > rows,cols; //记录按行按列插入操作
vector< PI > r,c; //记录每一 行/列 维护的区间
vector<int> alls;
int res;
bool cmp1(PII a, PII b)
{
    if(a.first!=b.first) return a.first<b.first;
    else return a.first.second < b.first.second;
}

bool cmp2(PII a, PII b)
{
    if(a.first.second!=b.first.second) return a.first.second<b.first.second;
    else return a.first.first < b.first.first;
}

void merge_rows()
{
    sort(rows.begin(),rows.end(),cmp1);
    for(auto row:rows )
    {
        
    }
}

void merge_cols()
{

}
int main()
{
    int x1,y1,x2,y2,n;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1==x2)  //按行
        {
            if(y1<y2) rows.push_back({{x1,y1},{x2,y2}});
            else rows.push_back({{x2,y2},{x1,y1}});
        }
        
        else if(y1==y2)//按列
        {
            if(x1<x2) cols.push_back({{x1,y1},{x2,y2}}); 
            else cols.push_back({{x2,y2},{x1,y1}});
        }
        
        
        else cols.push_back({{x1,y1},{x2,y2}}); 

        alls.push_back(x1);
        alls.push_back(x2);
        alls.push_back(y1);
        alls.push_back(y1);

    }

    merge_rows();
    merge_cols();

}