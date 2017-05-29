#ifndef Vector_hpp
#define Vector_hpp
#include "Complex.hpp"
class Vector{
 protected:
    int dim;
    Complex* v;
 public:
    Vector(int dim = 0);
    Vector(int dim, const Complex* c);
    Vector(const Vector& a);
    virtual ~Vector();
    friend Vector& operator >> (Vector& is,Complex z);
    friend std::istream& operator >> (std::istream& is,Vector& z);
    friend Vector& operator >> (Vector& is,Vector& v);
    friend std::ostream& operator<<(std::ostream&os,const Vector&v);
    void operator =(const Vector&z);
    void adauga(int pos, Complex z);
    void sterge(int pos);
    virtual Complex top()const=0;
    virtual bool empty()const=0;
    bool purImaginar();
};

#endif
