#include "Define.h"

double rho = 0.805;
double gma = (2*1.96 + 0)/rho;
double c = 3.;
double TMAX = 5.;
double z0 = 0.1;
double T = 3.4;
double lbda = 6.;

double theta1_min = 0.;
double theta1_max = PI/2.;
double theta2_min = 0.;
double theta2_max = PI/2.;
double s1_min = 0.;
double s1_max = TMAX;
double s2_min = 0.;
double s2_max = TMAX;
int N = 301;
int N1 = N;
int N2 = N;
int N3 = 201;
int N4 = 201;

unsigned int outStep = 20;