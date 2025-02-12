// count the number of grades belonging to the clusters of 10, using vectors.
#include <iostream>
#include <vector>
int main(){
    std::cout<<"Enter the grades and hit ctrl+d when you are done:\n";
    std::vector<int> marks(11,0);
    int inp;
    while(std::cin>>inp){
        if(inp<=100){
            ++marks[inp/10];
            std::cout<<"input ok"<<std::endl;
        }
        else{
        std::cout<<"Enter a number less than or equal to 100"<<std::endl;
        exit(0);
        }
    }

    for(int i=0;i<=9;i++){
        std::cout<<"Cluster "<<(i*10)<<"-"<<(i*10)+9<<" has size "<<marks[i]<<std::endl;
    }
    std::cout<<"Cluster 100 has size "<<marks[10]<<std::endl;
}