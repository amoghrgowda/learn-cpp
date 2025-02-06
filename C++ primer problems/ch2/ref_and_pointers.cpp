#include <iostream>
int main(){
    //references:
    int ival = 2;
    int &r = ival;
    int *ptr_ival;
    ptr_ival = &r;
    std::cout<<*ptr_ival<<std::endl;


    //pointers:
    int a = 5, b = 10;
    int *ptr_a;
    ptr_a = &a;
    ptr_a = &b;
    std::cout<<*ptr_a;
}