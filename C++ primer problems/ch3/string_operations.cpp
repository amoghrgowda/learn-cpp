using namespace std;
#include <string>
#include <iostream>

int main(){
    string s;
    cout<<"enter a string:";
    getline(cin, s);
    if (s.empty()){
        cout<<"The string you entered is empty.";
        return 0;
    }
    else{
        cout<<"The string you entered is of length "<<s.size();
        return 0;
    }
}

