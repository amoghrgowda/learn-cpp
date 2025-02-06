#include<iostream>

int main(){
  std::cout<<"hello world! I am using the cpp version number: "<<__cplusplus<<std::endl;

  int a[] {1,2,3,4,5};

  for(int i = 0; i<5; i++){
    std::cout<<a[i]<<std::endl;
  }
}
