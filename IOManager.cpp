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