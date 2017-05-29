#ifndef MATRICE_HPP_INCLUDED
#define MATRICE_HPP_INCLUDED
#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/LU>
#include <Eigen/Core>

struct Linie {
        std::vector<double> vv;
        double& operator [] (const int i1){return vv[i1];}
};
class Matrice{
private:
    int lin;
    int col;
    std::vector<Linie> v;
public:
    Matrice(int x = 4, int y = 4);
    Matrice(int, int, double);
    //Matrice(int, int, const std::vector<Linie>&&);
    Matrice(const Matrice&);
   ~Matrice();
    void citire(std::istream&);
    void afisare();
    void reactualizare(int,int,double);
    friend int nrlinii(const Matrice&);
    friend int nrcoloane(const Matrice&);
    friend int nrelemente(const Matrice&);

    Matrice operator = (const Matrice&);
    struct Linie& operator [] (const int&);
    friend Matrice operator + (Matrice&, Matrice&);
    friend Matrice operator + (Matrice&);
    friend Matrice operator - (Matrice&, Matrice&);
    friend Matrice operator - (Matrice&);
    friend Matrice operator * (Matrice&, Matrice&);
    friend Matrice operator * (Matrice&, double);
    friend Matrice operator * (double, Matrice&);
    friend Matrice& operator += (Matrice&, Matrice&);
    friend Matrice& operator -= (Matrice&, Matrice&);
    friend Matrice& operator *= (Matrice&, Matrice&);
    friend Matrice& operator *= (Matrice&, double);
    friend Matrice& operator *= (double, Matrice&);
    friend bool operator == (Matrice&, Matrice&);
    friend bool operator == (Matrice&, double);
    friend bool operator == (double, Matrice&);
    friend bool operator != (Matrice&, Matrice&);
    friend bool operator != (Matrice&, double);
    friend bool operator != (double, Matrice&);
    friend bool operator < (Matrice&, Matrice&);
    friend bool operator < (Matrice&, double);
    friend bool operator < (double, Matrice&);
    friend bool operator <= (Matrice&, Matrice&);
    friend bool operator <= (Matrice&, double);
    friend bool operator <= (double, Matrice&);
    friend bool operator > (Matrice&, Matrice&);
    friend bool operator > (Matrice&, double);
    friend bool operator > (double, Matrice&);
    friend bool operator >= (Matrice&, Matrice&);
    friend bool operator >= (Matrice&, double);
    friend bool operator >= (double, Matrice&);
    friend int operator ! (Matrice&);
    friend Matrice operator ~ (Matrice&);

    Matrice merge_lin(Matrice&);
    int rank();
    friend float invertible(Matrice&);
    void LU_A__B(Matrice&, Matrice&); // o folosim cand rank(A) = rank(A_extins)
};

#endif // MATRICE_HPP_INCLUDED
