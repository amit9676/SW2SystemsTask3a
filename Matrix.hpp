#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
namespace zich{

    class Matrix{
        public:
            vector<double> a;
            int b, c;
            Matrix(const vector<double>&,const int,const int); //constructor

            //addition
            Matrix& operator+(Matrix&); //Matrix1 + Matrix2
            Matrix& operator+();// copy Matrix
            Matrix& operator+=(double);
            Matrix& operator+(int);
            Matrix& operator+(double);
            Matrix& operator++(int);
            
            //substract
            Matrix& operator-(); //copy matrix negative
            void operator-=(Matrix&); //Matrix -= a
            Matrix& operator-(Matrix&); // Matrix1 - Matrix2
            Matrix& operator-(int);
            Matrix& operator-(double);
            Matrix& operator--(int);

            //multiplication with scalar
            void operator*=(const double); // Marix *= a
            friend Matrix& operator*(const double, Matrix&); // a* Matrix
            Matrix& operator*(const double); // Matrix * a
            Matrix& operator*(const int); // Matrix * a
            Matrix& operator*(Matrix&); // Matrix * Matrix
            
            //multiplication with another matrix
            Matrix& operator*=(Matrix&);

            

            //print
            friend ostream& operator<<(ostream& COUT, const Matrix mat);

            //comparasion
            bool operator>(const Matrix& mat) const;
            bool operator>=(const Matrix& mat) const;
            bool operator==(const Matrix& mat) const;
            bool operator<=(const Matrix& mat) const;
            bool operator<(const Matrix& mat) const;
            bool operator!=(const Matrix& mat) const;
            
    };

};