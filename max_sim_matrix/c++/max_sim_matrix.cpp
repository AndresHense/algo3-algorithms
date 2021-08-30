#include"max_sim_matrix.hpp"
#include<assert.h>
#include<algorithm>
#include<functional>

int maximizar(const std::vector<int>&sol_p,const std::vector<std::vector<int>>&m){
    int res=0;
    std::vector<std::pair<int,int>> pares={};
    std::vector<int> indices={};
    for(int i=0;i<sol_p.size();i++){
        if(sol_p[i]==1)indices.push_back(i);
    }
    for(int i=0;i<indices.size();i++){
        for(int j=0;j<indices.size();j++){
            pares.push_back(std::make_pair(indices[i],indices[j]));
        }
    }
    
    for(int i=0;i<pares.size();i++){
        res+=m[pares[i].first][pares[i].second];
    }
    return res;
}
int suma_positivos(const std::vector<std::vector<int>>&m,int i){
    int res=0;
    std::vector<std::pair<int,int>> pares={};
    std::vector<int> indices={};
    for(int j=i;j<m.size();j++){
        indices.push_back(j);
    }
    for(int i=0;i<indices.size();i++){
        for(int j=0;j<indices.size();j++){
            pares.push_back(std::make_pair(indices[i],indices[j]));
        }
    }
    
    for(int i=0;i<pares.size();i++){
        res+=(m[pares[i].first][pares[i].second])>0?m[pares[i].first][pares[i].second]:0;
    }
    return res;
}

void max_simM_aux(const std::vector<std::vector<int>>&m,int i,int k,std::vector<int>&sol_p,
    int &max,std::function<void(const std::vector<int>&,const int )>setter){
    /*
    std::cout<<"[";
    for_each(sol_p.begin(),sol_p.end(),[](int t){
        std::cout<<t<<", ";
    });
    std::cout<<"]"<<std::endl;
    */
    if(i==m.size()-1){    
        int p_max=maximizar(sol_p,m);
        //std::cout<<"El max es: "<<p_max<<std::endl;
        if(p_max>max)
            setter(sol_p,p_max);
        return;
    }

    int tmp_max=suma_positivos(m,i);
    //std::cout<<"tmp_max: "<<tmp_max<<std::endl;
    if(tmp_max<max)
        return;
    i++;
    k--;
    sol_p[i]=1;
    max_simM_aux(m,i,k,sol_p,max,setter);
    k++;
    sol_p[i]=0;
    max_simM_aux(m,i,k,sol_p,max,setter);
    return;
}

std::vector<int> max_simM(const std::vector<std::vector<int>>&m,const int k){
    std::vector<int> res={};
    std::vector<int> sol={};
    std::vector<int> sol2={};
    for(int i=1;i<=m.size();i++){
        sol.push_back(0);
    }
    int max=INT32_MIN;
    auto setter=[&sol2,&max](std::vector<int> s_p,int mac){
        //std::cout<<"Entre, porq no lo seteas?"<<std::endl;
        //std::for_each(s_p.begin(),s_p.end(),[](int t){
        //    sol2.push_back(t);
        //});
        sol2=s_p;
        max=mac;
    };
    max_simM_aux(m,-1,k,sol,max,setter);
    /*
    std::cout<<"El max es: "<<max<<std::endl;
    std::cout<<"la sol es:";
    for_each(sol2.begin(),sol2.end(),[](int t){
        std::cout<<t<<", ";
    });
    std::cout<<std::endl;
    */
    
    for(int i=0;i<sol.size();i++){
        if(sol2[i]==1)res.push_back(i);
    }
    return res;
}