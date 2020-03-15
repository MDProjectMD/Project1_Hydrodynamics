#include "Integral4D.h"
#include "IOManager.h"
#include "Matrix.h"
#include "Function.h"
#include <iostream>

int main(){
    std::cout<<"Integrated function:    "<<"COR_I3"<<std::endl;
    std::cout<< "Parameters:"<<std::endl;
    std::cout<< "rho_max:   "<<rho_max_I3<<std::endl;
    //std::cout<<"N1: "<<N1<<" "<<"N2:    "<<N2<<"    N3: "<<N3<<"    N4: "<<N4<<std::endl;
    //std::cout<<"N_rho: "<<N_rho<<" "<<"N_rho:    "<<N_rho<<"    N_time: "<<N_time<<"    N_time: "<<N_time<<std::endl;
    //double Q1 = Integral4D(&COR_I3_part1, rho_min_I3, rho_max_I3, rho_min_I3, rho_max_I3, s1_min_I3, s1_max_I3, s2_min_I3, s2_max_I3, N_rho, N_rho, N_time, N_time);
    //std::cout<<"N_theta: "<<N_theta<<" "<<"N_theta:    "<<N_theta<<"    N_time: "<<N_time<<"    N_time: "<<N_time<<std::endl;
    //double Q2 = Integral4D(&COR_I3_part2, theta_min_I3, theta_max_I3, theta_min_I3, theta_max_I3, s1_min_I3, s1_max_I3, s2_min_I3, s2_max_I3, N_theta, N_theta, N_time, N_time);
    //std::cout<<"N_rho: "<<N_rho<<" "<<"N_theta:    "<<N_theta<<"    N_time: "<<N_time<<"    N_time: "<<N_time<<std::endl;
    //double Q3 = Integral4D(&COR_I3_part3, rho_min_I3, rho_max_I3, theta_min_I3, theta_max_I3, s1_min_I3, s1_max_I3, s2_min_I3, s2_max_I3, N_rho, N_theta, N_time, N_time);
    //std::cout<<"N_rho: "<<N_rho<<" "<<"N_theta:    "<<N_theta<<"    N_time: "<<N_time<<"    N_time: "<<N_time<<std::endl;
    //double Q4 = Integral4D(&COR_I2I3_part1, rho_min_I2I3, rho_max_I2I3, theta_min_I2I3, theta_max_I2I3, s1_min_I2I3, s1_max_I2I3, s2_min_I2I3, s2_max_I2I3, N_rho, N_theta, N_time, N_time);
    //std::cout<<"N_theta: "<<N_theta<<" "<<"N_theta:    "<<N_theta<<"    N_time: "<<N_time<<"    N_time: "<<N_time<<std::endl;
    //double Q5 = Integral4D(&COR_I2I3_part2, theta1_min_I2I3, theta1_max_I2I3, theta2_min_I2I3, theta2_max_I2I3, s1_min_I2I3, s1_max_I2I3, s2_min_I2I3, s2_max_I2I3, N_theta, N_theta, N_time, N_time);
    //double Q6 = Integral4D(&COR_I1, theta1_min_I1, theta1_max_I1, theta2_min_I1, theta2_max_I1, s1_min_I1, s1_max_I1, s2_min_I1, s2_max_I1, N_theta, N_theta, N_time, N_time);
    //std::cout<< " part1:    " << Q6 << std::endl;
    //double Q7 = Integral4D(&COR_I1I3_part1, rho_min_I1I3, rho_max_I1I3, theta1_min_I1I3, theta1_max_I1I3, s1_min_I1I3, s1_max_I1I3, s2_min_I1I3, s2_max_I1I3, N_rho, N_theta, N_time, N_time);
    //std::cout<< " part1:    " << Q7 << std::endl;
    //double Q8 = Integral4D(&COR_I1I3_part2, theta1_min_I1I3, theta1_max_I1I3, theta2_min_I1I3, theta2_max_I1I3, s1_min_I1I3, s1_max_I1I3, s2_min_I1I3, s2_max_I1I3, N_theta, N_theta, N_time, N_time);
    //std::cout<< " part1:    " << Q8 << std::endl;
    double Q9 = Integral4D(&COR_I1I2, theta1_min_I1I2, theta1_max_I1I2, theta2_min_I1I2, theta2_max_I1I2, s1_min_I1I2, s1_max_I1I2, s2_min_I1I2, s2_max_I1I2, N_theta, N_theta, N_time, N_time);
    std::cout<< " part1:    " << Q9 << std::endl;

    //std::cout<< " part1:    " << Q5 << std::endl;
    //std::cout<< " part2:    " << Q2 << std::endl;
    //std::cout<< " part3:    " << Q3 << std::endl;
}