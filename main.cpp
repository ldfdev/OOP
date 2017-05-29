#include "Matrice.hpp"
using namespace std;
int main()
{
    // A*X=B

    Matrice A, A_rang, A_rang2, A_inv, A_unknowns, A_ext, B, X;
    int i, rank;
    A.citire(cin);
    B.citire(cin);
    cout << endl;
    cout<<(70>A);
return 0;
    if(invertible(A))
    {
        A_inv = ~A;
        A_inv.afisare();
        X = A_inv * B;
        X.afisare();
    }
    else{
        rank = A.rank();
        A_ext = A.merge_lin(B);
        if(A_ext.rank() == rank){ //A_rang*X = B' - A_unknowns
            A.LU_A__B(A_rang, A_unknowns);
            cout<<"Matricea ce da rangul: are" << nrlinii(A_rang) <<"\n";
            A_rang.afisare();
            cout<<"Matricea ramasa: \n";
            A_unknowns.afisare();
            A_rang = ~A_rang;
            A_ext.reactualizare(rank,1,0); // Matricea B trunchiata
            for(i = 0; i < rank; i++)
                A_ext[i][0] = B[i][0];
            cout<<"Partea ce da rangul(finale): \n";
            (A_rang*A_ext).afisare();
            cout<<"Matricea ramasa(finale): \n";
            (A_rang*A_unknowns).afisare();
        }
        else
            cout << "Sistem incompatibil" << endl;
    }
/*
    cout<<" Are rangul: " << A.rank() <<endl;
    A.LU_A__B(A_inv, A_ext);
    cout<<" A_rang: " << endl;
    A_inv.afisare();
    cout<<" A_in_rest: " << endl;
    A_ext.afisare();
*/
    return 0;
}
