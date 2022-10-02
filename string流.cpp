#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template<typename out_type, typename in_type>
    out_type convert(const in_type& t){
        stringstream ssin;
        ssin << t;//向流中传值
        out_type result;//这里存储转换结果
        ssin >> result;//向result中写入值
        return result;
    }

void test1() {
    string str = "3 4 5 abc a a12 12a 888 9 10";
    stringstream ssin(str);
    
    string p;
    vector<int> num;
    
    while (ssin >> p) { //把stringstream中 内容输入到int p
        int val = convert<int>(p);
        num.push_back(val);
    }

    cout << "原字符串：" << str << endl;
    cout << "str转int：";
    for (int x : num) cout << x << ' ';
    cout << endl;
}

void test2() {
    string str = "3 4: 5 abc a a12 12a 888 9 10";
    stringstream ssin;
    ssin << str;
    int p;
    vector<int> num;
    
    while (ssin >> p) {
        num.push_back(p);
    }

    cout << "原字符串：" << str << endl;
    cout << "str转int：";
    for (int x : num) cout << x << ' ';
    cout << endl;
}

int main() {
    test1();
    test2();
    cout << "-------" << endl;

    string str10 = "3.40.5.600.9";
    stringstream ssin(str10);
    int p;
    while(ssin >> p)
    {
        cout << p << endl;
    }

    return 0;
}