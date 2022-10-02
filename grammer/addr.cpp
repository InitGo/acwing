#include<iostream>
using namespace std;

char a,b;

int main()
{
    char c='a',d;
    cout << &c <<endl;
    cout << (void*)&c <<endl;
    cout << (void*)&d <<endl;

    cout << (void*)&a <<endl;
    cout << (void*)&b <<endl;

    return 0 ;
}
