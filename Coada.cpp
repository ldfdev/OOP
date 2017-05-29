#include "Coada.hpp"
#include <assert.h>
Coada::Coada(int dim):Vector(dim){}

Coada::Coada(int dim, const Complex* c):Vector(dim,c){}

Coada::Coada(const Vector& a):Vector(a){}

void Coada::operator =(const Coada&z){this->Vector::operator=(z);}

void Coada::adauga(Complex z){Vector::adauga(dim,z);}

void Coada::sterge(){Vector::sterge(0);}

Complex Coada::top()const{assert(dim>=1);return v[0];}

bool Coada::empty()const{if(v) return false;return true;}

Coada::~Coada(){this->Vector::~Vector();}

std::istream& operator >> (std::istream& is,Coada& z){
    std::cout<<"Dati dim coada: ";
    is>>z.dim;
    z.v=new Complex[z.dim];
    for(int i=0;i<z.dim;i++){
        std::cout<<"Dati nr complex: ";
        is>>z.v[i];
        std::cout<<std::endl;

    }
}

std::ostream& operator<<(std::ostream&os,const Coada&v){
    int i,l(v.dim);
    for(i=0;i<l;i++)os<<v.v[i]<<"; ";
    os<<std::endl;
    return os;
}
