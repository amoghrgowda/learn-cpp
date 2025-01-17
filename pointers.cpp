#include<iostream>
int main(){
  int b = 20;
 int *a = &b;
 int **c = &a;
  std::cout<<"*a : "<<*a<<"\t **c="<<**c;
  return 0;
}
