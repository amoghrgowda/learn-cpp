#include <ctime>
#include <iostream>

int main(){
    srand(time(nullptr));
    int random_num = rand();
    std::cout<<"A random number is: "<<random_num;
    return 0;
}