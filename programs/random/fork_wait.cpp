#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();

    if(pid<0){
        std::cerr<<"Fork failed!"<<std::endl;
    }
    else if(pid == 0){
        std::cout<<"Hello from child process! Starting work now...\n";
        sleep(5);
        std::cout<<"child process finished working"<<std::endl;
        return 10;
    }
    else if(pid>0){
        //int status;
        std::cout<<"Hello from the parent process! waiting on child to finish working...\n";
        //pid_t child_pid = wait(&status);
        pid_t child_pid = wait(nullptr);
       // std::cout<<"Child process with PID: "<<child_pid<<" has finished. exited with status code:"<<WEXITSTATUS(status)<<std::endl;
       std::cout<<"Child process with PID: "<<child_pid<<" has finished."<<std::endl;
    }
    return 0;
}