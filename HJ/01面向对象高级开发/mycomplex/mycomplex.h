#ifndef COMPLEX
#define COMPLEX

class complex
{
public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}
    complex& operator+= (const complex& r);

    double get_real() const {return re;}
    double get_imag() const {return im;}

private:
    double re, im;
    friend complex& __doapl(complex* ths, const complex& r);
};

inline
complex& __doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline
complex& complex::operator+=(const complex& r)
{
    return __doapl(this, r);
}

inline
complex operator+ (const complex& x, const complex& y)
{
    return complex(x.get_real() + y.get_real(), x.get_imag() + y.get_imag());
}

inline
complex operator+ (const double x, const complex& y)
{
    return complex(x + y.get_real(), y.get_imag());
}

inline
complex operator+ (const complex& x, const double y)
{
    return complex(x.get_real() + y, x.get_imag());
}

#include <iostream>
using namespace std;
ostream& operator<<(ostream& os, const complex& r)
{
    os << '[' << r.get_real() << ',' << r.get_imag() << ']';
    return os;
}

#endif