#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int i = 0;
    while (cin >> a >> b)
    {
        cout << "第" << ++ i << "组测试数据:" << "a + b = " << a + b << endl;
    }
    return 0;
}