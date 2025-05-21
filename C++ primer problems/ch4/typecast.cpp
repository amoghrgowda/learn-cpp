#include <iostream>
int main(){

    // c-style type cast
    float a = 3.14;
    int b = (int) a;

    // static cast is safer and will not allow conversion of pointer to an int for example.
    int c = static_cast<int>(a);

    std::cout<<"a = "<<a<<"\nb = "<<b<<"\nc = "<<c<<std::endl;

    // Example of static_cast preventing an invalid conversion (uncomment to see error)
    // std::string myString = "hello";
    // int stringToInt = static_cast<int>(myString); // This will cause a compilation error!
    // std::cout << stringToInt << std::endl;

     // Dangerous C-style cast example 

    // Uncommenting this might lead to a compilation error or warning,
    // or if it compiles, it will result in a runtime error or undefined behavior.
    // std::string myString = "hello";
    // int stringValue = (int)myString;
    // std::cout << stringValue << std::endl; // This is highly problematic!
}