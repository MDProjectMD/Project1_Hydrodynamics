#include "Function.h"

double func_test1(double x1, double x2){
    return x1*x1;
}

double func_test2(double theta1, double theta2){
    return rho;
}

double func_test3(double theta1, double theta2, double theta3, double theta4){
    return theta1*theta1;
}

double func_test4(double theta1, double theta2, double theta3, double theta4){
    return theta1*theta1 + theta2*theta2 + theta3*theta3 + theta4*theta4;
}

double func_test5(double theta1, double theta2, double theta3, double theta4){
    return theta1*theta2*theta3*theta4;
}

// ******************** Above Test **********************

// ******************** sub function module ********************
namespace function_I1_space{ 
    double func_exp(double theta, double s){
        return exp(c*c/gma*(cos(2.*theta)+1.)*(s-TMAX));
    }
    double func_sin_1(double theta, double s){
        return sin(c*c/gma*sin(2.*theta)*(s-TMAX)+2.*theta);
    }
    double func_sin_2(double theta){
        return sin(2.*c/gma*cos(theta)*z0);
    }
}

namespace function_I2_space{
    double func_exp(double theta, double s){
        return exp(2.*c*c/gma/cos(theta)/cos(theta)*(s-TMAX))/cos(theta); // In this way, either cos(theta) is 0 or infinity is not divergent
    }
    double func_angle(double theta, double s){
        return 2.*c*c/gma*tan(theta)/cos(theta)*(s-TMAX);
    }
    double func_sin(double theta){
        return sin(2.*c/gma/cos(theta)*z0);
    }
}

double func_decay(double s1, double s2){
    return T*exp(-lbda*abs(s1-s2));
}

// *************************************************************
double COR_I1(double theta1, double theta2, double s1, double s2){
    double T1 = function_I1_space::func_exp(theta1, s1) * function_I1_space::func_exp(theta2, s2);
    double T2 = function_I1_space::func_sin_1(theta1, s1) * function_I1_space::func_sin_1(theta2, s2);
    double T3 = function_I1_space::func_sin_2(theta1) * function_I1_space::func_sin_2(theta2);
    double T4 = func_decay(s1, s2);
    return T1*T2*T3*T4;
}

double COR_I2(double theta1, double theta2, double s1, double s2){
    double T1 = function_I2_space::func_exp(theta1, s1) * function_I2_space::func_exp(theta2, s2);
    double angle1 = function_I2_space::func_angle(theta1, s1);
    double angle2 = function_I2_space::func_angle(theta2, s2);
    double T2 = cosh(angle1) * cosh(angle2);
    double T3 = (1.-2./cos(theta1)/cos(theta1)) * tanh(angle1) - 2.*tan(theta1)/cos(theta1);
    T3 *= ( (1.-2./cos(theta2)/cos(theta2)) * tanh(angle2) - 2.*tan(theta2)/cos(theta2) );
    double T4 = function_I2_space::func_sin(theta1) * function_I2_space::func_sin(theta2);
    double T5 = func_decay(s1, s2);
    return T1*T2*T3*T4*T5;
}

double COR_I12(double theta1, double theta2, double s1, double s2){
    double T1_I1 = function_I1_space::func_exp(theta1, s1);
    double T2_I1 = function_I1_space::func_sin_1(theta1, s1);
    double T3_I1 = function_I1_space::func_sin_2(theta1);
    double T_I1 = T1_I1*T2_I1*T3_I1;

    double T1_I2 = function_I2_space::func_exp(theta2, s2);
    double angle2 = function_I2_space::func_angle(theta2, s2);
    double T2_I2 = cosh(angle2);
    double T3_I2 = (1.-2./cos(theta2)/cos(theta2)) * tanh(angle2) - 2.*tan(theta2)/cos(theta2);
    double T4_I2 = function_I2_space::func_sin(theta2);
    double T_I2 = T1_I2*T2_I2*T3_I2*T4_I2;

    double T = T_I1 * T_I2 * func_decay(s1, s2);
    return T;
}

double COR_VEL2(double theta1, double theta2, double s1, double s2){
    double term1 = COR_I1(theta1, theta2, s1, s2);
    double term2 = COR_I2(theta1, theta2, s1, s2);
    double term3 = COR_I12(theta1, theta2, s1, s2);
    return term1 + term2 - 2.*term3;
}


