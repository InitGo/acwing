#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int ,bool> st;

vector<vector<int>> segs;
int main()
{
    vector<int> seg ;

    int a[2] = {100,101};
    
    seg.clear();
    seg.push_back(1);
    seg.push_back(3);
    segs.push_back(seg);

    seg.clear();
    seg.push_back(2);
    seg.push_back(6);
    segs.push_back(seg);
    
    seg.clear();
    seg.push_back(8);
    seg.push_back(10);
    segs.push_back(seg);

    seg.clear();
    seg.push_back(15);
    seg.push_back(18);
    segs.push_back(seg);

    int arr[2] = {41,42};
    vector<int> vi(begin(arr),end(arr));
    segs.push_back( vi );

    for(auto seg : segs)
    {
        cout << seg[0]<< ' ' <<seg[1] << endl;
    }
    return 0;
}