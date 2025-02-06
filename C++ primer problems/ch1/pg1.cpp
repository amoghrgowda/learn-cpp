// program to read an unknown number of inputs (1.4.3)

#include <iostream>
int main(){
    std::cout<<"Enter the numbers to find a sum of: "<<std::endl;
    int inp,sum=0;
    while (std::cin>>inp){
        sum+=inp;
    }
    std::cout<<"\nThe sum of entered numbers is: "<<sum<<std::endl;
}
