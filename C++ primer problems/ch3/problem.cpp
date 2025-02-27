/*Problem Statement:

Write a C++ program that does the following:

    Takes input from the user:
        A vector of integers (size N).
        A string (size M).
        An array of size 5.
    Use pointers and references to:
        Find the maximum element in the vector using a pointer.
        Convert the string to uppercase using a pointer.
        Swap the first and last elements of the array using a reference.
        Finally, print the modified vector, string, and array.

*/

#include <iostream>
#include <vector>
using namespace std;

int max_v(vector<int> *v){
    int max_curr = (*v)[0];
    for(auto it = (*v).begin()+1; it != (*v).end(); it++ )
    {
        if(*it>max_curr)
        max_curr = *it;
    }
    return max_curr;
}

void uppr_string(string *s){
    for(char &c:*s){
        c = toupper(c);
    }
}

int main(){
// taking input:

    // vector initialization
    cout<<"Enter the size of the vector:"<<endl;
    int N;
    cin>>N;
    vector<int> v(N);
    cout<<"Enter the vector elements:"<<endl;
    for(int i = 0; i<N; i++)
        cin>>v[i];

    // String initialization
    cout<<"Enter a string:"<<endl;
    string s;
    cin>>s;

    // Array initialization
    cout<<"Enter the 5 values for the array:"<<endl;
    int arr[5];
    for(int i=0;i<5;i++)
    cin>>arr[i];

// Modifications:
cout<<"Modified output:\n"<<endl;

    // finding maximum of vector:
    cout<<"Maximum element in the vector is: "<<max_v(&v)<<endl;
    
    // print the string in uppercase using a pointer:
    uppr_string(&s);
    cout<<"String in uppercase: "<<s<<endl;

    //swapping first and last element in array using reference:
    int &first = arr[0], &last = arr[4], temp;
    temp = last;
    last = first;
    first = temp;       // or just do swap(a[0],a[4]) but the problem asks to use pointers

    cout<<"Swapping first and last element in array:"<<endl;
    
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}