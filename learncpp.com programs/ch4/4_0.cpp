/*Write a short program where the user is asked to enter a single character. Print the value of the character and its ASCII code, using static_cast.

The program’s output should match the following:

Enter a single character: a
You entered 'a', which has ASCII code 97.
*/
#include <iostream>

int return_ascii(char a);

int main(){
    std::cout<<"Enter a single character: "<<std::endl;
    char a {};
    std::cin>>a;
    std::cout<<"You entered "<<a<<", which has ASCII code "<<return_ascii(a)<<std::endl;
}

int return_ascii(char a){
    return static_cast<int>(a);
}