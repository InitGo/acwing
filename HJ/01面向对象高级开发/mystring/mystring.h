#ifndef MYSTRING
#define MYSTRING

#include <cstring>

class String
{
public:
    String(const char* c_str = 0);
    String(const String& str);
    String& operator = (const String& str);
    ~String();
    char* get_c_str() const {return m_data;}
private:
    char* m_data;
};

inline 
String::String(const char* c_str)
{
    if (c_str)
    {
        m_data = new char[strlen(c_str) + 1];
        strcpy(m_data, c_str); //不需要return？ 所谓构造函数就是给object里的data赋值
    }
    else
    {
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::~String()
{
    delete[] m_data;
}

inline
String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String&
String::operator=(const String& str)
{
    if (this->m_data == str.m_data) //有不同
    return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

#include <iostream>
using namespace std;

ostream&
operator << (ostream& os, const String& str)
{
    return os << str.get_c_str();
}

#endif