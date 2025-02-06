#include <iostream>
int main(){
    int knife = 0, killed = 0, n=0;
    
    std::cout<<"Enter the number of people: \n";
    std::cin>>n;
    
    int arr[n];
    
    //initializing all the elements inside the array
    for(int i=0;i<n;i++){
    arr[i]=i+1;
    }


    //main logic starts here:
    for(int i = 0; killed<(n-1);){
        while(arr[(i+1)%(n)]==0){
            i++;
        }
        i++;
        arr[i%(n)]=0;
        killed++;
        

        while(arr[i%(n)]==0){
            i++;
        }
        knife=i%(n);
        
    }
    
    std::cout<<"The survivor is: "<<arr[knife];
}