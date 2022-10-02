#include<iostream>
#include<vector>
using namespace std;

void learn_for()
{
    vector<int> a ;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    for(auto &r:a)//如果要 写 迭代的内容，必须加引用
    {
        r *= 2;
    }

    for(auto r:a)//只读，可以不加
    {
        cout  << r << endl;
    }
}

void learn_function_reference(int &r)
{
    //当要传入 不支持拷贝的类类型 或 传入的值拷贝起来开销大
    //并且 在函数内不需要修改 形参 【例如，比较两个字符串的大小】
    //可以使用引用避免拷贝 ，引用只是起了个别名，开销小

    //当函数需要返回多个值：使用引用形参返回额外信息
    while(r!=0) r--;
}
int main()
{
    // learn_for();

    int r = 5;
    learn_function_reference(r);
    cout << r << endl;


    return 0;
}