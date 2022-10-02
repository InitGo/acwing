#include<iostream>

using namespace std;

class Person
{
private:
    /* data */
    int age,height;
    double money;
    string book[100];

public:
    string name;
    void say()
    {
        cout << "I'm " << name << endl; 
    }
 
};
