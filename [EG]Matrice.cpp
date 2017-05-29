#include "Matrice.hpp"

/// https://github.com/isocpp/CppCoreGuidelines
Matrice::Matrice(int x, int y){
    lin = x, col = y;
    std::vector<double> tmp(y,0);
    v.resize(lin);
    for(decltype(v)::iterator it = v.begin(); it != v.end(); ++it)
        it->vv = tmp;
}

Matrice::Matrice(int L, int C, double val){
    lin = L, col = C;
    std::vector<double> tmp(C,val);
    v.resize(L);
    for(decltype(v)::iterator it = v.begin(); it != v.end(); ++it)
        it->vv = tmp;
}

Matrice::Matrice(const Matrice& obj){
    this->col = obj.col;
    this->lin = obj.lin;
    this->v = obj.v;
}

Matrice::~Matrice(){
    for(decltype(v)::iterator it = v.begin(); it != v.end(); ++it)
        it->vv.clear();
    v.clear();
}

void Matrice::citire(std::istream& in){
    in >> this->lin >> this->col;
    this->reactualizare(lin, col, 0);
    for(auto& x:this->v)
        for(auto& y:x.vv)
            in >> y;

}

void Matrice::afisare(){
    if(this->lin ==0 || this->col == 0)
        return;
    for(auto x:this->v){
        for(auto y:x.vv)
            std::cout <<y <<" ";
        std::cout << std::endl;
        }
}

void Matrice::reactualizare(int new_lin,int new_col,double new_val){
    lin = new_lin, col = new_col;
    v.resize(new_lin);
    for(decltype(v)::iterator it = v.begin(); it != v.end(); ++it){
        it->vv.clear();
        it->vv.assign(new_col, new_val);
    }
}

int nrlinii(const Matrice& Matroid){
    return Matroid.lin;
}

int nrcoloane(const Matrice& Matroid){
    return Matroid.col;
}

int nrelemente(const Matrice& Matroid){
    return (Matroid.lin * Matroid.col);
}

Matrice Matrice::operator=(const Matrice& M){
    if(this != &M){
        this->lin = M.lin;
        this->col = M.col;
        this->v = M.v;
        return *this;
    }
    return *this;
}

struct Linie& Matrice::operator [] (const int& i){
    return this->v[i];
}

Matrice operator + (Matrice& z1, Matrice& z2){
    int i,j;
    Matrice M(z1.lin, z1.col);
    if((z1.lin==z2.lin) && (z1.col==z2.col))
        for(i = 0; i < z1.lin; i++)
            for(j = 0; j < z1.col; j++)
                M[i][j] = z1[i][j] + z2[i][j];
    return M;
}

Matrice operator + (Matrice& z1){
    Matrice M(z1.lin, z1.col);
    M.v = z1.v;
    return M;
}

Matrice operator - (Matrice& z1, Matrice& z2){
    int i,j;
    Matrice M(z1.lin, z1.col);
    if((z1.lin==z2.lin) && (z1.col==z2.col))
        for(i = 0; i < z1.lin; i++)
            for(j = 0; j < z1.col; j++)
                M[i][j] = z1[i][j] - z2[i][j];
    return M;
    }

Matrice operator - (Matrice& z1){
    int i,j;
    Matrice M(z1.lin, z1.col);
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z1.col; j++)
            M[i][j] = z1[i][j]*(-1);
    return M;
}

Matrice operator * (Matrice& z1, Matrice& z2){
    int i,j,k;
    Matrice M(z1.lin, z2.col);
    if(z1.col != z2.lin)
        return M;
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z2.col; j++)
        {
            M[i][j] = 0;
            for(k = 0; k < z1.col; k++)
            M[i][j] += (z1[i][k]) * (z2[k][j]);
        }
    return M;
}

Matrice operator * (Matrice& z1, double z2){
    int i,j;
    Matrice M(z1.lin, z1.col);
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z1.col; j++)
            M[i][j] = z1[i][j]*(z2);
    return M;
}

Matrice operator * (double z2, Matrice& z1){
    int i,j;
    Matrice M(z1.lin, z1.col);
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z1.col; j++)
            M[i][j] = z1[i][j]*(z2);
    return M;
}

Matrice& operator += (Matrice& z1, Matrice& z2){
    int i,j;
    if((z1.lin != z2.lin) && (z1.col != z2.col))
        return z1;
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z1.col; j++)
            z1[i][j] = z1[i][j] + z2[i][j];
    return z1;
}

Matrice& operator -= (Matrice& z1, Matrice& z2){
    int i,j;
    if((z1.lin==z2.lin) && (z1.col==z2.col))
        for(i = 0; i < z1.lin; i++)
            for(j = 0; j < z1.col; j++)
                z1[i][j] = z1[i][j] - z2[i][j];
    return z1;
}

Matrice& operator *= (Matrice& z1, Matrice& z2){
    int i,j,k;
    double aux;
    Matrice z1_copie(z1);
    if(z1.col != z2.lin)
        return z1;
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z2.col; j++){
            aux = 0;
            for(k = 0; k < z1.col; k++)
            aux += (z1_copie[i][k]) * (z2[k][j]);
            z1[i][j] = aux;
        }
    return z1;
}

Matrice& operator *= (Matrice& z1, double z2){
    int i,j;
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z1.col; j++)
            z1[i][j] = z1[i][j]*z2;
    return z1;
}

Matrice& operator *= (double z2, Matrice& z1){
    return (z1 *= z2);
}

bool operator == (Matrice& z1, Matrice& z2){
    bool bt = true;
    int i, j;
    if((z1.lin != z2.lin) || (z1.col != z2.col))
        return false;
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z1.col; j++)
            if(z1[i][j] != z2[i][j]){
                bt = false;
                break;
            }
    return (bt) == (true) ? (true) : (false);
}

bool operator == (Matrice& z1, double z2){
    if((z1.lin != 1) || (z1.col != 1))
        return false;
    return (z1[0][0] == z2);
}

bool operator == (double z2 , Matrice& z1){
    return (z1 == z2);
}

bool operator != (Matrice& z1, Matrice& z2){
    return !(z1 == z2);
}

bool operator != (Matrice& z1, double z2){
    return !(z1 == z2);
}

bool operator != (double z1, Matrice& z2){
    return !(z1 == z2);
}

bool operator < (Matrice& z1, Matrice& z2){
    bool bt = true;
    int i, j;
    if((z1.lin <= z2.lin) && (z1.col <= z2.col)){
        for(i = 0; i < z1.lin; i++)
            for(j = 0; j < z1.col; j++)
                if(z1[i][j] >= z2[i][j]){
                    bt = false;
                    break;}}
    else return false;
    return (bt) == (true) ? (true) : (false);
}

bool operator < (Matrice& z1, double z2){
    if(z1.lin != 1 ||  z1.col != 1)
        return false;
    return (z1[0][0] < z2) ? (true) : (false);
}

bool operator < (double z1, Matrice& z2){
    return (z2 < z1);
}

bool operator <= (Matrice& z1 , Matrice& z2){
    bool bt = true;
    int i, j;
    if((z1.lin <= z2.lin) && (z1.col <= z2.col)){
        for(i = 0; i < z1.lin; i++)
            for(j = 0; j < z1.col; j++)
                if(z1[i][j] > z2[i][j]){
                    bt = false;
                    break;}}
    else return false;
    return (bt) == (true) ? (true) : (false);
}

bool operator <= (Matrice& z1 , double z2){
    if(z1.lin != 1 ||  z1.col != 1)
        return false;
    return (z1[0][0] <= z2) ? (true) : (false);
}

bool operator <= (double z2 , Matrice& z1){
    if(z1.lin != 1 ||  z1.col != 1)
        return false;
    return (z1[0][0] >= z2) ? (true) : (false);
}

bool operator > (Matrice& z1, Matrice& z2){
    return (1+(z1 <= z2))%2 ;
}

bool operator > (Matrice& z1, double z2){
    return (1+(z1 <= z2))%2;
}

bool operator > (double z2, Matrice& z1){
    return !(z2 <= z1);
}

bool operator >= (Matrice& z1, Matrice& z2){
    return !(z1 < z2);
}

bool operator >= (Matrice& z1, double z2){
    return !(z1 < z2);
}

bool operator >= (double z2, Matrice& z1){
    return !(z1 < z2);
}

int operator ! (Matrice& z1){
    bool bt = true;
    int i, j;
    for(i = 0; i < z1.lin; i++)
        for(j = 0; j < z1.col; j++)
            if(z1[i][j] != 0){
                bt = false;
                break;
            }
    return (bt) == (true) ? (1) : (0);
}

float invertible(Matrice& m){
    int n_lin, n_col;
    if(nrlinii(m) != nrcoloane(m))
        return 0;
    Eigen::MatrixXf m_eigen(m.lin, m.col); // M(float,dynamic,dynamic)
    for(n_lin = 0; n_lin < m.lin; n_lin++)
        for(n_col = 0; n_col < m.col; n_col++)
            m_eigen(n_lin, n_col) = m[n_lin][n_col];
    return m_eigen.determinant();
}

Matrice operator ~ (Matrice& m){
    int m_lin = m.lin, m_col = m.col, n_lin, n_col;
    if(invertible(m))
    {
        Matrice inv(m_lin, m_col); // aici stocam inversa
        Eigen::MatrixXf m_eigen(m_lin, m_col), m_eigen2; // M(float,dynamic,dynamic)
        for(n_lin = 0; n_lin < m_lin; n_lin++)
            for(n_col = 0; n_col < m_col; n_col++)
                m_eigen(n_lin,n_col) = m[n_lin][n_col];
        m_eigen2 = m_eigen.inverse();
        for(n_lin = 0; n_lin < m_lin; n_lin++)
            for(n_col = 0; n_col < m_col; n_col++)
                inv[n_lin][n_col] = m_eigen2(n_lin, n_col);
        return inv;
    }
    Matrice zero(m_lin, m_col);
    return zero;
}

Matrice Matrice::merge_lin(Matrice& m){
    Matrice zero(lin, col);
    int i,j, m_lin = nrlinii(m), m_col = nrcoloane(m);
    if(lin == m_lin){
    Matrice m2(m_lin, m_col + col);
        for(i = 0; i< m_lin; i++)
            for(j = 0; j < col; j++)
                m2[i][j] = (*this)[i][j];
        for(i = 0; i< m_lin; i++)
            for(j = 0; j < m_col; j++)
                m2[i][j + col] = m[i][j];
    return m2;
    }
    return zero;
}

int Matrice::rank(){
    Eigen::MatrixXf m_eigen(lin, col); // M(float,dynamic,dynamic)
    for(int n_lin = 0; n_lin < lin; n_lin++)
        for(int n_col = 0; n_col < col; n_col++)
            m_eigen(n_lin,n_col) = (*this)[n_lin][n_col];
    Eigen::FullPivLU<Eigen::MatrixXf> lu(m_eigen);
    auto rank = lu.rank();
    return rank;
}

void Matrice::LU_A__B(Matrice& A, Matrice& B){
 // A devine matricea ce da rank(A)
 // B este ce ramane din A(aceleasi linii, alte cols)
    int i, n_lin, n_col, rank;
    Eigen::MatrixXf LU_A(lin, col);
    for(int n_lin = 0; n_lin < lin; n_lin++)
        for(int n_col = 0; n_col < col; n_col++)
            LU_A(n_lin,n_col) = (*this)[n_lin][n_col];
    Eigen::FullPivLU<Eigen::MatrixXf> lu(LU_A);
    rank = lu.rank();
    A.reactualizare(rank, rank, 0);
    B.reactualizare(rank, col - rank, 0);

 //procesam intrarile pentru A, B
    Eigen::ArrayXi indici_lin = lu.permutationP().indices().cast<int>().array();
    Eigen::ArrayXi indici_col = lu.permutationQ().indices().cast<int>().array();

 // A = P LU Q => PtA = LU Q
    std::vector<int> perm_lin_transp(lin);
    for(i = 0; i < lin; i++)
        perm_lin_transp[ *(indici_lin.data() + i) ] = i;

 //pentru linii
    std::vector<int> indici_lin_ordonat(rank);
    for(i = 0; i < rank; i++)
        indici_lin_ordonat[ i ] = perm_lin_transp[ i ];
    std::sort(indici_lin_ordonat.begin(), indici_lin_ordonat.end());

 //pentru coloane(in matricea ce da rangul)
    std::vector<int> indici_col_ordonat(rank);
    for(i = 0; i < rank; i++)
        indici_col_ordonat[i] = *(indici_col.data() + i);
    std::sort(indici_col_ordonat.begin(), indici_col_ordonat.end());

 //pentru coloane(in matricea cu "necunoscute principale")
    std::vector<int> indici_col_ordonatB(col - rank);
    for(i = 0; i < (col - rank); i++)
        indici_col_ordonatB[i] = *(indici_col.data() + rank + i);
    std::sort(indici_col_ordonatB.begin(), indici_col_ordonatB.end());
    A.reactualizare(rank, rank,0);
    for(n_lin = 0; n_lin < rank; n_lin++)
        for(n_col = 0; n_col < rank; n_col++)
            A[n_lin][n_col] = v[indici_lin_ordonat[n_lin]][indici_col_ordonat[n_col]];
    B.reactualizare(rank,(col - rank), 0);
    for(n_lin = 0; n_lin < rank; n_lin++)
        for(n_col = 0; n_col < (col - rank); n_col++)
            B[n_lin][n_col] = v[indici_lin_ordonat[n_lin]][indici_col_ordonatB[n_col]];

}
