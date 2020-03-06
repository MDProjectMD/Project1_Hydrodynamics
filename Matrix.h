#ifndef MATRIX
#define MATRIX
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

// if Template is USED, then the implementation and the declaration should be palced in the SAME FILE !!!!

template <typename Scalar> 
class Matrix{
private:
    unsigned int M; // row
    unsigned int N; // column
    Scalar** ptr;
    Matrix(); // default empty object
    void AllocateMemory(){
        ptr = (Scalar**) calloc(M, sizeof(Scalar*));
        for(int i=0; i<M; i++){
            ptr[i] = (Scalar*) calloc(N, sizeof(Scalar));
        }
    }
public:
    Matrix(unsigned int m, unsigned int n); // initialize a matrix with all elements to be 0
    Matrix(unsigned int m, unsigned int n, Scalar* darray, char mode = 'r'); // assemble a given 2D array, 'r' -- row-major & 'c' -- column-major
    // for *.mat file, matlab stores matrix in column-major sequence
    void Free(); // HERE IF using deconstructor, then 'operator*' CANNOT return a object!
    Scalar* const operator[] (const unsigned int idx);
    Matrix<Scalar> operator* (Matrix<Scalar> M); // pairwise element product
    unsigned int getRowNum();
    unsigned int getColumnNum();
    Scalar sum();
};

template <typename Scalar>
Scalar Matrix<Scalar>::sum(){
    Scalar ac = 0.;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            ac += ptr[i][j];
        }
    }
    return ac;
}

template <typename Scalar>
Matrix<Scalar> Matrix<Scalar>::operator* (Matrix<Scalar> Mat){
    unsigned int Nr = Mat.getRowNum();
    unsigned int Nc = Mat.getColumnNum();
    if (M!=Nr || N!=Nc){
        std::cout<< "element pairwise product must have same dimensions " << std::endl;
        exit(0);
    }
    Matrix<Scalar> R(M, N);
    for(int i=0; i<Nr; i++){
        for(int j=0; j<Nc; j++){
            R[i][j] = ptr[i][j] * Mat[i][j];
        }
    }
    return R;
}

template <typename Scalar>
Matrix<Scalar>::Matrix(unsigned int m, unsigned int n, Scalar* darray, char mode){
    M = m;
    N = n;
    AllocateMemory();
    if(mode == 'r'){
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                ptr[i][j] = darray[i*N+j];
            }
        }
    }else{
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                ptr[i][j] = darray[j*M+i];
            }
        }
    }
}

template <typename Scalar>
Matrix<Scalar>::Matrix(unsigned int m, unsigned int n){
    M = m;
    N = n;
    AllocateMemory();
}

template<typename Scalar>
void Matrix<Scalar>::Free(){
    std::cout<<"matrix ptr free"<<std::endl;
    for(int i=0; i<M; i++){
        free(ptr[i]);
    }
    free(ptr);
}

template<typename Scalar>
Scalar* const Matrix<Scalar>::operator[](const unsigned int idx){
    return ptr[idx];
}

template<typename Scalar>
unsigned int Matrix<Scalar>::getRowNum(){
    return M;
}

template<typename Scalar>
unsigned int Matrix<Scalar>::getColumnNum(){
    return N;
}

#endif