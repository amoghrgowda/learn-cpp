#include <iostream>
#include <string>

template <typename T>
auto getMax(T a, T b){
    return ((a>b)?a:b);
}

int main(){
    int a {5}, b {10};
    std::cout<<"Max of "<<a<<" and "<<b<<" is "<<getMax(a,b)<<std::endl;

    std::string greet {"Good morning!"};
    std::string farewell {"Good Bye!"};
    std::cout<<"Max of "<<greet<<" and "<<farewell<<" is "<<getMax(greet,farewell)<<std::endl;
    return 0;
}