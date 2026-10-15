#include <iostream>
#include <thread>

void test(int x){
    std::cout<<"Hello from thread! The argument passed in is:"<<x<<std::endl;
}

int main(){
    std::thread some_thread(&test, 100);
    some_thread.join();

    std::cout<<"Hello from main. Finished waiting for test thread.."<<std::endl;

    return 0;
}