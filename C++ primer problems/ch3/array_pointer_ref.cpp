// Practice array traversal, pointer arithmetic, and references.
#include <iostream>
using namespace std;

void alter(int*& p){
    *(p + 4) = 150;
}
int main(){
    int arr[] = {10,20,30,40,50};
    int* ptr_arr = arr;
    int& ref = arr[2];
    cout<<"original array:\n";
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    alter(ptr_arr);

    ref = 50;

    cout<<"altered array:\n";
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}