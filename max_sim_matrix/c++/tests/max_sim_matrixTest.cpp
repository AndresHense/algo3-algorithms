#include<gtest/gtest.h>
#include "../max_sim_matrix.hpp"

TEST(m3, primearaPos){
    std::vector<std::vector<int>> m={{500,-412,-311},{-132,-412,-354},{-412,-412,-634}};
    int k=1;
    std::vector<int> expected={0};
    std::vector<int> res=max_simM(m,k);
    /*
    for_each(res.begin(),res.end(),[](int t){
        std::cout<<t<<" ";
    });
    std::cout<<std::endl;
    */
    EXPECT_TRUE(std::equal(begin(expected),end(expected),begin(res),end(res)));
}

TEST(m3, randomPos){
    std::vector<std::vector<int>> m={{412,-412,311},{-132,-412,-354},{-412,-412,-634}};
    int k=1;
    std::vector<int> expected={0};
    std::vector<int> res=max_simM(m,k);
    /*
    for_each(res.begin(),res.end(),[](int t){
        std::cout<<t<<" ";
    });
    */
    //std::cout<<std::endl;
    EXPECT_TRUE(std::equal(begin(expected),end(expected),begin(res),end(res)));
}

TEST(m3, todos){
    std::vector<std::vector<int>> m={{412,412,311},{132,412,354},{412,412,634}};
    int k=3;
    std::vector<int> expected={0,1,2};
    std::vector<int> res=max_simM(m,k);
    /*
    for_each(res.begin(),res.end(),[](int t){
        std::cout<<t<<" ";
    });
    std::cout<<std::endl;
    */
    EXPECT_TRUE(std::equal(begin(expected),end(expected),begin(res),end(res)));
}
