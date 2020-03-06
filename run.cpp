#include "Integral2D.h"
#include "IOManager.h"
#include "Matrix.h"
#include <iostream>

#define PI 3.14159265359

int main(){
    const char fname[] = "Int.mat";
    const char vname[] = "Int";
    double* darray;
    unsigned int M, N;
    if(ReadMatrixVariable(fname, vname, &darray)){
        ReadMatrixDim(fname, vname, &M, &N);
    }
    Matrix<double> FMat(M, N, darray, 'c');
    std::cout << "Matrix variable name: " << vname << "    Size: " << M << "*" << N << std::endl; 
    double theta1_min = 0.;
    double theta1_max = PI/2.;
    double theta2_min = 0.;
    double theta2_max = PI/2.;
    double Q = Integral2(FMat, theta1_min, theta1_max, theta2_min, theta2_max, M, N);
    std::cout<< Q <<std::endl;
}