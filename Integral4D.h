#ifndef INT4
#define INT4
#include <cmath>
#include "Integral2D.h"
#include "Define.h"

template <typename Scalar>
double Integral4D(Scalar(*func)(Scalar ,Scalar, Scalar, Scalar), double x1_min, double x1_max, double x2_min, double x2_max, double x3_min, double x3_max, double x4_min, double x4_max, int N1 = 101, int N2 = 101, int N3 = 101, int N4 = 101){
    double DX1 = (x1_max - x1_min)/(N1 - 1.);
    double DX2 = (x2_max - x2_min)/(N2 - 1.);
    double DX3 = (x3_max - x3_min)/(N3 - 1.);
    double DX4 = (x4_max - x4_min)/(N4 - 1.);
    double DS12 = DX1*DX2;
    double DS34 = DX3*DX4;
    double* tmpPtr;
    SimpsonMatrix(&tmpPtr, N3, N4);
    Matrix<Scalar> SMat34(N3, N4, tmpPtr); // default row-major
    free(tmpPtr);
    SimpsonMatrix(&tmpPtr, N1, N2);
    Matrix<Scalar> SMat12(N1, N2, tmpPtr);
    free(tmpPtr);
    Matrix<Scalar> FMat2D_34(N3, N4);
    Matrix<Scalar> FMat2D_12(N1, N2);
    // re-use the pointer tmpPtr
    for(int i=0; i<N1; i++){
        if (i%outStep == 0){
            std::cout << i << std::endl; 
        }
        for(int j=0; j<N2; j++){
            double x1 = x1_min + i*DX1;
            double x2 = x2_min + j*DX2;
            for(int k=0; k<N3; k++){
                for(int l=0; l<N4; l++){
                    FMat2D_34[k][l] = func(x1, x2, x3_min+k*DX3, x4_min+l*DX4);
                }
            }
            Matrix<Scalar> TMP = FMat2D_34*SMat34;
            double tmp = TMP.sum()*DS34/9.;
            TMP.Free();
            FMat2D_12[i][j] = tmp;
        }
    }
    Matrix<Scalar> TMP = FMat2D_12*SMat12;
    /*for(int i=0; i<FMat2D_12.getRowNum(); i++){
        for(int j=0; j<FMat2D_12.getColumnNum(); j++){
            std::cout << FMat2D_12[i][j] << " ";
        }
        std::cout<<std::endl;
    }*/
    double tmp = TMP.sum()*DS12/9.;
    TMP.Free();
    return tmp;
}

#endif