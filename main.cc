#include <iostream>
#include "Coada.hpp"
#include "Stiva.hpp"

using namespace std;

/*
class Complex{
    float re,im;
 public:
    Complex():re(1),im(1){}
    Complex(float re,float im):re(re),im(im){}
    ~Complex(){}
    void operator =(const Complex& a){
        re=a.re,im=a.im;}
    friend istream& operator >> (istream& istream,Complex z){
        string s,i("i"); int l,pos;
        istream>>s, l=s.length();
        switch (l) {
            case 1:{
                if(s==i){z.re=0,z.im=1;break;}
                else{z.re=stof(s),z.im=0;break;}}
            default:{
                if((pos=s.find("+"))!=string::npos){
                    z.re=stof(s.substr(0,pos));
                    if((pos+1)>=(l-pos)) z.im=1;
                    else z.im=stof(s.substr(pos+1,l-pos));}
                else if((pos=s.rfind("-"))!=string::npos){
                    z.re=stof(s.substr(0,pos));
                    if((pos+1)>=(l-pos)) z.im=-1;
                    else z.im=(-1)*stof(s.substr(pos+1,l-pos));}
                else if((pos=s.find("i"))!=string::npos){
                    z.re=0,z.im=stof(s.substr(0,pos));}
                else{
                    z.re=stof(s),z.im=0;}}}}
    friend ostream& operator<<(ostream& os,Complex z){
        string s;    //format de iesire
        if(z.re){ s=to_string(z.re);
            if(z.im>0){s+=" + ",s+=to_string(z.im),s+='i';}
            else if(z.im<0){s+=to_string(z.im),s+='i';}}
        else{(z.im)?(s=to_string(z.im)+"i"):(s="0");}
        os<<s;
        return os;}
};

class Vector{
 protected:
    int dim;
    Complex* v;
 public:
    Vector(int dim = 0):dim(dim){(dim)?(v=new Complex[dim]):(v=nullptr);}
    Vector(int dim, const Complex* c):dim(dim),v(new Complex[dim]){
        for(int i=0;i<dim;i++) v[i]=c[i];}
    Vector(const Vector& a){this->~Vector();
        dim=a.dim,v=new Complex[a.dim];
        for(int i=0;i<dim;i++) v[i]=a.v[i];}
    virtual ~Vector(){if(dim)delete [] v,dim=0,v=nullptr;}
    friend Vector& operator >> (Vector& is,Complex z){
        Complex* newv=new Complex[is.dim+1];
        copy(is.v,is.v+is.dim,newv);
        newv[is.dim]=z;
        delete [] is.v;
        is.v=newv;
        ++is.dim;
        return is;
    }
    friend Vector& operator >> (Vector& is,Vector& v){
        Complex* newv=new Complex[is.dim+v.dim];
        copy(is.v,is.v+is.dim,newv);
        copy(v.v,v.v+v.dim,newv+is.dim);
        delete [] is.v;
        is.v=newv;
        is.dim+=v.dim;
        return is;
    }
    friend ostream& operator<<(ostream&os,const Vector&v){
        int i,l(v.dim);
        for(i=0;i<l;i++)os<<v.v[i]<<"; ";
        os<<endl;
        return os;
    }
    void operator =(const Vector&z){
        if(dim) delete []v;
        dim=z.dim;
        v=new Complex[dim];
        for(int i = 0;i < dim;i ++)v[i]=z.v[i];
    }
    void adauga(int pos, Complex z);
    void sterge(int pos);
    virtual Complex top()const=0;
    virtual bool empty()const=0;
};
void Vector::adauga(int pos, Complex z){
    if(pos>0 and pos<dim){
        Complex *newv=new Complex[dim+1];
        copy(v,v+pos,newv);
        newv[pos]=z;
        copy(v+pos,v+dim,newv+pos+1);
        delete []v;
        v=newv;}
    else if(pos>0 and pos==dim){
        Complex *newv=new Complex[dim+1];
        copy(v,v+pos,newv);newv[dim]=z;
        delete []v;
        v=newv;
    }
    else if(pos==0 ){
        Complex *newv=new Complex[dim+1];
        copy(v,v+dim,newv+1);
        newv[0]=z;
        delete []v;
        v=newv;}
    ++dim;}
void Vector::sterge(int pos){
    if(pos==0){
        if(dim>1){
            Complex *newv=new Complex[dim-1];
            copy(v+1,v+dim,newv);
            delete []v;
            v=newv;}
        else if(dim==1)
            this->~Vector();
    }
    else if(pos<dim-1){
        Complex *newv=new Complex[dim-1];
        copy(v,v+pos,newv);
        copy(v+pos+1,v+dim,newv+pos);
        delete []v;
        v=newv;}
    else if(pos==dim-1){
        Complex *newv=new Complex[dim-1];
        copy(v,v+pos,newv);
        delete []v;
        v=newv;
    }
    --dim;}
bool Vector::empty()const{cout<<"Exception occured"<<endl;}
Complex Vector::top()const{cout<<"Exception occured"<<endl;}
class Stiva:public Vector{
 public:
    Stiva(int dim=0):Vector(dim){}
    Stiva(int dim, const Complex* c):Vector(dim,c){}
    Stiva(const Vector& a):Vector(a){}
    void operator =(const Stiva&z){this->Vector::operator=(z);}
    void adauga(Complex z){Vector::adauga(dim,z);}
    void sterge(){Vector::sterge(dim-1);}
    Complex top()const override{assert(dim>=1);return v[dim-1];}
    bool empty()const override{if(v) return false;return true;}
    ~Stiva(){this->Vector::~Vector();}
};

class Coada:public Vector{
 public:
    Coada(int dim=0):Vector(dim){}
    Coada(int dim, const Complex* c):Vector(dim,c){}
    Coada(const Vector& a):Vector(a){}
    void operator =(const Coada&z){this->Vector::operator=(z);}
    void adauga(Complex z){Vector::adauga(dim,z);}
    void sterge(){Vector::sterge(0);}
    Complex top()const override{assert(dim>=1);return v[0];}
    bool empty()const override{if(v) return false;return true;}
    ~Coada(){this->Vector::~Vector();}
};
*/
int main()
{
    int obiecte;
    cin>>obiecte;
    Stiva* stive=new Stiva[obiecte];
    for(int i=0;i<obiecte;i++){
        cin>>stive[i];
        cout<<stive[i];
    }
    Coada* cozi=new Coada[obiecte];
    for(int i=0;i<obiecte;i++){
        cin>>cozi[i];
        cout<<cozi[i];
    }
    delete[]stive;
    delete[]cozi;
    return 0;
}
