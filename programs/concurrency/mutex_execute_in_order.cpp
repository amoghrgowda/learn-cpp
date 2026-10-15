#include <iostream>
#include <thread>
#include <semaphore>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

int next_turn = 1;

void some_task(int id, int x,int y){
    std::unique_lock lock(mtx);
    cv.wait(lock, [&]{return id == next_turn;}); // waits until cv.notify_all() is used.
    std::cout<<"thread id:"<<id<<" is running"<<std::endl;
    
    for(;x<=y;x++){
        std::cout<<"x:"<<x<<"\t"<<std::endl;
    }

    next_turn++;
    lock.unlock();
    cv.notify_all();
}

int main(){
    // all of the follwing threads should be executed in the order t1->t2->t3
    std::jthread t2(some_task,2,25,35);
    std::jthread t3(some_task,3,40,50);
    std::jthread t1(some_task,1,0,10);

    return 0;
}