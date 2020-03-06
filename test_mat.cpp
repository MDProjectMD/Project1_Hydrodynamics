#include <stdio.h>
#include <string.h> /* For strcmp() */
#include <stdlib.h> /* For EXIT_FAILURE, EXIT_SUCCESS */
#include "mat.h"
#include <iostream>

int main(){
    MATFile *pmatFile = NULL;
    mxArray *pMxArray = NULL;
    double *initA;
 
    pmatFile = matOpen("A.mat","r");
    // "A.mat" contains a variable named 'A' (10*10 array)
    pMxArray = matGetVariable(pmatFile, "A");
    initA = (double*) mxGetData(pMxArray);
    size_t M = mxGetM(pMxArray);
    size_t N = mxGetN(pMxArray);
    // Matrix is stored as column-principal order in Matlab
    for(int i=0;i<M*N;i++){
        std::cout<<initA[i]<<std::endl;
    }
}