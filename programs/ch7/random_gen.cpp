// We can use Mersenne Twister (most common algorithm) to generate the pseudo-random number

#include <iostream>
#include <random>

int main(){
    //Mersenne twister:
    //std::mt19937 mt{};  ... is value initialized and therefore, not random (same seed)
    std::mt19937 mt{std::random_device{}()}; // std::random_device asks OS for some random number to use as a seed.

    //lets create a die roll random numbers

    //this makes sure that there is a uniform distribution (equal probability) that produces outputs between 1 and 6. 
    std::uniform_int_distribution die123{1, 6};

    //To print 15 die rolls:
    for(int i=1; i<16; i++){
        std::cout << die123(mt)<<"\t";
        if(i%5==0){
            std::cout<<"\n";
        }
    }

}