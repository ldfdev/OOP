#include "Stiva.hpp"
#include <assert.h>
#include <iostream>
Stiva::Stiva(int dim):Vector(dim){}

Stiva::Stiva(int dim, const Complex* c):Vector(dim,c){}

Stiva::Stiva(const Vector& a):Vector(a){}

void Stiva::operator =(const Stiva&z){this->Vector::operator=(z);}

void Stiva::adauga(Complex z){Vector::adauga(dim,z);}

void Stiva::sterge(){Vector::sterge(dim-1);}

Complex Stiva::top()const{assert(dim>=1);return v[dim-1];}

bool Stiva::empty()const{if(v) return false;return true;}


std::istream& operator >> (std::istream& is,Stiva& z){
    std::cout<<"Dati dim stiva: ";
    is>>z.dim;
    z.v=new Complex[z.dim];
    for(int i=0;i<z.dim;i++){
        Complex cmp;
        std::cout<<"Dati nr complex: ";
        is>>z.v[i];
        std::cout<<std::endl;
    }
}

std::ostream& operator<<(std::ostream&os,const Stiva&v){
    int i,l(v.dim);
    for(i=0;i<l;i++)os<<v.v[i]<<"; ";
    os<<std::endl;
    return os;
}
Stiva::~Stiva(){this->Vector::~Vector();}
