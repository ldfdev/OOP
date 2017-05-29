#ifndef Complex_hpp
#define Complex_hpp
#include <iostream>
class Complex{
    float re,im;
 public:
    Complex():re(1),im(1){}
    Complex(float re,float im):re(re),im(im){}
    ~Complex(){}
    void operator =(const Complex& a);
    friend std::istream& operator >> (std::istream& istream,Complex& z);
    friend std::ostream& operator<<(std::ostream& os,Complex z);
    float real(){return re;}
};
#endif
