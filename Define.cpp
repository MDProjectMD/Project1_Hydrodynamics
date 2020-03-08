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
double alpha = 0.3/50/50/50; // Select an appropriate THRESHOLD for integral domain partition

double theta1_min = 0.;
double theta1_threshold = theta1_max - alpha;
double theta1_max = PI/2. - epsilon;
double theta2_min = 0.;
double theta2_threshold = theta2_max - alpha;
double theta2_max = PI/2. - epsilon;
double s1_min = 0.;
double s1_max = TMAX;
double s2_min = 0.;
double s2_max = TMAX;
int N = 21;
int N1 = 51;
//int N1_ = 11;
int N2 = 51;
//int N2_ = 101;
int N3 = 201;
int N4 = 201;

unsigned int outStep = 5;