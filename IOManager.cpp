#include "mat.h"
#include <iostream>

bool ReadMatrixVariable(const char* fPointer, const char* varName, double** darray){
    MATFile *pmatFile = NULL;
    mxArray *pMxArray = NULL;
    pmatFile = matOpen(fPointer,"r");
    if(pmatFile != NULL){
        pMxArray = matGetVariable(pmatFile, varName);
    }else{
        std::cout << "Wrong *.mat file path" << std::endl;
        exit(0);
    }
    (*darray) = (double*) mxGetData(pMxArray);
    matClose(pmatFile);
    return true;
}

bool ReadMatrixDim(const char* fPointer, const char* varName, unsigned int* M, unsigned int* N){
    MATFile *pmatFile = NULL;
    mxArray *pMxArray = NULL;
    pmatFile = matOpen(fPointer,"r");
    if(pmatFile != NULL){
        pMxArray = matGetVariable(pmatFile, varName);
    }else{
        std::cout << "Wrong *.mat file path" << std::endl;
        exit(0);
    }
    (*M) = mxGetM(pMxArray);
    (*N) = mxGetN(pMxArray);
    matClose(pmatFile);
    return true;
}

bool WriteMatrixVariable(const char* fPointer, const char* varName, double* darray, int M, int N, char mode){
    MATFile *pMat = NULL;
    mxArray *pArr = NULL;
    if(mode == 'r'){
        double* darray_copy = (double*) calloc(M*N, sizeof(double));
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                darray_copy[j*M+i] = darray[i*N+j];
            }
        }
        memcpy(darray, darray_copy, M*N*sizeof(double));
        free(darray_copy);
    }
    pMat = matOpen(fPointer, "w");
    if(pMat == NULL){
        printf("Error creating file %s\n", fPointer);
        return false;
    }
    pArr = mxCreateDoubleMatrix(M, N, mxREAL);
    if(pArr == NULL){
        printf("%s : Out of memory on line %d\n", __FILE__, __LINE__); 
        printf("Unable to create mxArray.\n");
        return false;
    }
    memcpy((void *)(mxGetPr(pArr)), (void *)darray, M*N*sizeof(double));
    int wrt_status = matPutVariable(pMat, varName, pArr);
    if (wrt_status != 0) {
      printf("Error using matPutVariable\n");
      return false;
    }
    mxDestroyArray(pArr);
    matClose(pMat);
    return true;
}