#ifndef MYCOMPLEX
#define MYCOMPLEX

class complex
{
public:
    //构造函数
    complex(double r = 0, double i = 0): re(r), im(i) { } //为什么ctor不需要const来传？ 也可以，开销一样
    //成员函数
    complex& operator += (const complex&); //为什么这里不需要写形参？ 只是prototype
    double real() const{return re;}
    double imag() const{return im;}

private:
    double re, im;

    friend complex& __doapl(complex *,const complex& );
};

inline complex&
__doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex&
complex::operator+= (const complex& r)
{
    return __doapl(this, r);
}

//也可以把它定义成global function
inline double
real (const complex& x)
{
    return x.real();
}

inline double
imag (const complex& x)
{
    return x.imag();
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex(x.real() + real(y), imag(x) + imag(y));
}

inline complex
operator + (const complex& x, double y)
{
    return complex(real(x) + y, imag(x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex(x + real(y), imag(y));
}

#include<iostream>
using namespace std;
ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real(x) << ',' << imag(x) << ')';
}


#endif