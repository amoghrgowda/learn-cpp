// comments practice
#include <iostream>

int main(){
    std::cout<< "/*";
    std::cout<<"*/";
    //doesn't work --->  std::cout<</*"*/"*/;
    //also doesn't work ---> std::cout<</* "*/" /* "/*" */;
    return 0;
}