#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a1 = 123;
    long a2 = 123;
    long long a3 = 123;
    short a4 = 123;

    float b1 = 10.0;
    double b2 = 10.0;

    char c1 = 'a';

    cout << "sizeof int is : " << sizeof(a1) << endl;
    cout << "sizeof long is : " << sizeof(a2) << endl;
    cout << "sizeof long long is : " << sizeof(a3) << endl;
    cout << "sizeof short is : " << sizeof(a4) << endl;
    cout << "sizeof float is : " << sizeof(b1) << endl;
    cout << "sizeof double is : " << sizeof(b2) << endl;
    cout << "sizeof char is : " << sizeof(c1) << endl;

    int* a1_ = &(a1);
    char* c1_ = &(c1);
    cout << "sizeof *int is : " << sizeof(a1_) << endl;
    cout << "sizeof long is : " << sizeof(a2) << endl;
    cout << "sizeof long long is : " << sizeof(a3) << endl;
    cout << "sizeof short is : " << sizeof(a4) << endl;
    cout << "sizeof float is : " << sizeof(b1) << endl;
    cout << "sizeof double is : " << sizeof(b2) << endl;
    cout << "sizeof char* is : " << sizeof(c1_) << endl;

    return 0;
}