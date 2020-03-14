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

double func_decay(double s1, double s2){
    return T*exp(-lbda*abs(s1-s2));
}

namespace function_space{ 
    
    // I1 Modules
    double func1_exp(double theta, double s){
        return exp(c*c/gma*(cos(2.*theta)+1.)*(s-TMAX));
    }
    double func1_sin_1(double theta, double s){
        return sin(c*c/gma*sin(2.*theta)*(s-TMAX)+2.*theta);
    }
    double func1_sin_2(double theta){
        return sin(2.*c/gma*cos(theta)*z0);
    }

    // I2 Modules
    double func2_exp(double theta, double s){
        return exp(2.*c*c/gma/cos(theta)/cos(theta)*(s-TMAX));
    }
    double func2_cosh(double theta, double s){
        return cosh(2.*c*c/gma*tan(theta)/cos(theta)*(s-TMAX));
    }
    double func2_inside(double theta, double s){
        double costhetai = 1./cos(theta);
        double angle = 2.*c*c/gma*tan(theta)/cos(theta)*(s-TMAX);
        return (costhetai-2.*costhetai*costhetai*costhetai)*tanh(angle)-2.*tan(theta)*costhetai*costhetai;
    }
    double func2_sin(double theta){
        return sin(2.*c/gma/cos(theta)*z0);
    }

    // I3 Modules   part1
    double kr(double rho){
        return K0 + sqrt(2.)/2.*rho;
    }
    double ki(double rho){
        return sqrt(2.)/2.*rho;
    }
    double K(double rho){
        double kr2 = kr(rho);
        kr2 = kr2*kr2;
        double ki2 = ki(rho);
        ki2 = ki2*ki2;
        return pow(gma, 4.)*( (kr2-ki2)*(kr2-ki2)-4.*kr2*ki2 ) - 2.*gma*gma*c*c*(kr2-ki2) - 2.*pow(c, 4.);
    }
    double I(double rho){
        double kr2 = kr(rho);
        double ki2 = ki(rho);
        double krki = kr2*ki2;
        kr2 = kr2*kr2;
        ki2 = ki2*ki2;
        return 4.*pow(gma, 4.)*krki*(kr2-ki2) - 4.*krki*pow(gma, 2.)*c*c;
    }
    void cal_ab(double rho, double* a, double* b){
        double Kval = K(rho);
        double Ival = I(rho);
        double c4 = pow(c, 4.);
        (*a) = 0-gma-gma*c4*Kval/(Kval*Kval + Ival*Ival);
        (*b) = gma*c4*Ival/(Kval*Kval + Ival*Ival);
    }
    void cal_CD(double rho, double* C, double* D){
        double c = kr(rho);
        double d = ki(rho);
        double a, b;
        cal_ab(rho, &a, &b);
        double A = a*c - b*d;
        double B = b*c + a*d;
        (*C) = 0.-A-B;
        (*D) = A-B;
    }
    double g(double rho, double s){
        double kr2 = kr(rho);
        kr2 = kr2*kr2;
        double ki2 = ki(rho);
        ki2 = ki2*ki2;
        double c4 = pow(c, 4.);
        return 0.-(gma*(kr2-ki2) - c*c/gma - c4/gma/gma/gma*(kr2-ki2)/(kr2+ki2)/(kr2+ki2))*(TMAX-s) - ki(rho)*z0;
    }
    double h(double rho, double s){
        double kr2 = kr(rho);
        double ki2 = ki(rho);
        double krki = kr2*ki2;
        kr2 = kr2*kr2;
        ki2 = ki2*ki2;
        double c4 = pow(c, 4.);
        return 0.-(2.*gma*krki + c4/gma/gma/gma*2.*krki/(kr2+ki2)/(kr2+ki2))*(TMAX-s) + kr(rho)*z0;
    } 
    double Y1(double rho, double s){
        double gval = g(rho, s);
        double Cval, Dval;
        cal_CD(rho, &Cval, &Dval);
        double hval = h(rho, s);
        return sqrt(2.)*exp(gval)*( Cval*cos(hval) - Dval*sin(hval) );
    }

    // I3 Modules   part2
    double cot(double theta){
        return cos(theta)/sin(theta);
    }
    double func3_exp(double theta, double s){
        double expnt = 0. - ( c*c/gma + pow(c, 4.)/gma/gma/gma*cot(theta)*cot(theta) )*(TMAX-s);
        return exp(expnt);
    }
    double func3_sin(double theta){
        return sin(tan(theta)*z0);
    }
    double Y2(double theta, double s){
        double c4 = pow(c, 4.);
        double numerator = gma*c4*cot(theta)*func3_exp(theta, s);
        double costheta2 = cos(theta)*cos(theta);
        double denominator = pow(gma, 4.)*sin(theta)*sin(theta) - 2.*gma*gma*c*c*costheta2 - 2.*c4*costheta2*cot(theta)*cot(theta);
        return -2.*numerator/denominator*func3_sin(theta);
    }

    // I3 Module    part3
    double Y1Y2(double rho, double theta, double s1, double s2){
        return Y1(rho, s1)*Y2(theta, s2);
    }

    // I2I3 Module  NO
    // I1I3 Module NO

}

double COR_I2(double theta1, double theta2, double s1, double s2){    // accurate formula
    double T1 = function_space::func2_exp(theta1, s1) * function_space::func2_exp(theta2, s2);
    double T2 = function_space::func2_cosh(theta1, s1) * function_space::func2_cosh(theta2, s2);
    double T3 = function_space::func2_inside(theta1, s1) * function_space::func2_inside(theta2, s2);
    double T4 = function_space::func2_sin(theta1) * function_space::func2_sin(theta2);
    //std::cout<<T1<<" "<<T2<<" "<<T3<<" "<<T4<<std::endl;
    return T1*T2*T3*T4*func_decay(s1, s2);
}

double COR_I1(double theta1, double theta2, double s1, double s2){      // accurate formula
    double T1 = function_space::func1_exp(theta1, s1) * function_space::func1_exp(theta2, s2);
    double T2 = function_space::func1_sin_1(theta1, s1) * function_space::func1_sin_1(theta2, s2);
    double T3 = function_space::func1_sin_2(theta1) * function_space::func1_sin_2(theta2);
    return T1*T2*T3*func_decay(s1, s2);
}

double COR_I1I2(double theta1, double theta2, double s1, double s2){
    double func1_value = function_space::func1_exp(theta1, s1)*function_space::func1_sin_1(theta1, s1)*function_space::func1_sin_2(theta1);
    double func2_value = function_space::func2_exp(theta2, s2)*function_space::func2_cosh(theta2, s2)*function_space::func2_inside(theta2, s2)*function_space::func2_sin(theta2);
    return func1_value*func2_value*func_decay(s1, s2);
}

double COR_I3_part1(double rho1, double rho2, double s1, double s2){
    return function_space::Y1(rho1, s1) * function_space::Y1(rho2, s2) * func_decay(s1, s2);
}

double COR_I3_part2(double theta1, double theta2, double s1, double s2){
    return function_space::Y2(theta1, s1) * function_space::Y2(theta2, s2) * func_decay(s1, s2);
}

double COR_I3_part3(double rho, double theta, double s1, double s2){
    return function_space::Y1Y2(rho, theta, s1, s2) * func_decay(s1, s2);
}


double COR_I2I3_part1(double rho, double theta, double s1, double s2){
    double func2_value = function_space::func2_exp(theta, s1)*function_space::func2_cosh(theta, s1)*function_space::func2_inside(theta, s1)*function_space::func2_sin(theta);
    double Y1_value = function_space::Y1(rho, s2);
    return func2_value*Y1_value*func_decay(s1, s2);
}

double COR_I2I3_part2(double theta1, double theta2, double s1, double s2){
    double func2_value = function_space::func2_exp(theta1, s1)*function_space::func2_cosh(theta1, s1)*function_space::func2_inside(theta1, s1)*function_space::func2_sin(theta1);
    double Y2_value = function_space::Y2(theta2, s2);
    return func2_value*Y2_value*func_decay(s1, s2);
}

double COR_I1I3_part1(double rho, double theta, double s1, double s2){
    double func1_value = function_space::func1_exp(theta, s1)*function_space::func1_sin_1(theta, s1)*function_space::func1_sin_2(theta);
    double Y1_value = function_space::Y1(rho, s2);
    return func1_value*Y1_value*func_decay(s1, s2);
}

double COR_I1I3_part2(double theta1, double theta2, double s1, double s2){
    double func1_value = function_space::func1_exp(theta1, s1)*function_space::func1_sin_1(theta1, s1)*function_space::func1_sin_2(theta1);
    double Y2_value = function_space::Y2(theta2, s2);
    return func1_value*Y2_value*func_decay(s1, s2);
}


// *************************************************************





