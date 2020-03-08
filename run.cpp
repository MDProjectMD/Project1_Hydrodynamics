#include "Integral4D.h"
//#include "IOManager.h"
#include "Matrix.h"
#include "Function.h"
#include <iostream>

int main(){
    double Q = Integral4D(&COR_I2, theta1_threshold, theta1_max, theta2_threshold, theta2_max, s1_min, s1_max, s2_min, s2_max, N1, N2, N3, N4);
    std::cout<< Q << std::endl;
}