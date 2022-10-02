//https://www.acwing.com/activity/content/problem/content/825/

//易错点： 读入string到vector注意是 a[i]-'0'
#include <bits/stdc++.h>

using namespace std;

vector<int> A, B;

vector<int> add(vector<int>& a, vector<int>& b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

int main()
{
    string a, b;
    cin >> a >> b; //12345
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
    
    auto C = add(A, B);
    
    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl;
    return 0;
}