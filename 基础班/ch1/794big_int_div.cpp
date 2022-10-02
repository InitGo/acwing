//https://www.acwing.com/activity/content/problem/content/828/

#include <bits/stdc++.h>

using namespace std;

vector<int> A;

//C是商 r是余数
//这里r的用法是 引用 ， 传入指针以保证改变能影响外面，这是常用的做法，引用简化了这种做法的形式
//给传入的参数起了一个别名r，对r的操作何以改变传入的参数的值
vector<int> div(vector<int> A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i  = A.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b; //12345
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    
    int r = 0;
    auto C = div(A, b, r);
    for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];
    cout << endl << r << endl;
    
    return 0;
}