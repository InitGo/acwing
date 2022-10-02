#ifndef __MyCOMPLEX__
#define __MyCOMPLEX__

class ostream;
class complex;

complex& __doapl (complex* ths, const complex& r);

class complex //declaration
{
public:
    complex (double r = 0, double i = 0) : re(r), im(i) {}
    complex& operator+= (const complex&);
    double real() const {return re;}
    double imag() const {return im;}
    
private:
    double re, im;
};

#endif

//0. class guard
//1. constructor: public / 没有返回类型 / initialization list / overloading
//2. const member function: read data only
//3. pass by value / reference(to const)
//4. return bu value / reference(to const)
//5. friend : friend functions can get data directly / 相同class的各个objects互为friends
