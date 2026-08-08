// str1.compare(str2) returns 0 if both are equal, -1 if s1<s2, and 1 if s1>s2.

// The other method is the following

#include <string>
#include <iostream>
using namespace std;

int compareString(string& s1, string& s2) {
    if(!s1.compare(s2))
        return 0;
    else if(s1.compare(s2))
        return -1;
    else return 1;
}

int main() {
    string s1, s2;
    cin >> s1;
    cin.ignore();
    cin >> s2;
    cout << compareString(s1, s2) << endl;
    return 0;
}