#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
pair<int, int> segs[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        cin >> l >> r;
        segs[i] = {l, r};
    }
    
    sort(segs, segs + n);
    
    priority_queue<int, vector<int>, greater<int>> heap;
    
    for (int i = 0; i < n; i ++ )
    {
        auto seg = segs[i];
        int l = seg.first, r = seg.second;

        if (heap.size() && heap.top() < l) heap.pop();
        heap.push(r);
    }
    cout << heap.size() <<  endl;
    return 0;
}