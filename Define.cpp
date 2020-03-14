#include "Define.h"

double rho = 0.805;
double gma = (2*1.96 + 0)/rho;
double c = 3.;
double TMAX = 4.;
double z0 = 0.1;
double T = 3.4;
double lbda = 6.;

// See "Fokas Numerical" in OneNote
double epsilon = 0; 

double theta1_min_I1 = 0.;
double theta1_max_I1 = PI/2. - epsilon;
double theta2_min = 0.;
double theta2_max = PI/2. - epsilon;
double s1_min = 0.;
double s1_max = TMAX;
double s2_min = 0.;
double s2_max = TMAX;
 
double K0 = 5;  // threshold maximum k value
double theta1_min_I2 = 0.;
double theta1_max_I2 = acos(2.*c/gma/K0);
double theta2_min_I2 = 0.;
double theta2_max_I2 = acos(2.*c/gma/K0);
double s1_min_I2 = 0.;
double s1_max_I2 = TMAX;
double s2_min_I2 = 0.;
double s2_max_I2 = TMAX;

double rho_min_I3 = 0.;
double rho_max_I3 = 1./(sqrt(2.)/2.*z0) * 1.5;
double theta_min_I3 = acos(2.*c/gma/K0);
double theta_max_I3 = PI/2.;
double s1_min_I3 = 0.;
double s1_max_I3 = TMAX;
double s2_min_I3 = 0.;
double s2_max_I3 = TMAX;

double rho_min_I2I3 = 0.;
double rho_max_I2I3 = 1./(sqrt(2.)/2.*z0) * 1.5;
double theta_min_I2I3 = 0.;
double theta_max_I2I3 = acos(2.*c/gma/K0);
double s1_min_I2I3 = 0.;
double s1_max_I2I3 = TMAX;
double s2_min_I2I3 = 0.;
double s2_max_I2I3 = TMAX;

// COR_I2
int N = 21;
int N1 = 201;
//int N1_ = 11;
int N2 = 201;
//int N2_ = 101;
int N3 = 401;
int N4 = 401;

// COR_I3
int N_rho = 301;
int N_theta = 101;
int N_time = 901;

unsigned int outStep = 10;