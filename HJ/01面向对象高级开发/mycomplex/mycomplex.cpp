#include <iostream>
#include "mycomplex.h"

using namespace std;

int main()
{
    complex c1(0, 1);
    complex c2(4, 0);

    cout << c1 << endl;
    cout << c2 << endl;
    puts("");

    cout << c1 + c2 << endl;
    cout << c1 + 5 << endl;
    cout << 5 + c1 << endl;
    puts("");

    cout << c1 << endl;
    c1 += c2;
    cout << c1 << endl;

    return 0;
}