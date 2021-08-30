#include<vector>
#include<iostream>
#include<functional>
int maximizar(const std::vector<int>&sol_p,const std::vector<std::vector<int>>&m);
void max_simM_aux(const std::vector<std::vector<int>>&m,int j,int k,std::vector<int>&sol_p,int&,std::function<void(const std::vector<int>&,const int )>setter);
std::vector<int>max_simM(const std::vector<std::vector<int>>&,const int);