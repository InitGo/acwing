#include <iostream>
#include <cstring>
#include <thread>

using namespace std;

void func1()
{
    cout << "function: doit" << endl;
}

void func2()
{
    cout << "function:a" << endl;
}

int main()
{
    thread a(func1);
    thread b(func2);

    return 0;

}