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

#endif