/*
Write a program that asks the user to enter their full name and their age. As output, tell the user the sum of their age and the number of characters in their name (use the std::string::length() member function to get the length of the string). For simplicity, count any spaces in the name as a character.

Sample output:

Enter your full name: John Doe
Enter your age: 32
Your age + length of name is: 40

Reminder: We need to be careful not to mix signed and unsigned values. std::string::length() returns an unsigned value. If you’re C++20 capable, use std::ssize() to get the length as a signed value. Otherwise, static_cast the return value of std::string::length() to an int.
*/

#include <iostream>
#include <string>
#include <string_view>

int calc_age_name_length(std::string_view full_name, int age);

int main(){
    std::cout<<"Enter your full name: "<<std::flush;
    std::string full_name {};
    std::getline(std::cin>>std::ws, full_name);
    
    std::cout<<"Enter your age: "<<std::flush;
    int age {};
    std::cin>>age;

    std::cout<<"Your age + length of name is: "<<calc_age_name_length(full_name, age)<<"\n";
}

int calc_age_name_length(std::string_view full_name, int age){
    return static_cast<int>(full_name.length()) + age;
}