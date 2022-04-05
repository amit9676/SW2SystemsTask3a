
#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;

#include <string>
#include <algorithm>

vector<double> v1 = {1,0,0,0,1,0,0,0,1};
Matrix m1(v1,3,3); //standard 3x3 matrix

vector<double> v2 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
Matrix m2(v2,4,4); //standard 4x4 matrix

vector<double> v3 = {5,-2.2,14,0,29,-4,0.2,-1};
Matrix m3(v3,4,4); //3x3 matrix

vector<double> v4 = {-6, 4.73, 1, 1.1, 20, 13.2, -14.89, -5, 4.01};
Matrix m4(v4,3,3); //another 3x3 matrix

vector<double> v5 = {-31.21, 200, 10.1, -10, -11.11, 21, 41.29, -50.1,-101, 9,
    43, 9, 10.54 , -121.31, 23, 0};
Matrix m5(v5,4,4); //4x4 matrix

vector<double> v6 = {16, -14, -151.1, 90.98, 0, 2.6, -7, -61.16, 0, -5.5, 1, -1, 14 , -2.77, 87.7, 10};
Matrix m6(v6,4,4); //another 4x4 matrix

vector<double> v7 = {21, 15, -2.16, 0, -1, -4.4 ,-77, 10.21, 9.9, -11.12, 31.74, -2.99};
Matrix m7(v7,3,4); //3x4 matrix

vector<double> v8 = {6 ,0 ,2 ,-1, -5.5,-4.11, -90, 0, 12, 12.12, 303, -2.11, 50, 31.1, -100, 10.1
    , 10.1, 0, -7, -77, 4, 2.1, 0, -3.3};
Matrix m8(v8,4,6); //4x6 matrix

vector<double> v9 = {0, 1, 4.4, -44, -17.2, 11, 89, -11, 0, -17.65, 9.1, 2, -90.1, 12};
Matrix m9(v9,7,2); //7x2 matrix

vector<double> v10 = {6,-2,4};
Matrix m10(v10,1,3); //1x3 matrix



TEST_CASE("matrices addition good") {
    //all additions here are legel (matrices have matching dimentions for addition)
    vector<double> resultV1 = {2,0,0,0,2,0,0,0,2};
    Matrix resultM1(resultV1,3,3);
	CHECK(m1+m1 == resultM1);


    vector<double> resultV2 = {-15.210000, 186.000000, -141.000000, 80.980000, -11.110000, 23.600000, 34.290000, -111.260000, -101.000000, 3.500000, 44.000000, 8.000000, 24.540000, -124.080000, 110.700000, 10.000000};
    Matrix resultM2(resultV2,4,4);
	CHECK(m5+m6 == resultM2);

    vector<double> resultV3 = {-1.000000, 2.530000, 15.000000, 1.100000, 49.000000, 9.200000, -14.690000, -6.000000};
    Matrix resultM3(resultV3,3,3);
	CHECK(m3+m4 == resultM3);

}

TEST_CASE("matrices addition bad") {
    //attemptong to add matrices not in matching dimentions will throw error
    CHECK_THROWS(m1+m5);
    CHECK_THROWS(m2+m8);
    CHECK_THROWS(m3+m10);
}

TEST_CASE("add value to matrix"){
    //add some value to all matrix fields, works on any matrix's size
    vector<double> resultV4 = {2,0,0,0,2,0,0,0,2};
    Matrix resultM4(resultV4,3,3);
	CHECK(m1+1 == resultM4);

    vector<double> resultV5 = {10.000000, 4.000000, -13.160000, -11.000000, -12.000000, -15.400000, -88.000000, -0.790000, -1.100000, -22.120000, 20.740000, -13.990000};
    Matrix resultM5(resultV5,3,4);
	CHECK(m7+(-11) == resultM5);

    vector<double> resultV6 = {3.550000, 4.550000, 7.950000, -40.450000, -13.650000, 14.550000, 92.550000, -7.450000, 3.550000, -14.100000, 12.650000, 5.550000, -86.550000, 15.550000};
    Matrix resultM6(resultV6,7,2);
	CHECK(m9+3.55 == resultM6);

    vector<double> resultV7 = {7,-1,5};
    Matrix resultM7(resultV7,1,3);
	CHECK(m10++ == resultM7);
}

TEST_CASE("uplus"){
    //unary plus on matrix, it will return copy of the matrix
    vector<double> resultV8 = {1,0,0,0,1,0,0,0,1};
    Matrix resultM8(resultV8,3,3);
	CHECK(+m1 == resultM8);

    vector<double> resultV9 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    Matrix resultM9(resultV9,4,4);
	CHECK(+m2 == resultM9);

    vector<double> resultV10 = {6 ,0 ,2 ,-1, -5.5,-4.11, -90, 0, 12, 12.12, 303, -2.11, 50, 31.1, -100, 10.1
    , 10.1, 0, -7, -77, 4, 2.1, 0, -3.3};
    Matrix resultM10(resultV10,4,4);
	CHECK(+m8 == resultM10);
}

TEST_CASE("matrices substruction good") {
    //all substructions here are legel (matrices have matching dimentions for substruction)
    vector<double> resultV11 = {0,0,0,0,0,0,0,0,0};
    Matrix resultM11(resultV11,3,3);
	CHECK(m1-m1 == resultM11);


    vector<double> resultV12 = {-47.210000, 214.000000, 161.200000, -100.980000, -11.110000, 18.400000, 48.290000, 11.060000, -101.000000, 14.500000, 42.000000, 10.000000, -3.460000, -118.540000, -64.700000, -10.000000};
    Matrix resultM12(resultV12,4,4);
	CHECK(m5-m6 == resultM12);

    vector<double> resultV13 = {11.000000, -6.930000, 13.000000, -1.100000, 9.000000, -17.200000, 15.090000, 4.000000};
    Matrix resultM13(resultV13,3,3);
	CHECK(m3-m4 == resultM13);
}

TEST_CASE("matrices substruction bad") {
    //attemptong to add matrices not in matching dimentions will throw error
    CHECK_THROWS(m1-m5);
    CHECK_THROWS(m2-m8);
    CHECK_THROWS(m3-m10);
}

TEST_CASE("substruct value to matrix"){
    //substruct some value to all matrix fields, works on any matrix's size
    vector<double> resultV14 = {0,0,0,0,0,0,0,0,0};
    Matrix resultM14(resultV14,3,3);
	CHECK(m1-1 == resultM14);

    vector<double> resultV15 = {10.000000, 4.000000, -13.160000, -11.000000, -12.000000, -15.400000, -88.000000, -0.790000, -1.100000, -22.120000, 20.740000, -13.990000};
    Matrix resultM15(resultV15,3,4);
	CHECK(m7-(-11) == resultM15);

    vector<double> resultV16 = {-3.550000, -2.550000, 0.850000, -47.550000, -20.750000, 7.450000, 85.450000, -14.550000, -3.550000, -21.200000, 5.550000, -1.550000, -93.650000, 8.450000};
    Matrix resultM16(resultV16,7,2);
	CHECK(m9-3.55 == resultM16);

    vector<double> resultV17 = {5,-3,3};
    Matrix resultM17(resultV17,1,3);
	CHECK(m10-- == resultM17);
}

TEST_CASE("uminus"){
    //unary minus on matrix, it will return copy of the matrix in which all fields have the opposite sign,
    // + or -
    vector<double> resultV18 = {-1,0,0,0,-1,0,0,0,-1};
    Matrix resultM18(resultV18,3,3);
	CHECK(-m1 == resultM18);

    vector<double> resultV19 = {-1,0,0,0,0,-1,0,0,0,0,-1,0,0,0,0,-1};
    Matrix resultM19(resultV19,4,4);
	CHECK(-m2 == resultM19);

    vector<double> resultV20 = {-6 ,0 ,-2 ,1, 5.5,4.11, 90, 0, -12, -12.12, -303, 2.11, -50, -31.1, 100, -10.1
    , -10.1, 0, 7, 77, -4, -2.1, 0, 3.3};
    Matrix resultM20(resultV20,4,4);
	CHECK(-m8 == resultM20);
}

TEST_CASE("boolean operators good"){
    // check comparsion operators between 2 matrices. all comparions are legel (as all matrices have
    // matching dimentions)
	CHECK(m3 > m1);
    CHECK(m4 > m3);
    CHECK(m3 <= m4);
    CHECK(m5 >= m2);
    CHECK(m6 != m5);

    vector<double> resultV21 = {0,1,0,0,0,1,0,1,0};
    Matrix resultM21(resultV21,3,3);
	CHECK(m1 == resultM21);
}

TEST_CASE("boolean operators bad"){
    //all are not matching sizes
    //if the sizes do not match - error is thrown
	CHECK_THROWS(if(m1==m2));
    CHECK_THROWS(if(1==2));
    CHECK_THROWS(if(m4>m5));
    CHECK_THROWS(if(m6!=m10));
    CHECK_THROWS(if(m1>=m9));
    CHECK_THROWS(if(m6<=m8));
    CHECK_THROWS(if(m1>m2));
    CHECK_THROWS(if(m7<m9));

}

TEST_CASE("matrices multiplication good") {
    //all multiplications here are legel (matrices have matching dimentions for multiplications)
    vector<double> resultV22 = {1,0,0,0,1,0,0,0,1};
    Matrix resultM22(resultV22,3,3);
	CHECK(m1*m1 == resultM22);


    vector<double> resultV23 = {-639.36, 929.09, 2448.931, -15181.5858, -879.16, 121.822, -2820.759, -2837.4378,
        -1490, 1175.97, 16030.4, -9692.42, 168.64, -589.466, -720.424, 8355.2488};
    Matrix resultM23(resultV23,4,4);
	CHECK(m5*m6 == resultM23);

    vector<double> resultV24 = {-1332, -67.176, 438, 138.984, 4407.684, -117.96, -3531.47, -3180.87, 7686.04,
    -808.587, -2105.4, -20.299, 2668.13, 1217.344, -3299.6, 169.6206, -3103.236, -7.3588};
    Matrix resultM24(resultV24,3,3);
	CHECK(m7*m8 == resultM24);

}

TEST_CASE("matrices multiplication bad") {
    //any attempt to multiply matrices in which the size do not match according to matrix multiplication
    //rules will throw error
    CHECK_THROWS(m1*m2);
    CHECK_THROWS(m6*m9);
    CHECK_THROWS(m10*m3);
    CHECK_THROWS(m7*m10);
}

TEST_CASE("multiply value to matrix"){
    //multiplying every field in the matrix with some scalar, possible for any matrix's dimentions
    vector<double> resultV25 = {5,0,0,0,5,0,0,0,5};
    Matrix resultM25(resultV25,3,3);
	CHECK(m1*5 == resultM25);

    vector<double> resultV26 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    Matrix resultM26(resultV26,3,4);
	CHECK(m9*0 == resultM26);

    vector<double> resultV27 = {-12.000000, -0.000000, -4.000000, 2.000000, 11.000000, 8.220000, 180.000000, -0.000000, -24.000000, -24.240000, -606.000000, 4.220000, -100.000000, -62.200000, 200.000000, -20.200000, -20.200000, -0.000000, 14.000000, 154.000000, -8.000000, -4.200000, -0.000000, 6.600000};
    Matrix resultM27(resultV27,7,2);
	CHECK(m8*(-2) == resultM27);

    vector<double> resultV28 = {9.000000, -3.000000, 6.000000};
    Matrix resultM28(resultV28,1,3);
	CHECK(1.5 * m10 == resultM28);
}

TEST_CASE("wrong sizes matrices"){
    //any attempt to initilize matrix in which its give dimentions can not be made with vector size,
    //or any size which is not positibe, will throw error
    vector<double> resultV29 = {1,2,3,4,5};
	CHECK_THROWS(Matrix resultM29(resultV29,6,6));

    vector<double> resultV30 = {1,2,3,4,5};
	CHECK_THROWS(Matrix resultM30(resultV30,6,-1));

    vector<double> resultV31 = {1,2,3,4,5};
	CHECK_THROWS(Matrix resultM31(resultV31,-1,6));

    vector<double> resultV32 = {1,2,3,4,5};
	CHECK_THROWS(Matrix resultM32(resultV32,-1,-1));

    vector<double> resultV33 = {1,2,3,4,5};
	CHECK_THROWS(Matrix resultM33(resultV33,0,1));

    vector<double> resultV34 = {1,2,3,4,5};
	CHECK_THROWS(Matrix resultM34(resultV34,1,0));

    vector<double> resultV35 = {1,2,3,4,5};
	CHECK_THROWS(Matrix resultM35(resultV35,0,0));

}