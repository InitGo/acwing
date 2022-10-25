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
complex operator+(const complex& a, const complex& b)
{
    return complex(a.get_real() + b.get_real(), a.get_imag() + b.get_imag());
}

#include <iostream>
using namespace std;

ostream& operator << (ostream& os, const complex& r)
{
    return os << '(' << r.get_real() << ',' << r.get_imag() <<  ')'; 
}

#endif