#include <iostream>
#include <string>
#include "Complex.hpp"

void Complex::operator=(const Complex& a){
    re=a.re,im=a.im;}

std::istream& operator >> (std::istream& istream,Complex& z){
    std::string s,i("i"); int l,pos;
    istream>>s, l=s.length();
    switch (l) {
        case 1:{
            if(s==i){z.re=0,z.im=1;break;}
            else{z.re=stof(s),z.im=0;break;}}
        default:{
            if((pos=s.find("+"))!=std::string::npos){
                z.re=stof(s.substr(0,pos));
                if((pos+1)>=(l-pos)) z.im=1;
                else z.im=stof(s.substr(pos+1,l-pos));}
            else if((pos=s.rfind("-"))!=std::string::npos){
                z.re=stof(s.substr(0,pos));
                if((pos+1)>=(l-pos)) z.im=-1;
                else z.im=(-1)*stof(s.substr(pos+1,l-pos));}
            else if((pos=s.find("i"))!=std::string::npos){
                z.re=0,z.im=stof(s.substr(0,pos));}
            else{
                z.re=stof(s),z.im=0;}}}
    return istream;}

std::ostream& operator<<(std::ostream& os,Complex z){
    std::string s;    //format de iesire
    if(z.re){ s=std::to_string(z.re);
        if(z.im>0){s+=" + ",s+=std::to_string(z.im),s+='i';}
        else if(z.im<0){s+=std::to_string(z.im),s+='i';}}
    else{(z.im)?(s=std::to_string(z.im)+"i"):(s="0");}
    os<<s;
    return os;}
