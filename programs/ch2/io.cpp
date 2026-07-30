#include "io.h"
#include <iostream>

void writeAnswer(int res){
    std::cout<<"The sum of entered operands is: "<<res<<std::endl;
}

int readNumber(){
    int inp{};
    std::cin>>inp;
    return inp;
}