#ifndef COMPLEX
#define COMPLEX

class complex
{
public:
    complex(double r = 0, double i = 0): re(r), im(i) {};
    double real() const {return re;}
    double imag() const {return im;}
    complex& operator += (const complex x);

private:
    double re, im;

    friend complex& __doapl(complex*, const complex&);
};

inline complex&
__doapl(complex* ths, const complex& x)
{
    ths->re += x.re;
    ths->im += x.im;
    return *ths;
}

inline complex&
complex::operator += (const complex x)
{
    return __doapl(this, x);
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex(x.real() + y.real(), x.imag() + y.imag());
}

inline complex
operator + (double x, const complex& y)
{
    return complex(x + y.real(), y.imag());
}

inline complex
operator + (const complex& x, double y)
{
    return complex(x.real() + y, x.imag());
}

#include <iostream>

using namespace std;

ostream& operator << (ostream& os, const complex x)
{
    os << '(' << x.real() << ',' << x.imag() << ')';
    return os;
}

#endif