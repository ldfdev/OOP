#include <iostream>
#include <vector>
#include <exception>
using namespace std;
struct Data{int zi,luna,an;};

class Plata{
    double suma;
    Data data;
 public:
     static bool verificare(int,int,int);
     Plata(double d=1,Data dat={1,1,1901});
     virtual void afisare()=0;
     virtual ~Plata(){};
     Plata& operator=(const Plata& p);
     friend istream& operator>>(istream&,Plata&);
};
Plata::Plata(double d,Data dat):suma(d),data(dat){};
void Plata::afisare(){cout<<"in ziua de "<<data.zi<<" luna "<<data.luna<<" anul "<<data.an<<" s-a platit suma "<<suma<<endl;}
Plata& Plata::operator=(const Plata& p){suma=p.suma;data.zi=p.data.zi;data.luna=p.data.luna;data.an=p.data.an;return *this;};
istream& operator>>(istream& cin,Plata& p){
    int a,b,c;
    cout<<"Dati suma: ";
    cin>>p.suma;
    cout<<"\nDati data(zz/ll/aaaa): ";
    cin>>a>>b>>c;
    while(Plata::verificare(a,b,c)==false){
        cout<<"Date invalide.Reincercati";
        cout<<"\nDati data(zz/ll/aaaa): ";
        cin>>a>>b>>c;}
    p.data.zi=a,p.data.luna=b,p.data.an=c;
    return cin;};
bool Plata::verificare(int zi,int luna,int an){
    try{
        if((zi<1) or (zi>31))
            throw "Zi incorecta";
        if((luna<1) or (luna >12))
            throw "Luna incorecta";
        if((an<1901) or (an>2018))
            throw "An incorect";
    }catch(const char*e){
        cout<<"Exceptie: "<<e<<endl;return false;
    }
    return true;
}

class PlataCash:public Plata{
public:
    PlataCash(double d=1,Data dat={1,1,1901});
    PlataCash& operator=(const PlataCash&);
    friend istream& operator>>(istream&,PlataCash&);
    void afisare();
    ~PlataCash(){};
};
PlataCash::PlataCash(double d,Data dat):Plata(d,dat){};
PlataCash& PlataCash::operator=(const PlataCash& p){*this=p;return *this;}
istream& operator>>(istream& cin,PlataCash& p){cin>>static_cast<Plata&>(p);};
void PlataCash::afisare(){cout<<"\nPlata facuta cash, ";Plata::afisare();}

class PlataCec:public Plata{
 public:
    PlataCec(double d=1,Data dat={1,1,1901});
    PlataCec& operator=(const PlataCec&);
    friend istream& operator>>(istream&,PlataCec&);
    void afisare();
    ~PlataCec(){};
};
PlataCec::PlataCec(double d,Data dat):Plata(d,dat){};
PlataCec& PlataCec::operator=(const PlataCec& p){/**this=p;*/static_cast<Plata&>(*this)=p;return *this;}
istream& operator>>(istream& cin,PlataCec& p){cin>>static_cast<Plata&>(p);};
void PlataCec::afisare(){cout<<"\nPlata facuta cu cec, ";Plata::afisare();}

class PlataCard:public Plata{
    long int numarCard;
 public:
     PlataCard(int n=111222,double d=1,Data dat={1,1,1901});
     PlataCard& operator=(const PlataCard&);
     void cin(istream&);
     friend istream& operator>>(istream&,PlataCard&);
     ~PlataCard(){};
     void afisare();
};
PlataCard::PlataCard(int nr,double d,Data dat):Plata(d,dat),numarCard(nr){};
PlataCard& PlataCard::operator=(const PlataCard& p){Plata::operator=(p);numarCard=p.numarCard;return *this;}
void PlataCard::cin(istream&cin){cin>>(*this);};
istream& operator>>(istream& cin,PlataCard& p){cout<<"Dati nr card: ";cin>>p.numarCard;cin>>static_cast<Plata&>(p);};
void PlataCard::afisare(){cout<<"Card identificat: "<<numarCard<<endl;Plata::afisare();};

template<class T> class Gestiune{
 static int nrObj;
 int dim;
 vector<T*> obiecte;
 public:
     Gestiune();
     ~Gestiune();
     void citireObiecte(int);
     void afisareObiecte();
     Gestiune<T>& operator+=(T*&obj){obiecte.push_back(obj);++dim;++nrObj;};
     int Obiecte(){return nrObj;};
};
template<typename T>int Gestiune<T>::nrObj=0;
template<typename T>Gestiune<T>::Gestiune():dim(0){};
template<typename T>Gestiune<T>::~Gestiune(){for(auto&x:obiecte)delete x;obiecte.clear();dim=0;};
template<typename T>void Gestiune<T>::citireObiecte(int cate){
    dim=cate;
    nrObj=dim;
    for(int i=0;i<dim;i++){
        int s;
        cout<<"Alegeti tip de plata(cash 1/cec 2/card 3): ";
        cin>>s;
        switch (s) {
            case 2:{T* ob=new PlataCec();cin>>(*ob);obiecte.push_back(ob);break;}
            case 3:{T* ob=new PlataCard();dynamic_cast<PlataCard*>(ob)->cin(cin);obiecte.push_back(ob);break;}
            default:{T* ob=new PlataCash();cin>>(*ob);obiecte.push_back(ob);break;}
        }
    }
};
template<typename T>void Gestiune<T>::afisareObiecte(){
    int oby;
    cout<<"Alegeti ce afisati: toate 0/cash 1/cec 2/card 3: ";
    cin>>oby;
    for(int i=0;i<dim;i++)
        switch (oby) {
            case 3:{
        if(dynamic_cast<PlataCard*>(obiecte[i])!=nullptr)
            obiecte[i]->afisare();break;}
            case 2:{
        if(dynamic_cast<PlataCec*>(obiecte[i])!=nullptr)
            obiecte[i]->afisare();break;}
            case 1:{
        if(dynamic_cast<PlataCash*>(obiecte[i])!=nullptr)
            obiecte[i]->afisare();break;}
            default:{obiecte[i]->afisare();break;}
        }
};

template<> class Gestiune<char*>;
int main()
{
int n;
Gestiune<Plata> G;
cout<<"Cate tranzactii contine ledger_ul? ";
cin>>n;
G.citireObiecte(n);
G.afisareObiecte();
Plata* pc(new PlataCard);
dynamic_cast<PlataCard*>(pc)->cin(cin);
G+=pc;
G.afisareObiecte();
return 0;
}
template<> class Gestiune<char*>{
    static int nrObj;
    int dim;
    vector<char*> posesoriCarduri;
    public:
        Gestiune():dim(0){};
        ~Gestiune(){for(auto&x:posesoriCarduri)delete []x;dim=0;nrObj=0;};
        void citireObiecte(int n){char* o=new char[20];cin>>o;/*scanf("%20s",o);*/posesoriCarduri.push_back(o);};
        void afisareObiecte(){for(auto&x:posesoriCarduri)cout<<x;};
        int Obiecte(){return nrObj;};
};
int Gestiune<char*>::nrObj=0;
