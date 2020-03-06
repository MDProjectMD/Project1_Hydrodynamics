#include "Integral4D.h"
#include "IOManager.h"
#include "Matrix.h"
#include "Function.h"
#include <iostream>

int main(){
    double Q = Integral4D(&COR_I1, theta1_min, theta1_max, theta2_min, theta2_max, s1_min, s1_max, s2_min, s2_max, N1, N2, N3, N4);
    std::cout<< Q << std::endl;
}