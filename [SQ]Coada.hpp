#ifndef _COADA_HPP
#define _COADA_HPP
#include "Vector.hpp"
class Coada:Vector{
 public:
    Coada(int dim=0);
    Coada(int dim, const Complex* c);
    Coada(const Vector& a);
    void operator =(const Coada&z);
    void adauga(Complex z);
    void sterge();
    Complex top()const override;
    bool empty()const override;
    ~Coada();
    friend std::istream& operator >> (std::istream& is,Coada& z);
    friend std::ostream& operator<<(std::ostream&os,const Coada&v);
};
#endif
