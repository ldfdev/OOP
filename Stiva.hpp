#ifndef _STIVA_HPP
#define _STIVA_HPP
#include "Vector.hpp"
class Stiva:Vector{
 public:
    //using Vector::>>;
    Stiva(int dim=0);
    Stiva(int dim, const Complex* c);
    Stiva(const Vector& a);
    void operator =(const Stiva&z);
    void adauga(Complex z);
    void sterge();
    Complex top()const override;
    bool empty()const override;
    ~Stiva();
    friend std::istream& operator >> (std::istream& is,Stiva& z);
    friend std::ostream& operator<<(std::ostream&os,const Stiva&v);
};

#endif
