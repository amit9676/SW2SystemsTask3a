#include "Matrix.hpp"
using namespace zich;


Matrix::Matrix(const vector<double>& a,const int b,const int c){
    this->a = a;
    this->b = b;
    this-> c = c;
}

Matrix& Matrix::operator+(Matrix& mat1){
    return mat1;
} //Matrix1 + Matrix2

Matrix& Matrix::operator+(){
    return *this;
}

Matrix& Matrix::operator+(int value){return *this;}
Matrix& Matrix::operator+(double value){return *this;}
//consider changing return Matrix& to void
Matrix& Matrix::operator+=(double a){
    return *this;
}
Matrix& Matrix::operator++(int a)
{
    // vector<double> resultV7 = {7,-1,5};
    // Matrix p3(resultV7,2,2);
    // return p3;
    return *this;
}

//substract
Matrix& Matrix::operator-(){
    return *this;
} //copy matrix negative
void Matrix::operator-=(Matrix &mat){} //Matrix -= a
Matrix& Matrix::operator-(Matrix &a){return *this;} // Matrix1 - Matrix2
Matrix& Matrix::operator-(int value){return *this;}
Matrix& Matrix::operator-(double value){return *this;}
Matrix& Matrix::operator--(int){return *this;}

//multiplication
void Matrix::operator*=(const double scalar){} // Marix *= a
Matrix& zich::operator*(const double scalar, Matrix& mat){
    return mat;
}

Matrix& Matrix::operator*(const double){return *this;} // Matrix * a
Matrix& Matrix::operator*(const int){return *this;}  // Matrix * a

Matrix& Matrix::operator*(Matrix& mat){return *this;}



//print
ostream& zich::operator<<(ostream& COUT, const Matrix mat){return COUT;}

//comparasion
bool Matrix::operator>(const Matrix& mat) const{return true;}
bool Matrix::operator>=(const Matrix& mat) const{return true;}
bool Matrix::operator==(const Matrix& mat) const{return true;}
bool Matrix::operator<=(const Matrix& mat) const{return true;}
bool Matrix::operator<(const Matrix& mat) const{return true;}
bool Matrix::operator!=(const Matrix& mat) const{return true;}