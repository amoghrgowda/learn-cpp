#include <iostream>
#include <vector>

void ForEach(std::vector<int>& vec, void (*some_func)(int)){
    for (int i: vec){
        some_func(i);
    }
}

int main(){
    std::vector<int> vec;
    vec.reserve(5);
    vec.insert(vec.end(),{5,1,8,10,2});
    ForEach(vec, [](int val){
        std::cout<<"Value: "<<val<<std::endl;
    });

    return 0;
}