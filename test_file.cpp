#include "Integral2D.h"
#include "IOManager.h"
#include "Matrix.h"
#include <iostream>

double Func(double x1, double x2){
    return x1*x1;
}

int main(){
    Matrix<double> A(5, 5);
    std::cout<<A[1][1]<<std::endl;
    double* darray;
    unsigned int M , N;
    const char file[] = "A.mat";
    const char var[] = "A";
    if(ReadMatrixVariable(file, var, &darray)){
        ReadMatrixDim(file, var, &M, &N);
    }
    std::cout<<M<<"*"<<N<<std::endl;
    Matrix<double> B(M,N,darray);
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            std::cout<<B[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    Matrix<double> C(M,N,darray,'c');
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            std::cout<<C[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    double* tmpPtr;
    SimpsonMatrix(&tmpPtr, 15, 15);
    Matrix<double> SMat(15, 15, tmpPtr); // default row-major
    
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            std::cout<<SMat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    Matrix<double> Q = (SMat*SMat);
    std::cout<< Q.sum()<<std::endl;
}

/*
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
    double Q_ = Integral2D(&func_test1, 0, 1, 0, 1, 101, 101);
    std::cout<< Q_ <<std::endl; // should be 1/3
*/

/*
double* tmpPtr;
    SimpsonMatrix(&tmpPtr, 101, 101);
    double Q = Integral4D(&func_test5, 0, 1, 0, 1, 0, 1, 0, 1);
    std::cout<< Q << std::endl;
*/