#include <iostream>
#include <thread>
#include <mutex>

// Whatever thread locks the data, has to be the one to unlock it.
int common_num;
std::mutex mtx;

void some_func(){
    for(int i=0;i<100000;i++){
        std::scoped_lock lock(mtx); // can use scoped_lock or lock_guard here, lock_guard will go out of scope automatically
        ++common_num;
    }
}

int main(){
    std::thread t1(some_func);
    std::thread t2(some_func);
    t1.join();
    t2.join();

    std::cout<<"common_num:"<<common_num<<std::endl;
    return 0;
}