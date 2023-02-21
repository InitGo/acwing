#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& a)
{
    for (int i = 0; i < a.size(); i ++ )
        cout << a[i] << ' ' ;
    cout << endl;
}

int main()
{
    vector<int> a = {3, 2, 1};
    //sort(a.begin(), a.end());
    print(a);
    int t = next_permutation(a.begin(), a.end());
    print(a);
    cout << t << endl;
    
    return 0;
}