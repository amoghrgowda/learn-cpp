#include <iostream>
#include <unistd.h> //for fork() and getpid()
#include <sys/wait.h>

int main(){
    std::cout<< "Before forking, the PID is: "<< getpid() <<std::endl;
    pid_t pid = fork();
    
    if(pid<0){
        std::cerr<<"Fork failed!";
        return 1;
    }

    else if(pid == 0){
        std::cout<<"Hello from the child process!\n";
        std::cout<<"Child PID:"<<getpid()<<"\tParent PID:"<<getppid()<<std::endl;
    }
    else if (pid>0){
        std::cout<<"Hello from the parent process!\n";
        std::cout<<"Parent PID:"<<getpid()<<"\tChild PID:"<<pid<<std::endl;
    }
    return 0;
}