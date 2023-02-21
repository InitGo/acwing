#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    
    while (n -- ) 
    {
        int x;
        cin >> x;
        heap.push(x);
    }
    
    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        int c = a + b;
        res += c;
        heap.push(c);
    }
    cout << res << endl;
    return 0;
}