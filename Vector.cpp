#include <iostream>
#include <algorithm>
#include "Vector.hpp"
Vector::Vector(int dim):dim(dim){(dim)?(v=new Complex[dim]):(v=nullptr);}

Vector::Vector(int dim, const Complex* c):dim(dim),v(new Complex[dim]){
    for(int i=0;i<dim;i++) v[i]=c[i];}

Vector::Vector(const Vector& a){//this->~Vector();
    dim=a.dim,v=new Complex[a.dim];
    for(int i=0;i<dim;i++) v[i]=a.v[i];}

Vector::~Vector(){if(dim)delete [] v,dim=0,v=nullptr;}

Vector& operator >> (Vector& is,Complex z){
    Complex* newv=new Complex[is.dim+1];
    std::copy(is.v,is.v+is.dim,newv);
    newv[is.dim]=z;
    delete [] is.v;
    is.v=newv;
    ++is.dim;
    return is;
}

std::istream& operator >> (std::istream& is,Vector& z){
std::cout<<"Dati dim vector: ";
is>>z.dim;
z.v=new Complex[z.dim];
for(int i=0;i<z.dim;i++){
    Complex cmp;
    std::cout<<"Dati nr complex: ";
    is>>cmp;
    std::cout<<std::endl;
    z.v[i]=cmp;
}
}
Vector& operator >> (Vector& is,Vector& v){
    Complex* newv=new Complex[is.dim+v.dim];
    std::copy(is.v,is.v+is.dim,newv);
    std::copy(v.v,v.v+v.dim,newv+is.dim);
    delete [] is.v;
    is.v=newv;
    is.dim+=v.dim;
    return is;
}

std::ostream& operator<<(std::ostream&os,const Vector&v){
    int i,l(v.dim);
    for(i=0;i<l;i++)os<<v.v[i]<<"; ";
    os<<std::endl;
    return os;
}

void Vector::operator =(const Vector&z){
    if(dim) delete []v;
    dim=z.dim;
    v=new Complex[dim];
    for(int i = 0;i < dim;i ++)v[i]=z.v[i];
}

void Vector::adauga(int pos, Complex z){
    if(pos>0 and pos<dim){
        Complex *newv=new Complex[dim+1];
        std::copy(v,v+pos,newv);
        newv[pos]=z;
        std::copy(v+pos,v+dim,newv+pos+1);
        delete []v;
        v=newv;}
    else if(pos>0 and pos==dim){
        Complex *newv=new Complex[dim+1];
        std::copy(v,v+pos,newv);newv[dim]=z;
        delete []v;
        v=newv;
    }
    else if(pos==0 ){
        Complex *newv=new Complex[dim+1];
        std::copy(v,v+dim,newv+1);
        newv[0]=z;
        delete []v;
        v=newv;}
    ++dim;}

void Vector::sterge(int pos){
    if(pos==0){
        if(dim>1){
            Complex *newv=new Complex[dim-1];
            std::copy(v+1,v+dim,newv);
            delete []v;
            v=newv;}
        else if(dim==1)
            this->~Vector();
    }
    else if(pos<dim-1){
        Complex *newv=new Complex[dim-1];
        std::copy(v,v+pos,newv);
        std::copy(v+pos+1,v+dim,newv+pos);
        delete []v;
        v=newv;}
    else if(pos==dim-1){
        Complex *newv=new Complex[dim-1];
        std::copy(v,v+pos,newv);
        delete []v;
        v=newv;
    }
    --dim;}

bool Vector::empty()const{std::cout<<"Exception occured!!!"<<std::endl;}

Complex Vector::top()const{std::cout<<"Exception occured"<<std::endl;}

bool Vector::purImaginar(){
    bool bt=true;
    for(int i=0;i<dim;i++)
        if(v[i].real()!=0){
            bt=false
            ;
            break;
        }
    return bt;
}
