#include <iostream>
#include <string>

template <typename T>
constexpr bool is_lvalue(T&){
    return true;
}

template <typename T>
constexpr bool is_lvalue(T&&){
    return false;
}

// helper macro
#define PRINTVCAT(expr) \
    do{\
    std::cout<< #expr << " is an "<< (is_lvalue((expr))? "lvalue\n": "rvalue\n");\
}while(0)


int main(){
    PRINTVCAT(5);
    PRINTVCAT(std::string {"Hello world!"});
    int a {10};
    PRINTVCAT(a);
}