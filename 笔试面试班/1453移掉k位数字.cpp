#include <iostream>

using namespace std;

int main()
{
    string num;
    int k;
    cin >> num >> k;
    
    string ans = "0"; //先存一个先导0，避免答案字符串长度为0的条件判断
    for (int i = 0; i < num.size(); i ++ )
    {
        while (k && ans.back() > num[i])
        {
            ans.pop_back();
            k -- ;
        }
        ans += num[i];
    }

    while (k -- ) ans.pop_back(); //用掉剩下的移除机会

    int i = 0; //排除先导0
    while (i < ans.size() && ans[i] == '0') i ++ ;
    
    if (i == ans.size()) cout << "0" << endl; //如果为ans全0，while循环因为i==ans.size()才停下来，输出一个0
    else cout << ans.substr(i) << endl; //否则输出从第i位开始的子串
    
    return 0;
}