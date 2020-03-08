// FILE could not be a USER defined var !
#ifndef FILEIO
#define FILEIO
#include "Matrix.h"

/*
    Read matrix variable from *.mat file
    fPointer:   file path
    varName:    name of the matrix to be retrieved from *.mat file
*/
bool ReadMatrixVariable(const char* fPointer, const char* varName, double** darray);

bool ReadMatrixDim(const char* fPointer, const char* varName, unsigned int* M, unsigned int* N);

/*
    Write matrix variable to *.mat file
    mode:   'r' denotes row-major darray
            'c' denotes column-major darray
    if mode 'r' is selected, then first "row-major" to "colummn-major" is needed (MATLAB stores matrix in mode 'c')
*/
bool WriteMatrixVariable(const char* fPointer, const char* varName, double* darray, int M, int N, char mode = 'r');

#endif


/*

 * Write array value with the specified name to the MAT-file, deleting any previously existing variable with that name in the MAT-file.
 * Return zero for success, nonzero for error.
 * 
    EXTERN_C LIBMAT_API matError matPutVariable(MATFile * pMF, const char * name, const mxArray * pA);

 * Create a two-dimensional array to hold double-precision floating-point data; initialize each data element to 0.
 *
    LIBMMWMATRIX_PUBLISHED_API_EXTERN_C mxArray* mxCreateDoubleMatrix(mwSize m, mwSize n, mxComplexity flag);

 * 
    LIBMMWMATRIX_PUBLISHED_API_EXTERN_C double *mxGetPr(const mxArray *pa);


*/