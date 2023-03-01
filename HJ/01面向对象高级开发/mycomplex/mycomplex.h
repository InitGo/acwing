#ifndef __complex__
#define __complex__

// ----------------------forward declaration
class complex;

// ----------------------class declaration
class complex
{
public:
    complex(double r = 0, double i = 0) : re(r), im(i) {}

    complex& operator+= (const complex&);
    complex& operator-= (const complex&);
    complex& operator*= (const complex&);
    complex& operator/= (const complex&);

    double real() const {return re;}
    double imag() const {return im;}

private:
    double re, im;

    friend complex& __doapl(complex *, const complex&);
    // friend complex& __doami(complex *, const complex&);
    friend complex& __doaml(complex *, const complex&);
};

// ----------------------class definition

inline complex& __doapl(complex* ths, const complex& x)
{
    ths->re += x.re;
    ths->im += x.im;
    return *ths;
}

// inline complex& __doami(complex* ths, const complex& x)
// {
//     ths->re -= x.re;
//     ths->im -= x.im;
//     return *ths;
// }

inline complex& __doaml(complex* ths, const complex& x)
{
    double f = ths->re * x.re - ths->im * x.im;
    ths->im = ths->re * x.im + ths->im * x.re;
    ths->re = f;
    return *ths;
}


inline complex&
complex::operator+=(const complex& x)
{
    return __doapl(this, x);
}

inline complex&
complex::operator-=(const complex& x)
{
    this->re -= x.re;
    this->im -= x.im;
    return *this;
}

inline complex&
complex::operator*=(const complex& x)
{
    return __doaml(this, x);
}

// +  ---------
inline 
complex operator+ (const complex& x, const complex& y)
{
    return complex(x.real() + y.real(), x.imag() + y.imag());
}

inline 
complex operator+ (const complex& x, const double y)
{
    return complex(x.real() + y, x.imag());
}

inline 
complex operator+ (const double x, const complex& y)
{
    return complex(x + y.real(), y.imag());
}

// -  ---------
inline 
complex operator- (const complex& x, const complex& y)
{
    return complex(x.real() - y.real(), x.imag() - y.imag());
}

inline 
complex operator- (const complex& x, const double y)
{
    return complex(x.real() - y, x.imag());
}

inline 
complex operator- (const double x, const complex& y)
{
    return complex(x - y.real(), 0 - y.imag());
}

// *  ---------
inline 
complex operator* (const complex& x, const complex& y)
{
    return complex(x.real() * y.real() - x.imag() * y.imag(),
    x.real() * y.imag() + x.imag() * y.real());
}

inline 
complex operator* (const complex& x, const double y)
{
    return complex(x.real() * y, x.imag() * y);
}

inline 
complex operator* (const double x, const complex& y)
{
    return complex(x * y.real(), x * y.imag());
}


#include <iostream>
using namespace std;

ostream& operator<< (ostream& os, const complex x)
{
    os << "(" << x.real() << ", " << x.imag() << ")";
    return os; 
}


#endif