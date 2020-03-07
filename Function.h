#ifndef FUNCTION
#define FUNCTION
#include <math.h>
#include "Define.h"

double func_test1(double x1, double x2);

double func_test2(double theta1, double theta2); 

double func_test3(double theta1, double theta2, double theta3, double theta4);

double func_test4(double theta1, double theta2, double theta3, double theta4); // [0,1]*[0,1]*[0,1]*[0,1]

double func_test5(double theta1, double theta2, double theta3, double theta4); // [0,1]*[0,1]*[0,1]*[0,1] ~ (0.5)^4




double COR_I1(double theta1, double theta2, double s1, double s2);

double COR_I2(double theta1, double theta2, double s1, double s2);

double COR_I12(double theta1, double theta2, double s1, double s2);

double COR_VEL2(double theta1, double theta2, double s1, double s2);

#endif