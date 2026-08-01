/*
Rule of 5 states that if a class requires implementation of any one of the following 5 memory management functions,
it probably requires all 5 of them: Copy constructor, Copy assignment, Move constructor, Move assignment, and Destructor.
*/

#include <iostream>

class IntArray{
public:
    size_t size;
    int* data;
    
    // default constructor
    explicit IntArray(size_t size = 0): size(size), data(size>0?new int[size]:nullptr){
        std::cout<<"Created the object of size "<<size<<std::endl;
    }

    // 1. Destructor
    ~IntArray() noexcept{
        std::cout<<"Destroyed\n";
        delete[] data;
    }

    // 2. Copy constructor
    IntArray(const IntArray& other):size(other.size), data(size>0?new int[other.size]:nullptr){
        std::cout<<"Copy constructor invoked. Performing deep copy\n";
        
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // 3. Copy assignment
    IntArray& operator=(const IntArray& other){
        std::cout<<"Copy assignment invoked. performing deep copy inside existing object\n";

        if(this != &other){
            delete[] data;

            size = other.size;
            data = (size>0)?new int[size]:nullptr;

            for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        }
        return *this;
    }

    // 4. Move constructor
    IntArray(IntArray&& other) noexcept:size(other.size), data(other.data){
        std::cout<<"Move constructor stealing resources.\n";
        other.size = 0;
        other.data = nullptr;
    } 

    // 5. Move assignment
    IntArray& operator=(IntArray&& other) noexcept{
        std::cout<<"Move assignment invoked.\n";
        if(this != &other){
            delete[] data;

            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }
};

int main(){

    std::cout<<"Constructing original array... \n";
    IntArray a1(3);
    a1.data[0]= 10;
    a1.data[1] = 20;
    a1.data[2] = 30;
    std::cout<<"done.\n";

    IntArray a2(3);

    a2 = a1;

    IntArray a3;
    a3 = std::move(a2);

    IntArray a4(std::move(a3));


    return 0;
}