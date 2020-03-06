#ifndef INT2
#define INT2
#include <cmath>
#include "Matrix.h"

// implemented by Simpson's Method  N is Odd! N>=5 (Default param for N is 101)
double Integral2D(double(*func)(double ,double ), double x1_min, double x1_max, double x2_min, double x2_max, int N1 = 101, int N2 = 101){
    double DX1 = (x1_max - x1_min)/(N1 - 1);
    double DX2 = (x2_max - x2_min)/(N2 - 1);
    double Qint = 0.;
    return Qint;
}

// return shrinked 1D vector pointer
void SimpsonMatrix(double** S, int N1, int N2){
    (*S) = (double*) calloc(N1*N2, sizeof(double*));
    for(int i=0; i<N1*N2; i++){
        (*S)[i] = 1.;
    }
    
    for(int j=1; j<N2-1; j++){
        if(j%2==1){
            for(int i=0; i<N1; i++){
                (*S)[i*N2+j] *= 4.;
            }
        }else{
            for(int i=0; i<N1; i++){
                (*S)[i*N2+j] *= 2.;
            }
        }
    }

    for(int i=1; i<N1-1; i++){
        if(i%2==1){
            for(int j=0; j<N2; j++){
                (*S)[i*N2+j] *= 4.;
            }
        }else{
            for(int j=0; j<N2; j++){
                (*S)[i*N2+j] *= 2.;
            }
        }
    }
}
template <typename Scalar>
double Integral2(Matrix<Scalar> mat, double x1_min, double x1_max, double x2_min, double x2_max, int N1 = 101, int N2 = 101){
    double DX1 = (x1_max - x1_min)/(N1 - 1);
    double DX2 = (x2_max - x1_min)/(N2 - 1);
    double DS = DX1*DX2;
    double* tmpPtr;
    SimpsonMatrix(&tmpPtr, N1, N2);
    Matrix<Scalar> SMat(N1, N2, tmpPtr); // default row-major
    Matrix<Scalar> Prod = SMat*mat;
    double Q = Prod.sum();
    Q *= (DS/9.);
    Prod.Free();
    SMat.Free();
    return Q;
}

#endif
